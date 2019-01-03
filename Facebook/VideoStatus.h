#pragma once
#ifndef __VIDEOSTATUS_H
#define __VIDEOSTATUS_H


#include "status.h"
class VideoStatus : virtual public Status
{
protected:

public:
	virtual void show1();
	VideoStatus();
	~VideoStatus();
};

#endif // __VIDEOSTATUS_H