#pragma once
#include "BankUser.h"

class Bank
{
public:
	Bank() = default;
	~Bank();

	void depositIntoBankAccount(int value, int cardCode, int egn);
	void withdrawFromBankAccount(int value, int cardCode, int cardPin, int egn);

	void printBankAccout(int egn);
	void addBankAccount(int egn);
	void eraseBankAccount(int egn);

	void printCard(int egn);
	void addCard(int egn);
	void eraseCard(int egn);
	void eraseCardAndUser(int egn);

	void printUsers();
	void addUser(BankUser* bankUser);
	void eraseUser();

private:
	std::vector<BankUser*> m_vUsers;
};