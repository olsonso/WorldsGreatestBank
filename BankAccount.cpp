#include <iostream>
#include "BankAccount.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

void BankAccount::openAccount(string accountName){
  ofstream myfile;
  myfile.open ("accounts.txt", ios::app);
  myfile << accountName << "\n";
  myfile.close();
}

void BankAccount::openTransactions(string type, double amount){
	ofstream myfile;
	myfile.open ("transactions.txt", ios::app);
  	myfile << type << " " << amount << "\n";
  	myfile.close();

}

void BankAccount::cleanMyFile(){
	std::remove("transactions.txt");
}

void BankAccount::menu(){
	std::cout << "\nPlease select an action:" << endl;
	std::cout << "___________________________ \n" << endl;
	std::cout << "1. Create a New Account" << endl;
	std::cout << "2. Login" << endl;
	std::cout << "3. Deposit " << endl;
	std::cout << "4. Withdraw" << endl;
	std::cout << "5. Check your Account Balance" << endl;
	std::cout << "6. See all Transactions" << endl;
	std::cout << "7. Exit and Logout" << endl;
	std::cin >> answer;

	switch(answer){
		case 1:
			createNewAccount();
			break;
		case 2: 
			login();
		case 3:
			double amount;
			std::cout << "Enter Amount to Deposit" << endl;
			cin>> amount;
			deposit(amount);
			break;
		case 4:
			std::cout << "Enter Amount to Withdraw" << endl;
			cin>> amount;
			withdraw(amount);
			break;
		case 5:
			checkAccountBalance(accountName);
			break;
		case 6:
			transactionHistory(accountName);
			break;
		case 7:
			cleanMyFile();
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
	std::cout << "Please enter a username: " << endl;
	std::cin >> accountName;
	openAccount(accountName);
	std::cout << "Congrats" << accountName << "Has Been Made \n" << endl;
	menu();

}

void BankAccount::login(){
	string username;
	string _username;
	string line = " ";
	ifstream readFile("accounts.txt");
	std::cout << "Please Enter Your Username" << endl;
	std::cin >> username;

	bool found = false;
	while (getline(readFile,line)) {

    stringstream iss(line);
    iss >> _username;

    if (username == _username) {
        cout << "Login Successful!"<< endl;
        found = true;
        menu();
        break;
    }
   
}

if (!found) {
    cout << "That username doesnt exist, please try login again or create new account " << endl;
    menu();
}

}

//Adds user's amount to the current amount
void BankAccount::deposit(double amount)
{
	bank_amount += amount;
	openTransactions("deposit:", amount);
	menu();
}

//Subtracts the user's amount from the current amount
void BankAccount::withdraw(double amount)
{
	bank_amount -= amount;
	openTransactions("withdraw:", amount);
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
	std::cout << "Your Transactions:\n" << endl;
	std::ifstream f("transactions.txt");
	if (f.is_open()){
        std::cout << f.rdbuf();
	}
	menu();
	
}

