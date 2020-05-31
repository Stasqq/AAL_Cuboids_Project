#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "DataHandlers/Cuboid.h"
#include "Algorithms/CuboidAlgorithm.h"
#include "Algorithms/SingleTowerAlgorithm.h"
#include "Algorithms/FourTowersAlgorithm.h"
#include "Algorithms/SearchingAlgorithm.h"
#include "Algorithms/BruteForceAlgorithm.h"
#include "DataHandlers/FileHandler.h"
#include "DataHandlers/AlgorithmOutput.h"
#include "Generator/Generator.h"
#include "ResultPresenter/PresentResult.h"

using namespace std;

#define BRUTE_FORCE_ALGORITHM  1
#define SINGLE_TOWER_ALGORITHM 2
#define FOUR_TOWERS_ALGORITHM  3
#define SEARCHING_ALGORITHM    4

#define GENERATOR              1
#define INPUT_FILE             2
#define PRESENT                3

int algorithmSwitch, inputModeSwitch;

void determineRunMode(string algorithm, string inputMode){
  if(algorithm == "bf"){
    algorithmSwitch = BRUTE_FORCE_ALGORITHM;
  }else if(algorithm == "st"){
    algorithmSwitch = SINGLE_TOWER_ALGORITHM;
  }else if(algorithm == "ft"){
    algorithmSwitch = FOUR_TOWERS_ALGORITHM;
  }else if(algorithm == "sa"){
    algorithmSwitch = SEARCHING_ALGORITHM;
  }else{
    cout<<"Wrong algorithm type!\nPossible:\nbf - brute force\nst - single tower\nft - four towers\nsa - searching algorithm\n";
    exit(1);
  }

  if(inputMode == "f"){
    inputModeSwitch = INPUT_FILE;
  }else if(inputMode == "g"){
    inputModeSwitch = GENERATOR;
  }else if (inputMode == "p"){
    inputModeSwitch = PRESENT;
  }else{
    cout<<"Wrong input type!\nPossible:\ng - generator as input\nf - file as input\n";
    exit(1);
  }
}

int main(int argc, char **argv) {

    srand (time(NULL));

    if(argc >= 3){
      string algorithm(argv[1]), inputMode(argv[2]);
      determineRunMode(algorithm,inputMode);
    }else{
      cout<<"Wrong arguments number!\n";
      return 1;
    }

    Space *inputSpace;
    AlgorithmOutput* algorithmOutput;

    switch(inputModeSwitch){
      case PRESENT:{
        if(argc == 9){
          PresentResult *presentResult = new PresentResult(algorithmSwitch,atoi(argv[5]),atoi(argv[6]),atoi(argv[7]),atoi(argv[8]),atof(argv[3]));
          presentResult->startMeasurement(atoi(argv[4]));
          presentResult->presentResult();
          return 0;
        }else{
          cout<<"Wrong arguments number!\n";
          return 1;
        }
      }break;
      case GENERATOR:{
        if(argc == 6){
          int cuboidsNumber = atoi(argv[3]);
          double averageRatioSpaceToCuboid = atof(argv[4]);
          Generator generator(cuboidsNumber,averageRatioSpaceToCuboid);
          inputSpace = generator.generateSpace();
        }else if(argc == 7){
          int cuboidsNumber = atoi(argv[3]);
          double averageRatioSpaceToCuboid = atof(argv[4]);
          Generator generator(cuboidsNumber,averageRatioSpaceToCuboid);
          inputSpace = generator.generateSpace(atoi(argv[5]),atoi(argv[5]));
        }else{
          cout<<"Wrong arguments number!\n";
          return 1;
        }
      }break;
      case INPUT_FILE:{
        if(argc == 5){
          string inputFileName(argv[3]);
          FileHandler fileHandler;
          inputSpace = fileHandler.readInputFile(inputFileName);
        }else{
          cout<<"Wrong arguments number!\n";
          return 1;
        }
      }break;
    }

    switch(algorithmSwitch){
      case BRUTE_FORCE_ALGORITHM:{
        BruteForceAlgorithm bruteForceAlgorithm(inputSpace);
        algorithmOutput = bruteForceAlgorithm.runAlgorithm();
      }break;
      case SINGLE_TOWER_ALGORITHM:{
        SingleTowerAlgorithm singleTowerAlgorithm(inputSpace);
        algorithmOutput = singleTowerAlgorithm.runAlgorithm();
      }break;
      case FOUR_TOWERS_ALGORITHM:{
        FourTowersAlgorithm fourTowersAlgorithm(inputSpace);
        algorithmOutput = fourTowersAlgorithm.runAlgorithm();
      }break;
      case SEARCHING_ALGORITHM:{
        SearchingAlgorithm searchingAlgorithm(inputSpace);
        algorithmOutput = searchingAlgorithm.runAlgorithm();
      }break;
    }

    switch(inputModeSwitch){
      case GENERATOR:{
        string outputFileName;
        if(argc == 6){
          outputFileName = argv[5];
        }else{
          outputFileName = argv[6];
        }

        FileHandler fileHandler;
        fileHandler.saveAlgorithmOutput(outputFileName, algorithmOutput);
      }break;
      case INPUT_FILE:{
        string outputFileName(argv[4]);
        FileHandler fileHandler;
        fileHandler.saveAlgorithmOutput(outputFileName, algorithmOutput);
      }break;
    }

    return 0;
}
