//
//  PlayLayer.h
//  
//
//  Created by Tuan Hoang on 9/16/14.
//	
//	Contain matrix Slice and logic game
//

#ifndef __PLAY__LAYER__H__
#define __PLAY__LAYER__H__
#include "cocos2d.h"
USING_NS_CC;

class Slice;

class PlayLayer : public cocos2d::Layer
{
public:
	PlayLayer();
	~PlayLayer();
	static Scene* scene();
	CREATE_FUNC(PlayLayer);
	virtual bool init() override;
protected:
private:
	SpriteBatchNode *spriteSheet;
	Slice **_matrix;

	//kich thuoc matran
	int _width;
	int _height;

	//vi tri can chinh tren man hinh. Top Left
	float _matrixTopLeftX;
	float _matrixTopLeftY;

	void initMatrix();
	void createAndDropSlice(int row, int col);

	//Tra ve vi tri toa do Point cua Slice tai vi tri hang - col
	Point positionOfSlice(int row, int col);
};

#endif // !__PLAY__LAYER__H__
