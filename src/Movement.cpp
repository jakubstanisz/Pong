#include "Movement.hpp"
#include <raylib.h>

void Movement::Move(Paddle &paddle1, Paddle &paddle2, float speed){
    Vector2 position1 = paddle1.getPaddlePosition();
    Vector2 position2 = paddle2.getPaddlePosition();
    if (IsKeyDown(KEY_DOWN) && position1.y + paddle1.getPaddleHeight() < GetScreenHeight()){
        position1.y += GetFrameTime() * speed;
    }else if (IsKeyDown(KEY_UP) && (position1.y > 0)){
        position1.y -= GetFrameTime() * speed;
    }
    if (IsKeyDown(KEY_W) && (position2.y > 0) ){
        position2.y -= GetFrameTime() * speed;
    }else if (IsKeyDown(KEY_S) && position2.y + paddle2.getPaddleHeight() < GetScreenHeight()){
        position2.y += GetFrameTime() * speed;
    }
    paddle1.setPaddlePosition(position1);
    paddle2.setPaddlePosition(position2);
}