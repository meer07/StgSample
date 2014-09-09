//
//  Mover.h
//  StgSample
//
//  Created by 海下直哉 on 2014/08/29.
//
//

#ifndef __StgSample__Mover__
#define __StgSample__Mover__

#include "cocos2d.h"

using namespace cocos2d;

class Mover : public cocos2d::Sprite
{
public:
    // 速度
    float speed;
    // 加速度
    float speedRate;
    // 角度
    float angle;
    // 位置を示すID
    int placeID;
    // 生存しているかどうか
    bool isAlive;
    // それぞれの派生クラスで処理を実装するので仮想メソッド
    virtual void Move(){};
};

#endif /* defined(__StgSample__Mover__) */
