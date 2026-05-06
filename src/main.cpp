#include "raylib.h"
#include "GameWindow.hpp"
#include "Paddle.hpp"
#include "Movement.hpp"

#define PADDLE_SPEED 500.0

int main(int argc, char* argv[]){
    GameWindow gameWindow(argc, argv);
    gameWindow.initializeWindow();

    int screenWidth = gameWindow.getScreenWidth();
    int screenHeight = gameWindow.getScreenHeight();

    Paddle paddle1(5, 60, {20, 10});
    Paddle paddle2(5 , 60, {static_cast<float>(screenWidth) - 20, 10});
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 5, 
            screenWidth / 2 + 8, screenHeight, WHITE); 
        Movement::Move(paddle1, paddle2, PADDLE_SPEED);

        paddle1.drawPaddle();
        paddle2.drawPaddle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}