//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_ALGORITHMOUTPUT_H
#define CUBOIDS_AAL_ALGORITHMOUTPUT_H

#include "Cuboid.h"
#include "../Algorithms/Space.h"

class AlgorithmOutput {
private:
    double elapsedTimeInMs;
    Space *outputSpace;

public:
    AlgorithmOutput(Space *outputSpace, double time);

    double getElapsedTimeInMs() const;

    void setElapsedTimeInMs(double elapsedTimeInMs);

    Space *getOutputSpace();

    void setOutputSpace(Space *outputSpace);
};

#endif //CUBOIDS_AAL_ALGORITHMOUTPUT_H
