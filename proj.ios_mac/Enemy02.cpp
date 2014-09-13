//
//  Enemy02.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/09/12.
//
//

#include "Enemy02.h"

Enemy02* Enemy02::create(Layer *rootLayer_)
{
    Enemy02 *enemy = new Enemy02();
    
    enemy->speed = 0;
    enemy->speedRate = 0;
    enemy->angle = 0;
    
    enemy->shotSpeed = 3;
    enemy->shotSpeedRate = 1;
    enemy->shotAngle = -90;
    enemy->shotDelay = 1.0f;
    enemy->isAlive = true;
    enemy->rootLayer = rootLayer_;
    
    if (enemy && enemy->initWithFile("jiki.png"))
    {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
    
}

// 渦巻き弾
void Enemy02::Move()
{
    Enemy::Move();
    
    if (shotDelay <= 0) {
        Bullet *bullet = Bullet::create(shotSpeed,shotSpeedRate,shotAngle,"bullet02.png");
        bullet->setPosition(Enemy02::getPosition().x, Enemy02::getPosition().y);
        rootLayer->addChild(bullet);
        TaskManager::getInstance()->AddBulletTask(*bullet);
        shotAngle += 10;
        shotDelay = 1.0f;
    }
    
    shotDelay -= 0.05f;
}