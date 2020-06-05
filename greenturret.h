#ifndef GREENTURRET_H
#define GREENTURRET_H

#include "defetowerparent.h"

class GreenTurret : public DefeTowerParent
{
protected:

public:
    GreenTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // GREENTURRET_H
