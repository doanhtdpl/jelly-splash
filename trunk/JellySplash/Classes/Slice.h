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


using namespace cocos2d;

class Slice : public cocos2d::Sprite
{
public:
	static Slice* create(int row, int col);//tao ra slice tai vi tri hang, cot thuoc ma tran
    static Slice* create(Point pos, int tyle);
    
	static float getContentWidth();//lay chieu rong

	CC_SYNTHESIZE(int,_row,Row);//vi tri cot trong ma tran
	CC_SYNTHESIZE(int,_col,Col);//vi tri hang trong ma tran
	CC_SYNTHESIZE(int,_imgIndex,ImgIndex);//loai slice
    
    CC_SYNTHESIZE(Point, posSlice, PosSlice);
    CC_SYNTHESIZE(int, iDSlice, IDSlice);
        
    bool isActive;
    
    bool isTap(Vec2 tapPos);

	cocos2d::Vec2 _pos;
	cocos2d::Vec2 _posTile;//vi tri tren ma tran
protected:
private:
};

#endif // __SLICE__H___
