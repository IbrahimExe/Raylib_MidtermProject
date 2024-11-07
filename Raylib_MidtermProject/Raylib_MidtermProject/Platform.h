#pragma once
#include "GameObject.h"

class Platform : public GameObject {
public:
    bool isDisappearing;
    bool isMoving;
    float disappearTimer;
    float disappearDuration;
    bool isVisible;

    Platform(Vector2 pos, Vector2 sz, bool disappearing, bool moving);
    void Update(float deltaTime);
    void Disappear();
    void Draw() override;
};

