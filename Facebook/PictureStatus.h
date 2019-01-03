#pragma once
#ifndef __PICTURESTATUS_H
#define __PICTURESTATUS_H
#include "status.h"
class PictureStatus :virtual public Status
{
public:
	PictureStatus();
	virtual void show1();
	~PictureStatus();
};

#endif // !__PICTURESTATUS_H
