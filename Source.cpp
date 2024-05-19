#include<iostream>
#include<fstream>
#include <cstdlib>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Helper
{
public:
	static int StringLength(char* str)
	{
		int stringLen = 0;
		for (char* temp = str; *temp != '\0'; temp++)
			stringLen++;

		return stringLen;

	}
	static int StringLength(const char* str)
	{
		int stringLen = 0;
		for (const char* temp = str; *temp != '\0'; temp++)
			stringLen++;

		return stringLen;

	}
	static void StringCopy(char* dest, char* src)
	{
		char* tempDest = dest;
		for (char* tempSrc = src; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;
		}
		*tempDest = '\0';
	}
	static void StringCopy(char* dest, const char* src)
	{
		char* tempDest = dest;
		for (const char* tempSrc = src; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;
		}
		*tempDest = '\0';
	}
	static char* GetStringFromBuffer(char* buffer)
	{
		int strLen = StringLength(buffer);
		char* str = 0;
		if (strLen > 0)
		{
			str = new char[strLen + 1];
			StringCopy(str, buffer);
		}
		return str;

	}
	static char* GetStringFromBuffer(const char* buffer)
	{
		int strLen = StringLength(buffer);
		char* str = 0;
		if (strLen > 0)
		{
			str = new char[strLen + 1];
			StringCopy(str, buffer);
		}
		return str;

	}
	static int FindSubString(char* myStr, const char* strToFind)
	{
		int strLen1 = StringLength(myStr);
		int strLen2 = StringLength(strToFind);
		if (strLen2 > strLen1)
			return 0;
		bool found = false;
		for (int i = 0;i < strLen1;i++)
		{
			if (myStr[i] == strToFind[0] || myStr[i] == strToFind[0] + 32 || myStr[i] == strToFind[0] - 32)
			{
				for (int j = 0;j < strLen2;j++)
				{
					if (myStr[i + j] == strToFind[j] || myStr[i + j] == strToFind[j] + 32 || myStr[i + j] == strToFind[j] - 32)
						found = true;
					else
					{
						found = false;
						break;
					}
				}
				if (found == true && strLen1 == strLen2)
					return 1;   //if booth are equal
				if (found == true)
					return -1;    //if substring exists within string
			}
		}
		return 0;
	}
	static void StringConcatenate(char*& string1, char* string2)
	{
		int length1 = StringLength(string1);
		int length2 = StringLength(string2);
		int length = length1 + length2;
		char* temp = new char[length + 1];
		int tempPtr = 0;
		for (int i = 0;i < length1;i++)
			temp[tempPtr++] = string1[i];
		for (int i = 0;i < length2;i++)
			temp[tempPtr++] = string2[i];
		temp[tempPtr] = '\0';
		delete[]string1;
		string1 = temp;

	}
};


////////////////////////////////////////////////////////////////////////////////////////

class Post;
class Object;
class User;
class Post;
class Page;
class Date;
class Comment;
class Controller;

////////////////////////////////////////////////////////////////////////////////

class PostContent
{
public:
	virtual void printContent();
	virtual ~PostContent() { /* overridden */ }
};
void PostContent::printContent()
{
	//overriden in child classes
}

/////////////////////////////////////////////////////////////////

class Activity : public PostContent
{
	int type;
	char* value;
public:
	Activity();
	void printContent();
	void SetValues(int, char*);
	~Activity();
};
Activity::Activity()
{
	type = 0;
	value = 0;
}
void Activity::SetValues(int t, char* val)
{
	type = t;
	value = Helper::GetStringFromBuffer(val);
}
void Activity::printContent()
{
	cout << " is ";
	if (type == 1)
		cout << "feeling";
	else if (type == 2)
		cout << "thinking about";
	else if (type == 3)
		cout << "Making";
	else if (type == 4)
		cout << "celebrating";

	if (value != 0)
		cout << value;


}
Activity::~Activity()
{
	if (value)
		delete value;
}

////////////////////////////////////////////////////////////////////////////////////////

