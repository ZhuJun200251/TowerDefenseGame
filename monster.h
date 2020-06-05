#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include "globalstruct.h"

class Monster
{
private:
    QVector<CoorStr*> Waypoint;
    int mx, my;
    int mwidth, mheight;
    QString ImgPath;
    int id;
    int health;
    int mspeed = 10;

public:
    Monster(CoorStr **pointarr, int arrlength, int x, int y, int fid);

    bool Move();

    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
    QString GetImgPath() const;
    int GetId() const;
    int GetHealth() const;
    void SetHealth(int);
};

#endif // MONSTER_H
