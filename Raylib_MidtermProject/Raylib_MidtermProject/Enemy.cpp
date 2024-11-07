#include "Enemy.h"

Enemy::Enemy(Vector2 pos) : GameObject(pos, { 20, 20 }) {}

void Enemy::Draw() {
    DrawTriangle(
        { position.x, position.y + size.y },
        { position.x + size.x / 2, position.y },
        { position.x + size.x, position.y + size.y },
        RED
    );
    DrawTriangleLines(
        { position.x, position.y + size.y },
        { position.x + size.x / 2, position.y },
        { position.x + size.x, position.y + size.y },
        BLACK
    );
}