class Object
{
private:
	char* ID;
protected:
	Post** Timeline;
public:
	Object();

	void AddToTimeline(Post*);
	void setID(char*);
	char* getID();

	virtual void PrintInfo()
	{
		cout << ID;//names printed by child objects
	}
	virtual void PrintName()
	{
		//overriden in child functions
	}
	void ViewTimeline();
	void PrintLatestPosts();

	virtual ~Object();

};

class User : public Object
{
private:

	char* Fname;
	char* Lname;
	User** FriendList;//null or 10 pointers max
	Page** LikedPages;//null or 10 pointers max

public:
	User();
	void ReadDataFromFile(ifstream&);

	void AddFriend(User*&);
	void AddLikedPage(Page*&);

	void ViewFriendList();
	void ViewLikedPages();
	void ViewHome();
	void ViewMemories();
	void ViewTimeline();

	void PrintInfo();
	void PrintName();

	char* getFirstName();
	char* getLastName();

	~User();
};

////////////////////////////////////////////////////////////////////////////

class Comment
{
	char* ID;
	Object* CommentBy;
	char* Text;
	static int TotalComments;
public:
	Comment();
	Comment(User* user, const char* text);

	void setValues(char*, Object*, char*);
	void PrintComment();
	~Comment();

};
int Comment::TotalComments=0;
Comment::Comment()
{
	ID = 0;
	CommentBy = 0;
	Text = 0;
	TotalComments++;
}
Comment::Comment(User* user, const char* text)
{
	CommentBy = user;
	Text = Helper::GetStringFromBuffer(text);
	TotalComments++;

	char text2[5] = "post";
	char* temp = new char[50];
	Helper::StringCopy(temp, text2);

	char buffer[10];
	_itoa_s(TotalComments, buffer, 10);

	Helper::StringConcatenate(temp, buffer);
	ID = temp;
	
}
void Comment::setValues(char* cid, Object* objPtr, char* text)
{

	ID = Helper::GetStringFromBuffer(cid);
	CommentBy = objPtr;
	Text = Helper::GetStringFromBuffer(text);
}
void Comment::PrintComment()
{
	CommentBy->PrintName();
	cout << " : \"" << Text << "\"\n";
}
Comment::~Comment()
{
	if (ID)
		delete  ID;
	if (Text)
		delete Text;
	CommentBy = 0;
	TotalComments--;
}
//////////////////////////////////////////////////////////////////////

class Date
{
	int day;
	int month;
	int year;
public:
	static Date CurrentDate;

	Date(int, int, int);
	void ReadDataFromFile(ifstream&);

	int DateDiff();
	int YearDiff();

	void PrintDateDiff();
	void OutputDate();
	bool SameDate();
	static void setCurrentDate(int, int, int);
};
Date Date::CurrentDate(17, 4, 2024);
void Date::setCurrentDate(int d,int m,int y)
{
	CurrentDate.day = d;
	CurrentDate.month = m;
	CurrentDate.year = y;
}
Date::Date(int d = 0, int m = 0, int y = 0)
{
	day = d;
	month = m;
	year = y;
}
void Date::OutputDate()
{
	cout << day << "/" << month << "/" << year;
}
void Date::ReadDataFromFile(ifstream& fin)
{
	fin >> day;
	fin >> month;
	fin >> year;
}
void Date::PrintDateDiff()
{
	int Diff = DateDiff();
	if (Diff == 0)
		cout << " 1h ";
	else if (Diff < 7 && Diff> 0)
		cout << Diff << "d";
	else
		OutputDate();

}
int Date::DateDiff()
{
	if (day == CurrentDate.day && month == CurrentDate.month && year == CurrentDate.year)
		return 0;
	else if (month == CurrentDate.month && year == CurrentDate.year)
	{
		return (CurrentDate.day - day);
	}
	else
		return -1;
}
bool Date::SameDate()
{
	if (day == CurrentDate.day && month == CurrentDate.month && year != CurrentDate.year)
		return true;
	else
		return false;
}  
int Date::YearDiff()
{
	return (CurrentDate.year - year);
}

