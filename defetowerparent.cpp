#include "defetowerparent.h"

int DefeTowerParent::GetX() const
{
    return mx;
}

int DefeTowerParent::GetY() const
{
    return my;
}

int DefeTowerParent::GetWidth() const
{
    return width;
}

int DefeTowerParent::GetHeight() const
{
    return height;
}

int DefeTowerParent::GetRotatAngle() const
{
    return RotatAngle;
}

QString DefeTowerParent::GetBaseImgPath() const
{
    return BaseImgPath;
}

QString DefeTowerParent::GetDefImgPath() const
{
    return DefImgPath;
}

int DefeTowerParent::GetUpLeftX() const
{
    return UpLeftX;
}

int DefeTowerParent::GetUpLeftY() const
{
    return UpLeftY;
}

void DefeTowerParent::SetRotatAngle(int rot)
{
    RotatAngle = rot;
}

int DefeTowerParent::GetRange() const
{
    return Range;
}

Monster* DefeTowerParent::GetAimsMonster() const
{
    return aimsmon;
}

void DefeTowerParent::SetAimsMonster(Monster* mon)
{
    aimsmon = mon;
}

QString DefeTowerParent::GetBulletPath() const
{
    return BullPath;
}

QVector<BulletStr*>& DefeTowerParent::GetBulletVec()
{
    return BulletVec;
}

void DefeTowerParent::InterBullet()
{
    counter++;

    if(counter < 7 || !aimsmon)
        return;

    BulletStr *bull = new BulletStr(CoorStr(UpLeftX + 40, UpLeftY + 40));

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    if((!(aimsmon->GetX() - bull->coor.x)))
    {
        delete bull;
        bull = NULL;
        goto L1;
    }

    bull->k = (aimsmon->GetY() - bull->coor.y) / (aimsmon->GetX() - bull->coor.x);
    bull->b = aimsmon->GetY() - aimsmon->GetX() * bull->k;

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    BulletVec.push_back(bull);

    if(aimsmon->GetX() <= UpLeftX + 40)
        bull->dirflag = true;
    L1:

    counter = 0;

}

void DefeTowerParent::BulletMove(int speed)
{
    for(auto bulli : BulletVec)
    {
        if(bulli->dirflag == true)
            bulli->coor.x -= speed;
        else
            bulli->coor.x += speed;

        bulli->coor.y = bulli->k * bulli->coor.x + bulli->b;
    }

    for(auto bullit = BulletVec.begin(); bullit != BulletVec.end(); bullit++)
        if((*bullit)->coor.x > 1040 || (*bullit)->coor.x < 0 || (*bullit)->coor.y > 640 || (*bullit)->coor.y < 0)
        {
            BulletVec.erase(bullit);
            break;
        }
}

int DefeTowerParent::GetBulletWidth() const
{
    return bullwidth;
}

int DefeTowerParent::GetBulletHeight() const
{
    return bullheight;
}

int DefeTowerParent::GetAttack() const
{
    return attack;
}

void DefeTowerParent::SetAttack(int attack)
{
    this->attack = attack;
}

void DefeTowerParent::SetWidthHeight(int width, int height)
{
    this->width = width, this->height = height;
}

void DefeTowerParent::SetXY(int x, int y)
{
    this->mx = x, this->my = y;
}

void DefeTowerParent::SetBulletWidthHeight(int width, int height)
{
    bullwidth = width, bullheight = height;
}
