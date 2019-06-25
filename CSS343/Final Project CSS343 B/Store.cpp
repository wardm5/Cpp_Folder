//--------------------store.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementation file for the Store class
//contains all function/field declarations
//Store class meant to contain lists for all relevant
//data for running a movie rental store as well as
//function to interface with the store and all its components
//-----------------------------------------------
//Notes - Written to be extensible in the future
//for many types of new functionality
//If any new types of transactions or items are added,
//they will need to be included here
//-----------------------------------------------

#include "Store.h"

//INTILIZES customer list
Store::Store()
{
	for (int i = 0; i < CUSTOMERLENGTH; i++)  // for all customers
	{
		customers[i] = NULL;  // create new NULL customer
	}
}
//deletes customer list and inventory
Store::~Store()
{
	for (int i = 0; i < CUSTOMERLENGTH; i++)   // for each customer
	{
		delete customers[i];  // delete customer
	}
	inventory.ClearInventory(); // clear inventory

}
//Used to create inventory from the movies.txt file and if valid entry inputs to tree
void Store::CreateInventory()
{
	ifstream fin("data4movies.txt");
	if (!fin)  // if file was not found
	{
		cout << endl << "File not opened";  //print out file not opened
		return;
	}
	char inputGenre;
	while (!fin.eof())// start of input loop
	{
		fin >> inputGenre;
		if (fin.eof())  // if end of file...
		{
			return;  // return
		}

		Movie * inputMovie = MovieFact.creatMovie(inputGenre); // create pointer to move
		if (inputMovie == NULL)//if null is returned it doesn't input invalid movie
		{
			cout << endl << inputGenre << ": is an Invalid Genre";
			string invalid;
			getline(fin, invalid);
			continue;
		}
		else
		{
			if (inputMovie->setData(fin))  // set move to the input
			{
				inventory.insertMovie(inputMovie);
			}
			else  // if the movie is not valid entry
			{
				cout << endl << "Invalid entry, Movie was not created";
				string invalid;
				getline(fin, invalid);
				delete inputMovie;
				inputMovie = NULL;
			}
		}
	}//end input while statment
}

//Takes customer file in and adds to customerlist if its valid
void Store::CreateCustomers()
{
	fstream fin("data4customers.txt");
	if (!fin)  // if the file is not found...
	{
		cout << "The customer file could not be opened" << endl; // file not found
		return;
	}

	while (!fin.eof())  // when the file is not empty...
	{
		Customer* newCust = new Customer;  // create new customer
		if (newCust->setData(fin))  // set customer to the input
		{
			if (AddNewCustomer(*newCust))
			{
				continue;
			}
			else
			{
				delete newCust;
				newCust = NULL;
			}
		}
		else
		{
			string invalid;  // if the string is invald..
			getline(fin, invalid);
			delete newCust;  // delete customer
			newCust = NULL;  // set customer to NULL
			continue;
		}
	}
	return;
}

//Takes in the transactiono file and does the correct action
void Store::CreateTransactions()
{
	ifstream fin("data4commands.txt");
	if (!fin)
	{
		cout << endl <<"The comman file was not opened";
		return;
	}
	string actionType;
	while (!fin.eof())
	{
		fin >> actionType;
		if (fin.eof())
		{
			return;
		}
		if (actionType == "I")
		{
			InventoryTransaction(fin);
			continue;

		}
		else if (actionType == "H")
		{
			HistoryTransaction(fin);
			continue;
		}
		else if (actionType == "B")
		{
			BorrowTransaction(fin);
			continue;
		}
		else if (actionType == "R")
		{
			ReturnTransaction(fin);
			continue;
		}
		else
		{
			string empty = "";
			cout << endl << "Invalid Action Type: " << "\"" << actionType << "\"";
			getline(fin, empty);
			continue;
		}

	}


}

