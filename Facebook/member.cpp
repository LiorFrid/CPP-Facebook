
#include "member.h"
#include "Time.h"



void member::showLastTenFriendsStatuses()
{
	string name;
	int flag = 0;

	if (friends.size() == 0)
	{
		cout << "This user has no friends yet";
		return;
	}
	for (int d = 0; d <this->friends.size(); d++)
	{
		if (this->friends[d]->MemberStatus.size() != 0)
			flag = 1;

	}
	if (flag == 0)
	{
		cout << "This user's friends are not so active - no posts found";
		return;
	}
	Status *mostRecentStatus = nullptr, *currStatus;
	member *theWriterOfMostRecentStatus = nullptr;
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i]->MemberStatus.size() != 0)
			friends[i]->whereToCheck = friends[i]->MemberStatus.size();
		else
			friends[i]->whereToCheck = NOTHINGTOCHECK;
	}
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < friends.size(); j++)
		{
			if (friends[j]->whereToCheck != NOTHINGTOCHECK)
			{
				currStatus = friends[j]->MemberStatus[friends[j]->whereToCheck - 1];
				if (mostRecentStatus == nullptr)
				{
					mostRecentStatus = currStatus;
					theWriterOfMostRecentStatus = friends[j];
				}
				else if (mostRecentStatus != nullptr)
				{
					flag = mostRecentStatus->compare(currStatus);

					if (flag)
					{
						mostRecentStatus = currStatus;
						theWriterOfMostRecentStatus = friends[j];
					}

				}

			}
		}
		if (mostRecentStatus != nullptr)
		{
			name = theWriterOfMostRecentStatus->getName();
			cout << name << "'s post" << endl;
			mostRecentStatus->show();
		}
		if (theWriterOfMostRecentStatus)
		{
			if (theWriterOfMostRecentStatus->whereToCheck <= 1)
				theWriterOfMostRecentStatus->whereToCheck = NOTHINGTOCHECK;
			else
				theWriterOfMostRecentStatus->whereToCheck--;
			mostRecentStatus = nullptr;
		}

	}
}



member::member(Date birthday)
{
	this->birthday = birthday;
}


void member::setBirthDay(int day, int month, int year)
{
	birthday.setDay(day);
	birthday.setMonth(month);
	birthday.setYear(year);
}
member::member(const member& other)
{
	
	this->birthday = other.birthday;
}



 
void member::operator+=(member * newfriend)
{
	int flag = 1, logicalsize;

	for (vector<member*>::iterator t=friends.begin() ; t!=friends.end(); t++)
	{
		if (*t == newfriend)
		{
			cout << this->getName() << " and " << newfriend->getName() << " are already friends ";
			return;
		}
	}

	newfriend->friends.push_back(this);
	friends.push_back(newfriend);
	cout << this->getName() << " and " << newfriend->getName() << " are now friends " << endl;
	return;
}



void member::operator+=(fanPage *page)
{
	int flag = 1, logicalsizeofpage;


	for (vector<fanPage*>::iterator t = pageArr.begin(); t != pageArr.end(); t++)
	{
		if (*t == page)
		{
			cout << this->getName() << "already likes this page" << endl;
			return;
		}
	}

	this->pageArr.push_back( page);
	page->friends.push_back(this);
	cout << this->getName() << " now like the page " << page->getName();

}





void member::showPages()
{
	int i = 0;
	if (this->pageArr.size() == 0)
	{
		cout << this->getName() << " doesn't like any page" << endl;
	}
	else
	{
		vector<fanPage*>::iterator iter;
		cout << this->getName() << " is following the page:" << endl;
		for (iter = pageArr.begin(); iter!= pageArr.end(); iter++)
		{
			cout << i++ << ". ";
			(*iter)->getName();
			cout << endl;
			iter++;
		}
	}
}

member::~member()
{
	
	pageArr.clear();
}



