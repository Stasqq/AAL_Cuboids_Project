//
// Created by Stasiek on 2020-05-20.
//

#include "SearchingAlgorithm.h"

AlgorithmOutput *SearchingAlgorithm::runAlgorithm() {
    auto start = std::chrono::steady_clock::now();

    sortCuboidsByBiggestVolume(space->getCuboidsVector());

    for (int i = 0; i < space->getCuboidsNumber(); i++){
        handleCuboid(space->getCuboidPointer(i));
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start; //in seconds

    AlgorithmOutput *output = new AlgorithmOutput(space, duration.count() * 1000);
    return output;
}

void SearchingAlgorithm::handleCuboid(Cuboid *cuboid) {
  LevelSegmentCords* segmentCords;
  int afterAddingHeight[6];
  int bestHeightValue = space->getHeight() + cuboid->getZSize();
  int bestHeightRotateIndex=0;
  for(int i=0;i<6;i++){
      cuboid->rotate(i);
      segmentCords = space->findPlaceForBruteForce(cuboid->getXSize(),cuboid->getYSize(),cuboid->getZSize());
      if(segmentCords != nullptr){
          afterAddingHeight[i] = segmentCords->getStartLevel() + cuboid->getZSize();
          if(afterAddingHeight[i] < bestHeightValue){
              bestHeightValue = afterAddingHeight[i];
              bestHeightRotateIndex = i;
          }
      }else{
          if(space->getHeight() == 0){
              afterAddingHeight[i] =cuboid->getZSize();
          }else{
              afterAddingHeight[i] = space->getHeight() + cuboid->getZSize();
          }
          if(afterAddingHeight[i] < bestHeightValue) {
              bestHeightValue = afterAddingHeight[i];
              bestHeightRotateIndex = i;
          }
      }
  }

  for(int i=0;i<=bestHeightRotateIndex;i++){
      cuboid->rotate(i);
  }

    segmentCords = space->findPlaceForBruteForce(cuboid->getXSize(),cuboid->getYSize(),cuboid->getZSize());

    if(segmentCords != nullptr){
        space->occupySegmentInN(segmentCords->getStartLevel(),cuboid->getZSize(),segmentCords->getX1(),segmentCords->getY1(),segmentCords->getX2()+1,segmentCords->getY2()+1);
        cuboid->setPosition(segmentCords->getX1(),segmentCords->getY1(),segmentCords->getStartLevel());
    }
    else{
        int i=0;
        while(cuboid->getXSize() > space->getX() || cuboid->getYSize() > space->getY())
          cuboid->rotate(i++);

        cuboid->setPosition(0,0,space->getHeight());
        space->occupySegmentInN(space->getHeight(),cuboid->getZSize(),0,0,cuboid->getXSize(),cuboid->getYSize());
    }
}

void SearchingAlgorithm::sortCuboidsByBiggestVolume(std::vector<Cuboid>* cuboids) {
    for (auto &cuboid : *cuboids) {
        cuboid.calculateVolume();
    }

    auto volume_cmp = [](const Cuboid &a, const Cuboid &b){return a.getVolume() > b.getVolume();};

    std::sort(cuboids->begin(),cuboids->end(),volume_cmp);
}

int SearchingAlgorithm::getAsymptote(){
  return space->getCuboidsNumber()*space->getCuboidsNumber();
}
