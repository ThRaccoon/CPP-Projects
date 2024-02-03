#include "Bank.h"
#include <iostream>

BankAccount ba;
BankAccount* baa;
BankCard bc;
BankCard* bcc;
BankUser bu;
BankUser* buu;
Bank b;
Bank* bb;

int main()
{
	std::string fName, lName, dateOfBirth, cardFName, cardLName;
	int egn, cardEGN, cardCode, cardPin, value;
	int op = 0;

	while (true)
	{
		system("cls");
		std::cout << "||------------------------------------------------||" << std::endl;
		std::cout << "||      Welcome to Racco0n-Federation's bank      ||" << std::endl;
		std::cout << "||------------------------------------------------||" << std::endl;
		std::cout << std::endl;
		std::cout << "1.To add new user                          press (1)" << std::endl;
		std::cout << "2.To show a user                           press (2)" << std::endl;
		std::cout << "3.To remove a user                         press (3)" << std::endl;
		std::cout << "4.To add a card to a user                  press (4)" << std::endl;
		std::cout << "5.To show a card linked to a user          press (5)" << std::endl;
		std::cout << "6.To remove a card                         press (6)" << std::endl;
		std::cout << "7.To add a bank account to a user          press (7)" << std::endl;
		std::cout << "8.To show a bank account linked to a user  press (8)" << std::endl;
		std::cout << "9.To remove a bank account                 press (9)" << std::endl;
		std::cout << "10.To deposit into bank account            press (10)" << std::endl;
		std::cout << "11.To withdraw from bank account           press (11)" << std::endl;
		std::cout << "0.To exit                                  press (0)" << std::endl;
		std::cout << ">";
		std::cin >> op;
		isItInt(op);

		switch (op)
		{
		case 1:
		{
			system("cls");
			std::cin.ignore();
			std::cout << "Enter user first name: " << std::endl;
			std::cout << ">";
			getline(std::cin, fName);
			std::cout << "Enter user last name: " << std::endl;
			std::cout << ">";
			getline(std::cin, lName);
			std::cout << "Enter user date of birth: " << std::endl;
			std::cout << ">";
			getline(std::cin, dateOfBirth);
			std::cout << "Enter user EGN: " << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			buu = new BankUser(fName, lName, dateOfBirth, egn);
			b.addUser(buu);
			break;
		}
		case 2:
		{
			system("cls");
			b.printUsers();
			break;
		}
		case 3:
		{
			system("cls");
			b.eraseUser();
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "Enter user EGN: " << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.addCard(egn);
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Enter the EGN linked to the card that you want to show: " << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.printCard(egn);
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "Enter the EGN linked to the card that you want to delete: " << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.eraseCard(egn);
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "Enter user EGN:" << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.addBankAccount(egn);
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "Enter user EGN:" << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.printBankAccout(egn);
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "Enter user EGN:" << std::endl;
			std::cout << ">";
			std::cin >> egn;
			isItInt(egn);
			b.eraseBankAccount(egn);
			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "Enter user EGN:" << std::endl;
			std::cout << ">";
			std::cin >> egn;
			std::cout << "Enter card code:" << std::endl;
			std::cout << ">";
			std::cin >> cardCode;
			isItInt(cardCode);
			std::cout << "Deposit the value:" << std::endl;
			std::cout << ">";
			std::cin >> value;
			isItInt(value);
			b.depositIntoBankAccount(value, cardCode, egn);
			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "Enter user EGN:" << std::endl;
			std::cout << ">";
			std::cin >> egn;
			std::cout << "Enter card code:" << std::endl;
			std::cout << ">";
			std::cin >> cardCode;
			isItInt(cardCode);
			std::cout << "Enter card pin:" << std::endl;
			std::cout << ">";
			std::cin >> cardPin;
			isItInt(cardPin);
			std::cout << "Deposit the value:" << std::endl;
			std::cout << ">";
			std::cin >> value;
			isItInt(value);
			b.withdrawFromBankAccount(value, cardCode, cardPin, egn);
			break;
		}
		case 0:
		{
			system("cls");
			std::cout << "Are you sure you want to close this application?" << std::endl;
			std::cout << "Press (1) for YES" << std::endl;
			std::cout << "Press (2) for NO" << std::endl;
			std::cin >> op;
			isItInt(op);

			if (op == 1)
			{
				std::cout << "Thanks for using my application!" << std::endl;
				return 0;
			}
			else if (op == 2)
			{
				break;
			}
			break;
		}
		default:
		{
			system("cls");
			std::cout << "Enter numbers from (1) to (11)!" << std::endl;
			pressAnyKey();
			break;
		}
		}
	}
	return 0;
}