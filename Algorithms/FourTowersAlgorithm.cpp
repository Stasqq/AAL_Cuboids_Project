//
// Created by Stasiek on 2020-05-20.
//

#include "FourTowersAlgorithm.h"

FourTowersAlgorithm::FourTowersAlgorithm(Space *space) : CuboidAlgorithm(space),
                                                         leftUp(0, 0), leftDown(0, space -> getY() - 1),
                                                         rightUp(space -> getX() - 1, 0),
                                                         rightDown(space -> getX() - 1, space -> getY() - 1) {}

AlgorithmOutput *FourTowersAlgorithm::runAlgorithm() {

    auto start = std::chrono::steady_clock::now();

    sortedTowers.push_back(leftUp);
    sortedTowers.push_back(rightUp);
    sortedTowers.push_back(leftDown);
    sortedTowers.push_back(rightDown);

    for (int i = 0; i < space -> getCuboidsNumber(); i++)
        handleCuboid(space -> getCuboidPointer(i));

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start; //in seconds

    AlgorithmOutput *output = new AlgorithmOutput(space, duration.count() * 1000);
    return output;
}

void FourTowersAlgorithm::handleCuboid(Cuboid *cuboid) {
    cuboid -> rotateToSmallestHeight();
    std::sort(sortedTowers.begin(), sortedTowers.end());

    for (int i = 0; i < 4; i++) {
        if (addCuboidToTower(&sortedTowers[i], cuboid))
            break;
    }
}

bool FourTowersAlgorithm::addCuboidToTower(CornerTower *cornerTower, Cuboid *cuboid) {
    if (cornerTower -> getHeight() == space -> getHeight()) {
        cuboid -> setZ(space -> getHeight());
        LevelSegmentCords *segmentCords;
        segmentCords = space ->
                       addCornerOccupied(cuboid -> getZSize(), cornerTower -> getX(), cornerTower -> getY(),
                                         cuboid -> getXSize(), cuboid -> getYSize());
        cuboid -> setX(segmentCords -> getX1());
        cuboid -> setY(segmentCords -> getY1());
        cornerTower -> increaseHeight(cuboid -> getZSize());
        return true;
    }

    LevelSegmentCords *segmentCords;
    segmentCords = space ->
                   isCornerSectorOccupiedInN(cornerTower -> getHeight(), cuboid -> getZSize(), cornerTower -> getX(),
                                             cornerTower -> getY(), cuboid -> getXSize(), cuboid -> getYSize());

    if (segmentCords != nullptr) {
        cuboid -> setZ(cornerTower -> getHeight());
        cuboid -> setX(segmentCords -> getX1());
        cuboid -> setY(segmentCords -> getY1());
        space ->
        occupySegmentInN(cornerTower -> getHeight(), cuboid -> getZSize(), cuboid -> getX(), cuboid -> getY(),
                         cuboid -> getXSize() + cuboid -> getX(), cuboid -> getYSize() + cuboid -> getY());
        cornerTower -> increaseHeight(cuboid -> getZSize());
        return true;
    }

    return false;
}

int FourTowersAlgorithm::getAsymptote() {
    return space -> getCuboidsNumber();
}
