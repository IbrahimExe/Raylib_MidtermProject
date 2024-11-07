#include "Platform.h"
#include "raymath.h"

Platform::Platform(Vector2 pos, Vector2 sz, bool disappearing, bool moving)
    : GameObject(pos, sz), isDisappearing(disappearing), isMoving(moving), disappearTimer(0),
    disappearDuration(2.0f), isVisible(true) {}

void Platform::Update(float deltaTime) 
{
    if (isMoving) {
        position.x += 2 * sin(GetTime());
    }

    if (isDisappearing && !isVisible) {
        disappearTimer += deltaTime;
        if (disappearTimer >= disappearDuration) {
            isVisible = true;
            disappearTimer = 0.0f;
        }
    }
}

void Platform::Disappear() 
{
    if (isDisappearing && isVisible) {
        isVisible = false;
    }
}

void Platform::Draw() 
{
    if (isVisible) {
        DrawRectangle(position.x, position.y, size.x, size.y, DARKGRAY);
    }
}
