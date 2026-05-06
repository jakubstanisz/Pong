#pragma once
#include "PointCounter.hpp"
#include "raylib.h"
#include "Paddle.hpp"

class Ball {
private:
    Vector2 position;
    Vector2 velocity;
    float radius; 

public:
    Ball(Vector2 pos);
    void setBallPosition(Vector2 pos);
    Vector2 getBallPosition();
    void setVelocity(Vector2 vel);
    Vector2 getVelocity();
    
    void Update(Paddle &paddle, PointCounter &pointCounter);
    void drawBall();
    void respawn();
};