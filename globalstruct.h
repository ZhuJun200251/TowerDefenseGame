#ifndef GLOBALSTRUCT_H
#define GLOBALSTRUCT_H

#include <QString>

class SubbutStr
{
public:
    int SubX;
    int SubY;
    int SubWidth = 56;
    int SubHeight = 56;
    QString SubImgPath;
};

class CoorStr
{
public:
    int x;
    int y;

    CoorStr(int x1, int y1) : x(x1), y(y1) {}
};

class BulletStr
{
public:
    CoorStr coor;
    int k = 0, b = 0;
    bool dirflag = false;

    BulletStr(CoorStr fcoor) : coor(fcoor) {}

    int GetX()  const
    {
        return coor.x;
    }

    int GetY() const
    {
        return coor.y;
    }
};

#endif // GLOBALSTRUCT_H
