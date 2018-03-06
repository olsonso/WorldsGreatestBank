/* Program that does the following

-Create a new account
-Login
-Record a deposit
-Record a withdrawal
-Check balance
-See transaction history
-Log out

*/

#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace std;

int main(){
	
	
	BankAccount account;
	BankAccount obj;
	std::cout << "\n ___________________________________________\n" << endl;
	std::cout << "\nWelcome to the Worlds Greatest Bank Ledger!\n" << endl;
	std::cout << "\n ___________________________________________\n" << endl;
	obj.menu();

	return 0;
}
