//--------------------MovieBST.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementaion file for the MovieBST class
//contains
//-----------------------------------------------


#include "MovieBST.h"

MovieBST::MovieBST()
{
	root = NULL;
}
MovieBST::~MovieBST()
{
	//makeEmpty();

}
void MovieBST::addMovie(Movie* inputData)
{
	insert(root, inputData);
}
void MovieBST::insert(MovieNode* ptr, Movie* dataMoviePtr)
{
  if (ptr == NULL || dataMoviePtr == NULL)
  {
    return;
  }
	if (root == NULL)//Insert Root
	{
		root = new MovieNode;
		root->movieptr = dataMoviePtr;
		root->right = NULL;
		root->left = NULL;
	}
	else
	{
		//Just the titles are equal for classical so update total stock of classical
		if (ptr->movieptr->GetTitle() == dataMoviePtr->GetTitle())
		{
			int totalStock = ptr->movieptr->GetTotalStock() + dataMoviePtr->GetTotalStock();
			ptr->movieptr->SetTotalStock(totalStock);
			dataMoviePtr->SetTotalStock(totalStock);
		}

		if (*dataMoviePtr > *ptr->movieptr)//Go right
		{
			if (ptr->right == NULL)
			{

				ptr->right = new MovieNode;
				ptr->right->movieptr = dataMoviePtr;
				ptr->right->left = NULL;
				ptr->right->right = NULL;
			}
			else
			{
				insert(ptr->right, dataMoviePtr);
			}

		}
		else if (*dataMoviePtr < *ptr->movieptr)// go left if less than or equal
		{
			if (ptr->left == NULL)
			{
				ptr->left = new MovieNode;
				ptr->left->movieptr = dataMoviePtr;
				ptr->left->left = NULL;
				ptr->left->right = NULL;
			}
			else
			{
				insert(ptr->left, dataMoviePtr);
			}
		}

		else//Movie already exists
		{
			//ptr->movieptr->SetTotalStock(ptr->movieptr->GetTotalStock() + dataMoviePtr->GetTotalStock());
			delete dataMoviePtr;// delete movie passed in because it already exists
		}

	}
}
void MovieBST::outputInOrder() const
{
	outputInOrderHelper(root);
}
void MovieBST::outputInOrderHelper(MovieNode* ptr) const
{
	if (root == NULL)
	{
		cout << endl << "No Movies In Current Tree ";
	}
	if (ptr != NULL)
	{
		outputInOrderHelper(ptr->left);
		ptr->movieptr->OutputInfo();
		outputInOrderHelper(ptr->right);

	}
	else
	{
		return;
	}

}
void MovieBST::makeEmpty()
{
	if (root == NULL)
	{
		//delete root
		return;
	}
	else
	{
		makeEmptyHelper(root);
	}

}
void MovieBST::makeEmptyHelper(MovieNode* ptr)
{
	if (ptr != NULL)
	{
		makeEmptyHelper(ptr->left);
		makeEmptyHelper(ptr->right);
		delete ptr->movieptr;
		delete ptr;
	}
	else
	{
		return;
	}
}
// searchs for the movie and returns a pointer to found location or returns null if not found
Movie * MovieBST::searchMovie(Movie * searchPtr)
{
	if (searchPtr == NULL)
	{
		return NULL;
	}
	else if (root == NULL)
	{
		return NULL;
	}
	else
	{
		return searchMovieHelper(root, searchPtr);
	}

	return NULL;
}
void MovieBST::searchOtherClassicalMovie(string title, Movie * setptr)
{
	if (root == NULL) {
		return;
	}
	else
	{
		searchOtherClassicalMovieHelper(title, setptr, root);
	}
}
void MovieBST::searchOtherClassicalMovieHelper(string title, Movie * setptr, MovieNode * ptr)
{
	if (ptr != NULL)
	{
		if (ptr->movieptr->GetTitle() == title && ptr->movieptr->GetCurrentStock() > 0)
		{
			setptr = ptr->movieptr;
			return;
		}
		searchOtherClassicalMovieHelper(title, setptr, ptr->left);
		searchOtherClassicalMovieHelper(title, setptr, ptr->right);
	}
	else
	{
		return;
	}
}
Movie * MovieBST::searchMovieHelper(MovieNode * ptr, Movie *inputMoviePtr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	else
	{
		if (*ptr->movieptr == *inputMoviePtr)
		{
			return ptr->movieptr;
		}
		else if (*inputMoviePtr > *ptr->movieptr)// go right
		{
			return searchMovieHelper(ptr->right, inputMoviePtr);
		}
		else
		{
			return searchMovieHelper(ptr->left, inputMoviePtr);
		}
	}
}
