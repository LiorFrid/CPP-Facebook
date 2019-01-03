

#include "TextStatus.h"




TextStatus::TextStatus()
{
	Status();
	int size;
	cout << "what on your mind today? " << endl;

	this->Post = new char[MAXSTATUS];
	cin.ignore();
	cin.getline(this->Post, MAXSTATUS);
	

}
void TextStatus::show1()
{
	cout <<"the text is:\n"<< this->Post;
}
bool TextStatus::operator==(TextStatus *post)
{
	int flag;
	flag = strcmp(this->Post, post->Post);
	if (flag == 0)
		return true; //same post
	else
		return false; // new post
}
TextStatus::TextStatus(const TextStatus& other)
{
	this->Post = other.Post; 
}
TextStatus::~TextStatus()
{
	delete[]this->Post;
}
