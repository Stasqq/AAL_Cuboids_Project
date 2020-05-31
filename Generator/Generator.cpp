//
// Created by Stasiek on 2020-05-20.
//

#include "Generator.h"

Generator::Generator(int cuboidsNumber, double averageRatioSpaceToCuboid){
  this->cuboidsNumber = cuboidsNumber;
  this->averageRatioSpaceToCuboid = averageRatioSpaceToCuboid;
}

Cuboid* Generator::genetareCuboid(int x, int y, int id){
  int xSize,ySize,zSize;
  double rangeStart = (1.0 - averageRatioSpaceToCuboid)/2;
  double rangeEnd = (1.0 + averageRatioSpaceToCuboid)/2;
  do{
    xSize = (std::rand()%100);
  }while(rangeEnd * x< xSize || xSize < rangeStart * x);
  do{
    ySize = (std::rand()%100);
  }while(rangeEnd * y< ySize || ySize < rangeStart * y);
  int smaller = (xSize<=ySize) ? xSize : ySize;
  zSize = ((std::rand()%80)/(double)100+0.1) * smaller;
  return new Cuboid(xSize,ySize,zSize,id);
}

Space* Generator::generateSpace(){
  std::vector<Cuboid> cuboids;

  int x = (std::rand()%81) + 20;
  int y = x * (((std::rand()%6) + 7)/(double)10 );

  for(int i=0;i<cuboidsNumber;i++){
    Cuboid* cuboid = genetareCuboid(x,y,i);
    cuboids.push_back(*cuboid);
  }
  return new Space(&cuboids,x,y);
}

Space* Generator::generateSpace(int x, int y){
  std::vector<Cuboid> cuboids;

  for(int i=0;i<cuboidsNumber;i++){
    Cuboid* cuboid = genetareCuboid(x,y,i);
    cuboids.push_back(*cuboid);
  }
  return new Space(&cuboids,x,y);
}
