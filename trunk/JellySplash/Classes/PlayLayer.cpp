#include "PlayLayer.h"
#include "Slice.h"

//define kich thuoc matrix
#define MATRIX_WIDTH 7
#define MATRIX_HEIGHT 8

#define SLICE_GRAP 1



PlayLayer::PlayLayer()
	:spriteSheet(NULL)
	,_matrix(NULL)
	,_width(0)
	,_height(0)
	,_matrixTopLeftX(0)
	,_matrixTopLeftY(0)
{

}

PlayLayer::~PlayLayer()
{
	if (_matrix)
	{
		free(_matrix);
	}
}

bool PlayLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
    
    winSize = Director::getInstance()->getWinSize();
    
	//tao anh nen
	

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sushi.plist");
	spriteSheet = SpriteBatchNode::create("sushi.pvr.ccz"); 

	addChild(spriteSheet); 

	_width = MATRIX_WIDTH;
	_height = MATRIX_HEIGHT;

	_matrixTopLeftX = (winSize.width - Slice::getContentWidth() * _width - (
		_width -1 ) * SLICE_GRAP) / 2; 
	_matrixTopLeftY = (winSize.height - Slice::getContentWidth() * _height - 
				_height * SLICE_GRAP) / 2;


	int arraySize = sizeof(Slice*) * _width * _height;

	_matrix = (Slice **)malloc(arraySize);
	memset((void*)_matrix, 0, arraySize);// Đặt tất cả giá trị của mảng là 0, bắt buộc ép kiểu void* của mọi loại mảng
	initMatrix();
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
	Size size = Director::getInstance()->getWinSize();
    
    int i = rand()%(6);
    Slice* slice = Slice::create(Point(row, col), i);
    
    slice->setPosSlice(positionOfSlice(row, col));
    
	//Slice* slice = Slice::create(row, col);

	//tao animation
	Point endPosition = positionOfSlice(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + size.height / 2);

	slice->setPosition(startPosition);
	float speed = startPosition.y / (size.height);

	slice->runAction(MoveTo::create(speed, endPosition));// roi xuong

	spriteSheet->addChild(slice);
	_matrix[row * _width + col] = slice;
}

Point PlayLayer::positionOfSlice(int row, int col)
{
	float x  = _matrixTopLeftX + (Slice::getContentWidth() + SLICE_GRAP) * col + 
				Slice::getContentWidth() / 2;

	float y = _matrixTopLeftY + (Slice::getContentWidth() + SLICE_GRAP) * row + 
		Slice::getContentWidth() / 2;

	return Point(x, y);
}


void PlayLayer::processTouchBegin(cocos2d::Vec2 pos)
{
    for (int row = 0; row < _height; row++)
	{
		for (int col = 0; col < _width; col++)
		{
			if(_matrix[row][col].isTap(pos))
            {
                CCLOG("%d",_matrix[row][col].getIDSlice());
            }
		}
	}
}