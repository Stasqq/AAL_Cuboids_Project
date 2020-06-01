//
// Created by Stasiek on 2020-05-20.
//

#include "FileHandler.h"

Space *FileHandler::readInputFile(std::string fileName) {
    int xSpace = 0, ySpace = 0;
    std::vector <Cuboid> cuboids;
    std::fstream inputFile;
    inputFile.open(fileName, std::ios::in);
    int idNumber = 0;
    if (inputFile.is_open()) {
        inputFile >> xSpace >> ySpace;
        while (!inputFile.eof()) {
            int x, y, z;
            inputFile >> x >> y >> z;
            Cuboid temp(x, y, z, idNumber);
            cuboids.push_back(temp);
            idNumber++;
        }
        inputFile.close();
    }
    Space *outputSpace = new Space(&cuboids, xSpace, ySpace);
    return outputSpace;
}

void FileHandler::saveAlgorithmOutput(std::string filename, AlgorithmOutput *algorithmOutput) {
    std::fstream outputFile;
    outputFile.open(filename, std::fstream::out | std::ios::trunc);
    Space *outputSpace = algorithmOutput->getOutputSpace();
    if (outputFile.is_open()) {
        outputFile << algorithmOutput->getElapsedTimeInMs() << std::endl;
        outputFile << outputSpace->getX() << " " << outputSpace->getY() << " " << outputSpace->getHeight() << std::endl;
        for (int i = 0; i < outputSpace->getCuboidsNumber(); i++) {
            const Cuboid *cuboid = outputSpace->getCuboidPointer(i);
            outputFile << cuboid->getXSize() << " " << cuboid->getYSize() << " " << cuboid->getZSize()
                       << " " << cuboid->getX() << " " << cuboid->getY() << " " << cuboid->getZ() << std::endl;
        }
    }
    outputFile.close();
}
