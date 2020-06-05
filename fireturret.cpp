#include "fireturret.h"

FireTurret::FireTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    mx = x, my = y;
    BaseImgPath = QString(":/image/火瓶底座.png");
    DefImgPath = QString(":/image/二级火瓶.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 170;

    BullPath = QString(":/image/炮弹1.png");
    bullwidth = 40, bullheight = 40;

    attack = 65;
}
