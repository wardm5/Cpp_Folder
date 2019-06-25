//--------------------ComedyMovie.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementaion file for the Store class
//contains comparison functions as well as
// display
//-----------------------------------------------

#include "ComedyMovie.h"
ComedyMovie::ComedyMovie() : Movie('F') // constructor
{
}


ComedyMovie::~ComedyMovie()  // deconstructor
{
}

bool ComedyMovie:: operator > (const Movie & inputMov)  // greater than operator
{
	if (GetTitle() > inputMov.GetTitle())
	{
		return true;
	}
	else if (GetTitle() < inputMov.GetTitle())
	{
		return false;
	}
	else
	{
		if (GetReleaseYear() > inputMov.GetReleaseYear())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

bool ComedyMovie:: operator < (const Movie & inputMov)  // less than operator
{
	if (GetTitle() < inputMov.GetTitle())  
	{
		return true;
	}
	else if (GetTitle() > inputMov.GetTitle())
	{
		return false;
	}
	else
	{
		if (GetReleaseYear() < inputMov.GetReleaseYear())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool ComedyMovie:: operator == (const Movie & inputMov) // equals to operator
{
	if (GetTitle() == inputMov.GetTitle() && GetReleaseYear() == inputMov.GetReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ComedyMovie::OutputInfo() // display
{
	cout << endl << Genre << " " << "Total Stock:" << setw(2) << left << TotalStock << "Current Stock:" << setw(2)
		<< CurrentStock << setw(6) << " Title:" << setw(32) << Title << setw(10)
		<< " Release:" << setw(10) << left<< ReleaseYear << setw(10) << "Director:" << setw(20) << Director;
}
