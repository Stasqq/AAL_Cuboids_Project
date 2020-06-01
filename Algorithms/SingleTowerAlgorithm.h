//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_SINGLETOWERALGORITHM_H
#define CUBOIDS_AAL_SINGLETOWERALGORITHM_H

#include "CuboidAlgorithm.h"

class SingleTowerAlgorithm : public CuboidAlgorithm {
public:
    SingleTowerAlgorithm(Space *space) : CuboidAlgorithm(space) {}

    AlgorithmOutput *runAlgorithm() override;

    void handleCuboid(Cuboid *cuboid) override;

    int getAsymptote();
};

#endif //CUBOIDS_AAL_SINGLETOWERALGORITHM_H
