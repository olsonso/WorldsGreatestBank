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
	string user_input;
	string username;
	string password;
	string deposit_amount;
	string withdraw_amount;

	BankAccount obj;
	obj.menu();

	return 0;
}
