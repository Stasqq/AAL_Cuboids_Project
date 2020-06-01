//
// Created by Stasiek on 2020-05-20.
//

#ifndef CUBOIDS_AAL_CUBOID_H
#define CUBOIDS_AAL_CUBOID_H

class Cuboid {
    private:
        int xSize, ySize, zSize;
        int x, y, z;
        int id;
        int volume;
    public:
        Cuboid(int xSize, int ySize, int zSize);

        Cuboid(int xSize, int ySize, int zSize, int id);

        bool operator < (const Cuboid & other) const {
          return id < other.getId();
        }

        void rotate(int rotateDirection);

        void rotateXY();

        void rotateXZ();

        void rotateYZ();

        void rotateToSmallestHeight();

        void calculateVolume();

        void setPosition(int x, int y, int z);

        int getXSize() const;

        void setXSize(int xSize);

        int getYSize() const;

        void setYSize(int ySize);

        int getZSize() const;

        void setZSize(int zSize);

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

        int getZ() const;

        void setZ(int z);

        int getId() const;

        int getVolume() const;

        void setVolume(int volume);

};

#endif //CUBOIDS_AAL_CUBOID_H
