//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_SEARCHINGALGORITHM_H
#define CUBOIDS_AAL_SEARCHINGALGORITHM_H

#include <algorithm>

#include "CuboidAlgorithm.h"

class SearchingAlgorithm : public CuboidAlgorithm {
public:
    SearchingAlgorithm(Space *space) : CuboidAlgorithm(space) {}

    AlgorithmOutput *runAlgorithm() override;

    void handleCuboid(Cuboid *cuboid) override;

    void sortCuboidsByBiggestVolume(std::vector <Cuboid> *cuboids);

    int getAsymptote();
};

#endif //CUBOIDS_AAL_SEARCHINGALGORITHM_H
