//
// Created by Stasiek on 2020-05-27.
//

#ifndef CUBOIDS_AAL_LEVELSEGMENTCORDS_H
#define CUBOIDS_AAL_LEVELSEGMENTCORDS_H


class LevelSegmentCords {
private:
    int x1,y1,x2,y2;
    int startLevel;
    int height;
public:
    LevelSegmentCords(int x1, int y1, int x2, int y2);

    LevelSegmentCords(int x1, int y1, int x2, int y2, int startLevel, int height);

    int getX1() const;

    int getY1() const;

    int getX2() const;

    int getY2() const;

    int getStartLevel() const;

    int getHeight() const;

    void setStartLevel(int startLevel);

    void setHeight(int height);
};


#endif //CUBOIDS_AAL_LEVELSEGMENTCORDS_H
