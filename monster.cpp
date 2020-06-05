#include "monster.h"
#include <QDebug>

Monster::Monster(CoorStr **pointarr, int arrlength, int x, int y, int fid) :
    mx(x), my(y), id(fid)
{
    for(int i = 0; i < arrlength; i++)
        Waypoint.push_back(pointarr[i]);

    switch (id)
    {
    case 1:
        health = 100;
        mwidth = 64, mheight = 64;
        ImgPath = ":/image/怪物1.png";
        break;
    case 2:
        health = 120;
        mwidth = 86, mheight = 64;
        ImgPath = ":/image/怪物2.png";
        break;
    case 3:
        health = 650;
        mwidth = 84, mheight = 93;
        ImgPath = ":/image/怪物3.png";
        break;
    case 4:
        health = 310;
        mwidth = 98, mheight = 70;
        ImgPath = ":/image/怪物4.png";
        break;
    case 5:
        health = 200;
        mwidth = 90, mheight = 76;
        ImgPath = ":/image/怪物5.png";
        break;
    default:
        break;
    }
}

bool Monster::Move()
{
    if(Waypoint.empty())
        return true;

    if (Waypoint.at(0)->y > my)
    {
        my += mspeed;
        return false;
    }

    if (Waypoint.at(0)->x < mx)
    {
        mx -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->x > mx)
    {
        mx += mspeed;
        return false;
    }

    if (Waypoint.at(0)->y < my)
    {
        my -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->y == my && Waypoint.at(0)->x == mx)
    {
        delete Waypoint.begin();
        Waypoint.erase(Waypoint.begin());
    }

    return false;
}


int Monster::GetX() const
{
    return mx;
}

int Monster::GetY() const
{
    return my;
}

int Monster::GetWidth() const
{
    return mwidth;
}

int Monster::GetHeight() const
{
    return mheight;
}

QString Monster::GetImgPath() const
{
    return ImgPath;
}

int Monster::GetId() const
{
    return id;
}

int Monster::GetHealth() const
{
    return health;
}

void Monster::SetHealth(int fhealth)
{
    health = fhealth;
}

