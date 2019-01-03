#pragma once
#ifndef __TEXTSTATUS_H
#define __TEXTSTATUS_H
#define MAXSTATUS 30

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
	TextStatus(const TextStatus& other);

	bool operator==(TextStatus *post);

	bool operator!=(TextStatus *post) {
		return !(*this == post); //return the opposite of the == function
	}
};

#endif // !__TEXTSTATUS_H