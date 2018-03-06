#include <iostream>
#include "BankAccount.h"
#include <string>

int answer;
string accountName;

void BankAccount::menu(){
	std::cout << "Welcome to the Worlds Greatest Bank Ledger, please select an action" << endl;
	std::cout << "1. Create a New Account" << endl;
	std::cout << "2. Deposit " << endl;
	std::cout << "3. Withdraw" << endl;
	std::cout << "4. Check your Account Balance" << endl;
	std::cout << "5. See all Transactions" << endl;
	std::cout << "6. Exit and Logout" << endl;
	std::cin >> answer;

	switch(answer){
		case 1:
			createNewAccount();
			break;
		case 2:
			double amount;
			std::cout << "You are depostiting into\n" << accountName;
			std::cout << "Enter Amount to Deposit" << endl;
			cin>> amount;
			deposit(amount);
			break;
		case 3:
			std::cout << "You are withdrawing from\n" << accountName;
			std::cout << "Enter Amount to Withdraw" << endl;
			cin>> amount;
			withdraw(amount);
			break;
		case 4:
			checkAccountBalance(accountName);
			break;
		// case 5:
		// 	transactionHistory();
		// 	break;
	}
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

//Creates new account 
void BankAccount::createNewAccount(){
	std::cout << "Enter Name of Account Holder" << endl;
	std::cin >> accountName;
	std::cout << "Congrats Your New Account Has Been Made" << endl;
	std::cout << "Hit 0 to return to Menu" << endl;
	std::cin >> answer;
	if(answer == 0){
		menu();
	}

}


//Adds user's amount to the current amount
void BankAccount::deposit(double amount)
{
	bank_amount += amount;
	std::cout << "Hit 0 to return to Menu" << endl;
	std::cin >> answer;
	if(answer == 0){
		menu();
	}
}

//Subtracts the user's amount from the current amount
void BankAccount::withdraw(double amount)
{
	bank_amount -= amount;
	std::cout << "Hit 0 to return to Menu" << endl;
	std::cin >> answer;
	if(answer == 0){
		menu();
	}
}

//Returns the bank account's balance
void BankAccount::checkAccountBalance(string accountName)
{
	std::cout << "Balance:\n" << bank_amount;
	std::cout << "Hit 0 to return to Menu" << endl;
	std::cin >> answer;
	if(answer == 0){
		menu();
	}
}

// //Returns all recorded transactions
// void BankAccount::transactionHistory() 
// {
// }
