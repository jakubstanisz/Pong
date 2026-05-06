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
        void setPaddlePosition(Vector2 pos);
        int getPaddleWidth();
        int getPaddleHeight();
        Vector2 getPaddlePosition();
        void drawPaddle();
};