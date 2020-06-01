//
// Created by Stasiek on 2020-05-20.
//

#include "BruteForceAlgorithm.h"

AlgorithmOutput *BruteForceAlgorithm::runAlgorithm() {
    auto start = std::chrono::steady_clock::now();

    bestPermutationValue = 10000000;

    std::vector <Cuboid> cuboidVector = *space -> getCuboidsVector();
    int iterator = 0;

    do {
        calculatePermutation(&cuboidVector, iterator);
        iterator++;
    } while (std::next_permutation(cuboidVector.begin(), cuboidVector.end()));

    for (int i = 0; i <= bestPermutationId; i++)
        std::next_permutation(space -> getCuboidsVector() -> begin(), space -> getCuboidsVector() -> end());

    for (int i = 0; i < space -> getCuboidsNumber(); i++) {
        handleCuboidTempSpace(space, space -> getCuboidPointer(i));
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start; //in seconds

    AlgorithmOutput *output = new AlgorithmOutput(space, duration.count() * 1000);
    return output;
}

void BruteForceAlgorithm::handleCuboid(Cuboid *cuboid) {}

void BruteForceAlgorithm::handleCuboidTempSpace(Space *tempSpace, Cuboid *cuboid) {
    LevelSegmentCords *segmentCords;
    int afterAddingHeight[6];
    int bestHeightValue = space -> getHeight() + cuboid -> getZSize();
    int bestHeightRotateIndex = 0;
    for (int i = 0; i < 6; i++) {
        cuboid -> rotate(i);
        segmentCords =
                space -> findPlaceForBruteForce(cuboid -> getXSize(), cuboid -> getYSize(), cuboid -> getZSize());
        if (segmentCords != nullptr) {
            afterAddingHeight[i] = segmentCords -> getStartLevel() + cuboid -> getZSize();
            if (afterAddingHeight[i] < bestHeightValue) {
                bestHeightValue = afterAddingHeight[i];
                bestHeightRotateIndex = i;
            }
        } else {
            if (space -> getHeight() == 0) {
                afterAddingHeight[i] = cuboid -> getZSize();
            } else {
                afterAddingHeight[i] = space -> getHeight() + cuboid -> getZSize();
            }
            if (afterAddingHeight[i] < bestHeightValue) {
                bestHeightValue = afterAddingHeight[i];
                bestHeightRotateIndex = i;
            }
        }
    }

    for (int i = 0; i <= bestHeightRotateIndex; i++) {
        cuboid -> rotate(i);
    }

    segmentCords =
            tempSpace -> findPlaceForBruteForce(cuboid -> getXSize(), cuboid -> getYSize(), cuboid -> getZSize());

    if (segmentCords != nullptr) {
        tempSpace ->
        occupySegmentInN(segmentCords -> getStartLevel(), cuboid -> getZSize(), segmentCords -> getX1(),
                         segmentCords -> getY1(), segmentCords -> getX2() + 1, segmentCords -> getY2() + 1);
        cuboid -> setPosition(segmentCords -> getX1(), segmentCords -> getY1(), segmentCords -> getStartLevel());
    } else {
        cuboid -> setPosition(0, 0, tempSpace -> getHeight());
        tempSpace -> occupySegmentInN(tempSpace -> getHeight(), cuboid -> getZSize(), 0, 0, cuboid -> getXSize(),
                                       cuboid -> getYSize());
    }
}

void BruteForceAlgorithm::calculatePermutation(std::vector <Cuboid> *cuboidVector, int iterator) {
    Space tempSpace(cuboidVector, this -> space -> getX(), this -> space -> getY());

    for (int i = 0; i < tempSpace.getCuboidsNumber(); i++) {
        handleCuboidTempSpace(&tempSpace, tempSpace.getCuboidPointer(i));
    }

    if (tempSpace.getHeight() < bestPermutationValue) {
        bestPermutationValue = tempSpace.getHeight();
        bestPermutationId = iterator;
    }
}

int BruteForceAlgorithm::getAsymptote() {
    return space -> getCuboidsNumber() * factorial(space -> getCuboidsNumber());
}

int BruteForceAlgorithm::factorial(int n) {
    long int a = 1;
    while (n)
        a *= n--;
    return a;
}
