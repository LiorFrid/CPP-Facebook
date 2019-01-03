#pragma once
#ifndef __STATUS_H
#define __STATUS_H
#include <ctime>
#include "Date.h"
#include "Time.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
enum KIND { text, photo, video };
class Status
{
	friend class member;

protected:
	char *post;
	Date postDate;
	Time postTime;
	KIND kind;

public:
	Status();
	Status(const Status&other);
	int compare(Status *statusToCheck);
	void show();
	virtual void show1() {};
	char *GetTheStatus() const;
	Date GetStatusDate() const;
	bool operator==(Status *post);

	bool operator!=(Status *post) {
		return !(*this == post); //return the opposite of the == function
	}
	~Status();
};
#endif
