//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_SPACE_H
#define CUBOIDS_AAL_SPACE_H

#include <vector>
#include <iostream>
#include "../DataHandlers/Cuboid.h"
#include "../DataHandlers/Level.h"

class Space {
private:
    int x, y;
    std::vector<Cuboid> cuboids;
    std::vector<Level> levels;
public:
    Space(std::vector<Cuboid> *startCuboids, int x, int y);

    Space(const Space &spaceTarget);

    int getHeight() const;

    int getCuboidsNumber() const;

    Cuboid *getCuboidPointer(int i);

    void occupySegmentInN(int startLevel, int levelNumber, int x1, int y1, int x2, int y2);

    void addLevelOccupied(int x1, int y1, int x2, int y2);

    LevelSegmentCords* addCornerOccupied(int levelNumber, int x, int y, int occupiedSizeX, int occupiedSizeY);

    LevelSegmentCords* isCornerSectorOccupiedInN(int startLevel, int levelNumber, int x, int y, int occupiedSizeX, int occupiedSizeY);

    LevelSegmentCords* findPlaceForBruteForce(int x, int y, int z);

    void printSpace();

    int getX() const;

    int getY() const;

    std::vector<Cuboid>* getCuboidsVector();
};


#endif //CUBOIDS_AAL_SPACE_H
