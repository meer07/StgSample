//
//  Enemy01.h
//  StgSample
//
//  Created by 海下直哉 on 2014/09/07.
//
//

#ifndef __StgSample__Enemy01__
#define __StgSample__Enemy01__

#include <iostream>
#include "cocos2d.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

using namespace cocos2d;

class Enemy01 : public Enemy{
private:
    float shotDelay;
public:
    static Enemy01* create(Layer *rootLayer_);
    void Move();
};
#endif /* defined(__StgSample__Enemy01__) */
