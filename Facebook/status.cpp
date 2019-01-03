#include "status.h"
#pragma warning (disable : 4996)

const char* KINDS[] = { "text","photo","video" };


Status::Status() {
	Time PostTime;
	Date PostDate;
	this->post = nullptr;

	
	//set the current time of the post

	time_t rawtime;
	tm timeinfo;
	time(&rawtime);
	errno_t result = localtime_s(&timeinfo, &rawtime);

	PostTime.sethour(timeinfo.tm_hour);
	PostTime.setminutes(timeinfo.tm_min);
	this->postTime = PostTime;
	PostDate.setDay(timeinfo.tm_mday);
	PostDate.setMonth(timeinfo.tm_mon + 1);
	PostDate.setYear(timeinfo.tm_year + 1900);
	this->postDate = PostDate;
}

char * Status::GetTheStatus()const
{
	return this->post;

}
void Status::show()
{
	this->postDate.ShowDate();
	cout << " ";
	this->postTime.showTime();
	this->show1();
	/*if (this->kind == text)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}
	if (this->kind == photo)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}
	if (this->kind == video)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}

	cout << "\n";*/
}

int Status::compare(Status *statusToCheck)
{
	if (postDate.getYear() < statusToCheck->postDate.getYear())
		return 1;
	else if (postDate.getMonth() < statusToCheck->postDate.getMonth())
		return 1;
	else if (postDate.getDay() < statusToCheck->postDate.getDay())
		return 1;
	else if (postTime.gethour() < statusToCheck->postTime.gethour())
		return 1;
	else if (postTime.getminutes() < statusToCheck->postTime.getminutes())
		return 1;
	else
		return 0;
}
bool Status::operator==(Status *post)
{
	int flag;
	flag = strcmp(this->post, post->post);
	if (flag == 0)
		return true; //same post
	else
		return false; // new post
}



Date Status::GetStatusDate()const
{
	return this->postDate;

}
Status::~Status()
{
	delete[]post;
}
Status::Status(const Status&other)
{
	this->kind = other.kind;
	this->postDate = other.postDate;
	this->postTime = other.postTime;
	int i, size = strlen(other.post);
	post = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		post[i] = other.post[i];

	}
	post[i] = '\0';
}
