#pragma once
#include "raylib.h"

class GameWindow{
    private:
        int screenWidth;
        int screenHeight;
    public:
        GameWindow(int argc, char* argv[]);
        void setScreenWidth(int sW);
        void setScreenHeight(int sH);
        int getScreenWidth();
        int getScreenHeight();
        void initializeWindow();
};