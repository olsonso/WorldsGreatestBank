#include <iostream>
#include "BankAccount.h"
#include <string>


void BankAccount::menu(){
	string user_input;
	std::cout << "Welcome to the Worlds Greatest Bank Ledger, please select an action" << endl;
	std::cout << "1. Create a New Account" << endl;
	std::cout << "2. Deposit " << endl;
	std::cout << "3. Withdraw" << endl;
	std::cout << "4. Check your Account Balance" << endl;
	std::cout << "5. See all Transactions" << endl;
	std::cout << "6. Exit and Logout" << endl;
	getline(cin, user_input);
}

BankAccount::BankAccount()
{
	bank_amount = 0;
}

//Constructor that initilizes amount to 0, and owner name to an empty string 
BankAccount::BankAccount(double initial_amount, std::string name)
{
	 bank_amount = initial_amount;
	 owner_name = name;
}

//Adds user's amount to the current amount
void BankAccount::deposit(double amount)
{
	bank_amount += amount;
}

//Subtracts the user's amount from the current amount
void BankAccount::withdraw(double amount)
{
	bank_amount -= amount;
}

//Returns the bank account's current amount
double BankAccount::amount() const
{
	return bank_amount;
}
