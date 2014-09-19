//
//  Slice.h
//  CrazyGost
//
//  Created by Tuan Hoang on 9/16/14.
//	
//	Contain information of one tile. Include image, pos, 
//

#ifndef __SLICE__H___
#define __SLICE__H___

#include "cocos2d.h"


typedef enum {
    isTap,
    isNormal,
}SliceStaus;

using namespace cocos2d;

class Slice : public cocos2d::Sprite
{
public:
    
    SliceStaus sliceStatus;    
	
    static Slice* create(Point pos, int tyle);
    
	static float getContentWidth();
    
    CC_SYNTHESIZE(int, iD, ID);
    CC_SYNTHESIZE(int, style, STYLE);
    CC_SYNTHESIZE(Point, index, INDEX);
    
        
    bool isActive;
    
    bool isBack;
    
    bool isCheckTap(Vec2 pos);

	
protected:
private:
    

};

#endif // __SLICE__H___
