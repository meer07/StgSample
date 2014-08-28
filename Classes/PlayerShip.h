//
//  PlayerShip.h
//  StgSample
//
//  Created by 海下直哉 on 2014/08/29.
//
//

#ifndef __StgSample__PlayerShip__
#define __StgSample__PlayerShip__

#include "cocos2d.h"
#include "Mover.h"

using namespace cocos2d;

class PlayerShip : public Mover
{
public:
    PlayerShip();
    void Move();
};

#endif /* defined(__StgSample__PlayerShip__) */
