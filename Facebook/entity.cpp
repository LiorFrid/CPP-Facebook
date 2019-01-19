
#include "entity.h"
#include "Time.h"
#include "facebook.h"






entity::entity(string name, member ** friends)
{
	this->name = name;

}

void entity::setName(const string name)
{
	this->name = name;
}



void entity::WritePost()
{
	int i = 0, duppost = 0;
	Status * newstatus;
	cout << "1. Text Status\n2. Picture Status\n3. Video Status\n4. Text and Picture Status\n5. Video and Text Status\n";
	int x;
	cin >> x;
	if(x==1)
		 newstatus = new TextStatus[1];
	else if (x==2)
	     newstatus = new PictureStatus[1];
	else if(x==3)
		 newstatus = new VideoStatus[1];
	else if(x==4)
		 newstatus = new TextAndPicture[1];
	else
		 newstatus = new TextVideo[1];

	TextStatus *check1, *check2;
	int flag = 0;
	if (x == 1)
	{
		check1 = dynamic_cast<TextStatus*>(newstatus);
		vector<Status*>::iterator StatusIter;
		for (StatusIter=MemberStatus.begin(); StatusIter!= MemberStatus.end(); StatusIter++)
		{
			check2=  dynamic_cast<TextStatus*> (*StatusIter);
			
			if (check1&&check2)
			{
				duppost = *check2 != check1;

				if (duppost == 0) //means it is the same post
				{
					flag = 1;
					cout << "unfortunately " << this->getName() << " already has the same post in his wall, nothing was added";
					
				}
			}
		}
	}
	if (flag == 0)
	{
		this->MemberStatus.push_back (newstatus);

	}
}



void entity::showFriends()
{
	int i = 0;
	if (this->friends.size() == 0)
	{

		cout << this->getName() << " has no Facebook friends" << endl; ///fix this!!!!
	}
	else
	{
		cout << this->getName() << "'s Facebook's friends are:" << endl;
		vector<member*>::iterator FriendIter;
		for (FriendIter=friends.begin(); FriendIter != friends.end(); FriendIter++)
		{
			cout << i << ".  " << (*FriendIter)->getName() << endl;
			//cout << i << ". " <<this->friends->show << endl;
			i++;
		}
	}
}



void  entity::operator>(entity *other)
{
	if (friends.size() > other->friends.size())
		cout << this->getName() << "'s number of followers (" << friends.size() << ") is higher than " << other->getName() << "'s (" << other->friends.size() << ")\n";
	if (friends.size() < other->friends.size())
		cout << other->getName() << "'s number of followers (" << other->friends.size() << ") is higher than " << this->getName() << "'s (" << friends.size() << ")\n";
	if (friends.size() == other->friends.size())
		cout << "both " << other->getName() << " and " << this->getName() << " as the same number of followers - " << friends.size() << "\n";
}

entity::~entity()
{
	
	//need to clear all friends
	friends.clear();
	//need to clear all status
	MemberStatus.clear();
}
