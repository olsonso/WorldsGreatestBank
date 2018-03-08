#include <iostream>
#include "BankAccount.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

//adds username into accounts text file
void BankAccount::openAccount(string username){
  ofstream myfile;
  myfile.open ("accounts.txt", ios::app);
  myfile << username << "\n";
  myfile.close();
}

//adds transactions to transactions text file
//this is erased at every end of console
void BankAccount::openTransactions(string type, double amount){
	ofstream myfile;
	myfile.open ("transactions.txt", ios::app);
  	myfile << type << " " << amount << "\n";
  	myfile.close();

}

//clears out all data in transaction file 
void BankAccount::cleanMyFile(){
	std::remove("transactions.txt");
}

//menu options for user
void BankAccount::menu(){
	std::cout << "\n Menu" << endl;
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
			cin >> amount;
			deposit(amount);
			break;
		case 4:
			std::cout << "Enter Amount to Withdraw" << endl;
			cin>> amount;
			withdraw(amount);
			break;
		case 5:
			checkAccountBalance(username);
			break;
		case 6:
			transactionHistory(username);
			break;
		case 7:
			break;
		default:
            std::cout << "Invalid input, please enter a choice 1 - 7" << endl;
           	menu();
	}
}

//initiates account at start of program regardless of login
BankAccount::BankAccount()
{
	bank_amount = 0;
}

//Creates new account 
void BankAccount::createNewAccount(){
	std::cout << "Please enter a username: " << endl;
	std::cin >> username;
	string _username;
	string line = " ";
	ifstream readFile("accounts.txt");

	bool found = false;
	while (getline(readFile,line)) {

    stringstream iss(line);
    iss >> _username;

    if (username == _username) {
        cout << "That username already exists, please login"<< endl;
        found = true;
        menu();
        break;
    }
   
}

if (!found) {
	openAccount(username);
	std::cout << "Congrats " << username << " Has Been Made \n" << endl;
    menu();
	}


}

// checks to see if username exists already or not
void BankAccount::login(){
	string username;
	string _username;
	string line = " ";
	ifstream readFile("accounts.txt");
	std::cout << "Please enter your username" << endl;
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

//Adds input amount to the balance
void BankAccount::deposit(double amount)
{
	bank_amount += amount;
	openTransactions("deposit:", amount);
	std::cout << "You deposited " << amount << " into your account \n" << endl;
	std::cout << "Your new balance is: $ " << bank_amount << endl;

	menu();
}

//Subtracts the input amount from the balance
void BankAccount::withdraw(double amount)
{
	bank_amount -= amount;
	openTransactions("withdraw:", amount);
	std::cout << "You withdrew " << amount << " from your account \n" << endl;
	std::cout << "Your new balance is: $ " << bank_amount << endl;
	menu();

}

//Returns the bank account's balance
void BankAccount::checkAccountBalance(string username)
{
	std::cout << "\n Your Current Balance: $" << bank_amount << "\n";
	menu();
}

//Returns all recorded transactions
void BankAccount::transactionHistory(string username) 
{
	std::cout << "Your Transactions:\n" << endl;
	std::ifstream f("transactions.txt");
	if (f.is_open()){
        std::cout << f.rdbuf();
	}
	menu();
	
}