////////////////////////////////////////////////////////////////////////////////////////

class Post
{
	char* ID;
	char* Text;
	Object* SharedBy;
	Object** LikedBy;
	Comment** PostComments;
	PostContent* Content;
	Date SharedDate;
	static int PostCount;

public:
	Post();
	Post(const char*, User&);
	void ReadDataFromFile(ifstream&);

	void SetSharedBy(Object*);
	void AddLikedBy(Object*);
	void AddComment(Comment*);
	void AddComment(User*, const char*);
	void AddContent(PostContent*);

	void ViewLikedList();
	void PrintComments();
	virtual void PrintPost();
	void PrintOriginalPost();
	void printSharedByName();

	char* getText();
	char* getID();

	void PrintDateDifference();
	int GetDateDifference();
	bool SameDate();
	int yearDiff();

	virtual ~Post();

};
int Post::PostCount = 0;
Post::Post()
{
	PostCount++;
	ID = Text = 0;
	SharedBy = 0;
	LikedBy = 0;
	PostComments = 0;
	Content = 0;
}
Post::Post(const char* newText, User& currUser)
{

	Text = Helper::GetStringFromBuffer(newText);
	SharedBy = &currUser;
	SharedDate = Date::CurrentDate;

	char text[5] = "post";
	char* temp = new char[50];
	Helper::StringCopy(temp, text);

	PostCount++;
	char buffer[10];
	_itoa_s(PostCount, buffer, 10);
	
	Helper::StringConcatenate(temp,buffer);
	ID = temp;

	LikedBy = 0;
	PostComments = 0;
	Content = 0;

}
void Post::ReadDataFromFile(ifstream& fin)
{

	char temp[200];
	fin.getline(temp, 200, '\n');
	fin.getline(temp, 200);
	fin >> temp;
	ID = Helper::GetStringFromBuffer(temp);
	SharedDate.ReadDataFromFile(fin);
	fin.getline(temp, 200, '\n');
	fin.getline(temp, 200);
	Text = Helper::GetStringFromBuffer(temp);
}
void Post::SetSharedBy(Object* obj)
{
	SharedBy = obj;
}
void Post::AddLikedBy(Object* obj)
{

	if (LikedBy == 0)
	{
		LikedBy = new Object * [10];
		for (int i = 0;i < 10;i++)
			LikedBy[i] = 0;
	}
	for (int i = 0;i < 10;i++)
	{
		if (LikedBy[i] == 0)
		{

			LikedBy[i] = obj;
			break;
		}
	}

}
void Post::AddComment(Comment* comment)
{
	if (PostComments == 0)
	{
		PostComments = new Comment * [13];
		for (int i = 0;i < 13;i++)
			PostComments[i] = 0;

	}

	for (int i = 0;i < 13;i++)
	{
		if (PostComments[i] == 0)
		{
			PostComments[i] = comment;
			break;
		}
	}
}
void Post::AddComment(User* user, const char* text)
{
	if (PostComments == 0)
	{
		PostComments = new Comment * [13];
		for (int i = 0;i < 13;i++)
			PostComments[i] = 0;

	}

	for (int i = 0;i < 13;i++)
	{
		if (PostComments[i] == 0)
		{
			cout << "Command:\tPostComment(" << ID << "," << text << ")" << endl;

			PostComments[i] = new Comment(user, text);
			break;
		}
	}
}

