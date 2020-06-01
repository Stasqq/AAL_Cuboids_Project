//
// Created by Stasiek on 2020-05-20.
//

#include "Space.h"

Space::Space(std::vector <Cuboid> *startCuboids, int x, int y) {
    this -> cuboids = *startCuboids;
    this -> x = x;
    this -> y = y;
}

Space::Space(const Space &space) {
    x = space.x;
    y = space.y;
    cuboids = space.cuboids;
}

int Space::getHeight() const {
    return levels.size();
}

int Space::getCuboidsNumber() const {
    return cuboids.size();
}

Cuboid *Space::getCuboidPointer(int i) {
    return &cuboids[i];
}

void Space::addLevelOccupied(int x1, int y1, int x2, int y2) {
    Level level(x, y);
    level.setSectorOccupied(x1, y1, x2, y2);
    levels.push_back(level);
}

void Space::occupySegmentInN(int startLevel, int levelNumber, int x1, int y1, int x2, int y2) {
    for (int i = 0; i < levelNumber; i++) {
        if (startLevel + i >= this -> getHeight()) {
            addLevelOccupied(x1, y1, x2, y2);
        } else {
            levels[startLevel + i].setSectorOccupied(x1, y1, x2, y2);
        }
    }
}

LevelSegmentCords *Space::addCornerOccupied(int levelNumber, int x, int y, int occupiedSizeX, int occupiedSizeY) {
    LevelSegmentCords *segmentCords;
    if (x == 0 && y == 0) {
        for (int i = 0; i < levelNumber; i++)
            addLevelOccupied(0, 0, occupiedSizeX, occupiedSizeY);
        segmentCords = new LevelSegmentCords(0, 0, occupiedSizeX, occupiedSizeY);
    } else if (x == 0 && y != 0) {
        for (int i = 0; i < levelNumber; i++)
            addLevelOccupied(0, this -> y - occupiedSizeY, occupiedSizeX, this -> y);
        segmentCords = new LevelSegmentCords(0, this -> y - occupiedSizeY, occupiedSizeX, this -> y);
    } else if (x != 0 && y == 0) {
        for (int i = 0; i < levelNumber; i++)
            addLevelOccupied(this -> x - occupiedSizeX, 0, this -> x, occupiedSizeY);
        segmentCords = new LevelSegmentCords(this -> x - occupiedSizeX, 0, this -> x, occupiedSizeY);
    } else {
        for (int i = 0; i < levelNumber; i++)
            addLevelOccupied(this -> x - occupiedSizeX, this -> y - occupiedSizeY, this -> x, this -> y);
        segmentCords = new LevelSegmentCords(this -> x - occupiedSizeX, this -> y - occupiedSizeY, this -> x,
                                             this -> y);
    }
    return segmentCords;
}

