//
// Created by Stasiek on 2020-05-20.
//

#include "Level.h"

Level::Level(int x, int y) {
    this->x = x;
    this->y = y;
    cells = (bool **) malloc(x * sizeof(bool *));
    for (int i = 0; i < x; i++)
        cells[i] = (bool *) malloc(y * sizeof(bool));

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cells[i][j] = false;
}

bool Level::setSectorOccupied(int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2 && x2 <= x && y2 <= y) {
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                cells[i][j] = true;
        return true;
    }
    return false;
}

LevelSegmentCords *Level::findFreeSector(int x, int y, int startX, int startY) {
    if (x > this->x || y > this->y) return nullptr;
    for (int i = startX; i < this->x; i++) {
        int holeStart;
        if (i == startX)
            holeStart = findHoleInRow(x, i, startY);
        else
            holeStart = findHoleInRow(x, i, 0);
        if (holeStart != -1) {
            if (checkHoleSector(x, y, holeStart, i)) {
                return new LevelSegmentCords(i, holeStart, i + x - 1, holeStart + y - 1);
            }
        }
    }
    return nullptr;
}

int Level::findHoleInRow(int holeLength, int rowNumber, int startPlace) {
    for (int i = startPlace; i < y; i++) {
        if (i + holeLength - 1 < x) {
            for (int j = 0; j < holeLength; j++) {
                if (cells[rowNumber][i + j])
                    break;
                if (j == holeLength - 1)
                    return i;
            }
        } else
            break;
    }
    return -1;
}

bool Level::checkHoleSector(int x, int y, int holeStart, int rowNumber) {
    for (int i = 0; i < x; i++) {
        if (i + rowNumber < this->x) {
            for (int j = 0; j < y; j++)
                if (cells[i + rowNumber][j + holeStart])
                    return false;

        } else
            return false;
    }
    return true;
}

bool Level::isPointFree(int x, int y) {
    return !cells[x][y];
}

bool Level::isEdgeFree(int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2 && x2 <= x && y2 <= y) {
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                if (cells[i][j])
                    return false;
        return true;
    }
    return false;
}

bool Level::isSectorFree(int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2 && x2 <= x && y2 <= y) {
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                if (cells[i][j])
                    return false;
        return true;
    }
    return false;
}

void Level::printLevel() {
    for (int i = 0; i < x; i++) {
        std::cout << "| ";
        for (int j = 0; j < y; j++) {
            if (cells[i][j])
                std::cout << "X ";
            else
                std::cout << "  ";

        }
        std::cout << "|\n";
    }
}
