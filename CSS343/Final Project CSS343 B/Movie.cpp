//--------------------Movie.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementaion file for the Movie class
//contains
//-----------------------------------------------


#include"Movie.h"

Movie::Movie()  // constructor
{
}

Movie::Movie(char genre)  // movie constructor with genre
{
	TotalStock = 0;
	CurrentStock = 0;
	Director = "";
	Title = "";
	ReleaseYear = 0;
	ReleaseMonth = 0;
	MajorActorFname = "";
	MajorActorLname = "";
	Genre = genre;
}

Movie::~Movie()  //deconstructor
{
}

//---------------Getters/setters---------------
string Movie::GetTitle() const
{
	return Title;
}

string Movie::GetDirector()const
{
	return Director;
}
int Movie::GetReleaseYear()const
{
	return ReleaseYear;
}
char Movie::GetGenre()const
{
	return Genre;
}
int Movie::GetReleaseMonth()const
{
	return ReleaseMonth;
}
string Movie::GetMajorActorFname()const
{
	if (MajorActorFname == "")
	{
		return"No Major Actor for This Movie";
	}
	return MajorActorFname;
}
string Movie::GetMajorActorLname()const
{
	if (MajorActorLname == "")
	{
		return"No Major Actor for This Movie";
	}
	return MajorActorLname;
}
bool Movie::setData(ifstream & fin)
{
	string empty;
	getline(fin, empty, ',');
	fin >> TotalStock;
	CurrentStock = TotalStock;
	getline(fin, empty, ',');
	getline(fin, Director, ',');
	getline(fin, Title, ',');
	fin >> ReleaseYear;
	return true;

}
int Movie::GetTotalStock()const
{
	return TotalStock;

}
int Movie::GetCurrentStock()const
{
	return CurrentStock;
}
void Movie::SetTotalStock(int inputStock)
{
	TotalStock = inputStock;
}
void Movie::SetCurrentStock(int inputStock)
{
	CurrentStock = inputStock;
}

void Movie::setReleaseMonth(int inputMonth)
{
	ReleaseMonth = inputMonth;
}

void Movie::SetFname(string inputName)
{
	MajorActorFname = inputName;
}

void Movie::SetLname(string inputLname)
{
	MajorActorLname = inputLname;
}

void Movie::SubtractOneCurrentStock()
{
	CurrentStock -= 1;
}

void Movie::AddOneCurrentStock()
{
	CurrentStock += 1;
}

void Movie::SetTitle(string inputTitle)
{
	Title = inputTitle;
}

void Movie::SetReleaseYear(int inputYear)
{
	ReleaseYear = inputYear;
}

void Movie::SetDirector(string inputDirector)
{
	Director = inputDirector;
}
