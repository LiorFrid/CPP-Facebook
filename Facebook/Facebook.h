
#pragma once
#ifndef __FACEBOOK_H
#define __FACEBOOK_H
#include "member.h"
#include "fanPage.h"
#include <vector>
// Respect
class member;
class fanPage;

class Facebook
{
public:

	void AddMember();
	void AddFanFage();
	int GetNumOfMember()const;
	int GetNumOfPages()const;
	int GetNumOfEntities()const;
	member * GetMember(int index)const;
	fanPage* GetFanPage(int index)const;
	void setfriendship();
	void LikePage();
	//GetFanPage;
	void ShowMembers();
	void ShowFanPage();
	int CheckNoDupName(string name, int flag);
	~Facebook();

private:

	int LogicalNumberOfMembers = 0;
	int LogicalNumberOfFanPage = 0;

	vector<entity*> ArryOfEntities;


};


#endif
