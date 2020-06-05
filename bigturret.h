#ifndef BIGTURRET_H
#define BIGTURRET_H

#include "defetowerparent.h"

class BigTurret : public DefeTowerParent
{
protected:

public:
    BigTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // BIGTURRET_H
