//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_FOURTOWERSALGORITHM_H
#define CUBOIDS_AAL_FOURTOWERSALGORITHM_H

#include <algorithm>
#include "CuboidAlgorithm.h"
#include "../DataHandlers/CornerTower.h"

class FourTowersAlgorithm : public CuboidAlgorithm {
private:
    CornerTower leftDown, leftUp, rightDown, rightUp;
    std::vector<CornerTower> sortedTowers;
public:
    FourTowersAlgorithm(Space *space);

    AlgorithmOutput *runAlgorithm() override;

    void handleCuboid(Cuboid *cuboid) override;

    bool addCuboidToTower(CornerTower* cornerTower ,Cuboid* cuboid);

    int getAsymptote();
};


#endif //CUBOIDS_AAL_FOURTOWERSALGORITHM_H
