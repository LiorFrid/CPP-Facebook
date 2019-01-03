
#include "entity.h"
#include "Time.h"
#include "facebook.h"



void  entity::AllocateMemoryFriends()
{

	physicSizeOfFriends *= 2;
	member** tempArry = new member*[physicSizeOfFriends];
	for (int i = 0; i < logicSizeOfFriends; i++)
	{
		tempArry[i] = friends[i];
	}
	delete[] friends;
	this->friends = tempArry;

}




void  entity::AllocateMemoryStatus()
{

	physicSizeOfStatus *= 2;
	Status ** tempArry = new Status*[physicSizeOfStatus];
	for (int i = 0; i < logicSizeOfStatus; i++)
	{
		tempArry[i] = MemberStatus[i];
	}
	delete[] MemberStatus;
	this->MemberStatus = tempArry;

}




entity::entity(char name[MAXNAME], member ** friends)
{
	this->name = name;

}

void entity::setName(char *name)
{
	this->name = name;
}

entity::entity(const entity& other)
{
	int i, size = strlen(other.name);
	name = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		name[i] = other.name[i];

	}
	name[i] = '\0';
	//strcpy(name, other.name);	
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
		for (i = 0; i < logicSizeOfStatus; i++)
		{
			check2=  dynamic_cast<TextStatus*>(this->MemberStatus[i]);
			
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
		this->MemberStatus[this->logicSizeOfStatus] = newstatus;

		logicSizeOfStatus++;
		if (logicSizeOfStatus == physicSizeOfStatus)
			AllocateMemoryStatus();
	}
}



void entity::showFriends()
{
	if (logicSizeOfFriends == 0)
	{

		cout << this->getName() << " has no Facebook friends" << endl; ///fix this!!!!
	}
	else
	{
		cout << this->getName() << "'s Facebook's friends are:" << endl;
		for (int i = 0; i < logicSizeOfFriends; i++)
		{
			cout << i << ".  " << friends[i]->getName() << endl;
			//cout << i << ". " <<this->friends->show << endl;
		}
	}
}



void  entity::operator>(entity *other)
{
	if (logicSizeOfFriends > other->logicSizeOfFriends)
		cout << this->getName() << "'s number of followers (" << logicSizeOfFriends << ") is higher than " << other->getName() << "'s (" << other->logicSizeOfFriends << ")\n";
	if (logicSizeOfFriends < other->logicSizeOfFriends)
		cout << other->getName() << "'s number of followers (" << other->logicSizeOfFriends << ") is higher than " << this->getName() << "'s (" << logicSizeOfFriends << ")\n";
	if (logicSizeOfFriends == other->logicSizeOfFriends)
		cout << "both " << other->getName() << " and " << this->getName() << " as the same number of followers - " << logicSizeOfFriends << "\n";
}

entity::~entity()
{
	delete[] name;
	delete[] friends;
	delete[] MemberStatus;
}
