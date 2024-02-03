#pragma once
#include "BankАccount.h"
#include <vector>

class BankCard
{
public:
	BankCard() = default;
	BankCard(std::string cardFName, std::string cardLName, int cardCode, int cardPin, int cardEGN);
	~BankCard();

	void depositIntoBankAccount(int value, int cardCode);
	void withdrawFromBankAccount(int value, int cardCode, int cardPin);

	void printCard(std::string cardFName, std::string cardLName, int cardCode, int cardPin);

	void printBankAccount(int accCode, int accPin);
	void addBankAccount(BankAccount* bankAccount, int egn);
	void eraseBankAccount(int egn);

	void addCardFName(std::string cardFName);
	std::string getCardFName();

	void addCardLName(std::string cardLName);
	std::string getCardLName();

	void addCardCode(int cardCode);
	int getCardCode();

	void addCardPin(int cardPin);
	int getCardPin();

	void addCardEGN(int cardEGN);
	int getCardEGN();

private:
	std::vector<BankAccount*> m_vAccounts;
	std::string m_cardFName;
	std::string m_cardLName;
	int m_cardCode;
	int m_cardPin;
	int m_cardEGN;
};
