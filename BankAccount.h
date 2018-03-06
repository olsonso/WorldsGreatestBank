#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class BankAccount
{
public:
	char username;
	char password;

	BankAccount();
	BankAccount(double inital_amount, std::string name);

	void menu(void);
	void deposit(double amount);
	void withdraw(double amount);
	void balance(double amount);
	void transactionHistory();
  
	double amount() const;
	double inital_amount;

private:
	double bank_amount;
	string owner_name;
};

#endif    //BANKACCOUNT_H