void Post::AddContent(PostContent* temp)
{
	Content = temp;
}
void Post::PrintComments()
{
	if (PostComments != 0)
		for (int i = 0;PostComments[i] != 0;i++)
		{
			cout << "\t\t";
			PostComments[i]->PrintComment();
		}

}
void Post::PrintPost()
{
	cout << "\n--";
	SharedBy->PrintName();
	if (Content)
		Content->printContent();
	cout << " (";
	PrintDateDifference();
	cout << ") : \n";
	cout << "\t\"" << Text << "\"\n";
	PrintComments();
}
void Post::PrintOriginalPost()
{
	cout << "--";
	SharedBy->PrintName();
	if (Content)
		Content->printContent();
	cout << " (";
	PrintDateDifference();
	cout << ") : \n";
	cout << "\t\"" << Text << "\"\n";
}
void Post::ViewLikedList()
{
	cout << "\n------------------------------------------------";
	cout << "\nCommand :\tView Liked List (" << ID << ")";
	cout << "\n------------------------------------------------\n";
	cout << "Post Liked By : \n";
	if (LikedBy != 0)
		for (int i = 0;LikedBy[i] != 0;i++)
		{
			LikedBy[i]->PrintInfo();
		}
	cout << "------------------------------------------------\n";
}
char* Post::getID()
{
	return ID;
}
void Post::PrintDateDifference()
{
	SharedDate.PrintDateDiff();
}
int Post::GetDateDifference()
{
	return SharedDate.DateDiff();
}
char* Post::getText()
{
	return Text;
}
void Post::printSharedByName()
{
	SharedBy->PrintName();
}
bool Post::SameDate()
{
	return SharedDate.SameDate();
}
int Post::yearDiff()
{
	return SharedDate.YearDiff();
}

Post::~Post()
{
	if (ID)
		delete[] ID;
	if (Text != 0)
	{
		delete[] Text;
		Text = 0;
	}

	SharedBy = 0;
	if (LikedBy)
		delete LikedBy;

	if (PostComments)
	{
		for (int i = 0;i < 10;i++)
			delete PostComments[i];
	}

	delete[] PostComments;

	if (Content)
		delete Content;

	PostCount--;

}
////////////////////////////////////////////////////////////////////////////////////////

class Page : public Object
{
private:
	char* Title;

public:
	Page();

	void ReadDataFromFile(ifstream&);
	char* getTitle();

	void PrintInfo();
	void ViewPage();
	void PrintName();

	~Page();
};
Page::Page()
{
	Title = 0;
}
void Page::ReadDataFromFile(ifstream& fin)
{
	char temp[100];
	fin >> temp;
	setID(temp);
	fin.getline(temp, 80, '\t');
	fin.getline(temp, 50);
	Title = Helper::GetStringFromBuffer(temp);
}
void Page::PrintInfo()
{
	cout << getID() << "-" << Title << endl;
}

void Page::ViewPage()
{
	cout << "\n------------------------------------------------------------------------------";
	cout << "\nCommand :\tView Page (" << getID() << ")";
	cout << "\n------------------------------------------------------------------------------\n";
	ViewTimeline();

}
void Page::PrintName()
{
	cout << Title;
}
//Getters
char* Page::getTitle()
{
	return Title;
}

Page::~Page()
{

	if (Title)
		delete Title;
}


//////////////////////////////////////////////////////////////////

//User definitions 
User::User()
{
	Fname = 0;
	Lname = 0;
	FriendList = 0;
	LikedPages =0;
}
void User::ReadDataFromFile(ifstream& fin)
{
	char temp[50];
	fin >> temp;
	setID(temp);
	fin >> temp;
	Fname = Helper::GetStringFromBuffer(temp);
	fin >> temp;
	Lname = Helper::GetStringFromBuffer(temp);
}

void User::AddFriend(User*& Friend)
{
	if (FriendList == 0)
	{
		FriendList = new User * [10];
		for (int i = 0;i < 10;i++)
			FriendList[i] = 0;
	}
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		if (FriendList[i] == 0)
		{
			FriendList[i] = Friend;
			break;
		}
	}
}
void User::AddLikedPage(Page*& page)
{
	if (LikedPages == 0)
	{
		LikedPages = new Page * [10];
		for (int i = 0;i < 10;i++)
			LikedPages[i] = 0;
	}
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		if (LikedPages[i] == 0)
		{
			LikedPages[i] = page;
			break;
		}
	}
}

