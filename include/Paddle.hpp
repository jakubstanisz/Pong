#pragma once
#include "raylib.h"

class Paddle{
    private:
        int paddleWidth;
        int paddleHeight;
        Vector2 position;
    public:
        Paddle(int pW, int pH, Vector2 pos);
        void setPaddleWidth(int pWidth);
        void setPaddleHeight(int pHeight);
        int getPaddleWidth();
        int getPaddleHeight();
        void drawPaddle();
};