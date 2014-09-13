//
//  Enemy.h
//  StgSample
//
//  Created by 海下直哉 on 2014/08/29.
//
//

#ifndef __StgSample__Enemy__
#define __StgSample__Enemy__

#include "cocos2d.h"
#include "Mover.h"

using namespace cocos2d;

class Enemy : public Mover
{
public:
    Layer *rootLayer;
    
    void Move();
};

#endif /* defined(__StgSample__Enemy__) */
