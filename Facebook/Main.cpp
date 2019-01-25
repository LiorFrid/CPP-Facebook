#include <iostream>
using namespace std;
#include "Date.h"
#include "Facebook.h"
#include "member.h"
#include "Time.h"
//doh type?


void MenuStatus(Facebook * myFace)
{
		int  index;
		member * user;
		fanPage *fan;
		if ((*myFace).GetNumOfEntities() == 0)
		{
			cout << "we cannot post any status as there are no members of pages, going to back screen\n";
			return;
		}
		cout << "choose fanPage or members\n1.members\n2.fanpages" << endl;
		cin >> index;
		if (index == 1)
		{
			if ((*myFace).GetNumOfMember() == 0)
			{
				cout << "there are no active users";
				getchar();
				return;
			}
			(*myFace).ShowMembers();
			cout << "Choose the member you would like to post a status from" << endl;
			cin >> index;
			user = (*myFace).GetMember(index);
			user->WritePost();
		}
		else
		{
			if ((*myFace).GetNumOfPages() == 0)
			{
				cout << "there are no active Fan Pages";
				getchar();
				return;
			}
			(*myFace).ShowFanPage();
			cout << "Choose the member you would like to post a status from" << endl;
			cin >> index;
			fan = (*myFace).GetFanPage(index);
			fan->WritePost();
		}
}

void MenuShowLast10(Facebook * myFace)
{
	int index;
	member * user;
	if((*myFace).GetNumOfMember() <2)
	{
		cout << "This function is not available when there are less than 2 members\n ";
			return;
	}
	cout << "Choose the member which you'd like to see the last 10 statuses his friends posted" << endl;
	(*myFace).ShowMembers();
	cin >> index;
	user = (*myFace).GetMember(index);
	user->showLastTenFriendsStatuses();

}

void MenuMakeFriends(Facebook * myFace)
{
	if ((*myFace).GetNumOfMember() < 2)
	{
		cout << "there are less than 2 member, we are going to the main screen";
		getchar();
		return;
	}
	myFace->setfriendship();
}


void MenuLikePage(Facebook * myFace)
{
	if ((*myFace).GetNumOfPages() == 0)
	{
		cout << "there are still no fan pages at the site, back to the main screen";
		getchar();

	}
	myFace->LikePage();
}

void MenuShowFaceEntities(Facebook * myFace)
{
	cout << endl << "Facebook members:" << endl;
	(*myFace).ShowMembers();
	cout << endl << "Facebook pages:" << endl;
	(*myFace).ShowFanPage();
}

void MenuShowFriends(Facebook * myFace)
{
	member *TheMember;
	int NumOfFriend;
	if ((*myFace).GetNumOfMember() < 2)
	{
		cout << "This function is not available when there are less than 2 members\n ";
		return;

	}
	cout << endl << "choose the member you'd like to check his friends" << endl;
	(*myFace).ShowMembers();
	cin >> NumOfFriend;
	TheMember = (*myFace).GetMember(NumOfFriend);

	(*TheMember).showFriends();
}

void MenuShowFriendsOfPage(Facebook * myFace)
{
	int NumOfPage,checkentities=1;
	fanPage *page;
	if ((*myFace).GetNumOfPages() == 0)
	{
		cout << endl << "No pages just yet";
		return;
	}
	cout << endl << "choose the member you'd like to check his friends" << endl;

	(*myFace).ShowFanPage();
	cout << "your decision : ";
	cin >> NumOfPage;
	page = (*myFace).GetFanPage(NumOfPage);
	(*page).showFriends();
	cout << endl << endl;
}

void Extra(Facebook * myFace)
{
	int firstindex, secondindex;
	entity *first, *second;
	cout << endl << "time to compare two facebook entities based on number of followers" << endl;
	myFace->ShowMembers();
	cout << endl << "From the below users, choose the numbers of the two you want to compare " << endl;
	myFace->ShowMembers();
	cout << "\nfirst member : ";
	cin >> firstindex;
	cout << "\nsecond member : ";
	cin >> secondindex;
	first = myFace->GetMember(firstindex);
	second = myFace->GetMember(secondindex);
	*first > second;
}

int menu(Facebook *myFace)
{
	cout << endl << "1. add member \n2. add fan page \n3. add status\n4. show last 10 statuses\n5. add friendship\n6. add fan to page\n7. show all members and pages\n8. show all friends of member\n9. show all fans of page\n10.extra\n11.exit" << endl;
	int choice = 0;
	cin >> choice;
	while (choice > 11 || choice < 1)
	{
		cout << "please make sure to enter the correct number\n";
		cin >> choice;
	}
	system("cls");
	switch (choice) {
	case 1: (*myFace).AddMember();
		break;
	case 2: (*myFace).AddFanFage();
		break;
	case 3: MenuStatus(myFace);
		break;
	case 4: MenuShowLast10(myFace);
		break;
	case 5: MenuMakeFriends(myFace);
		break;
	case 6:  MenuLikePage(myFace);
		break;
	case 7:  MenuShowFaceEntities(myFace);
		break;
	case 8:  MenuShowFriends(myFace);
		break;
	case 9:  MenuShowFriendsOfPage(myFace);
		break;
	case 10: Extra(myFace);
		break;
	}
	return choice;
}

void banner()
{

	cout << R"(

 ____ _             _   _                ______             _                 _    
|_   _| |          | \ | |               |  ___|           | |               | |   
  | | | |__   ___  |  \| | _____      __ | |_ __ _  ___ ___| |__   ___   ___ | | __
  | | | '_ \ / _ \ | . ` |/ _ \ \ /\ / / |  _/ _` |/ __/ _ \ '_ \ / _ \ / _ \| |/ /
  | | | | | |  __/ | |\  |  __/\ V  V /  | || (_| | (_|  __/ |_) | (_) | (_) |   < 
  \_/ |_| |_|\___| \_| \_/\___| \_/\_/   \_| \__,_|\___\___|_.__/ \___/ \___/|_|\_\
                                                                                   

)";
}
void main()
	{
	banner();
	banner();
	cout << "WELCOME TO THE NEW GENERATION OF FACEBOOK!!!" << endl << endl;
	Facebook myface;
	int choice;
	choice = menu(&myface);
	while (choice <= 10 && choice>0)
	{
		choice = menu(&myface);

	}
}
