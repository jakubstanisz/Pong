#include "raylib.h"
#include "Paddle.hpp"
#include "Movement.hpp"
#include "PointCounter.hpp"
#include "Ball.hpp"
#include <iostream>

#define PADDLE_SPEED 1000.0

int main(int argc, char* argv[]){
    int screenWidth;
    int screenHeight;
    if (argc == 3){
        screenWidth = std::atoi(argv[1]);
        screenHeight = std::atoi(argv[2]);
    }else {
        std::cout << "Blednie podane argumenty startowe. Ustawiam wartosci domyslne" << std::endl;
        screenWidth = 1200;
        screenHeight = 650;
    }
    InitWindow(screenWidth, screenHeight, "Pong Game");

    Paddle paddle1(5, 75, {20, 10});
    Paddle paddle2(5 , 75, {GetScreenWidth() - 20.0f, 10});
    PointCounter pCounter1(0);
    PointCounter pCounter2(0);
    Ball ball({GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f});
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 5, 
            screenWidth / 2 + 8, screenHeight, WHITE); 
        Movement::Move(paddle1, paddle2, PADDLE_SPEED);
        ball.drawBall();
        pCounter1.drawPoints({75, 30});
        pCounter2.drawPoints({GetScreenWidth() - 75.0f, 30});
        ball.Update(paddle1, pCounter1, pCounter2);
        ball.Update(paddle2, pCounter1, pCounter2);
        paddle1.drawPaddle();
        paddle2.drawPaddle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}