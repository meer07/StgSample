//
//  Enemy01.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/09/07.
//
//

#include "Enemy01.h"

Enemy01* Enemy01::create(Layer *rootLayer_)
{
    Enemy01 *enemy = new Enemy01();
    
    enemy->speed = 0;
    enemy->speedRate = 0;
    enemy->angle = 0;
    enemy->shotDelay = 2.0f;
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

void Enemy01::Move()
{
    Enemy::Move();
    
    if (shotDelay <= 0) {
        Bullet *bullet = Bullet::create();
        bullet->setPosition(Enemy01::getPosition().x, Enemy01::getPosition().y);
        rootLayer->addChild(bullet);
        TaskManager::getInstance()->AddBulletTask(*bullet);
        shotDelay = 2.0f;
    }
    
    shotDelay -= 0.05f;
}