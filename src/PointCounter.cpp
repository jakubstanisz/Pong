#include "PointCounter.hpp"

PointCounter::PointCounter(int pts){
    points = pts;
}

void PointCounter::setPoints(int pts){
    points = pts;
}

void PointCounter::addPoint(){
    points++;
}

int PointCounter::getPoints(){
    return points;
}

void PointCounter::drawPoints(Vector2 position){
    DrawText(TextFormat("%d", points), position.x, position.y, 30, WHITE);
}