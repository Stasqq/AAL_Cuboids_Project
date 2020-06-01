//
// Created by Stasiek on 2020-05-27.
//

#ifndef CUBOIDS_AAL_CORNERTOWER_H
#define CUBOIDS_AAL_CORNERTOWER_H

#include <vector>

class CornerTower {
private:
    int height;
    int x, y;
public:
    CornerTower(int x, int y);

    bool operator<(const CornerTower &other) const {
        return height < other.getHeight();
    }

    int getHeight() const;

    void increaseHeight(int x);

    int getX() const;

    int getY() const;
};

#endif //CUBOIDS_AAL_CORNERTOWER_H
