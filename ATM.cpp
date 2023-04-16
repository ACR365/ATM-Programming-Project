#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

bool endProgram = false;

struct CustomerInfo
{
	string customerName; //for enrollment purpose
	string loginID;      //for login purpose
	string passWord;     //for login purpose
	int numOfAccounts;
	int accountNumber[3];
	float accountBalance[3];
	bool accountStatus[3];
	bool logStatus;      //logged in or off
};

int numOfEnrolled = 0; //for customer search purpose
CustomerInfo ATM[20];
int currentCustomer; //index (subscript) into the ATM array

void Enrollment()
{
	bool registration = true;
	char choice;
	do
	{
		cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
		cout << "Please enter your first name.\nName: ";
		cin >> ATM[numOfEnrolled].customerName;

		bool enrollCheck = false;
		if (numOfEnrolled >= 1) //If the person makes another account, this will employ the checking the array
		{
			bool nameCheck = false;
			while (nameCheck != true)
			{
				for (int check = 0; check < numOfEnrolled; check++) //checking if the customer's name is already in the array
				{
					if (ATM[check].customerName != ATM[numOfEnrolled].customerName)
					{
						enrollCheck = true;
					}
				}

				if (enrollCheck == true)
				{
					nameCheck = true;
				}
				else
				{
					cout << "Name is already taken! Please enter a different name." << endl;
					cout << "Name: ";
					cin >> ATM[numOfEnrolled].customerName;
				}
			}
		}
	
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Next, create a login ID for your Biolan Virtual Bank account\nLogin ID: ";
		cin >> ATM[numOfEnrolled].loginID;

		bool loginCheck = false;
		if (numOfEnrolled >= 1)
		{
			bool login = false;
			while (loginCheck != true)
			{
				for (int check2 = 0; check2 < numOfEnrolled; check2++) //checking if the customer's login ID is already in the array
				{
					if (ATM[numOfEnrolled].loginID != ATM[check2].loginID)
					{
						login = true;
					}
				}

				if (login == true)
				{
					loginCheck = true;
				}
				else
				{
					cout << "Login ID is already taken! Please enter a different name." << endl;
					cout << "Login ID: ";
					cin >> ATM[numOfEnrolled].loginID;
				}
			}
		}
	
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Finally, create a password for your Biolan Virtual Bank account\nPassword: ";
		cin >> ATM[numOfEnrolled].passWord;
		cout << endl << "Biolan Virtual Bank account created!" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Do you want to create another account?\nY\nN\nAnswer: ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			registration = true;
			numOfEnrolled++;
		}
		else if (choice == 'N' || choice == 'n')
		{
			registration = false;
			numOfEnrolled++;
		}
		else
		{
			cout << "Invalid response! Please enter Y or N.\nY\nN\nAnswer: ";
			cin >> choice;
		}

	} while (registration == true);
}

void login()
{
	string loginID, password;
	bool login = false;
	cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
	cout << "Welcome to the Biolan Virtual Bank\nPlease login to access your account" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Login ID: ";
	cin >> loginID;
	cout << "Password: ";
	cin >> password;

	bool loginCheck = true;
	do
	{
		bool login = false;
		for (int check = 0; check < numOfEnrolled; check++) //checking if the customer's login ID or password is correct
		{
			
			if (loginID == ATM[check].loginID && password == ATM[check].passWord)
			{
				login = true;
				currentCustomer = check;
			}
		}

		if (login == true)
		{
			loginCheck = true;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl << endl;
			cout << "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()(" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||Welcome to the Biolan Virtual Bank!||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << ")()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()" << endl << endl;
		}
		else
		{
			cout << "Login is invalid! Please try again." << endl;
			cout << "Login ID: ";
			cin >> loginID;
			cout << "Password: ";
			cin >> password;
		}
	} while (loginCheck == false);
}

