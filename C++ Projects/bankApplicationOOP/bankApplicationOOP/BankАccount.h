#pragma once
#include <iostream>

int isItInt(int& digit);
void pressAnyKey();

class BankAccount
{
public:
	BankAccount() = default;
	BankAccount(int balance, int accCode, int accPin, int egn);

	void addbalance(int Balance);
	int getbalance();

	void addAccCode(int accCode);
	int getAccCode();

	void addAccPin(int accPin);
	int getAccPin();

	void addAccEGN(int accEGN);
	int getAccEGN();

private:
	int m_balance;
	int m_accCode;
	int m_accPin;
	int m_accEGN;
};
