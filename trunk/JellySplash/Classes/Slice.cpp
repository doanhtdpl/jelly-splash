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

//tao moi slice co vi tri row, col. tra ve 1 con tro kieu Slice*
Slice* Slice::create(int row, int col)
{
	Slice* slice = new Slice();
    
    slice->_imgIndex = rand() % TOTAL_SLICE;
   
    if(slice && slice->initWithSpriteFrameName(sliceNormal[slice->_imgIndex]))
       {
    
           slice->_col = col;
           slice->_row = row;
           
           //tao hinh anh tu chuoi cua mang tren
	
           slice->autorelease();
           return slice;
       }
    
    CC_SAFE_DELETE(slice);
    return nullptr;
}

Slice* Slice::create(Point pos, int tyle)
{
    Slice* slice = new Slice();
    
    if(slice && slice->initWithSpriteFrameName(sliceNormal[tyle]))
    {
        //slice->setPosSlice(pos);
        
        slice->setIDSlice(tyle);
        
        slice->isActive = false;
        
        slice->autorelease();
        
        return slice;
    }
    
    CC_SAFE_DELETE(slice);
    return nullptr;
}

bool Slice::isTap(cocos2d::Vec2 tapPos)
{
    float _distanceX = posSlice.x - tapPos.x;
    float _distanceY = posSlice.y - tapPos.y;
    
    if(_distanceX < 0)
        _distanceX = -_distanceX;
    if(_distanceY < 0)
        _distanceY = -_distanceY;
    
    float _radianX = 90 + 10.0;
    float _radianY = 90 +10.0;
    
    //return (!(powf(_distanceX, 2) + powf(_distanceY, 2) > powf(_radian, 2)));
    return (!(_distanceX > _radianX) && !(_distanceY > _radianY));
}

