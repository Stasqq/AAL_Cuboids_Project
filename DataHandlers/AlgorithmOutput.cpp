//
// Created by Stasiek on 2020-05-20.
//

#include "AlgorithmOutput.h"

AlgorithmOutput::AlgorithmOutput(Space *outputSpace, double time) {
    this->outputSpace = outputSpace;
    this->elapsedTimeInMs = time;
}

double AlgorithmOutput::getElapsedTimeInMs() const {
    return elapsedTimeInMs;
}

void AlgorithmOutput::setElapsedTimeInMs(double elapsedTimeInMs) {
    AlgorithmOutput::elapsedTimeInMs = elapsedTimeInMs;
}

Space *AlgorithmOutput::getOutputSpace() {
    return outputSpace;
}

void AlgorithmOutput::setOutputSpace(Space *outputSpace) {
    AlgorithmOutput::outputSpace = outputSpace;
}
