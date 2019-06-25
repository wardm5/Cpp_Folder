//--------------------MovieBST.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the MovieBST class
//contains
//-----------------------------------------------


#ifndef MOVIEBST_H
#define MOVIEBST_H
#include "Movie.h"
class MovieBST
{
public:
	//---------------constructor/deconstructor---------------
	MovieBST();  // constructor
	~MovieBST();  // deconstructor

	//---------------MovieBST Actions---------------
	void outputInOrder()const;  // output in order
	void addMovie(Movie*);  // add movie to tree
	void makeEmpty();  // make tree empty
	Movie * searchMovie(Movie *);  // search tree for movie
	void searchOtherClassicalMovie(string, Movie*);  // search Classical
	//																									 movie

private:
	// tree node
	struct MovieNode
	{
		Movie* movieptr;
		MovieNode* left;
		MovieNode* right;
	};

	// tree field values and functions
	MovieNode* root;
	void searchOtherClassicalMovieHelper(string, Movie*, MovieNode*);
	void insert(MovieNode*, Movie*);
	void outputInOrderHelper(MovieNode*)const;
	void makeEmptyHelper(MovieNode*);
	Movie * searchMovieHelper(MovieNode*, Movie *);
	//void deleteTree(MovieNode*);


};
#endif
