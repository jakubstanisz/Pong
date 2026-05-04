#include "Paddle.hpp"
#include "GameWindow.hpp"
#include "raylib.h"
#include <cmath>
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
int Paddle::getPaddleWidth(){
    return paddleWidth;
}
int Paddle::getPaddleHeight(){
    return paddleHeight;
}
void Paddle::drawPaddle(){
    DrawRectangle(position.x, position.y, paddleWidth, paddleHeight, WHITE);
}