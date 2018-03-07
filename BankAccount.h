#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H



using namespace std;

class BankAccount
{
public:
	char username;
	char password;
	string accountName;
	int answer;

	BankAccount();
	BankAccount(double inital_amount);
	void openAccount(string accountName);
	void openTransactions(string type, double amount);
	void cleanMyFile();
	void menu(void);
	void createNewAccount();
	void login();
	void deposit(double amount);
	void withdraw(double amount);
	void checkAccountBalance(string accountName);
	void transactionHistory(string accountName);
	
	//Acessors
	double amount() const;
	double inital_amount;

private:
	double bank_amount;
};

#endif    //BANKACCOUNT_H


