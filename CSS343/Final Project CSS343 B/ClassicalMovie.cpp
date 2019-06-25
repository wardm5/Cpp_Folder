//--------------------ClassicalMovie.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
// Purpose - Implementation file for the ClassicalMovie class
// contains comparison opperators and display for
// classical movies.
//-----------------------------------------------

#include "ClassicalMovie.h"
ClassicalMovie::ClassicalMovie() : Movie('C')  // constructor
{
}

//set data of classic movie from data file
bool ClassicalMovie::setData(ifstream& fin)
{
	string empty;
	getline(fin, empty, ',');
	fin >> TotalStock;
	CurrentStock = TotalStock;
	getline(fin, empty, ',');
	getline(fin, Director, ',');
	getline(fin, Title, ',');
	fin >> MajorActorFname;
	fin >> MajorActorLname;
	fin >> ReleaseMonth;
	fin >> ReleaseYear;
	return true;
}

// deconstructor
ClassicalMovie::~ClassicalMovie()
{
}

// returns true if one movie is greater than the other
bool ClassicalMovie::operator > (const Movie & inputMov)
{
	if (GetReleaseYear() > inputMov.GetReleaseYear())
	{
		return true;
	}
	else if (GetReleaseYear() < inputMov.GetReleaseYear())
	{
		return false;
	}
	else//if year is equal
	{
		if (GetReleaseMonth() > inputMov.GetReleaseMonth())
		{
			return true;
		}
		else if (GetReleaseMonth() < inputMov.GetReleaseMonth())
		{
			return false;
		}
		else //if year and month are equal check compared actors last Name
		{
			if (GetMajorActorFname() > inputMov.GetMajorActorFname())
			{
				return true;
			}
			else if (GetMajorActorFname() < inputMov.GetMajorActorFname())
			{
				return false;
			}
			else
			{
				if (GetMajorActorLname() > inputMov.GetMajorActorLname())
				{
					return true;
				}
				else
				{
					return false;
				}

			}

		}
	}
}

// returns true if one movie is less than another movie
bool ClassicalMovie::operator < (const Movie & inputMov)
{
	if (GetReleaseYear() < inputMov.GetReleaseYear())
	{
		return true;
	}
	else if (GetReleaseYear() > inputMov.GetReleaseYear())
	{
		return false;
	}
	else//if year is equal
	{
		if (GetReleaseMonth() < inputMov.GetReleaseMonth())
		{
			return true;
		}
		else if (GetReleaseMonth() > inputMov.GetReleaseMonth())
		{
			return false;
		}
		else //if year and month are equal check compared actors last Name
		{
			if (GetMajorActorFname() < inputMov.GetMajorActorFname())
			{
				return true;
			}
			else if (GetMajorActorFname() > inputMov.GetMajorActorFname())
			{
				return false;
			}
			else
			{
				if (GetMajorActorLname() < inputMov.GetMajorActorLname())
				{
					return true;
				}
				else
				{
					return false;
				}

			}

		}
	}

}

// returns bool if the movie matches the other movie
bool ClassicalMovie::operator == (const Movie & inputMov)
{
	if (GetReleaseYear() == inputMov.GetReleaseYear() && GetReleaseMonth() == inputMov.GetReleaseMonth() &&
		GetMajorActorLname() == GetMajorActorLname() && GetMajorActorFname() == GetMajorActorFname())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// returns the output info of the movie
void ClassicalMovie::OutputInfo()
{
	cout << endl << Genre << " " << "Total Stock:" << setw(2) << left << TotalStock << " Current Stock:" << setw(2)
		<< CurrentStock <<setw(8) << " Release:" << setw(2)<<ReleaseMonth<< setw(4)<<ReleaseYear
		<< setw(6)<< " Actor:"<< setw(10) << MajorActorFname
		<<setw(15)<< MajorActorLname << setw(6)<< "Title:" << setw(25)<< Title
		<< setw(10)<< " Director:" << Director;
}
