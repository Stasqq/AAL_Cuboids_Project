//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_CUBOIDALGORITHM_H
#define CUBOIDS_AAL_CUBOIDALGORITHM_H

#include <vector>
#include <chrono>
#include "../DataHandlers/Cuboid.h"
#include "../DataHandlers/AlgorithmOutput.h"
#include "Space.h"

class CuboidAlgorithm {
protected:
    Space *space;
public:
    CuboidAlgorithm(Space *space);

    virtual AlgorithmOutput *runAlgorithm() = 0;

    virtual void handleCuboid(Cuboid *cuboid) = 0;

};


#endif //CUBOIDS_AAL_CUBOIDALGORITHM_H