int exit() //The menu that returns to the login screen if a person chooses to leave the ATM (Option 7)
{
	string loginID, password;
	bool login = false;
	cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
	cout << "Welcome to the Biolan Virtual Bank\nPlease login to access your account or type quit to leave the ATM" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Login ID: ";
	cin >> loginID;


	if (loginID == "quit") //Will not even ask for the password if they type 'quit'
	{
		endProgram = true;
		cout << endl << "Thank you and have a good day!!" << endl;
		return 0;
	}

	cout << "Password: ";
	cin >> password;

	bool loginCheck = true;
	do
	{
		bool login = false;
		for (int check = 0; check < numOfEnrolled; check++) //checking if the customer's login ID or password is correct
		{

			if (loginID == ATM[check].loginID && password == ATM[check].passWord)
			{
				login = true;
				currentCustomer = check;
			}
		}

		if (login == true)
		{
			loginCheck = true;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl << endl;
			cout << "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()(" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||Welcome to the Biolan Virtual Bank!||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << ")()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()" << endl << endl;
		}
		else
		{
			cout << "Login is invalid! Please try again." << endl;
			cout << "Login ID: ";
			cin >> loginID;
			cout << "Password: ";
			cin >> password;
		}
	} while (loginCheck == false);

	return 0;
}

int menu()
{
	int choice;
	cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
	cout << "Welcome " << ATM[currentCustomer].customerName << "!" << endl;
	cout << "1.Opening an Account                        4.Withdrawing Money from Account" << endl;
	cout << "2.Checking Account Balance                  5.Transferring Money from Account" << endl;
	cout << "3.Depositing Money			    6.Closing an account" << endl << endl;
	cout << "			7. Log off account" << endl;
	cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
	cin >> choice;
	return choice;
}

int openingAccount() //Option 1
{
	if (ATM[currentCustomer].numOfAccounts == 3)
	{
		cout << "You can not open up more than 3 accounts" << endl;
		return 0;
	}

	ATM[currentCustomer].accountStatus[ATM[currentCustomer].numOfAccounts] = true; //true = open, false = closed

	int minAccountNum = 100;
	int maxAccountNum = 999;
	ATM[currentCustomer].accountBalance[ATM[currentCustomer].numOfAccounts] = 0;
	ATM[currentCustomer].accountNumber[ATM[currentCustomer].numOfAccounts] = rand() % 999 + 100;

	return ATM[currentCustomer].accountNumber[ATM[currentCustomer].numOfAccounts];

}

