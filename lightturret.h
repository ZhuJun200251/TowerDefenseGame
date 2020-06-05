#ifndef LIGHTTURRET_H
#define LIGHTTURRET_H

#include "defetowerparent.h"
class LightTurret : public DefeTowerParent
{
protected:

public:
    LightTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // LIGHTTURRET_H
