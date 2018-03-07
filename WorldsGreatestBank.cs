using System;

namespace BankAccount
{
    public class DoLoop
    {
        private static double balance;
        private static double withdraw;
        private static double deposit;

        private static void Menu()
        {
            Console.WriteLine("Please Select an Option Below:");
            Console.WriteLine("1 - Create Account");
            Console.WriteLine("2 - Deposit");
            Console.WriteLine("3 - Withdrawal");
            Console.WriteLine("4 - Check");
            Console.WriteLine("5 - Transactions");
            Console.WriteLine("6 - Logout/Quit\n");
        }

        private static string GetUserInput()
        {
            return Console.ReadLine();
        }

        private static void menuSelection(string selection)
        {
            selection = selection.ToUpper();

            switch (selection)
            {
                case "1":
                    CreateNewAccount();
                    break;
                case "2":
                    ProcessDeposit();
                    break;
                case "3":
                    ProcessWithdrawl();
                    break;
                case "4":
                    ProcessCheckBalance();
                    break;
                case "5":
                    TotalTransactions();
                    break;
                case "6":
                    QuitApplication();
                    break;
                default:
                    Console.WriteLine("{0} is not a valid choice", selection);
                    break;
            }
        }

        private static void CreateNewAccount()
        {
            string userName = string.Empty;
            Console.WriteLine("Please enter a name for your new account");
            userName = Console.ReadLine();
            Console.WriteLine("You have create a new account for {0:C2}", userName);
        }


        private static void ProcessDeposit()
        {
            string userInput = string.Empty;
            Console.WriteLine("How much do you want to deposit?.");
            userInput = Console.ReadLine();
            deposit = Double.Parse(userInput);

            Console.WriteLine("{0:c} has been deposited", deposit);

            balance += deposit;

            Console.WriteLine("you have {0:C2} in your account", balance);
        }


        private static void ProcessWithdrawl()
        {
            string userInput = string.Empty;
            Console.WriteLine("How much do you want to withdrawal?.");
            userInput = Console.ReadLine();
            withdraw = Double.Parse(userInput);
            int withdrawcharge = int.Parse(userInput);


            Console.WriteLine("{0:c} has been withdrawn", withdraw);

            balance -= withdraw;
            Console.WriteLine("you have {0:C2} in your account", balance);
        }

      
        private static void ProcessCheckBalance()
        {
            Console.WriteLine("Your current balance is {0:C}", balance);
        }


        private static void TotalTransactions()
        {
            Console.WriteLine("Your total transactions:");

        }


        private static void QuitApplication()
        {
            Console.WriteLine("Have a great day!.");

        }

        public static void Main()
        {
            string user_input;

            do
            {

                Menu();
                user_input = GetUserInput();
                menuSelection(user_input);



            } while (user_input != "6");

        }
    }
}
