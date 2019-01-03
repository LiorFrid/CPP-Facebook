#pragma once
#ifndef __TEXTANDVIDEO_H
#define __TEXTANDVIDEO_H

#include "TextStatus.h"
#include "VideoStatus.h"
class TextVideo : public TextStatus, public VideoStatus
{
public:
	TextVideo();
	~TextVideo();
	virtual void show1() {
		TextStatus::show1();
		cout << endl;
		VideoStatus::show1();
	};
};

#endif //__TEXTANDVIDEO_H

