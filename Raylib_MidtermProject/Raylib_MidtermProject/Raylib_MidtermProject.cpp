// main.cpp
#include "raylib.h"
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Item.h"
#include "GameUtils.h"
#include <vector>

const int screenWidth = 800;
const int screenHeight = 450;

enum GameState { Start, Playing, GameOver };
GameState currentState = Start;

float startTime = 0.0f;
float endTime = 0.0f;

Vector2 respawnPosition = { 50, 300 };

int main() {
    InitWindow(screenWidth, screenHeight, "Midterm Platformer Project");

    Player player(respawnPosition);
    std::vector<Platform> platforms = {
        Platform({1, 300}, {110, 300}, false, false),
        Platform({200, 310}, {120, 10}, true, false), // Dissapearing
        Platform({450, 250}, {100, 10}, false, true) // Moving 
    };

    /*
    std::vector<Enemy> spike = {
        Enemy({ 500, 230 }),
        Enemy({ 550, 230 }), 
    };
    */
    Enemy spike ({ 500, 230 });
    Enemy spike2({ 550, 230 });

    Item coin({ 700, 150 });

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentState == Start) {
            DrawRectangleGradientV(0, 0, screenWidth, screenHeight, RAYWHITE, DARKGRAY);
            DrawText("Midterm", screenWidth / 2 - MeasureText("Midterm", 25) / 2, screenHeight / 2 - 100, 25, SKYBLUE);
            DrawText("Platformer Project", screenWidth / 2 - MeasureText("Platformer Project", 40) / 2, screenHeight / 2 - 70, 40, BLUE);

            DrawRectangle(screenWidth / 2 - 50, screenHeight / 2, 100, 40, LIGHTGRAY);

            DrawText("Play", screenWidth / 2 - MeasureText("Play", 20) / 2, screenHeight / 2 + 10, 20, DARKGRAY);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, { screenWidth / 2 - 50, screenHeight / 2, 100, 40 })) {
                    currentState = Playing;
                    startTime = GetTime();
                }
            }
        }
        else if (currentState == Playing) {
            player.Update();

            if (player.position.y > screenHeight) {
                player.position = respawnPosition;
                player.velocity = { 0, 0 };
                player.isJumping = false;
            }

            for (auto& platform : platforms) platform.Update(deltaTime);

            for (auto& platform : platforms) {
                if (CheckCollision(&player, &platform) && player.velocity.y > 0) {
                    if (platform.isVisible) {
                        player.isJumping = false;
                        player.velocity.y = 0;
                        player.position.y = platform.position.y - player.size.y;
                        platform.Disappear();
                    }
                }
            }

            if (CheckCollision(&player, &spike)) {
                player.position = respawnPosition;
                player.velocity = { 0, 0 };
                player.isJumping = false;
            }

            if (CheckCollision(&player, &coin) && !coin.collected) {
                coin.collected = true;
                endTime = GetTime();
                currentState = GameOver;
            }

            player.Draw();
            for (auto& platform : platforms) platform.Draw();
            spike.Draw();
            coin.Draw();
        }
        else if (currentState == GameOver) {
            float timeTaken = endTime - startTime;
            DrawRectangleGradientV(0, 0, screenWidth, screenHeight, GOLD, RAYWHITE);
            DrawText("Congrats", screenWidth / 2 - MeasureText("Congrats", 60) / 2, screenHeight / 2 - 150, 60, ORANGE);
            DrawText("You're Rick!", screenWidth / 2 - MeasureText("You're Rick!", 40) / 2, screenHeight / 2 - 60, 40, DARKGRAY);
            DrawText(TextFormat("Time Taken: %.2f seconds", timeTaken), screenWidth / 2 - MeasureText("Time Taken: 0.00 seconds", 20) / 2, screenHeight / 2, 20, DARKGRAY);
            DrawText("Press ENTER to Restart", screenWidth / 2 - MeasureText("Press ENTER to Restart", 20) / 2, screenHeight / 2 + 150, 20, LIGHTGRAY);

            if (IsKeyPressed(KEY_ENTER)) {
                currentState = Start;
                player.position = respawnPosition;
                player.velocity = { 0, 0 };
                player.isJumping = false;
                coin.collected = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}