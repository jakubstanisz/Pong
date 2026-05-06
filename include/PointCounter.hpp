#pragma once
#include "raylib.h"
class PointCounter{
    private:
        int points;
    public:
        PointCounter(int Points);
        void setPoints(int points);
        int getPoints();
        void addPoint();
        void drawPoints(Vector2 position);
};