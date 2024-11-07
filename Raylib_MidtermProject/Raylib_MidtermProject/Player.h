#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
    Vector2 velocity;
    bool isJumping;

    Player(Vector2 pos);
    void Update();
    void Draw() override;
};

