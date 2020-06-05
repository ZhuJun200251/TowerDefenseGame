#ifndef SELECTIONBOX_H
#define SELECTIONBOX_H

#include <QString>
#include "globalstruct.h"

class SelectionBox
{
private:
    bool display = false;
    int mx = 0, my = 0;
    const int mwidth, mheight;
    QString SelecBoxImgPath;

    SubbutStr SubBut[4];

public:
    SelectionBox(QString Path, int width = 270, int height = 270);

    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
    QString GetImgPath() const;
    bool GetDisplay() const;
    void SetDisplay(const bool SetPlay);
    void CheckTower(int x, int y);
    SubbutStr* GetSelSubBut();
};

#endif // SELECTIONBOX_H
