#include "HelloWorldScene.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto windowSize = Director::getInstance()->getWinSize();
    
    Enemy04 *enemy = Enemy04::create(this);
    enemy->setPosition(windowSize.width/2, windowSize.height/2);
    TaskManager::getInstance()->AddEnemyTask(*enemy, *this);
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float frame){
    TaskManager::getInstance()->MoveTask((TaskManager::getInstance()->enemyManager), *this);
    TaskManager::getInstance()->MoveTask((TaskManager::getInstance()->bulletManager), *this);
}

void HelloWorld::PlayerMove(){
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    // タッチ始めた時
    listener->onTouchBegan = [](Touch *touch,Event *event){
        return true;
    };
    
    // タッチ中
    listener->onTouchMoved = [](Touch *touch,Event *event){
    };
    
    // タッチ終了
    listener->onTouchEnded = [](Touch *touch,Event *event){
        
    };
}