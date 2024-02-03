#pragma once
#include "BankCard.h"
#include <string> 
#include <random>

class BankUser
{
public:
	BankUser() = default;
	BankUser(std::string fName, std::string lName, std::string bDate, int egn);
	~BankUser();

	void depositIntoBankAccount(int value, int cardCode);
	void withdrawFromBankAccount(int value, int cardCode, int cardPin);

	void printBankAccount(int egn);
	void addBankAccount(int egn);
	void eraseBankAccount(int egn);

	void printCard(std::string cardFName, std::string cardLName, int egn);
	void addCard(BankCard* bankCard, int egn);
	void eraseCard(int egn);
	void eraseCardAndUser(int egn);

	int pinGen();
	int codeGen();

	void printUser(std::string fName, std::string lName, std::string bDate, int egn);

	void addFName(std::string fName);
	std::string getFName();

	void addLName(std::string lName);
	std::string getLName();

	void addBDate(std::string bDate);
	std::string getBDate();

	void addEGN(int egn);
	int getEGN();
	int getEGN() const;

private:
	std::vector<BankCard*> m_vCards;
	std::string m_fName;
	std::string m_lName;
	std::string m_bDate;
	int m_egn;

};
