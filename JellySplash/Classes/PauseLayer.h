//
//  PauseLayer.h
//  CrazyGost
//
//  Created by Tran Tho on 8/25/14.
//
//

#ifndef __CrazyGost__PauseLayer__
#define __CrazyGost__PauseLayer__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

USING_NS_CC;

using namespace ui;

class PauseLayer : public cocos2d::Layer
{
public:
    
    CREATE_FUNC(PauseLayer);
    
    virtual void onEnter() override;
    virtual void onExit() override;
    
private:
    
    
    Layout* layout;
    
    void touchResumButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchHomeButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchCloseButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    
    
};


#endif /* defined(__CrazyGost__PauseLayer__) */
