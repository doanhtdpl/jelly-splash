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
	
	CREATE_FUNC(PlayLayer);
	virtual bool init() override;
    
    void processTouchBegin(Vec2 pos);
    
    void processTouchMove(Vec2 pos);
    
    void processTouchEnd();
    
    Vector<Slice*>* listSlice;
    Vector<Slice*>* sublistSlice;
    
protected:
private:
    
    virtual void update(float dt);
    
    virtual void onExit();
    
    Size winSize;
    
	Slice* indexSlice;
    
    int idSlice;
    int firstID;
    int endID;

	//kich thuoc matran
	int _width;
	int _height;

	//vi tri can chinh tren man hinh. Top Left
	float _matrixTopLeftX;
	float _matrixTopLeftY;

	void initMatrix();
	void createAndDropSlice(int row, int col);
    
    bool checkSlice(Slice* slice);
    
    bool checkSliceAround(Slice* currSlice, Slice* nextSlice);

	//Tra ve vi tri toa do Point cua Slice tai vi tri hang - col
	Point positionOfSlice(int row, int col);
};

#endif // !__PLAY__LAYER__H__
