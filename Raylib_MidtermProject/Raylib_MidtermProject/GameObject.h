// Base Class for the game object
#pragma once
#include "raylib.h"

class GameObject {
public:
    Vector2 position;
    Vector2 size;

    GameObject(Vector2 pos, Vector2 sz) : position(pos), size(sz) {}
    virtual void Draw() = 0;
};

