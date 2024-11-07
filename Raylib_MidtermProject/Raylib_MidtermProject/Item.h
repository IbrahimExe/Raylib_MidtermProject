#pragma once

#include "GameObject.h"

class Item : public GameObject {
public:
    bool collected;

    Item(Vector2 pos); // Where the item spawns
    void Draw() override;
};
