#ifndef DEFENSETOWERPIT_H
#define DEFENSETOWERPIT_H

#include <QVector>

class DefenseTowerPit
{
private:
    const int mx, my;
    const int mwidth, mheight;

public:
    DefenseTowerPit(int x, int y, int width = 80, int height = 80);

    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
};

#endif // DEFENSETOWERPIT_H
