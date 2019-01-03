

#include "TextStatus.h"




TextStatus::TextStatus()
{
	Status();
	char text[30];
	int size;
	cout << "what on your mind today? " << endl;

	this->Post = new char[30];
	cin.ignore();
	cin.getline(this->Post, 30);
	//size = strlen(text);
	//cin.ignore();
	//strcpy(this->Post, text);

}
void TextStatus::show1()
{
	cout <<"the text is:\n"<< this->Post;
}


TextStatus::~TextStatus()
{
}
