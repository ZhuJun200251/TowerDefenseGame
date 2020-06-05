#include "greenturret.h"

GreenTurret::GreenTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    mx = x, my = y;
    BaseImgPath = QString(":/image/绿瓶底座.png");
    DefImgPath = QString(":/image/二级绿瓶.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 200;

    BullPath = QString(":/image/绿瓶子弹.png");
    bullwidth = 30, bullheight = 30;

    attack = 40;
}
