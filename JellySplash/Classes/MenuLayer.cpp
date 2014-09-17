//
//  MenuScene.cpp
//  CrazyGost
//
//  Created by Tran Tho on 8/23/14.
//
//

#include "MenuLayer.h"
#include "cocostudio/CocoStudio.h"
//#include "ui/CocosGUI.h"
#include "GameScene.h"
//#include "ChartboostX.h"
//#include <GKHWrapperCpp.h>




using namespace CocosDenshion;
using namespace cocostudio;


Scene* Menulayer::scene()
{
    auto scene = Scene::create();
    
    auto layer = Menulayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


bool Menulayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    _size = Director::getInstance()->getWinSize();
    
    
    return true;
}

void Menulayer::update(float dt)
{
   
    
}

void Menulayer::onEnter()
{
    Layer::onEnter();
    
    
    Layout* layout = static_cast<Layout*>(cocostudio::timeline::NodeReader::getInstance()->createNode("Menu.json"));
    this->addChild(layout);
    
    Button* button;
    
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Play"));
    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonPlayEvent,  this));
//
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Rate"));
//    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonRateEvent,  this));
//    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Score"));
//    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonScoreEvent,  this));
}


void Menulayer::touchButtonPlayEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
        //SimpleAudioEngine::getInstance()->playEffect(CLICK);
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        Director::getInstance()->replaceScene(GameScene::create());
        
        
    }
}

void Menulayer::touchButtonScoreEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
//        SimpleAudioEngine::getInstance()->playEffect(CLICK);
//        GKHWrapperCpp gkh;
//        gkh.showLeaderBoard();
    }

}

void Menulayer::touchButtonRateEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{if(type == ui::Widget::TouchEventType::ENDED)
    
//    {
//        SimpleAudioEngine::getInstance()->playEffect(CLICK);
//       IOSShare::rate();
//    }
    
    CCLOG("rate");
}

void Menulayer::onExit()
{
    _eventDispatcher->removeEventListenersForTarget(this);
    
    Layer::onExit();
}


