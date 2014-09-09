//
//  TaskManager.cpp
//  StgSample
//
//  Created by 海下直哉 on 2014/08/30.
//
//
#include "TaskManager.h"

TaskManager* TaskManager::getInstance()
{
    static TaskManager instance;
    return &instance;
}

TaskManager::TaskManager(){
    enemyManager.reserve(100);
    bulletManager.reserve(100);
}

void TaskManager::AddBulletTask(Mover &bullet)
{
    bulletManager.push_back(&bullet);
}

void TaskManager::AddEnemyTask(Mover &enemy, Layer &sceneLayer)
{
    sceneLayer.addChild(&enemy);
    enemyManager.push_back(&enemy);
}

void TaskManager::MoveTask(std::vector<Mover *> &list,Layer &sceneLayer)
{
    std::vector<Mover *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i)
    {
        if(list.size() > 0){
            if ((*i)->isAlive == false)
            {
                sceneLayer.removeChild(*i);
                list.erase(std::remove(list.begin(), list.end(), *i),list.end());
            }
            else
            {
                (*i)->Move();
            }
        }
    }
    std::cout << list.size() << std::endl;
}