#include "GameWindow.hpp"
#include <iostream>
GameWindow::GameWindow(int argc,char* argv[]){
    if (argc == 3){
        screenWidth = std::atoi(argv[1]);
        screenHeight = std::atoi(argv[2]);
    }else {
        std::cout << "Blednie podane argumenty startowe. Ustawiam wartosci domyslne" << std::endl;
        screenWidth = 800;
        screenHeight = 600;

    }
}
void GameWindow::setScreenWidth(int sW){
    screenWidth = sW;
}
void GameWindow::setScreenHeight(int sH){
    screenHeight = sH;
}
int GameWindow::getScreenWidth(){
    return screenWidth;
}
int GameWindow::getScreenHeight(){
    return screenHeight;
}
void GameWindow::initializeWindow(){
    InitWindow(screenWidth, screenHeight, "Pong Game");
}