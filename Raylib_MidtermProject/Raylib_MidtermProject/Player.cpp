// Player.cpp
#include "Player.h"

Player::Player(Vector2 pos) : GameObject(pos, { 30, 40 }), velocity({ 0, 0 }), isJumping(false) {}

void Player::Update() {
    if (IsKeyDown(KEY_RIGHT)) velocity.x = 5;
    else if (IsKeyDown(KEY_LEFT)) velocity.x = -5;
    else if (IsKeyDown(KEY_D)) velocity.x = 5;
    else if (IsKeyDown(KEY_A)) velocity.x = -5;
    else velocity.x = 0;

    if (IsKeyPressed(KEY_SPACE) && !isJumping) {
        velocity.y = -10;
        isJumping = true;
    }

    if (IsKeyPressed(KEY_W) && !isJumping) {
        velocity.y = -10;
        isJumping = true;
    }

    if (IsKeyPressed(KEY_UP) && !isJumping) {
        velocity.y = -10;
        isJumping = true;
    }

    velocity.y += 0.5; 

    position.x += velocity.x;
    position.y += velocity.y;
}

void Player::Draw() {
    DrawRectangle(position.x, position.y, size.x, size.y, BLUE);
}
