/*
Ryan Reames
CS-210-T4455
3/29/2022
*/

// This file includes all definitions for Banking.h

#include "Banking.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void Banking::setInvestment(double investment) // Sets initial investment amount
{
	this->m_investment = investment;
	this->m_investNoDep = investment;
}

void Banking::setMonthlyDeposit(double monthly) // Sets monthly deposit
{
	this->m_monthly = monthly;
}

void Banking::setInterestRate(double interest) // Sets interest rate
{
	this->m_interestRate = interest;
	this->m_interestNoDep = interest;
}

void Banking::setYears(int year) // Sets years used in display function
{
	this->m_years = year;
}

void Banking::menu() // Used to get data from the user to be used in calculations
{
	string clearInput; // Used to clear incorrect input from user
	string userChoice; // Used to prompt user to continue after showing user input
	cout << setw(24) << setfill('_') << " Data Input "; // Formats so that Display Input is centered
	cout << setw(13) << setfill('_') << "" << endl;

	// The following prompts for the user's initial investment and then passes it to the setInvestment function
	cout << "Initial Investment Amount: $";
	cin >> userInvestment;
	while (cin.fail() || (userInvestment < 0)) // Checks for incorrect input
	{
		try // If incorrect input, throws error
		{
			if (cin.fail() || (userInvestment < 0))
			{
				
				throw runtime_error("Invalid input.");
			}
		}
		catch (runtime_error& excpt) // Clears user input and sends to clearInput string, then requests input again
		{
			cout << excpt.what() << endl;
			cin.clear();
			getline(cin, clearInput);
			cout << "Enter digit value >= 0: $";
			cin >> userInvestment;
		}
	}
	setInvestment(userInvestment);
	cin.clear(); // Clears any additional input beyond initial number value
	getline(cin, clearInput);

	// Prompts for monthly deposit and passes to the setMonthlyDeposit function
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	// While loop and try / catch are same as above for userInvestment
	while (cin.fail() || (monthlyDeposit < 0))
	{
		try
		{
			if (cin.fail() || (monthlyDeposit < 0))
			{

				throw runtime_error("Invalid input.");
			}
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
			cin.clear();
			getline(cin, clearInput);
			cout << "Enter digit value >= 0: $";
			cin >> monthlyDeposit;
		}
	}
	setMonthlyDeposit(monthlyDeposit);
	cin.clear();
	getline(cin, clearInput);

	// Prompts the user for the annual interest percentage and passes to setInterestRate function
	cout << "Annual Interest: %";
	cin >> interestRate;
	// While loop and try / catch are same as above for userInvestment
	while (cin.fail() || (interestRate < 0))
	{
		try
		{
			if (cin.fail() || (interestRate < 0))
			{

				throw runtime_error("Invalid input.");
			}
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
			cin.clear();
			getline(cin, clearInput);
			cout << "Enter digit value >= 0: %";
			cin >> interestRate;
		}
	}
	setInterestRate(interestRate);
	cin.clear();
	getline(cin, clearInput);

	// Prompts user for year time-period and passes to setYears function
	cout << "Years: ";
	cin >> numYears;
	// While loop and try / catch are same as above for userInvestment
	while (cin.fail() || (numYears < 0))
	{
		try
		{
			if (cin.fail() || (numYears < 0))
			{

				throw runtime_error("Invalid input.");
			}
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
			cin.clear();
			getline(cin, clearInput);
			cout << "Enter digit value >= 1: ";
			cin >> numYears;
		}
	}
	setYears(numYears);
	cin.clear();
	getline(cin, clearInput);

	cout << endl;
	system("CLS"); // Clears the screen, then displays user input for each value
	cout << setw(24) << setfill('_') << " Data Input ";
	cout << setw(13) << setfill('_') << "" << endl;
	cout << "Initial Investment Amount: $" << m_investment << endl;
	cout << "Monthly Deposit: $" << m_monthly << endl;
	cout << "Annual Interest: %" << m_interestRate << endl;
	cout << "Number of Years: " << m_years << endl;
	
	// Prompts the user to enter a key to continue
	while (empty(userChoice))
	{
		cout << "Enter any key to continue... ";
		cin >> userChoice;
		system("CLS"); // Clears screen once user enters any key
	}
}

void Banking::display() // Displays results over user-specified time-period of balance and interest gained, both with and without monthly deposits
{	
	int formatLength; // Used in formatting output based on length of user initial investment
	cout << "Initial deposit of: $" << m_investment << endl;
	cout << "Interest rate of: " << m_interestRate << "%, compounded monthly\n" << endl;

	cout << "Balance and Interest without Additional Monthly Deposits" << endl;
	cout << "________________________________________________________" << endl;
	cout << "- Year ----- Year End Balance ----- Year End Interest --" << endl;

	// The following for loop utilizes the calculateBalance function, updating each respective private variable by year, without a monthly deposit amount
	// It then outputs the year, account balance, and interest earned, cumulatively
	for (int i = 1; i <= m_years; i++)
	{
		calculateBalance(m_investNoDep, m_interestNoDep, m_interestRate); // Utilizes default for monthly deposit, being $0.00
		// The following setw() and setfill() values format the output such that they do not exceed the length of the text preceding the for loop
		cout << setw(2) << setfill('-') << " " << i << " ";
		cout << setw(11 - to_string(i).size()) << setfill('-');
		cout << " $" << m_investNoDep << " ";
		cout << setw(26 - to_string(m_investNoDep).size()) << setfill('-') << " $" << m_interestNoDep << " ";
		cout << setw(22 - to_string(m_interestNoDep).size()) << setfill('-') << "" << endl;
	}

	cout << "\n" << endl;
	formatLength = to_string(m_monthly).size() + 51; // Used in altering underscore length based on length of m_monthly deposit
	cout << "Balance and Interest with $" << m_monthly << " Additional Monthly Deposits" << endl;
	cout << setw(formatLength) << setfill('_') << "" << endl; // Formats underscores following the above line
	cout << "- Year ----- Year End Balance ----- Year End Interest ";
	cout << setw(formatLength - 54) << setfill('-') << "" << endl; // Adds - symbols after Year End Interest

	// The following for loop is the same as the preceding for loop, but this time includes an amount for m_monthly deposits being passed to calculateBalance
	for (int i = 1; i <= m_years; i++)
	{
		calculateBalance(m_investment, m_interestVal, m_interestRate, m_monthly);
		cout << setw(2) << setfill('-') << " " << i << " ";
		cout << setw(11 - to_string(i).size()) << setfill('-');
		cout << " $" << m_investment << " ";
		cout << setw(26 - to_string(m_investment).size()) << setfill('-') << " $" << m_interestVal << " ";
		cout << setw(formatLength - 34 - to_string(m_interestVal).size()) << setfill('-') << "" << endl;
	}
	cout << endl;
}

void Banking::calculateBalance(double& investment, double& interest, double interestRate, double monthly) // Calculates total balance plus interest, compounded monthly, for one year
{
	double totalInterest = 0.0; // Used to hold total interest, added each month in the next for loop

	// Calculates interest for one month at a time, adding to total interest, and increasing the account balance by both interest for the month and monthly deposit amount
	for (int i = 1; i <= 12; i++)
	{
		interest = (investment + monthly) * ((interestRate / 100.0) * (1 / 12.0));
		totalInterest += interest;
		investment += monthly + interest;
	}
	interest = totalInterest; // This value is used to update the overall interest for one year, which is used in the display function
}
