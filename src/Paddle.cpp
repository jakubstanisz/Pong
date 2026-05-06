#include "Paddle.hpp"
#include "raylib.h"

Paddle::Paddle(int pW, int pH, Vector2 pos){
    paddleWidth = pW;
    paddleHeight = pH;
    position = pos;
}
void Paddle::setPaddleWidth(int pWidth){
    paddleWidth = pWidth;
}
void Paddle::setPaddleHeight(int pHeight){
    paddleHeight = pHeight;
}
void Paddle::setPaddlePosition(Vector2 pos){
    position = pos;
}
int Paddle::getPaddleWidth(){
    return paddleWidth;
}
int Paddle::getPaddleHeight(){
    return paddleHeight;
}
Vector2 Paddle::getPaddlePosition(){
    return position;
}
void Paddle::drawPaddle(){
    DrawRectangle(position.x, position.y, paddleWidth, paddleHeight, WHITE);
}