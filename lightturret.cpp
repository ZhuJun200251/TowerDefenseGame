#include "lightturret.h"

LightTurret::LightTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    mx = x, my = y;
    BaseImgPath = QString(":/image/绿瓶底座.png");
    DefImgPath = QString(":/image/一级光炮.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 260;

    BullPath = QString(":/image/炮弹2.png");
    bullwidth = 40, bullheight = 40;

    attack = 94;
}
