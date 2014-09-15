//
//  PauseLayer.cpp
//  CrazyGost
//
//  Created by Tran Tho on 8/25/14.
//
//

#include "PauseLayer.h"
#include "GameScene.h"
#include "MenuLayer.h"
#include "cocostudio/CocoStudio.h"



USING_NS_CC;
using namespace cocostudio;
using namespace ui;
using namespace CocosDenshion;

void PauseLayer::onEnter()
{
    //Pause Game
//    GameScene::getInstance()->isPaused = true;
//    GameScene::getInstance()->button->setVisible(false);
//    GameScene::getInstance()->button->setEnabled(false);
    
    
    layout  = static_cast<Layout*>(cocostudio::timeline::NodeReader::getInstance()->createNode("Pause.json"));
    layout->runAction(MoveTo::create(0.3, Vec2(300, layout->getPositionY())));
    this->addChild(layout);
    
    Button* button;
    
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Pause_Resume"));    
    button->addTouchEventListener(CC_CALLBACK_2(PauseLayer::touchResumButtonEvent,  this));
    
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Pause_Home"));
    button->addTouchEventListener(CC_CALLBACK_2(PauseLayer::touchHomeButtonEvent,  this));
    
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Pause_Close"));
    button->addTouchEventListener(CC_CALLBACK_2(PauseLayer::touchCloseButtonEvent,  this));

    
    Layer::onEnter();
}

void PauseLayer::onExit()
{
    
    _eventDispatcher->removeEventListenersForTarget(this);
//    HelloWorld::getInstance()->isPaused = false;
//    HelloWorld::getInstance()->button->setVisible(true);
//    HelloWorld::getInstance()->button->setEnabled(true);
//
    Layer::onExit();
}

void PauseLayer::touchResumButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
        layout->runAction(MoveTo::create(0.3, Vec2(640, layout->getPositionY())));
        this->removeFromParentAndCleanup(true);
        
    }
}

void PauseLayer::touchHomeButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
        this->removeFromParentAndCleanup(true);
        Director::getInstance()->replaceScene(Menulayer::scene());
    }
}

void PauseLayer::touchCloseButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
        CCLOG("Close");
    }
}


