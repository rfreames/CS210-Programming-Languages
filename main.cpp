/*
Ryan Reames
CS-210-T4455
3/29/2022
*/

// This file is used to create a Banking class object and run a prompt asking the user if they would like to continue.
#include "Banking.h"
#include <iostream>
#include <iomanip>

int main()
{
	Banking bank;						// Object that the file primarily uses
	string userChoice = "start";		// Used in running while loop below

	cout << fixed << setprecision(2);	// Sets precision for all values to two decimal places
	while (userChoice != "q")			// While loop runs until user enters q to quit
	{
		bank.menu();					// Runs the menu, getting user input
		bank.display();					// Displays results of the user's inputs over the user's specified time period.
		cout << "Enter q to quit, or any other value to continue: ";
		cin >> userChoice;
		system("CLS");					// Clears screen prior to restarting while loop
	}

	cout << "Goodbye!" << endl;

	return 0;
}