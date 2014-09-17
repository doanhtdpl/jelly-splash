#include "Slice.h"

USING_NS_CC;

#define TOTAL_SLICE 6//tong cong co 5 loai slice

//tao mang con tro, chua dia chi toi anh cua slice. 
static const char* sliceNormal[TOTAL_SLICE] = {
	/*"Slice/gem_blue.png",
	"Slice/gem_green.png",
	"Slice/gem_purple.png",
	"Slice/gem_rainbow.png",
	"Slice/gem_red.png",
	"Slice/gem_yellow.png"*/
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
	slice->_col = col;
	slice->_row = row;
	slice->_imgIndex = rand() % TOTAL_SLICE;

	//tao hinh anh tu chuoi cua mang tren
	slice->initWithSpriteFrameName(sliceNormal[slice->_imgIndex]);
	slice->autorelease();
	return slice;
}