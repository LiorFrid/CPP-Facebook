#pragma once
#ifndef __ENTITY_H
#define __ENTITY_H
#define NOTHINGTOCHECK -1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define MAXNAME 20
#include "Date.h"
#include <vector>
#include "status.h"
#include "TextStatus.h"
#include "PictureStatus.h"
#include <string.h>
#include <string>
#include "TextAndPicture.h"
#include "VideoStatus.h"
#include "TextVideo.h"



class entity
{

protected:
	string name;
	vector < member*>  friends;
	vector < Status*> MemberStatus;



public:


	entity() = default;

	void operator>(entity *other);
	entity(string name, member ** friends);
	//entity(const entity& other);


	virtual const string&  getName() const
	{
		return name;

	}



	void setName(string name);
	void WritePost();


	void showFriends();


	virtual ~entity();


};
#endif // __ENTITY_H
