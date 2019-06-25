//--------------------DramaMovie.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementaion file for the DramaMovie class
//contains comparison functions as well as
// display
//-----------------------------------------------

#include "DramaMovie.h"


DramaMovie::DramaMovie() : Movie('D')  // constructor
{
}

DramaMovie::~DramaMovie()  // deconstructor
{
}

// Greater than operator
bool DramaMovie:: operator > (const Movie & inputMov)
{
	if (GetDirector() > inputMov.GetDirector())
	{
		return true;
	}
	else if (GetDirector() < inputMov.GetDirector())
	{
		return false;
	}
	else
	{
		if (GetTitle() > inputMov.GetTitle())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

// less than operator
bool DramaMovie:: operator < (const Movie & inputMov)
{
	if (GetDirector() < inputMov.GetDirector())
	{
		return true;
	}
	else if (GetDirector() > inputMov.GetDirector())
	{
		return false;
	}
	else
	{
		if (GetTitle() < inputMov.GetTitle())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

// equals operator
bool DramaMovie:: operator == (const Movie & inputMov)
{
	if (GetDirector() == inputMov.GetDirector() && GetTitle() == inputMov.GetTitle())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// display drama movie info
void DramaMovie::OutputInfo()
{
	cout << endl << Genre << " " << "Total Stock:" << setw(2) << left << TotalStock << " Current Stock:" << setw(2)
		<< CurrentStock << setw(10) <<" Director:"<< setw(20) << Director
		<< setw(6)<< " Title:"<< setw(30) << left <<Title<<setw(10) <<" Release:"<<setw(30) << ReleaseYear;
}
