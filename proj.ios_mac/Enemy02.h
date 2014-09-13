//
//  Enemy02.h
//  StgSample
//
//  Created by 海下直哉 on 2014/09/12.
//
//

#ifndef __StgSample__Enemy02__
#define __StgSample__Enemy02__

#include <iostream>

#include <iostream>
#include "cocos2d.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

using namespace cocos2d;

class Enemy02 : public Enemy{
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle;
    float shotDelay;
    
    static Enemy02* create(Layer *rootLayer_);
    void Move();
};

#endif /* defined(__StgSample__Enemy02__) */
