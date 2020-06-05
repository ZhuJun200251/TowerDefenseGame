#include "bigturret.h"

BigTurret::BigTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    mx = x, my = y;
    BaseImgPath = QString(":/image/火瓶底座.png");
    DefImgPath = QString(":/image/一级大炮.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 230;

    BullPath = QString(":/image/炮弹3.png");
    bullwidth = 40, bullheight = 40;

    attack = 118;
}
