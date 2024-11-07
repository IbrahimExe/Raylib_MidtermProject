#include "Item.h"

Item::Item(Vector2 pos) : GameObject(pos, { 10, 10 }), collected(false) {}

void Item::Draw() 
{
    if (!collected) 
        DrawCircleLines(position.x, position.y, size.x + 1, BLACK);
        DrawCircleGradient(position.x, position.y, size.x, GOLD, YELLOW);
}

