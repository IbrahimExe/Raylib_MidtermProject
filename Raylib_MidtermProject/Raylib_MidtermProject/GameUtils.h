#pragma once
#include "raylib.h"
#include "GameObject.h"

bool CheckCollision(GameObject* obj1, GameObject* obj2) {
    return (obj1->position.x < obj2->position.x + obj2->size.x &&
        obj1->position.x + obj1->size.x > obj2->position.x &&
        obj1->position.y < obj2->position.y + obj2->size.y &&
        obj1->position.y + obj1->size.y > obj2->position.y);
}