void User::ViewFriendList()
{
	cout << "\n------------------------------------------------";
	cout << "\nCommand :\tView Friend List ";
	cout << "\n------------------------------------------------\n";
	cout << Fname << " " << Lname << " - Friend List " << endl << endl;

	if(FriendList!=0)
	for (int i = 0;i < 10;i++)
	{
		if (FriendList[i] != 0)
		{
			cout << FriendList[i]->getID() << " - ";
			cout << FriendList[i]->Fname << " " << FriendList[i]->Lname << endl;
		}
	}
	cout << "------------------------------------------------\n";

}
void User::ViewLikedPages()
{
	cout << "\n------------------------------------------------";
	cout << "\nCommand :\tView Liked Pages ";
	cout << "\n------------------------------------------------\n";
	cout << Fname << " " << Lname << " - Liked Pages " << endl << endl;

	if(LikedPages!=0)
	for (int i = 0;i < 10;i++)
	{
		if (LikedPages[i] != 0)
		{
			cout << LikedPages[i]->getID() << " - ";
			cout << LikedPages[i]->getTitle() << endl;
		}
	}
	cout << "------------------------------------------------\n\n";
}
void User::ViewHome()
{
	cout << "\n--------------------------------------------------------------------------------";
	cout << "\nCommand :\tView Home (" << getID() << ")";
	cout << "\n--------------------------------------------------------------------------------\n";
	cout << Fname << " " << Lname << " - Home Page " << endl;
	PrintLatestPosts();

	if(FriendList!=0)
		for (int i = 0;i < 10;i++)
		{
			if (FriendList[i] != 0)
				FriendList[i]->PrintLatestPosts();
		}

	if(LikedPages!=0)
		for (int i = 0;i < 10;i++)
		{
			if (LikedPages[i] != 0)
				LikedPages[i]->PrintLatestPosts();
		}


	cout << "--------------------------------------------------------------------------------\n";

}
void User::ViewMemories()
{
	cout << "--------------------------------------------------------------------------------";
	cout << "\nCommand :\tView Memories ";
	cout << "\n--------------------------------------------------------------------------------\n";
	cout << "\n**We hope you enjoy looking back and sharing your memories on Facebook,**";
	cout << " \n\t\t**from the most recent to those long ago.** \n\n";
	cout << "On This Day\n";

	if(Timeline!=0)
	for (int i = 0;Timeline[i] != 0;i++)
	{
		if (Timeline[i]->SameDate())
		{
			cout << " " << Timeline[i]->yearDiff() << " Years Ago\n";
			Timeline[i]->PrintPost();
		}
	}
	cout << "\n---------------------------------------------------------------------------------\n";
}
void User::ViewTimeline()
{
	cout << "-------------------------------------------------------------\n";
	cout << "Command :\tView Timeline \n";
	cout << "-------------------------------------------------------------\n";
	Object::ViewTimeline();
}
void User::PrintInfo()
{
	cout << getID() << "-" << Fname << " " << Lname << endl;
}
void User::PrintName()
{
	cout << Fname << " " << Lname;
}

//Getters
char* User::getFirstName()
{
	return Fname;
}
char* User::getLastName()
{
	return Lname;
}

User::~User()
{
	if (Fname)
		delete Fname;
	if (Lname)
		delete Lname;
	if (FriendList)
	{
		delete FriendList;
	}

	if (LikedPages)
	{
		delete LikedPages;
	}
}

////////////////////////////////////////////////////////////////////////////////////////

