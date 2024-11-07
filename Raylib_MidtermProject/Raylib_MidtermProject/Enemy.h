#pragma once

#include "GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(Vector2 pos);
    void Draw() override;
};

