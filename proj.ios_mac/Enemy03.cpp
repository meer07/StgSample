//
//  Enemy03.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/09/14.
//
//

#include "Enemy03.h"

Enemy03* Enemy03::create(Layer *rootLayer_)
{
    Enemy03 *enemy = new Enemy03();
    
    enemy->speed = 0;
    enemy->speedRate = 0;
    enemy->angle = 0;
    
    enemy->shotSpeed = 3;
    enemy->shotSpeedRate = 1;
    enemy->shotAngle = -90;
    enemy->shotDelay = 1.0f;
    enemy->shotCount = 4;
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

// 多方向渦巻き弾
void Enemy03::Move()
{
    Enemy::Move();
    
    if (shotDelay <= 0) {
        
        for (int i = 0; i < shotCount; i++) {
            Bullet *bullet = Bullet::create(shotSpeed,shotSpeedRate,shotAngle+90*i,"bullet02.png");
            bullet->setPosition(Enemy03::getPosition().x, Enemy03::getPosition().y);
            rootLayer->addChild(bullet);
            TaskManager::getInstance()->AddBulletTask(*bullet);
        }
        
        shotAngle += 10;
        shotDelay = 1.0f;
    }
    
    shotDelay -= 0.05f;
}