//helper function add customer to list
bool Store::AddNewCustomer(Customer& cust)
{
	int hashValue = hash(cust);
	if (customers[hashValue] == NULL)
	{
		customers[hashValue] = &cust;
		return true;
	}
	else
	{
		cout << endl << "Customer ID already stored.. Can't have duplicates";
		return false;
	}

}
// hash function adds the customer to hash based on cust id
int Store::hash(Customer& cust)
{
	return cust.GetidAsInt();;
}
void Store::DisplayInventory()
{
	cout << endl << "----------------------Comedy Movies-------------------------------" << endl;
	inventory.displayComedy();
	cout << endl << "----------------------Drama Movies--------------------------------" << endl;
	inventory.displayDramas();
	cout << endl << "---------------------Classical Movies-----------------------------" << endl;
	inventory.displayClassical();
	cout << endl;

}

//transaction I outputs inventory
void Store::InventoryTransaction(ifstream& fin)
{
	cout << endl << "STORE INVENTORY: ";
	string empty = "";
	DisplayInventory();
	getline(fin, empty);
}

//outputs history for partocular customer
void Store::HistoryTransaction(ifstream& fin)
{
	int custID = 0;
	string empty;
	fin >> custID;
	if (!CustomerExist(custID))
	{
		getline(fin, empty);
		return;
	}
	else
	{
		customers[custID]->outputCustHistory();
		getline(fin, empty);
		return;
	}
}

//Borrow transaction if its valid decrements current stock and adds transaction to cust history
void Store::BorrowTransaction(ifstream& fin)
{
	int custID = 0;
	string mediaCode = "";
	string empty = "";
	char movieGenre;
	fin >> custID;
	fin >> mediaCode;
	if (mediaCode != "D")
	{
		cout << endl << mediaCode << ": is not a valid Media Code.";
		getline(fin, empty);
		return;
	}
	fin >> movieGenre;
	Movie * checkMovie = MovieFact.creatMovie(movieGenre);
	if (checkMovie == NULL)//means trying to borrow invalid genre
	{
		cout << endl << "Not a valid Movie Genre: " << movieGenre;
		delete checkMovie;
		getline(fin, empty);
		return;
	}
	else// trying to borrow one of the valid Genres
	{
		if (movieGenre == 'F')
		{
			BorrowCommedy(fin, checkMovie, custID);
			return;
		}
		else if (movieGenre == 'D')
		{
			BorrowDrama(fin, checkMovie, custID);
			return;
		}
		else // genre is classical
		{
			BorrowClassical(fin, checkMovie, custID);
			return;
		}
	}
	getline(fin, empty);
	return;
}

