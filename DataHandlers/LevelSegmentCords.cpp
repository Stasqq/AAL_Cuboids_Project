//
// Created by Stasiek on 2020-05-27.
//

#include "LevelSegmentCords.h"

LevelSegmentCords::LevelSegmentCords(int x1, int y1, int x2, int y2) {
    this -> x1 = x1;
    this -> x2 = x2;
    this -> y1 = y1;
    this -> y2 = y2;
}

LevelSegmentCords::LevelSegmentCords(int x1, int y1, int x2, int y2, int startLevel, int height) {
    this -> x1 = x1;
    this -> x2 = x2;
    this -> y1 = y1;
    this -> y2 = y2;
    this -> startLevel = startLevel;
    this -> height = height;
}

int LevelSegmentCords::getX1() const {
    return x1;
}

int LevelSegmentCords::getY1() const {
    return y1;
}

int LevelSegmentCords::getX2() const {
    return x2;
}

int LevelSegmentCords::getY2() const {
    return y2;
}

int LevelSegmentCords::getStartLevel() const {
    return startLevel;
}

int LevelSegmentCords::getHeight() const {
    return height;
}

void LevelSegmentCords::setStartLevel(int startLevel) {
    LevelSegmentCords::startLevel = startLevel;
}

void LevelSegmentCords::setHeight(int height) {
    LevelSegmentCords::height = height;
}
