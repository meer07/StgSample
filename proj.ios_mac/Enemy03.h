//
//  Enemy03.h
//  StgSample
//
//  Created by 海下直哉 on 2014/09/14.
//
//

#ifndef __StgSample__Enemy03__
#define __StgSample__Enemy03__

#include <iostream>
#include "cocos2d.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

using namespace cocos2d;

class Enemy03 : public Enemy{
private:
    int shotCount;
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle;
    float shotDelay;
    
    static Enemy03* create(Layer *rootLayer_);
    void Move();
};

#endif /* defined(__StgSample__Enemy03__) */
