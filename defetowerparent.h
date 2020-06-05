#ifndef DEFETOWERPARENT_H
#define DEFETOWERPARENT_H

#include <QString>
#include "monster.h"

class DefeTowerParent
{
protected:
    int mx, my;
    int width, height;
    QString BaseImgPath;
    QString DefImgPath;
    int RotatAngle = 0;
    int UpLeftX, UpLeftY;
    int Range;

    Monster* aimsmon = NULL;

    QString BullPath;
    int power;
    int speed;
    int bullwidth, bullheight;
    QVector<BulletStr*> BulletVec;
    int counter = 0;
    int attack;

public:
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetRotatAngle() const;
    QString GetBaseImgPath() const;
    QString GetDefImgPath() const;
    int GetUpLeftX() const;
    int GetUpLeftY() const;
    void SetRotatAngle(int rot);
    int GetRange() const;

    Monster* GetAimsMonster() const;
    void SetAimsMonster(Monster*);

    QString GetBulletPath() const;
    QVector<BulletStr*>& GetBulletVec();
    void InterBullet();
    void BulletMove(int speed = 80);
    int GetBulletWidth() const;
    int GetBulletHeight() const;
    int GetAttack() const;

    void SetAttack(int);
    void SetWidthHeight(int, int);
    void SetXY(int, int);

    void SetBulletWidthHeight(int, int);
};

#endif // DEFETOWERPARENT_H
