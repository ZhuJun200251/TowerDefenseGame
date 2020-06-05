#ifndef FIRETURRECT_H
#define FIRETURRECT_H

#include "defetowerparent.h"

class FireTurret : public DefeTowerParent
{
protected:

public:
    FireTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // FIRETURRECT_H
