//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_PRESENTRESULT_H
#define CUBOIDS_AAL_PRESENTRESULT_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

#include "../Algorithms/SearchingAlgorithm.h"
#include "../Algorithms/BruteForceAlgorithm.h"
#include "../Algorithms/SingleTowerAlgorithm.h"
#include "../Algorithms/FourTowersAlgorithm.h"
#include "../Generator/Generator.h"

#define BRUTE_FORCE_ALGORITHM  1
#define SINGLE_TOWER_ALGORITHM 2
#define FOUR_TOWERS_ALGORITHM  3
#define SEARCHING_ALGORITHM    4

class PresentResult {

private:
    int stepsNumber;
    int increasingProblemSize;
    int incrementator;
    int problemsSolvedInStep;
    int algorithmSwitch;
    double generatorRatio;
    std::vector<int> steps;
    std::vector<double> averages;
    std::set<double> asymptotes;

public:
    PresentResult(int algorithmSwitch, int increasingProblemSize, int incrementator, int stepsNumber, int problemsSolvedInStep, double generatorRatio);

    void startMeasurement(int x);

    void presentResult();

    void print();
};

#endif //CUBOIDS_AAL_PRESENTRESULT_H
