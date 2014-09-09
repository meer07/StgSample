//
//  TaskManager.h
//  StgSample
//
//  Created by 海下直哉 on 2014/08/30.
//
//

#ifndef __StgSample__TaskManager__
#define __StgSample__TaskManager__

#include "cocos2d.h"
#include "Mover.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

using namespace cocos2d;

class TaskManager{
private:
    TaskManager();
    TaskManager(const TaskManager& t){}
    TaskManager &operator = (const TaskManager &t){}
    
public:
    std::vector<Mover *> bulletManager;
    std::vector<Mover *> enemyManager;

    static TaskManager* getInstance();
    void AddEnemyTask(Mover &enemy, Layer &sceneLayer);
    void AddBulletTask(Mover &bullet);
    void MoveTask(std::vector<Mover *> &list,Layer &sceneLayer);
};

#endif /* defined(__StgSample__TaskManager__) */