class Memory : public Post
{
	Post* OriginalPost;
public:
	Memory(const char*, Post*, User&);
	virtual void PrintPost();
	~Memory();
};
Memory::Memory(const char* newText, Post* Original, User& currUser) : Post(newText, currUser)
{
	OriginalPost = Original;

	//indicates that we are adding a new memory
	cout << "Command:\tShareMemory(" << OriginalPost->getID() << ",\"" << newText << "\")" << endl;
}
void Memory::PrintPost()
{
	cout << "\n\n~~~";
	printSharedByName();
	cout << " shared a memory ~~~ ";
	cout << " (";
	PrintDateDifference();
	cout << ") : \n";
	cout << "\t\"" << getText() << "\"\n";
	cout << " ~~~ " << OriginalPost->yearDiff() << " years ago ~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	OriginalPost->PrintOriginalPost();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	PrintComments();

}
Memory::~Memory()
{
	OriginalPost = 0;
}
/////////////////////////////////////////////////////////////////////

//Object Definitions

Object::Object()
{
	Timeline = 0;
	ID = 0;
}
void Object::AddToTimeline(Post* post)
{
	if (!Timeline)
	{
		Timeline = new Post * [10];
		for (int i = 0;i < 10;i++)
			Timeline[i] = 0;
	}
	for (int i = 0;i < 10;i++)
	{
		if (Timeline[i] == 0)
		{
			Timeline[i] = post;
			break;
		}
	}

}
void Object::setID(char* temp)
{
	ID = Helper::GetStringFromBuffer(temp);
}
char* Object::getID()
{
	return ID;
}
void Object::PrintLatestPosts()
{
	if (Timeline != 0)
		for (int i = 0;i < 10;i++)
		{
			if (Timeline[i] != 0)
			{
				int DateDifference = Timeline[i]->GetDateDifference();
				if (DateDifference >= 0 && DateDifference <= 2)
					Timeline[i]->PrintPost();
			}
		}
}
void Object::ViewTimeline()
{
	cout << "\n ** ";
	PrintName();
	cout << " **\n";
	if (Timeline != 0)
		for (int i = 0;Timeline[i] != 0;i++)
		{
			Timeline[i]->PrintPost();
		}
	else
		cout << "\n--No Posts Yet-- \n";
	cout << "-----------------------------------------------------------------------------\n";
}
Object::~Object()
{
	if (ID)
		delete ID;
	if (Timeline)
	{
		for (int i = 0;i < 10;i++)
		{
			if (Timeline[i])
				delete Timeline[i];
		}
		delete[] Timeline;
	}
}


////////////////////////////////////////////////////////////////////////////////////////

class Controller
{
private:
	User** AllUsers;
	Page** AllPages;
	Post** AllPosts;
	int totalUsers;
	int totalPages;
	int TotalPosts;
	User* CurrentUser;
public:

	void LoadData();
	void LoadAllUsers(const char*);
	void LoadAllPages(const char*);
	void LinkUsersAndPages(const char*);
	void LoadAllPosts(const char*);
	void LoadAllComments(const char*);
	void LoadAllActivities(const char*);


	User* SearchUserByID(const char*);
	Page* SearchPageByID(const char*);
	Post* SearchPostByID(const char*);
	Object* SearchObjectByID(const char*);

	void setCurrentUser(const char*);
	void setCurrentDate(int,int,int);
	void Run();
	~Controller();
};

