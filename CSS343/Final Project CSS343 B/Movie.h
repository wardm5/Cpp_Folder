//--------------------Movie.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the Movie class
//contains constructors/deconstructors, getters, Setters
// display virtual function, comparison function
//-----------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Movie
{
public:
	//---------------constructor/destructors---------------
	Movie();  // movie constructor
	Movie(char genre);  // movie constructor with name
	virtual~Movie();  // movie deconstructor

	//---------------Getters---------------
	string GetTitle()const;  // get Title
	string GetDirector()const;  // get director
	int GetReleaseYear()const;  // get year released
	int GetTotalStock()const;  // get total stock
	int GetCurrentStock()const;  // get current stock
	int GetReleaseMonth()const;  // get release month
	string GetMajorActorFname()const;  // get actor first name
	string GetMajorActorLname()const;  // get actor last name
	char GetGenre()const;  // get genre

	//---------------Setters---------------
	void SetTotalStock(int);  // set total stock
	void SetCurrentStock(int);  //set current stock
	void setReleaseMonth(int);//USed for searches to create a new tree with partial info
	void SetFname(string);//USed for searches to create a new tree with partial info
	void SetLname(string);//USed for searches to create a new tree with partial info
	void SubtractOneCurrentStock();  // subtract from stock
	void AddOneCurrentStock();  // add to stock
	void SetTitle(string);//USed for searches to create a new tree with partial info
	void SetReleaseYear(int); //USed for searches to create a new tree with partial info
	void SetDirector(string);//USed for searches to create a new tree with partial info
	virtual bool setData(ifstream &);  // set data

	//---------------Display info---------------
	virtual void OutputInfo() = 0; //virtual function

	//---------------Comparison Operator---------------
	virtual bool operator > (const Movie & inputMov) = 0;  // greater than operator
	virtual bool operator < (const Movie & inputMov) = 0;  // less than operator
	virtual bool operator == (const Movie & inputMov) = 0;  // equals operator

protected:
	// various fields for movies
	char Genre;
	int TotalStock;
	int CurrentStock;
	string Director;
	string Title;
	int ReleaseYear;
	int ReleaseMonth;
	string MajorActorFname;
	string MajorActorLname;
};
#endif
