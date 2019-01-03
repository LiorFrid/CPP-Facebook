#pragma once
#ifndef __TEXTANDPICTURE_H
#define __TEXTANDPICTURE_H


#include "PictureStatus.h"
#include "TextStatus.h"
class TextAndPicture :public TextStatus, public PictureStatus
{
public:
	TextAndPicture();
	~TextAndPicture();
	virtual void show1() {
		TextStatus::show1();
		cout << endl;
		PictureStatus::show1();
	};
};

#endif // !__TEXTANDPICTURE_H