void Controller::LoadData()
{
	LoadAllUsers("SocialNetworkUsers.txt");
	LoadAllPages("SocialNetworkPages.txt");
	LinkUsersAndPages("UsersFriendsAndLikedPages.txt");
	LoadAllPosts("SocialNetworkPosts.txt");
	LoadAllComments("SocialNetworkComments.txt");
	LoadAllActivities("SocialNetworkActivities.txt");
}
void Controller::setCurrentUser(const char* user)
{
	CurrentUser = SearchUserByID(user);
	cout << "Command :\tSet current User \"" << CurrentUser->getID() << "\"\n";
	cout << CurrentUser->getFirstName() << " " << CurrentUser->getLastName() << " Successfully set as current User \n";
	cout << "\n***************************************************************************************\n";
}
void Controller::setCurrentDate(int d,int m,int y)
{
	cout << "\nCommand:\tSet current System Date "<<d<<" "<<m<<" "<<y;
	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "System Date : ";
	Date::setCurrentDate(d, m, y);
	Date::CurrentDate.OutputDate();
	cout << "\n-------------------------------------------------------------------------------\n\n";

}
void Controller::Run()
{
	Post* postPtr = 0;
	Page* pagePtr = 0;

	//setting current date
	setCurrentDate(17, 4, 2024);
	//For setting current user
	setCurrentUser("u7");

	//Command Execution
	CurrentUser->ViewFriendList();
	cout << "\n***************************************************************************************\n";
	CurrentUser->ViewLikedPages();
	cout << "\n***************************************************************************************\n";
	CurrentUser->ViewTimeline();
	cout << "\n***************************************************************************************\n";

	postPtr = SearchPostByID("post5");

	postPtr->ViewLikedList();
	cout << "\n***************************************************************************************\n";
	cout << "Command :\tLike Post (" << postPtr->getID() << ")\n";
	postPtr->AddLikedBy(CurrentUser);   //Likes a post 
	cout << "\n***************************************************************************************\n";
	postPtr->ViewLikedList();
	cout << "\n***************************************************************************************\n";


	pagePtr = SearchPageByID("p1");
	pagePtr->ViewPage();
	cout << "\n***************************************************************************************\n";
	CurrentUser->ViewHome();
	cout << "\n***************************************************************************************\n\n";

	postPtr = SearchPostByID("post4");
	postPtr->AddComment(CurrentUser, "Good Luck for your Result");
	cout << "-----------------------------------------------------\n";
	cout << "Command :\tView Post (" << postPtr->getID() << ")\n\n";
	postPtr->PrintPost();
	cout << "\n***************************************************************************************\n\n";


	postPtr = SearchPostByID("post8");
	postPtr->AddComment(CurrentUser, "Thanks for the wishes");
	cout << "-----------------------------------------------------\n";
	cout << "Command :\tView Post (" << postPtr->getID() << ")\n\n";
	postPtr->PrintPost();
	cout << "\n***************************************************************************************\n\n";


	CurrentUser->ViewMemories();
	cout << "\n***************************************************************************************\n\n";
	postPtr = SearchPostByID("post10");
	Memory* ptr = new Memory("Never thought I will be specialist in this field...", postPtr, *CurrentUser);
	CurrentUser->AddToTimeline(ptr);
	cout << "\n***************************************************************************************\n";
	CurrentUser->ViewTimeline();

}

