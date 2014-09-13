//
//  Bullet.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/08/29.
//
//

#include "Bullet.h"

Bullet* Bullet::create(float speed,float speedRate,float angle,std::string fileName)
{
    Bullet *bullet = new Bullet();
    bullet->speed = speed;
    bullet->speedRate = speedRate;
    bullet->angle = angle;
    bullet->isAlive = true;
    
    if (bullet && bullet->initWithFile(fileName))
    {
        bullet->autorelease();
        bullet->retain();
        return bullet;
    }

    CC_SAFE_DELETE(bullet);
    return NULL;
}

void Bullet::Move(){
    Size windowSize = Director::getInstance()->getWinSize();
    
    // 角度をラジアンに変える
    float rad = CC_DEGREES_TO_RADIANS(angle);
    
    // 現在の座標を取得して角度と速度に合わせて移動
    Vec2 position = this->getPosition();
    this->setPosition(position.x + speed*cosf(rad), position.y + speed*sinf(rad));
    
    // 画面外に出たら生存フラグを下ろす。
    if (this->getPosition().x > windowSize.width || this->getPosition().y > windowSize.height
        || this->getPosition().x < 0 || this->getPosition().y < 0) {
        isAlive = false;
    }
}