//Performs return transaction if its a valid transaction performs adds to current stock of movie and adds to cust history
void Store::ReturnTransaction(ifstream& fin)
{
	{
		int custID = 0;
		string mediaCode = "";
		string empty = "";
		char movieGenre;
		fin >> custID;
		if (customers[custID] == NULL)
		{
			cout << endl << " customer id "<<custID << " Doesn't exist";
			getline(fin, empty);
			return;
		}
		fin >> mediaCode;
		if (mediaCode != "D")
		{
			cout << endl << mediaCode << ": is not a valid mediaType";
			getline(fin, empty);
			return;
		}
		fin >> movieGenre;
		Movie * checkMoviePtr = MovieFact.creatMovie(movieGenre);
		if (checkMoviePtr == NULL)
		{
			cout << endl << movieGenre << ": is an invalid genre";
			getline(fin, empty);
			delete checkMoviePtr;
			return;
		}
		else
		{
			//Movie * movieUpdatePtr = NULL;
			if (movieGenre == 'F')
			{
				ReturnComedy(fin, checkMoviePtr, custID);
				return;
			}
			else if (movieGenre == 'D')
			{
				ReturnDrama(fin, checkMoviePtr, custID);
				return;
			}
			else// has to be classical
			{
				ReturnClassical(fin, checkMoviePtr, custID);
				return;
			}
		}


	}

}
//checks to see if customer exists used to verify doing transaction on actual cust
bool Store:: CustomerExist(int id)
{
	if (customers[id] == NULL)
	{
		cout << endl << "Customer: " << id
			<< " doesn't exist";
		return false;
	}
	else
	{
		return true;
	}
}
//helper for borrow performs borrow on a movie genre commedy
void Store::BorrowCommedy(ifstream& fin, Movie *checkMoviePtr, int custID)
{
	Movie* movieUpdatePtr = NULL;
	string inputTitle = "";
	int inputYear = 0;
	getline(fin, inputTitle, ',');//get title
	fin >> inputYear;//get release year
	checkMoviePtr->SetTitle(inputTitle);
	checkMoviePtr->SetReleaseYear(inputYear);
	movieUpdatePtr = inventory.movieList[0]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << inputTitle
			<< " not found. could not borrow";
		return;
	}
	else// decrement stock
	{
		if (movieUpdatePtr->GetCurrentStock() > 1)
		{
			if (!CustomerExist(custID))//customer doesn't exist error and return
			{
				return;
			}
			else
			{
				movieUpdatePtr->SubtractOneCurrentStock();
				customers[custID]->addToCustHistory("B", movieUpdatePtr->GetTitle());
				return;
			}
		}
		else
		{
			cout << endl << movieUpdatePtr->GetTitle()
				<< "is out of stock you can not borrow";
			return;
		}
	}
}
//helper for borrow performs borrow on a movie genre Drama
void Store::BorrowDrama(ifstream& fin, Movie* checkMoviePtr, int custID)
{
	Movie* movieUpdatePtr = NULL;
	string inputTitle = "";
	string inputDirector = "";
	getline(fin, inputDirector, ',');//Get Director
	getline(fin, inputTitle, ',');//Get Title
	checkMoviePtr->SetDirector(inputDirector);
	checkMoviePtr->SetTitle(inputTitle);
	movieUpdatePtr = inventory.movieList[1]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << inputTitle
			<< " not found. could not borrow";
		return;
	}
	else// decrement stock
	{
		if (movieUpdatePtr->GetCurrentStock() > 1)
		{
			if (!CustomerExist(custID))//customer doesn't exist error and return
			{
				return;
			}
			else
			{
				movieUpdatePtr->SubtractOneCurrentStock();
				customers[custID]->addToCustHistory("B", movieUpdatePtr->GetTitle());
				return;;
			}
		}
		else
		{
			cout << endl << movieUpdatePtr->GetTitle()
				<< "is out of stock you can not borrow";
			return;
		}
	}
}
//helper for borrow performs borrow on a movie genre Classical
void Store::BorrowClassical(ifstream& fin, Movie* checkMoviePtr, int custID)
{
	Movie* movieUpdatePtr = NULL;
	int inputMonth = 0;
	int inputYear = 0;
	string inputfName = "";
	string inputlName = "";
	fin >> inputMonth;
	fin >> inputYear;
	fin >> inputfName;
	fin >> inputlName;
	checkMoviePtr->setReleaseMonth(inputMonth);
	checkMoviePtr->SetReleaseYear(inputYear);
	checkMoviePtr->SetFname(inputfName);
	checkMoviePtr->SetLname(inputlName);
	movieUpdatePtr = inventory.movieList[2]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << "Actor "<< inputfName<< " "<< inputlName <<
			" Release date: " << inputMonth << " " << inputYear <<" Movie was not found";
		return;
	}
	if (movieUpdatePtr->GetCurrentStock() > 0)
	{
		if (!CustomerExist(custID))//customer doesn't exist error and return
		{
			return;
		}
		else
		{
			movieUpdatePtr->SubtractOneCurrentStock();
			customers[custID]->addToCustHistory("B", movieUpdatePtr->GetTitle());
			return;
		}

	}
	else//check for other instances of classical movie with same title but has stock
	{
		string movieTitle = movieUpdatePtr->GetTitle();
		movieUpdatePtr = NULL;
		inventory.movieList[2]->searchOtherClassicalMovie(movieTitle, movieUpdatePtr);
		if (movieUpdatePtr == NULL)//out of stock for that title including all actors
		{
			cout << endl << movieTitle
				<< "is out of stock you can not borrow";
			return;
		}
		else
		{
			movieUpdatePtr->SubtractOneCurrentStock();
			customers[custID]->addToCustHistory("B", movieUpdatePtr->GetTitle());
			return;
		}
	}
}

