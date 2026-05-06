#include "Ball.hpp"
#include "PointCounter.hpp"
#include <raylib.h>
#include <cmath>

Ball::Ball(Vector2 pos){
    position = pos;
    radius = 10.0f;
    respawn();
}

void Ball::setBallPosition(Vector2 pos){
    position = pos;
}

Vector2 Ball::getBallPosition(){
    return position;
}

void Ball::setVelocity(Vector2 vel) { 
    velocity = vel; 
}

Vector2 Ball::getVelocity() {
    return velocity; 
}

void Ball::Update(Paddle &paddle, PointCounter &pointCounter) {
    position.x += velocity.x * GetFrameTime();
    position.y += velocity.y * GetFrameTime();

    if (position.y - radius <= 0) {
        position.y = radius;
        velocity.y *= -1;
    } else if (position.y + radius >= GetScreenHeight()) {
        position.y = GetScreenHeight() - radius;
        velocity.y *= -1;
    }
    if (position.x < 0 || position.x > GetScreenWidth()){
        respawn();
        pointCounter.addPoint();
    }
    if (CheckCollisionCircleRec(position, radius, paddle.getRect())){
        velocity.x *= -1;
    }
}

void Ball::drawBall(){
    // TODO :
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::respawn() {
    position.x = GetScreenWidth() / 2.0f;
    position.y = (float)GetRandomValue(20, GetScreenHeight() - 20);

    float speed = 100.0f;
    float angle = (float)GetRandomValue(-30, 30); 

    if (GetRandomValue(0, 1) == 0) angle += 180.0f;

    float radians = angle * DEG2RAD; 

    velocity.x = cos(radians) * speed;
    velocity.y = sin(radians) * speed;
}