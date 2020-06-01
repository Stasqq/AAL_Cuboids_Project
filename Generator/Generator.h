//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_GENERATOR_H
#define CUBOIDS_AAL_GENERATOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "../Algorithms/Space.h"

class Generator {
private:
    int cuboidsNumber;
    double averageRatioSpaceToCuboid;
public:
    Generator(int cuboidsNumber, double averageRatioSpaceToCuboid);

    Cuboid *genetareCuboid(int x, int y, int id);

    Space *generateSpace();

    Space *generateSpace(int x, int y);

};

#endif //CUBOIDS_AAL_GENERATOR_H
