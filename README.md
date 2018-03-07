# WorldsGreatestBank <p>
-Create a new account<p>
-Login<p>
-Record a deposit<p>
-Record a withdrawal<p>
-Check balance<p>
-See transaction history<p>
-Log out<p>
  
# How to compile
 g++ -o exec WGB.cpp BankAccount.cpp
 ./exec

# Function Definitions:
<p></b>
openAccount() - writes to accounts.txt to add new user account<p>
openTransactions() - writes to transactions.txt every time a user does a transaction<p>
cleanMyFile() - deletes transactions.txt at end of program to clear transactions for given session<p>
<br>
menu() - lists out all the menu options a user can do during the program<p>
createNewAccount() - creates new account with account name user inputs<p>
deposit() - deposits user input amount into bank acccount balance<p>
widthdraw() - withdraws user input amount from bank account balance<p>
checkAccountBalance() - prints out current balance of account <p>
transactionHistory() - prints out to user all recorded transactions for session<p>


 # Additional features that could be added:
 <p>
  login with username and password check
  
