#include "defensetowerpit.h"

DefenseTowerPit::DefenseTowerPit(int x, int y, int width, int height)
    : mx(x), my(y), mwidth(width), mheight(height) {}

int DefenseTowerPit::GetX() const
{
    return mx;
}

int DefenseTowerPit::GetY() const
{
    return my;
}

int DefenseTowerPit::GetWidth() const
{
    return mwidth;
}

int DefenseTowerPit::GetHeight() const
{
    return mheight;
}

