//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_BRUTEFORCEALGORITHM_H
#define CUBOIDS_AAL_BRUTEFORCEALGORITHM_H

#include <algorithm>
#include "CuboidAlgorithm.h"

class BruteForceAlgorithm : public CuboidAlgorithm {
private:
    int bestPermutationId, bestPermutationValue;
public:
    BruteForceAlgorithm(Space *space) : CuboidAlgorithm(space) {}

    AlgorithmOutput *runAlgorithm() override;

    void handleCuboid(Cuboid* cuboid) override;

    void handleCuboidTempSpace(Space * tempSpace,Cuboid *cuboid);

    void calculatePermutation(std::vector<Cuboid>* cuboidVector, int iterator);

    int getAsymptote();

    int factorial(int i);
};


#endif //CUBOIDS_AAL_BRUTEFORCEALGORITHM_H
