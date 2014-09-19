#include "PlayLayer.h"
#include "Slice.h"

//define kich thuoc matrix
#define MATRIX_WIDTH 7
#define MATRIX_HEIGHT 8

#define SLICE_GRAP 1



PlayLayer::PlayLayer()
	:_width(0)
	,_height(0)
	,_matrixTopLeftX(0)
	,_matrixTopLeftY(0)
{

}

PlayLayer::~PlayLayer()
{
	
}

bool PlayLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
    
    winSize = Director::getInstance()->getWinSize();
    
    //this->scheduleUpdate();
    
	//tao anh nen
    idSlice = 0;
    firstID = 0;
    endID = 0;
    
	listSlice = new Vector<Slice*>();
    sublistSlice = new Vector<Slice*>();
    
    indexSlice = new Slice();
    
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sushi.plist");
	

	_width = MATRIX_WIDTH;
	_height = MATRIX_HEIGHT;

	_matrixTopLeftX = (winSize.width - Slice::getContentWidth() * _width - (
		_width -1 ) * SLICE_GRAP) / 2; 
	_matrixTopLeftY = (winSize.height - Slice::getContentWidth() * _height - 
				_height * SLICE_GRAP) / 2;


	

	initMatrix();
    
    CCLOG("%d",(int)listSlice->size());
    
	return true;
}

void PlayLayer::initMatrix()
{
	for (int row = 0; row < _height; row++)
	{
		for (int col = 0; col < _width; col++)
		{
			createAndDropSlice(row, col);
		}
	}
}

void PlayLayer::createAndDropSlice(int row, int col)
{
    idSlice++;
    
	Size size = Director::getInstance()->getWinSize();
    Point endPosition = positionOfSlice(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + size.height / 2);
    float speed = startPosition.y / (size.height);
    
    int i = rand()%(6);
    Slice* slice = Slice::create(Point(row, col), i);
   
	slice->setPosition(startPosition);
    slice->setID(idSlice - 1);
    slice->setINDEX(Vec2(row, col));

	slice->runAction(MoveTo::create(speed, endPosition));// roi xuong

	
    
    this->addChild(slice);
    
    listSlice->pushBack(slice);
    
	
}

Point PlayLayer::positionOfSlice(int row, int col)
{
	float x  = _matrixTopLeftX + (Slice::getContentWidth() + SLICE_GRAP) * col + 
				Slice::getContentWidth() / 2;

	float y = _matrixTopLeftY + (Slice::getContentWidth() + SLICE_GRAP) * row + 
		Slice::getContentWidth() / 2;

	return Point(x, y);
}

void PlayLayer::update(float dt)
{
    for(auto sl : *listSlice)
    {
        if(sl->sliceStatus == isTap && sl->isActive)
        {
            sl->sliceStatus = isNormal;
            sl->isActive = false;
            //CCLOG("ID");
        }

    }
}

void PlayLayer::onExit()
{
    if(listSlice)
    {
        listSlice->clear();
        delete listSlice;
        listSlice = nullptr;
    }
    if(sublistSlice)
    {
        delete sublistSlice;
        sublistSlice = nullptr;
    }
    
    CCLOG("onExit");
}



void PlayLayer::processTouchBegin(cocos2d::Vec2 pos)
{

    
    for( auto sl : *listSlice)
    {
        
        if(sl->isCheckTap(pos) && !sl->isActive)
        {
            sl->sliceStatus = isTap;
            sl->isActive = true;
            sl->setScale(0.8);
            sublistSlice->pushBack(sl);
            indexSlice = sl;
            firstID = ((Slice*)listSlice->at(listSlice->getIndex(indexSlice)))->getID();
        }
    
    }
    
   
}

void PlayLayer::processTouchMove(cocos2d::Vec2 pos)
{
    for(auto sl : *listSlice)
    {
        if(!sl->isActive)
        {
            if(checkSlice(sl) && sl->isCheckTap(pos) &&checkSliceAround(indexSlice, sl) )
            {
                
                sl->sliceStatus = isTap;
                sl->isActive = true;
                sl->setScale(0.8);
                sublistSlice->pushBack(sl);
                indexSlice = sl;
                
                endID = ((Slice*)listSlice->at(listSlice->getIndex(indexSlice)))->getID();
                if(sl->getID() != firstID || sl->getID() != endID)
                {
                    sl->isBack = true;
                    
                }
                
                CCLOG("%d %d",firstID, endID );

            }
        }
        else
        {
            if(sl->isBack && sl->getID() != firstID && sl->getID() != endID)
            {
                sl->sliceStatus = isNormal;
                sl->isActive = false;
                sl->isBack = false;
                sl->runAction(Sequence::create(ScaleTo::create(0.4, 1.2), ScaleTo::create(0.5, 1.0), NULL));
                indexSlice = sl;
            }
        }
    }
    
    
    
}

void PlayLayer::processTouchEnd()
{
    for(auto sl : *listSlice)
    {
    
        if(sl->sliceStatus == isTap && sl->isActive)
        {
            sl->sliceStatus = isNormal;
            sl->isActive = false;
            sl->runAction(Sequence::create(ScaleTo::create(0.4, 1.2), ScaleTo::create(0.5, 1.0), NULL));
            
        }
    }
    
    sublistSlice->clear();
    
   // CCLOG("%d",(int)listSlice->size());
}

bool PlayLayer::checkSlice(Slice *slice)
{
    
    for(auto sl : *sublistSlice)
    {
        if(sl->getSTYLE() == slice->getSTYLE())
            return true;
        else
            return false;
    }
    
    return nullptr;
}

bool PlayLayer::checkSliceAround(Slice *currSlice, Slice *nextSlice)
{
    float _distanceX = currSlice->getPositionX() - nextSlice->getPositionX();
    float _distanceY = currSlice->getPositionY() - nextSlice->getPositionY();
    
    float _distance = _distanceX * _distanceX + _distanceY * _distanceY;
    float _radian = Slice::getContentWidth();
    
    
    return (_distance  <= _radian * _radian * 2.3);
}



