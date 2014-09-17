#include "GameScene.h"


USING_NS_CC;


static GameScene* instance;

GameScene* GameScene::getInstance()
{
    CC_ASSERT(instance != nullptr);
    
    return instance;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    instance = this;
    
    listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    _size = Director::getInstance()->getWinSize();
    
    
    addBackGround();
    
    play = PlayLayer::create();
    this->addChild(play);
    
    
    return true;
}

void GameScene::addBackGround()
{
    auto bg = Sprite::create("bgGamePlay.png");
    bg->setPosition(_size.width / 2, _size.height / 2);
    this->addChild(bg);
}

void GameScene::update(float dt)
{}

void GameScene::onExit()
{
    
    Scene::onExit();
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    play->processTouchBegin(touch->getLocation());
    
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
}


void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
}


