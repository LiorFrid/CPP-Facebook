#pragma once
#ifndef __TEXTSTATUS_H
#define __TEXTSTATUS_H


#include "status.h"
#include<string.h>
class TextStatus : virtual public Status
{
protected:
	char *Post;
public:
	TextStatus();
	virtual void show1();
	~TextStatus();
};

#endif // !__TEXTSTATUS_H