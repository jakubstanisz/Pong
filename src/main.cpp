#include "raylib.h"
#include "GameWindow.hpp"
#include "Paddle.hpp"
#include "Movement.hpp"
#include "PointCounter.hpp"
#include "Ball.hpp"

#define PADDLE_SPEED 500.0
// todo:
// 2. delete game window.

int main(int argc, char* argv[]){
    GameWindow gameWindow(argc, argv);
    gameWindow.initializeWindow();

    int screenWidth = gameWindow.getScreenWidth();
    int screenHeight = gameWindow.getScreenHeight();

    Paddle paddle1(5, 60, {20, 10});
    Paddle paddle2(5 , 60, {GetScreenWidth() - 20.0f, 10});
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
        pCounter1.drawPoints({60, 30});
        pCounter2.drawPoints({GetScreenWidth() - 60.0f, 30});
        ball.Update(paddle1, pCounter1);
        ball.Update(paddle2, pCounter2);
        paddle1.drawPaddle();
        paddle2.drawPaddle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}