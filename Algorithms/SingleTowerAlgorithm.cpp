//
// Created by Stasiek on 2020-05-20.
//

#include "SingleTowerAlgorithm.h"

AlgorithmOutput *SingleTowerAlgorithm::runAlgorithm() {

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < space->getCuboidsNumber(); i++)
        handleCuboid(space->getCuboidPointer(i));

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start; //in seconds

    AlgorithmOutput *output = new AlgorithmOutput(space, duration.count() * 1000);
    return output;
}

void SingleTowerAlgorithm::handleCuboid(Cuboid *cuboid) {
    cuboid->rotateToSmallestHeight();
    int actualSpaceHeight = space->getHeight();
    for (int i = actualSpaceHeight; i < actualSpaceHeight + cuboid->getZSize(); i++) {
        space->addLevelOccupied(0, 0, cuboid->getXSize(), cuboid->getYSize());
        cuboid->setPosition(0, 0, actualSpaceHeight);
    }
}

int SingleTowerAlgorithm::getAsymptote(){
  return space->getCuboidsNumber();
}
