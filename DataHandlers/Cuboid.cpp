//
// Created by Stasiek on 2020-05-20.
//

#include "Cuboid.h"

Cuboid::Cuboid(int xSize, int ySize, int zSize) {
    this -> xSize = xSize;
    this -> ySize = ySize;
    this -> zSize = zSize;
}

Cuboid::Cuboid(int xSize, int ySize, int zSize, int id) {
    this -> xSize = xSize;
    this -> ySize = ySize;
    this -> zSize = zSize;
    this -> id = id;
}

void Cuboid::rotate(int rotateDirection) {
    rotateDirection = rotateDirection % 3;
    switch (rotateDirection) {
        case 0: {
            rotateXY();
        }
            break;
        case 1: {
            rotateYZ();
        }
            break;
        case 2: {
            rotateXZ();
        }
            break;
    }
}

void Cuboid::rotateXY() {
    int temp = this -> xSize;
    this -> xSize = this -> ySize;
    this -> ySize = temp;
}

void Cuboid::rotateXZ() {
    int temp = this -> xSize;
    this -> xSize = this -> zSize;
    this -> zSize = temp;
}

void Cuboid::rotateYZ() {
    int temp = this -> ySize;
    this -> ySize = this -> zSize;
    this -> zSize = temp;
}

void Cuboid::rotateToSmallestHeight() {
    if (zSize <= xSize && zSize <= ySize) {
        return;
    } else {
        int tempZ;
        if (xSize <= ySize) {
            tempZ = xSize;
            xSize = zSize;
            zSize = tempZ;
        } else {
            tempZ = ySize;
            ySize = zSize;
            zSize = tempZ;
        }
    }
}

void Cuboid::calculateVolume() {
    volume = xSize * ySize * zSize;
}

void Cuboid::setPosition(int x, int y, int z) {
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

int Cuboid::getXSize() const {
    return xSize;
}

void Cuboid::setXSize(int xSize) {
    Cuboid::xSize = xSize;
}

int Cuboid::getYSize() const {
    return ySize;
}

void Cuboid::setYSize(int ySize) {
    Cuboid::ySize = ySize;
}

int Cuboid::getZSize() const {
    return zSize;
}

void Cuboid::setZSize(int zSize) {
    Cuboid::zSize = zSize;
}

int Cuboid::getX() const {
    return x;
}

void Cuboid::setX(int x) {
    Cuboid::x = x;
}

int Cuboid::getY() const {
    return y;
}

void Cuboid::setY(int y) {
    Cuboid::y = y;
}

int Cuboid::getZ() const {
    return z;
}

void Cuboid::setZ(int z) {
    Cuboid::z = z;
}

int Cuboid::getId() const {
    return id;
}

int Cuboid::getVolume() const {
    return volume;
}

void Cuboid::setVolume(int volume) {
    Cuboid::volume = volume;
}
