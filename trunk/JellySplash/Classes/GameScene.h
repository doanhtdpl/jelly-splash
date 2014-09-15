#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class GameScene : public Scene
{
public:
    virtual bool init();
    
    virtual void update(float dt);
    
    virtual void onExit();
    
    static GameScene* getInstance();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
private:
    Size _size;
    
    void addBackGround();
    
    //touch
    
    EventListenerTouchOneByOne* listener;
    
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

};

#endif // __HELLOWORLD_SCENE_H__
