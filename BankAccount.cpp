#include <iostream>
#include "BankAccount.h"
#include <string>

int answer;
string accountName;
int dCount;
int wCount;

struct transactions{
	string transaction;
	double tAmount;
} records;

int trecords[128];
int numOfValues = 0;

void BankAccount::menu(){
	std::cout << "\nPlease select an action:\n" << endl;
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
			std::cout << "Enter Amount to Deposit" << endl;
			cin>> amount;
			deposit(amount);
			break;
		case 3:
			std::cout << "Enter Amount to Withdraw" << endl;
			cin>> amount;
			withdraw(amount);
			break;
		case 4:
			checkAccountBalance(accountName);
			break;
		case 5:
			transactionHistory(accountName);
			break;
		case 6:
			break;
		default:
            std::cout << "That was not an option, please try again" << endl;
           	menu();
	}
}

BankAccount::BankAccount()
{
	bank_amount = 0;
}

//Creates new account 
void BankAccount::createNewAccount(){
	std::cout << "Enter Name of Account Holder" << endl;
	std::cin >> accountName;
	std::cout << "Congrats Your New Account Has Been Made \n" << endl;
	menu();

}

//Adds user's amount to the current amount
void BankAccount::deposit(double amount)
{
	bank_amount += amount;
	numOfValues = numOfValues + 1;
	dCount += 1;
	trecords[numOfValues] = amount;
	records.transaction = "deposit" ;
	records.tAmount = amount;
	menu();
}

//Subtracts the user's amount from the current amount
void BankAccount::withdraw(double amount)
{
	bank_amount -= amount;
	wCount += 1;
	menu();

}

//Returns the bank account's balance
void BankAccount::checkAccountBalance(string accountName)
{
	std::cout << "\n Your Current Balance:" << bank_amount << "\n";
	menu();
}

//Returns all recorded transactions

void BankAccount::transactionHistory(string accountName) 
{
	std::cout << "You Deposited " << dCount << " times";
	std::cout << "You Withdrew " << wCount << " times";

	std::cout << "\n" << endl;
	//std::cout << "All" << records.transaction;

	cout << "The value of the array is:" << endl;
    for (int i = 1; i < numOfValues; i++)
    {
        cout << i << ": " << trecords[i] << endl;
    }
    cout << endl;
	menu();
	
}
