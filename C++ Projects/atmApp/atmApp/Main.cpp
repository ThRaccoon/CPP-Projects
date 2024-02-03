#include <iostream>

double deposit(double balance);
double withdraw(double balance);
void showBalance(double balance);

int main()
{
	double balance = 0;
	int option = 0;
	 
	do {
		std::cout << "------------------------" << std::endl;
		std::cout << "Please choose a option" << std::endl;
		std::cout << "Press 1 for deposit" << std::endl;
		std::cout << "Press 2 for withdraw" << std::endl;
		std::cout << "Press 3 to check balance" << std::endl;
		std::cout << "Press 4 to exit" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cin >> option;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter only digits from 1 to 4!" << std::endl;
		}

		switch (option) {
		case 1:
		{
			balance = deposit(balance);
			break;
		}
		case 2:
		{
			balance = withdraw(balance);
			break;
		}
		case 3:
		{
			showBalance(balance);
			break;
		}
		case 4:
		{
			std::cout << "Thanks for visiting" << std::endl;
			exit(0);
			break;
		}
		default:
		{
			std::cout << "Error" << std::endl;
			break;
		}
		}

	} while (option != 4);

	return 0;
}

double deposit(double balance)
{
	double result = 0;
	double depositMoney;
	std::cout << "Enter the amout you want to deposit" << std::endl;
	std::cin >> depositMoney;
	if (depositMoney > 0) {
		std::cout << "You deposit " << "$" << depositMoney << std::endl;
		result = balance + depositMoney;
	}
	else
	{
		std::cout << "Invalid value" << std::endl;
	}

	return result;
}

double withdraw(double balance)
{
	double result = 0;
	double withdrawMoney;
	std::cout << "Enter the amout you want to withdraw" << std::endl;
	std::cin >> withdrawMoney;
	if (balance >= withdrawMoney)
	{
		std::cout << "You withdraw " << "$" << withdrawMoney << std::endl;
		result = balance - withdrawMoney;
	}
	else
	{
		std::cout << "You don't have enough balance" << std::endl;
		return balance;
	}

	return result;
}

void showBalance(double balance)
{
	std::cout << "Your balance is " << balance << "$" << std::endl;
}