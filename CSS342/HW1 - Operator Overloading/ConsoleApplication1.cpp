#include "Pizza.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int num;   // Global variable num, to store numbers from user input
string pause;   // Global variable pause, to prevent console window from closing (visual studio)

int input();									// User input function
Pizza Addition(Pizza a, Pizza b);				// Addition overload function
void Difference(Pizza a, Pizza b, Pizza c);		//  Difference overload function
void Compound(Pizza a);							//  Compound overload function
void Comparison(Pizza a, Pizza b);				//  Comparison overload function

int main()
{
	cout << "Hello, this program will help you calculate your pizza slice consumption and compare it to your friends. \n" << endl;

	cout << "How many pizza slices do you have? Please enter a number above or equal 1." << endl;  	//entering your pizza count
	num = input();		// setting pizza slices from user input
	Pizza a(num);		// creating tracker for person 1's pizzas

	cout << "\nHow many pizza slices does your friend have? " << endl; 	//entering first friend's pizza count
	num = input();		// setting pizza slices from user input
	Pizza b(num);		// creating tracker for person 2's pizzas

	Pizza c = Addition(a, b); // Setting person 3's pizza tracker by using Addition overload function

	Comparison(a, b); 	// Comparison Operand Function

	Compound(a); 	// Coin game with GREG and Compound overload function

	Difference(a, b, c); 	// Difference Function

    return 0;
}

int input()
{
	int answer;  
	cin >> answer;
	while (answer < 1)  // Loop until number greater or equal to 1, then return answer.
	{
		cout << "Please input a number greater than or equal to 1." << endl;
		cin >> answer;
		
	}
	return answer;
}


Pizza Addition(Pizza a, Pizza b)
{
	cout << "\n\nARITHMETIC OPERAND" << endl;
	Pizza c = a + b;    // Addition overload.
	int totalSlices = c.getPizzaSlices(); 
	cout << "You both have a total of " << totalSlices << " Pizzas slices." << endl;
}

void Comparison(Pizza a, Pizza b)
{

	cout << "\n\nCOMPARISON OPERAND" << endl;
	cout << "How many pizza slices has your second friend have? " << endl;
	num = input();   	//entering 4th friend's pizza slices
	Pizza d(num);		//create pizza slices tracker for 4th friend
	
	if (d == (a + b)) {  // Comparison Operand  (equal to)
		cout << "Your second friend has as many pizza slices as both you and your orginal friend combined!\n";
	}
	else if (d > (a + b))  // Comparison Operand  (greater than)
	{
		cout << "\nYour second friend has more pizza slices than you and your orginal friend combined!\n";
	}
	else 
	{
		cout << "\nYour second friend has less pizza slices than you and your orginal friend combined. Get them more pizza! \n";
	}
}

void Difference(Pizza a, Pizza b, Pizza c)
{
	cout << "\n\nARITHMETIC OPERAND" << endl;
	c = a - b;   // Subtraction operator overload. 
	int difference = c.getPizzaSlices();   // setting variable value to the value from the subtraction operator. 
	if (difference > 0)    // logic to see if you and your first friend have more pizza slices, your third friend has more pizza, or you are equal. 
	{
		cout << "You have have " << difference << " more pizza slices than your first friend... That is an estimated " << difference * pizzaCalories << " extra calories... \n" << endl;
	}
	else if (difference == 0)
	{
		cout << "You have the same amount of pizza as your first friend. \n" << endl;
	}
	else
	{
		cout << "Your first friend has " << -difference << " more pizza slices than you... That is an estimated " << -(difference * pizzaCalories) << " extra calories. \n" << endl;
	}

	cout << endl << "Thank you for using this program! Press any key and enter to end." << endl;

	cin >> pause;
}

void Compound(Pizza a)
{
	cout << "\n\nCOMPOUND OPERAND" << endl;  
	cout << "Your friend GREG challenged you to a coin toss game! If you lose, you give him your pizza slices, if you win, you get his 3 slices!" << endl;
	Pizza e(3);																		// creating pizza slice tracker for friend 5 (GREG).
	cout << "Your current amount of pizza slices: " << a.getPizzaSlices() << endl;  //  outputting person 1's current amount of pizza slices.
	cout << "GREG's amount of pizza slices: " << e.getPizzaSlices() << endl;		//  outputting GREG's current amount of pizza slices.

	cout << "Press any number and enter to play!" << endl << endl;
	cin >> pause;

	int randNum;						//creating new variable for random number
	srand(time(0));						//setting system time to 0 to ensure randomness
	randNum = (rand() % 10) + 1;		//creating random number from 1 to 10 

	if (randNum > 5)   // if random number greater than 5, you win and take pizzas (Compound Operator), otherwise GREG gets your pizza slices.
	{
		a += e;
		e -= e;
	}
	else
	{
		e += a;
		a -= a;
	}
	cout << endl << "The results are in!" << endl;													
	cout << "Your ending amount of pizza slices: " << a.getPizzaSlices() << endl;					//  outputting person 1's updated amount of pizza slices.
	cout << "Your friend GREG's ending amount of pizza slices: " << e.getPizzaSlices() << "\n";		//  outputting GREG's updated amount of pizza slices.
}
