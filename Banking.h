/*
Ryan Reames
CS-210-T4455
3/29/2022
*/

// This file includes all declarations for the Banking class

#ifndef BANKING_H
#define BANKING_H

using namespace std;

class Banking
{
public:
	double userInvestment, monthlyDeposit, interestRate;	// Used to get values from user in main.cpp
	int numYears;											
	void setInvestment(double investment);					// Setters for each value passed in by the user
	void setMonthlyDeposit(double monthly);
	void setInterestRate(double interest);
	void setYears(int year);
	void menu();											// Prompts user for input passes values through setters
	void display();											// Runs private calculateBalance function and displays results
private:
	double m_investment, m_monthly, m_interestRate, m_interestVal, m_investNoDep, m_interestNoDep; // Used in calculateBalance
	int m_years;
	void calculateBalance(double& investment, double& interest, double interestRate, double monthly = 0); // Calculates balance and interest, compounded monthly
};

#endif // !BANKING_H
