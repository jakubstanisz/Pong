#include "raylib.h"
#include "GameWindow.hpp"
#include "Paddle.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    GameWindow gameWindow(argc, argv);
    gameWindow.initializeWindow();
    Paddle paddle(5, 60, {20, 10});
    int screenWidth = gameWindow.getScreenWidth();
    int screenHeight = gameWindow.getScreenHeight();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 5, 
            screenWidth / 2 + 8, screenHeight, WHITE); 
        paddle.drawPaddle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}