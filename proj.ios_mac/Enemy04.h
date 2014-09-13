//
//  Enemy04.h
//  StgSample
//
//  Created by 海下直哉 on 2014/09/14.
//
//

#ifndef __StgSample__Enemy04__
#define __StgSample__Enemy04__

#include <iostream>
#include "cocos2d.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

using namespace cocos2d;

class Enemy04 : public Enemy{
private:
    int shotCount;
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle[2];
    float shotDelay;
    
    static Enemy04* create(Layer *rootLayer_);
    void Move();
};

#endif /* defined(__StgSample__Enemy04__) */
