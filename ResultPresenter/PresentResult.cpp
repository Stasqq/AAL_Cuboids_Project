//
// Created by Stasiek on 2020-05-20.
//

#include "PresentResult.h"


PresentResult::PresentResult(int algorithmSwitch, int increasingProblemSize, int incrementator, int stepsNumber,
                             int problemsSolvedInStep, double generatorRatio) {

    this -> algorithmSwitch = algorithmSwitch;
    this -> stepsNumber = stepsNumber;
    this -> increasingProblemSize = increasingProblemSize;
    this -> incrementator = incrementator;
    this -> problemsSolvedInStep = problemsSolvedInStep;
    this -> generatorRatio = generatorRatio;
}

void PresentResult::startMeasurement(int x) {
    BruteForceAlgorithm *bruteForceAlgorithm;
    SingleTowerAlgorithm *singleTowerAlgorithm;
    FourTowersAlgorithm *fourTowersAlgorithm;
    SearchingAlgorithm *searchingAlgorithm;
    AlgorithmOutput *algorithmOutput;

    Generator *generator;

    int actualProblemSize = increasingProblemSize;
    int basicStepSize = incrementator;

    double averageTime;

    for (int i = 0; i < stepsNumber; i++) {
        std::cout << "Step number: " << i << std::endl;
        averageTime = 0;
        for (int j = 0; j < problemsSolvedInStep; j++) {
            generator = new Generator(actualProblemSize, generatorRatio);
            Space *space = generator -> generateSpace(x, x);
            std::cout << "\t" << j << "/" << problemsSolvedInStep << std::endl;
            switch (algorithmSwitch) {
                case BRUTE_FORCE_ALGORITHM: {
                    bruteForceAlgorithm = new BruteForceAlgorithm(space);
                    algorithmOutput = bruteForceAlgorithm -> runAlgorithm();
                    asymptotes.insert(bruteForceAlgorithm -> getAsymptote());
                }
                    break;
                case SINGLE_TOWER_ALGORITHM: {
                    singleTowerAlgorithm = new SingleTowerAlgorithm(space);
                    algorithmOutput = singleTowerAlgorithm -> runAlgorithm();
                    asymptotes.insert(singleTowerAlgorithm -> getAsymptote());
                }
                    break;
                case FOUR_TOWERS_ALGORITHM: {
                    fourTowersAlgorithm = new FourTowersAlgorithm(space);
                    algorithmOutput = fourTowersAlgorithm -> runAlgorithm();
                    asymptotes.insert(fourTowersAlgorithm -> getAsymptote());
                }
                    break;
                case SEARCHING_ALGORITHM: {
                    searchingAlgorithm = new SearchingAlgorithm(space);
                    algorithmOutput = searchingAlgorithm -> runAlgorithm();
                    asymptotes.insert(searchingAlgorithm -> getAsymptote());
                }
                    break;
            }
            averageTime += algorithmOutput -> getElapsedTimeInMs();
        }
        if (stepsNumber % 2 == 0 && i == stepsNumber / 2 - 1 && incrementator % 2 == 0) {
            incrementator /= 2;
        }
        if (stepsNumber % 2 == 0 && i == stepsNumber / 2 + 1 && incrementator % 2 == 0) {
            incrementator = basicStepSize;
            stepsNumber++;
        }
        averages.push_back(averageTime / problemsSolvedInStep);
        steps.push_back(actualProblemSize);
        actualProblemSize += incrementator;
    }
}

void PresentResult::presentResult() {
    int medianaIndex = averages.size() / 2;
    auto medianaAsymptoteIt = asymptotes.begin();
    std::advance(medianaAsymptoteIt, medianaIndex);
    auto asymptotesIt = asymptotes.begin();

    std::cout << "n           t(n)[ms]         q(n)" << '\n';
    for (int i = 0; i < (int) averages.size(); i++, asymptotesIt++) {
        double qn = (averages[i] * (*medianaAsymptoteIt)) / (*asymptotesIt * averages[medianaIndex]);
        std::cout << std::fixed << steps[i] << "        " << averages[i] << "       " << qn << '\n';
    }
}