void Controller::LoadAllUsers(const char* UsersFile) {
	ifstream fin;
	fin.open(UsersFile);
	if (fin)
	{
		fin >> totalUsers;
		AllUsers = new User * [totalUsers];
		for (int i = 0;i < totalUsers;i++)
		{
			AllUsers[i] = new User;
			AllUsers[i]->ReadDataFromFile(fin);
		}
	}
	else
		cout << "Cant open file " << UsersFile;
}
void Controller::LoadAllPages(const char* PagesFile) {
	ifstream fin;
	fin.open(PagesFile);
	if (fin)
	{
		fin >> totalPages;
		AllPages = new Page * [totalPages];
		for (int i = 0;i < totalPages;i++)
		{
			AllPages[i] = new Page;
			AllPages[i]->ReadDataFromFile(fin);
		}
	}
	else
		cout << "Cant open file " << PagesFile;
}
void Controller::LinkUsersAndPages(const char* File)
{
	ifstream fin;
	fin.open(File);
	if (!fin)
	{
		cout << "Cant open file " << File;
		return;
	}
	char uID[4];
	char friendID[4];
	char LikedPages[4];

	fin >> uID;
	while (uID[0] != '-' || uID[1] != '1')
	{
		User* temp = SearchUserByID(uID);

		//for linking friends
		fin >> friendID;
		while (friendID[0] != '-' || friendID[1] != '1')
		{
			User* temp2 = SearchUserByID(friendID);
			temp->AddFriend(temp2);
			fin >> friendID;
		}

		//for linking pages
		fin >> LikedPages;
		while (LikedPages[0] != '-' || LikedPages[1] != '1')
		{
			Page* temp2 = SearchPageByID(LikedPages);
			temp->AddLikedPage(temp2);
			fin >> LikedPages;
		}

		fin >> uID;
	}
}
void Controller::LoadAllPosts(const char* File)
{
	ifstream fin;
	fin.open(File);
	if (!fin)
	{
		cout << "Cant open file " << File;
		return;
	}
	char obj[4];
	fin >> TotalPosts;
	AllPosts = new Post * [TotalPosts];
	for (int i = 0;i < TotalPosts;i++)
	{
		AllPosts[i] = new Post;
		AllPosts[i]->ReadDataFromFile(fin);
		fin >> obj;
		Object* ptr = SearchObjectByID(obj);
		AllPosts[i]->SetSharedBy(ptr);
		ptr->AddToTimeline(AllPosts[i]);
		fin >> obj;
		while (obj[0] != '-' || obj[1] != '1')
		{
			ptr = SearchObjectByID(obj);
			AllPosts[i]->AddLikedBy(ptr);
			fin >> obj;
		}
	}
}
void Controller::LoadAllComments(const char* File)
{
	ifstream fin;
	fin.open(File);
	if (!fin)
	{
		cout << "Cant open file " << File;
		return;
	}
	char cid[4];
	char obj[4];
	char postID[10];
	char text[200];
	int TotalComments;
	fin >> TotalComments;
	for (int i = 0;i < TotalComments;i++)
	{
		Comment* cptr = new Comment;
		fin >> cid;

		fin >> postID;
		Post* postPtr = SearchPostByID(postID);
		postPtr->AddComment(cptr);

		fin >> obj;
		Object* objPtr = SearchObjectByID(obj);

		fin.getline(text, 20, '\t');
		fin.getline(text, 200);
		cptr->setValues(cid, objPtr, text);

	}
}
void Controller::LoadAllActivities(const char* File)
{
	ifstream fin;
	fin.open(File);
	if (!fin)
	{
		cout << "Cant open file " << File;
		return;
	}
	char postID[10];
	char activity[100];
	int type;
	int Total;
	fin >> Total;
	for (int i = 0;i < Total;i++)
	{
		Activity* ptr = new Activity;

		fin >> postID;
		Post* postPtr = SearchPostByID(postID);
		postPtr->AddContent(ptr);

		fin >> type;

		fin.getline(activity, 100);
		ptr->SetValues(type, activity);

	}
}
Object* Controller::SearchObjectByID(const char* ID)
{
	if (ID[0] == 'u')
		return SearchUserByID(ID);
	else if (ID[0] == 'p')
		return SearchPageByID(ID);
	else return 0;
}
User* Controller::SearchUserByID(const char* uID)
{
	for (int i = 0;i < totalUsers;i++)
	{
		if (Helper::FindSubString(AllUsers[i]->getID(), uID) == 1)
			return AllUsers[i];
	}
	return 0;
}
Page* Controller::SearchPageByID(const char* pID)
{
	for (int i = 0;i < totalPages;i++)
	{
		if (Helper::FindSubString(AllPages[i]->getID(), pID) == 1)
			return AllPages[i];
	}
	return 0;
}
Post* Controller::SearchPostByID(const char* pID)
{
	for (int i = 0;i < TotalPosts;i++)
	{
		if (Helper::FindSubString(AllPosts[i]->getID(), pID) == 1)
			return AllPosts[i];
	}
	return 0;
}

Controller::~Controller()
{
	for (int i = 0;i < totalUsers;i++)
	{
		if (AllUsers[i])
			delete AllUsers[i];
	}
	if (AllUsers)
		delete[]AllUsers;

	for (int i = 0;i < totalPages;i++)
	{
		if (AllPages[i])
			delete AllPages[i];
	}
	if (AllPages)
		delete[]AllPages;

	if (AllPosts)
		delete[]AllPosts;

}


int main()
{
	{
		Controller mainApp;
		mainApp.LoadData();
		mainApp.Run();
	}
	cout << _CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}