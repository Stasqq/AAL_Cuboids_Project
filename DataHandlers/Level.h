//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_LEVEL_H
#define CUBOIDS_AAL_LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "LevelSegmentCords.h"

class Level {
private:
    bool **cells;
    int x, y;
public:
    Level(int x, int y);

    bool setSectorOccupied(int x1, int y1, int x2, int y2);

    LevelSegmentCords *findFreeSector(int x, int y, int startX, int startY);

    int findHoleInRow(int holeLength, int rowNumber, int startPlace);

    bool checkHoleSector(int x, int y, int holeStart, int rowNumber);

    bool isPointFree(int x, int y);

    bool isEdgeFree(int x1, int y1, int x2, int y2);

    bool isSectorFree(int x1, int y1, int x2, int y2);

    void printLevel();

};

#endif //CUBOIDS_AAL_LEVEL_H
