//
// Created by Stasiek on 2020-05-27.
//

#include "CornerTower.h"

CornerTower::CornerTower(int x, int y) {
    this -> height = 0;
    this -> x = x;
    this -> y = y;
}

int CornerTower::getHeight() const {
    return height;
}

void CornerTower::increaseHeight(int x) {
    height += x;
}

int CornerTower::getX() const {
    return x;
}

int CornerTower::getY() const {
    return y;
}