LevelSegmentCords *
Space::isCornerSectorOccupiedInN(int startLevel, int levelNumber, int x, int y, int occupiedSizeX, int occupiedSizeY) {
    LevelSegmentCords *segmentCords = nullptr;
    if (x == 0 && y == 0) {
        for (int i = 0; i < levelNumber; i++) {
            if (startLevel + i == this -> getHeight()) break;
            if (levels[startLevel + i].isPointFree(x, y) &&
                levels[startLevel + i].isPointFree(occupiedSizeX - 1, occupiedSizeY - 1)) {
                if (levels[startLevel + i].isEdgeFree(occupiedSizeX - 1, 0, occupiedSizeX - 1, occupiedSizeY - 1) &&
                    levels[startLevel + i].isEdgeFree(0, occupiedSizeY - 1, occupiedSizeX - 1, occupiedSizeY - 1)) {

                } else
                    return nullptr;
            } else
                return nullptr;
        }
        segmentCords = new LevelSegmentCords(0, 0, occupiedSizeX, occupiedSizeY);
    } else if (x == 0 && y != 0) {
        for (int i = 0; i < levelNumber; i++) {
            if (startLevel + i == this -> getHeight()) break;
            if (levels[startLevel + i].isPointFree(x, y) &&
                levels[startLevel + i].isPointFree(occupiedSizeX - 1, y - occupiedSizeY + 1)) {
                if (levels[startLevel + i].isEdgeFree(0, y - occupiedSizeY + 1, occupiedSizeX - 1,
                                                      y - occupiedSizeY + 1) &&
                    levels[startLevel + i].isEdgeFree(occupiedSizeX - 1, y - occupiedSizeY + 1, occupiedSizeX - 1, y)) {

                } else
                    return nullptr;
            } else
                return nullptr;
        }
        segmentCords = new LevelSegmentCords(0, y - occupiedSizeY + 1, occupiedSizeX, this -> y);
    } else if (x != 0 && y == 0) {
        for (int i = 0; i < levelNumber; i++) {
            if (startLevel + i == this -> getHeight()) break;
            if (levels[startLevel + i].isPointFree(x, y) &&
                levels[startLevel + i].isPointFree(x - occupiedSizeX + 1, occupiedSizeY - 1)) {
                if (levels[startLevel + i].isEdgeFree(x - occupiedSizeX + 1, 0, x - occupiedSizeX + 1,
                                                      occupiedSizeY - 1) &&
                    levels[startLevel + i].isEdgeFree(x - occupiedSizeX + 1, occupiedSizeY - 1, x, occupiedSizeY - 1)) {

                } else
                    return nullptr;
            } else
                return nullptr;
        }
        segmentCords = new LevelSegmentCords(x - occupiedSizeX + 1, 0, this -> x, occupiedSizeY);
    } else {
        for (int i = 0; i < levelNumber; i++) {
            if (startLevel + i == this -> getHeight()) break;
            if (levels[startLevel + i].isPointFree(x, y) &&
                levels[startLevel + i].isPointFree(x - occupiedSizeX + 1, y - occupiedSizeY + 1)) {
                if (levels[startLevel + i].isEdgeFree(x - occupiedSizeX + 1, y - occupiedSizeY + 1,
                                                      x - occupiedSizeX + 1, y) &&
                    levels[startLevel + i].isEdgeFree(x - occupiedSizeX + 1, y - occupiedSizeY + 1, x,
                                                      y - occupiedSizeY + 1)) {

                } else
                    return nullptr;
            } else
                return nullptr;
        }
        segmentCords = new LevelSegmentCords(x - occupiedSizeX + 1, y - occupiedSizeY + 1, this -> x, this -> y);
    }
    return segmentCords;
}

LevelSegmentCords *Space::findPlaceForBruteForce(int x, int y, int z) {
    LevelSegmentCords *segmentCords = nullptr;
    int i;
    for (i = 0; i < this -> getHeight(); i++) {
        int lastX = 0, lastY = 0;
        int checkerX = 0, checkerY = 0;
        do {
            segmentCords = levels[i].findFreeSector(x, y, lastX, lastY);
            if (segmentCords != nullptr) {
                segmentCords -> setStartLevel(i);
                for (int j = 0; i + j < this -> getHeight() && j <= z; j++) {
                    if (!levels[i + j].isSectorFree(segmentCords -> getX1(), segmentCords -> getY1(),
                                                    segmentCords -> getX2() + 1, segmentCords -> getY2() + 1)) {
                        checkerX = segmentCords -> getX1();
                        checkerY = segmentCords -> getY1() + 1;
                    }
                }
                if (checkerX != lastX || checkerY != lastY) {
                    if (checkerY + 1 < this -> y) {
                        lastX = checkerX;
                        lastY = checkerY;
                    } else {
                        break;
                    }
                } else {
                    return segmentCords;
                }
            } else {
                break;
            }
        } while (true);
    }
    return nullptr;
}

void Space::printSpace() {
    for (int i = 0; i < getHeight(); i++) {
        std::cout << "Level: " << i << "\n";
        levels[i].printLevel();
    }
}

int Space::getX() const {
    return x;
}

int Space::getY() const {
    return y;
}

std::vector <Cuboid> *Space::getCuboidsVector() {
    return &cuboids;
}
