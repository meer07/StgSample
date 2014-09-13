//
//  Enemy04.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/09/14.
//
//

#include "Enemy04.h"

Enemy04* Enemy04::create(Layer *rootLayer_)
{
    Enemy04 *enemy = new Enemy04();
    
    enemy->speed = 0;
    enemy->speedRate = 0;
    enemy->angle = 0;
    
    enemy->shotSpeed = 3;
    enemy->shotSpeedRate = 1;
    enemy->shotAngle[0] = 0;
    enemy->shotAngle[1] = 0;
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
void Enemy04::Move()
{
    Enemy::Move();
    
    if (shotDelay <= 0) {
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < shotCount; j++) {
                Bullet *bullet = Bullet::create(shotSpeed,shotSpeedRate,shotAngle[i]+90*j,"bullet02.png");
                bullet->setPosition(Enemy04::getPosition().x, Enemy04::getPosition().y);
                rootLayer->addChild(bullet);
                TaskManager::getInstance()->AddBulletTask(*bullet);
            }
        }
        shotAngle[0] += 10;
        shotAngle[1] -= 10;
        
        shotDelay = 1.0f;
    }
    
    shotDelay -= 0.05f;
}