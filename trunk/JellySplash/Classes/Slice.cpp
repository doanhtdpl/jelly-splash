#include "Slice.h"

USING_NS_CC;

#define TOTAL_SLICE 6//tong cong co 5 loai slice

//tao mang con tro, chua dia chi toi anh cua slice. 
static const char* sliceNormal[TOTAL_SLICE] = {
//	"gem_blue.png",
//	"gem_green.png",
//	"gem_purple.png",
//	"gem_rainbow.png",
//	"gem_red.png",
//	"gem_yellow.png"
	"sushi_1n.png",
	"sushi_2n.png",
	"sushi_3n.png",
	"sushi_4n.png",
	"sushi_5n.png",
	"sushi_6n.png"
};




float Slice::getContentWidth()
{
	static float itemWidth = 0;
	if (itemWidth == 0)
	{
		auto sprite = Sprite::create(sliceNormal[0]);
		itemWidth = sprite->getContentSize().width;

	}
	return itemWidth;
}



Slice* Slice::create(Point pos, int tyle)
{
    Slice* slice = new Slice();
    
    if(slice && slice->initWithSpriteFrameName(sliceNormal[tyle]))
    {
        
        slice->sliceStatus = isNormal;
        
        slice->setSTYLE(tyle);
        
        slice->isActive = false;
        
        slice->isBack = false;
        
        slice->autorelease();
        
        return slice;
    }
    
    CC_SAFE_DELETE(slice);
    return nullptr;
}

bool Slice::isCheckTap(Vec2 pos)
{
    float _distanceX = ((Slice*)this)->getPositionX() - pos.x;
    float _distanceY = ((Slice*)this)->getPositionY() - pos.y;
    
    if(_distanceX < 0)
        _distanceX = -_distanceX;
    if(_distanceY < 0)
        _distanceY = -_distanceY;
    
    float _radianX = ((Slice*)this)->getContentSize().width / 2;
    float _radianY = ((Slice*)this)->getContentSize().height / 2;
    
    
    return ((_distanceX < _radianX) && (_distanceY < _radianY));
       
}

