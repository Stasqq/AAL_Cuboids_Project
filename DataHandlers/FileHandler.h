//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_FILEHANDLER_H
#define CUBOIDS_AAL_FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Cuboid.h"
#include "../Algorithms/Space.h"
#include "AlgorithmOutput.h"

class FileHandler {
public:
    Space *readInputFile(std::string fileName);

    void saveAlgorithmOutput(std::string fileName, AlgorithmOutput *algorithmOutput);
};


#endif //CUBOIDS_AAL_FILEHANDLER_H
