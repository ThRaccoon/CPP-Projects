#include "BankАccount.h"

BankAccount::BankAccount(int balance, int accCode, int accPin, int accEGN)
	:m_balance(balance)
	, m_accCode(accCode)
	, m_accPin(accPin)
	, m_accEGN(accEGN)
{
}

void BankAccount::addbalance(int balance)
{
	m_balance = balance;
}
int BankAccount::getbalance()
{
	return m_balance;
}

void BankAccount::addAccCode(int accCode)
{
	m_accCode = accCode;
}
int BankAccount::getAccCode()
{
	return m_accCode;
}

void BankAccount::addAccPin(int accPin)
{
	m_accPin = accPin;
}
int BankAccount::getAccPin()
{
	return m_accPin;
}

void BankAccount::addAccEGN(int accEGN)
{
	m_accEGN = accEGN;
}
int BankAccount::getAccEGN()
{
	return m_accEGN;
}

int isItInt(int& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
	return digit;
}
void pressAnyKey()
{
	std::string key;
	std::cout << "Press any key to continue" << std::endl;
	std::cin >> key;
}
