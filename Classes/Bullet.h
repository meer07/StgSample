//
//  Bullet.h
//  StgSample
//
//  Created by 海下直哉 on 2014/08/29.
//
//

#ifndef __StgSample__Bullet__
#define __StgSample__Bullet__

#include "cocos2d.h"
#include "Mover.h"
using namespace cocos2d;

class Bullet : public Mover
{
public:
    void Move();
    static Bullet* create(float speed,float speedRate,float angle,std::string fileName);
};

#endif /* defined(__StgSample__Bullet__) */