void accountBalance() //Option 2
{
	int accountNum, accountIndex;
	bool accountNumber = false;
	
	cout << "Please enter your account number to check your balance\nAccount Number: ";
	cin >> accountNum;

	while (accountNumber != true)
	{

		int trueCount = 0;
		for (int check = 0; check < ATM[currentCustomer].numOfAccounts; check++)
		{
			if (accountNum == ATM[currentCustomer].accountNumber[check] && ATM[currentCustomer].accountStatus[check] == true)
			{
				trueCount++;
				accountIndex = check;
			}
		}
			if (trueCount == 1) //if check is false
			{
				accountNumber = true;
				cout << accountIndex;
			}
			else
			{
				accountNumber = false;
				cout << "Error: Invalid account number. Please enter again." << endl;
				cout << "Account Number: ";
				cin >> accountNum;
			}

	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Account Balance: $" << ATM[currentCustomer].accountBalance[accountIndex] << " ----------------------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

void accountDeposit() //Option 3
{
	int accountNum, accountIndex;
	double depositAmount;
	bool accountNumber = false;
	bool amountCheck = false;

	cout << "Please enter your account number in which you want to deposit money into\nAccount Number: ";
	cin >> accountNum;

	while (accountNumber != true)
	{

		int trueCount = 0;
		for (int check = 0; check < ATM[currentCustomer].numOfAccounts; check++)
		{
			if (accountNum == ATM[currentCustomer].accountNumber[check] && ATM[currentCustomer].accountStatus[check] == true)
			{
				trueCount++;
				accountIndex = check;
			}
		}
		if (trueCount == 1) //if check is false
		{
			accountNumber = true;
			cout << accountIndex;
		}
		else
		{
			accountNumber = false;
			cout << "Error: Invalid account number. Please enter again." << endl;
			cout << "Account Number: ";
			cin >> accountNum;
		}

	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please enter the amount you want deposited into the account" << endl;
	cout << "Amount: ";
	cin >> depositAmount;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	while (amountCheck != true)
	{
		if (depositAmount <= 0)
		{
			cout << "Please enter a nonzero and nonnegative amount you want to deposit" << endl;
			cout << "Amount: ";
			cin >> depositAmount;
		}
		else
		{
			amountCheck = true;
		}
	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	ATM[currentCustomer].accountBalance[accountIndex] =+ depositAmount;
	cout << "Deposit is complete!" << endl;

}

void accountWithdrawal() //Option 4
{
	int accountNum, accountIndex;
	double withdrawalAmount;
	bool amountCheck = false;
	bool accountNumber = false;

	cout << "Please enter your account number in which you want to withdraw money from\nAccount Number: ";
	cin >> accountNum;

	while (accountNumber != true)
	{

		int trueCount = 0;
		for (int check = 0; check < ATM[currentCustomer].numOfAccounts; check++)
		{
			if (accountNum == ATM[currentCustomer].accountNumber[check] && ATM[currentCustomer].accountStatus[check] == true)
			{
				trueCount++;
				accountIndex = check;
			}
		}
		if (trueCount == 1) //if check is false
		{
			accountNumber = true;
			cout << accountIndex;
		}
		else
		{
			accountNumber = false;
			cout << "Error: Invalid account number. Please enter again." << endl;
			cout << "Account Number: ";
			cin >> accountNum;
		}

	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please enter the amount you want withdrawn into the account" << endl;
	cout << "Amount: ";
	cin >> withdrawalAmount;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

	while (amountCheck != true)
	{
		if (withdrawalAmount <= 0)
		{
			amountCheck = false;
			cout << "Please enter a nonzero and nonnegative amount you want to deposit" << endl;
			cout << "Amount: ";
			cin >> withdrawalAmount;
		}
		else
		{
			amountCheck = true;
		}
	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	if (withdrawalAmount > ATM[currentCustomer].accountBalance[accountIndex])
	{
		while (withdrawalAmount > ATM[currentCustomer].accountBalance[accountIndex])
		{
			cout << "Error: Withdrawal amount is greater than your balance" << endl;
			cout << "Amount: ";
			cin >> withdrawalAmount;
		}
	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	ATM[currentCustomer].accountBalance[accountIndex] = ATM[currentCustomer].accountBalance[accountIndex] - withdrawalAmount;
	cout << "Witdrawal is complete!" << endl;
}

void accountTransfer() //Option 5
{
	int accountNum, accountIndex, accountTransferto, accTransferIndex, transferIndex;
	double transferAmount;
	bool amountCheck = false;
	bool accountNumber = false;

	cout << "Please enter the account in which you are accessing the funds" << endl;
	cout << "Account Number: ";
	cin >> accountNum;

	while (accountNumber != true)
	{

		int trueCount = 0;
		for (int check = 0; check < ATM[currentCustomer].numOfAccounts; check++)
		{
			if (accountNum == ATM[currentCustomer].accountNumber[check] && ATM[currentCustomer].accountStatus[check] == true)
			{
				trueCount++;
				accountIndex = check;
			}
		}
		if (trueCount == 1) //if check is false
		{
			accountNumber = true;
			cout << accountIndex;
		}
		else
		{
			accountNumber = false;
			cout << "Error: Invalid account number. Please enter again." << endl;
			cout << "Account Number: ";
			cin >> accountNum;
		}

	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Next, please enter the account number in which you want to transfer money to" << endl;
	cout << "Account Number: ";
	cin >> accountTransferto;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

	bool accountTransfercheck = false;
	int transferTrueCount = 0;
	while (accountTransfercheck != true) //Checks the account number of the second person
	{
		for (int i = 0; i < numOfEnrolled; i++)
		{
			for (int c = 0; c < ATM[i].numOfAccounts; c++)
			{
				if (ATM[i].accountNumber[c] == accountTransferto && ATM[i].accountStatus[c] == true)
				{
					transferTrueCount++;
					accTransferIndex = c;
					transferIndex = i;
				}
			}
		}

		if (transferTrueCount == 1)
		{
			accountTransfercheck = true;
		}
		else
		{
			accountTransfercheck = false;
			cout << "Error: The acount number in which you are trying to transfer money to is invalid. Please enter again" << endl;
			cout << "Account Number: ";
			cin >> accountTransferto;
		}
			
		
	}

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please enter the amount you want withdrawn into the account" << endl;
	cout << "Amount: ";
	cin >> transferAmount;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

	while (amountCheck != true)
	{
		if (transferAmount <= 0)
		{
			amountCheck = false;
			cout << "Please enter a nonzero and nonnegative amount you want to deposit" << endl;
			cout << "Amount: ";
			cin >> transferAmount;
		}
		else
		{
			amountCheck = true;
		}
	}

	ATM[currentCustomer].accountBalance[accountIndex] = ATM[currentCustomer].accountBalance[accountIndex] - transferAmount;
	ATM[transferIndex].accountBalance[accTransferIndex] = ATM[transferIndex].accountBalance[accTransferIndex] + transferAmount;
	cout << "Transfer completed!" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

void closingAccount() //Option 6
{
	int accountNum, accountIndex;
	bool accountNumber = false;

	cout << "Please enter your account number\nAccount Number: ";
	cin >> accountNum;

	while (accountNumber != true)
	{

		int trueCount = 0;
		for (int check = 0; check < ATM[currentCustomer].numOfAccounts; check++)
		{
			if (accountNum == ATM[currentCustomer].accountNumber[check] && ATM[currentCustomer].accountStatus[check] == true)
			{
				trueCount++;
				accountIndex = check;
			}
		}
		if (trueCount == 1) //if check is false
		{
			accountNumber = true;
			cout << accountIndex;
		}
		else
		{
			accountNumber = false;
			cout << "Error: Invalid account number. Please enter again." << endl;
			cout << "Account Number: ";
			cin >> accountNum;
		}

	}


	ATM[currentCustomer].accountStatus[accountIndex] = false; //false, once again, means the account is closed
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "The account is now closed!" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

}

int main()
{

	cout << "Welcome to the Biolan Virtual Bank!\nPlease enter the following to register as a member under this bank" << endl;
	//Enrolling into a bank
	Enrollment();

	//Logging into the ATM
	login();

	while (endProgram != true)
	{

		//The menu
		int choice = menu(); //The variable will receive the value from the menu

		switch (choice)
		{
		case 1:
			cout << endl << "-------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Account Number: " << openingAccount() << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			ATM[currentCustomer].numOfAccounts++;
			cout << "Number of Accounts Currently: " << ATM[currentCustomer].numOfAccounts << endl;
			break;
		case 2:
			if (ATM[currentCustomer].numOfAccounts == 0) //If no accounts are opened, the program will go back to the menu
			{
				cout << "There are no accounts under this name. Please open an account before accessing account balance" << endl;
				break;
			}
			accountBalance();
			break;
		case 3:
			if (ATM[currentCustomer].numOfAccounts == 0)
			{
				cout << "There are no accounts under this name. Please open an account before accessing account balance" << endl;
				break;
			}
			accountDeposit();
			break;
		case 4:
			if (ATM[currentCustomer].numOfAccounts == 0)
			{
				cout << "There are no accounts under this name. Please open an account before accessing account balance" << endl;
				break;
			}
			accountWithdrawal();
			break;
		case 5:
			if (ATM[currentCustomer].numOfAccounts == 0)
			{
				cout << "There are no accounts under this name. Please open an account before accessing account balance" << endl;
				break;
			}
			accountTransfer();
			break;
		case 6:
			if (ATM[currentCustomer].numOfAccounts == 0)
			{
				cout << "There are no accounts under this name. Please open an account before accessing account balance" << endl;
				break;
			}
			closingAccount();
			break;
		case 7:
			cout << "Logging off now........." << endl;
			cout << "Thank you for using the Biolan Virtual bank and have a good day" << endl;
			exit();
			break;
		}
	}
	return 0;
}