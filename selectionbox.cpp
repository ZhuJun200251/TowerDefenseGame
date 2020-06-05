#include "selectionbox.h"

SelectionBox::SelectionBox(QString Path, int width, int height) :
    mwidth(width), mheight(height), SelecBoxImgPath(Path) {}

int SelectionBox::GetX() const
{
    return mx;
}
int SelectionBox::GetY() const
{
    return my;
}
int SelectionBox::GetWidth() const
{
    return mwidth;
}
int SelectionBox::GetHeight() const
{
    return mheight;
}

QString SelectionBox::GetImgPath() const
{
    return SelecBoxImgPath;
}

bool SelectionBox::GetDisplay() const
{
    return display;
}

void SelectionBox::SetDisplay(const bool SetPlay)
{
    display = SetPlay;
}

void SelectionBox::CheckTower(int x, int y)
{
    mx = x - 95, my = y - 95;

    SubBut[0].SubX = mx + 106, SubBut[0].SubY = my + 14;
    SubBut[0].SubImgPath = QString(":/image/购买状态绿瓶.png");

    SubBut[1].SubX = mx + 14, SubBut[1].SubY = my + 106;
    SubBut[1].SubImgPath = QString(":/image/购买状态火瓶.png");

    SubBut[2].SubX = mx + 202, SubBut[2].SubY = my + 106;
    SubBut[2].SubImgPath = QString(":/image/一级光炮.png");

    SubBut[3].SubX = mx + 106, SubBut[3].SubY = my + 190;
    SubBut[3].SubImgPath = QString(":/image/一级大炮.png");

    display = true;
}

SubbutStr* SelectionBox::GetSelSubBut()
{
    return SubBut;
}
