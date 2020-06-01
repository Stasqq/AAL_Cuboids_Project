ODIR = obj/
OBJS	= $(ODIR)main.o $(ODIR)AlgorithmOutput.o $(ODIR)BruteForceAlgorithm.o $(ODIR)CornerTower.o $(ODIR)Cuboid.o $(ODIR)CuboidAlgorithm.o $(ODIR)FileHandler.o $(ODIR)FourTowersAlgorithm.o $(ODIR)Level.o $(ODIR)LevelSegmentCords.o $(ODIR)SearchingAlgorithm.o $(ODIR)SingleTowerAlgorithm.o $(ODIR)Generator.o $(ODIR)Space.o $(ODIR)PresentResult.o
OUT	= cuboids_AAL
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =



ALG = Algorithms/
DATA = DataHandlers/
GEN = Generator/
RES = ResultPresenter/


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(ODIR)main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14 -o $(ODIR)main.o

$(ODIR)AlgorithmOutput.o: $(DATA)AlgorithmOutput.cpp
	$(CC) $(FLAGS) $(DATA)AlgorithmOutput.cpp -std=c++14 -o $(ODIR)AlgorithmOutput.o

$(ODIR)BruteForceAlgorithm.o: $(ALG)BruteForceAlgorithm.cpp
	$(CC) $(FLAGS) $(ALG)BruteForceAlgorithm.cpp -std=c++14 -o $(ODIR)BruteForceAlgorithm.o

$(ODIR)CornerTower.o: $(DATA)CornerTower.cpp
	$(CC) $(FLAGS) $(DATA)CornerTower.cpp -std=c++14 -o $(ODIR)CornerTower.o

$(ODIR)Cuboid.o: $(DATA)Cuboid.cpp
	$(CC) $(FLAGS) $(DATA)Cuboid.cpp -std=c++14 -o $(ODIR)Cuboid.o

$(ODIR)CuboidAlgorithm.o: $(ALG)CuboidAlgorithm.cpp
	$(CC) $(FLAGS) $(ALG)CuboidAlgorithm.cpp -std=c++14 -o $(ODIR)CuboidAlgorithm.o

$(ODIR)FileHandler.o: $(DATA)FileHandler.cpp
	$(CC) $(FLAGS) $(DATA)FileHandler.cpp -std=c++14 -o $(ODIR)FileHandler.o

$(ODIR)FourTowersAlgorithm.o: $(ALG)FourTowersAlgorithm.cpp
	$(CC) $(FLAGS) $(ALG)FourTowersAlgorithm.cpp -std=c++14 -o $(ODIR)FourTowersAlgorithm.o

$(ODIR)Level.o: $(DATA)Level.cpp
	$(CC) $(FLAGS) $(DATA)Level.cpp -std=c++14 -o $(ODIR)Level.o

$(ODIR)LevelSegmentCords.o: $(DATA)LevelSegmentCords.cpp
	$(CC) $(FLAGS) $(DATA)LevelSegmentCords.cpp -std=c++14 -o $(ODIR)LevelSegmentCords.o

$(ODIR)SearchingAlgorithm.o: $(ALG)SearchingAlgorithm.cpp
	$(CC) $(FLAGS) $(ALG)SearchingAlgorithm.cpp -std=c++14 -o $(ODIR)SearchingAlgorithm.o

$(ODIR)SingleTowerAlgorithm.o: $(ALG)SingleTowerAlgorithm.cpp
	$(CC) $(FLAGS) $(ALG)SingleTowerAlgorithm.cpp -std=c++14 -o $(ODIR)SingleTowerAlgorithm.o

$(ODIR)Generator.o: $(GEN)Generator.cpp
	$(CC) $(FLAGS) $(GEN)Generator.cpp -std=c++14 -o $(ODIR)Generator.o

$(ODIR)Space.o: $(ALG)Space.cpp
	$(CC) $(FLAGS) $(ALG)Space.cpp -std=c++14 -o $(ODIR)Space.o

$(ODIR)PresentResult.o: $(RES)PresentResult.cpp
	$(CC) $(FLAGS) $(RES)PresentResult.cpp -std=c++14 -o $(ODIR)PresentResult.o

clean:
	rm -f $(OBJS) $(OUT)