//helper for Return performs return on a movie genre commedy
void Store::ReturnComedy(ifstream& fin, Movie* checkMoviePtr, int custID)
{
	Movie * movieUpdatePtr = NULL;
	string empty = "";
	string title = "";
	int year = 0;
	getline(fin, title, ',');
	fin >> year;
	checkMoviePtr->SetTitle(title);
	checkMoviePtr->SetReleaseYear(year);
	movieUpdatePtr = inventory.movieList[0]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << "Movie was not found ";
		getline(fin, empty);
		return;
	}
	else
	{
		int currentStock = movieUpdatePtr->GetCurrentStock();
		int totalstock = movieUpdatePtr->GetTotalStock();
		if (currentStock == totalstock)//can't go above totalStockOfAMove
		{
			cout << "Already have full stock: " << movieUpdatePtr->GetTitle() << endl;
			getline(fin, empty);
			return;
		}
		else
		{
			movieUpdatePtr->AddOneCurrentStock();//add return
			customers[custID]->addToCustHistory("R", movieUpdatePtr->GetTitle());//log cust hist
			getline(fin, empty);
			return;
		}
	}
}
//helper for Return performs return on a movie genre drama
void Store::ReturnDrama(ifstream& fin, Movie* checkMoviePtr, int custID)
{
	Movie * movieUpdatePtr = NULL;
	string empty = "";
	string inputTitle = "";
	string inputDirector = "";
	getline(fin, inputDirector, ',');//Get Director
	getline(fin, inputTitle, ',');//Get Title
	checkMoviePtr->SetDirector(inputDirector);
	checkMoviePtr->SetTitle(inputTitle);
	movieUpdatePtr = inventory.movieList[1]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << "Movie was not found ";
		getline(fin, empty);
		return;
	}
	else
	{
		int currentStock = movieUpdatePtr->GetCurrentStock();
		int totalstock = movieUpdatePtr->GetTotalStock();
		if (currentStock == totalstock)//can't go above totalStockOfAMove
		{
			cout << "Already have full stock: " << movieUpdatePtr->GetTitle() << endl;
			getline(fin, empty);
			return;
		}
		else
		{
			movieUpdatePtr->AddOneCurrentStock();//add return
			customers[custID]->addToCustHistory("R", movieUpdatePtr->GetTitle());//log cust hist
			getline(fin, empty);
			return;
		}
	}
}
//helper for Return performs return on a movie genre classical
void Store::ReturnClassical(ifstream& fin, Movie* checkMoviePtr, int custID)
{
	Movie * movieUpdatePtr = NULL;
	string empty = "";
	int inputMonth = 0;
	int inputYear = 0;
	string inputfName = "";
	string inputlName = "";
	fin >> inputMonth;
	fin >> inputYear;
	fin >> inputfName;
	fin >> inputlName;
	checkMoviePtr->setReleaseMonth(inputMonth);
	checkMoviePtr->SetReleaseYear(inputYear);
	checkMoviePtr->SetFname(inputfName);
	checkMoviePtr->SetLname(inputlName);
	movieUpdatePtr = inventory.movieList[2]->searchMovie(checkMoviePtr);
	delete checkMoviePtr;
	if (movieUpdatePtr == NULL)
	{
		cout << endl << "Movie was not found.";
		getline(fin, empty);
		return;
	}
	else
	{
		int currentStock = movieUpdatePtr->GetCurrentStock();
		int totalstock = movieUpdatePtr->GetTotalStock();
		if (currentStock == totalstock)//can't go above totalStockOfAMove
		{
			cout << "Already have full stock: " << movieUpdatePtr->GetTitle() << endl;
			getline(fin, empty);
			return;
		}
		else
		{
			movieUpdatePtr->AddOneCurrentStock();//add return
			customers[custID]->addToCustHistory("R", movieUpdatePtr->GetTitle());//log cust hist
			getline(fin, empty);
			return;
		}
	}
}
//I just used this function to verify all the transactions not actually used in code
void Store::GetEveryCustHist()
{
	for (int i = 1000; i < 9999; i++)
	{
		if (CustomerExist(i))
		{
			customers[i]->outputCustHistory();
		}
		else
			continue;
	}
}
