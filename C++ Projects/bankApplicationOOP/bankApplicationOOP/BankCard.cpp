#include "BankCard.h"

BankCard::BankCard(std::string cardFName, std::string cardLName, int cardCode, int cardPin, int cardEGN)
	:m_cardFName(cardFName)
	, m_cardLName(cardLName)
	, m_cardCode(cardCode)
	, m_cardPin(cardPin)
	, m_cardEGN(cardEGN)
{
}
BankCard::~BankCard()
{
	for (auto accounts : m_vAccounts)
	{
		delete accounts;
		std::cout << "Destructor was called!" << std::endl;
	}
}


void BankCard::depositIntoBankAccount(int value, int cardCode)
{
	int value1;

	if (m_vAccounts.empty())
	{
		std::cout << "The list of bank accounts is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vAccounts.size(); i++)
	{
		if (cardCode == m_vAccounts[i]->getAccCode())
		{
			value1 = m_vAccounts[i]->getbalance();
			value1 += value;
			m_vAccounts[i]->addbalance(value1);
			std::cout << "You successfully deposit:" << value << "$ into your bank account!" << std::endl;
			pressAnyKey();
			return;
		}
	}
	std::cout << "Bank account with this card code was not found" << std::endl;
	pressAnyKey();
}
void BankCard::withdrawFromBankAccount(int value, int cardCode, int cardPin)
{
	int value1;

	if (m_vAccounts.empty())
	{
		std::cout << "The list of bank accounts is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vAccounts.size(); i++)
	{
		if (cardCode == m_vAccounts[i]->getAccCode() && cardPin == m_vAccounts[i]->getAccPin())
		{
			value1 = m_vAccounts[i]->getbalance();
			if (value <= value1)
			{
				value1 -= value;
				m_vAccounts[i]->addbalance(value1);
				std::cout << "You successfully withdraw:" << value << "$ from your bank account!" << std::endl;
				pressAnyKey();
				return;
			}
		}
	}
	std::cout << "Bank account with this card code or card PIN was not found" << std::endl;
	pressAnyKey();
}

void BankCard::printCard(std::string cardFName, std::string cardLName, int cardCode, int cardPin)
{
	std::string text = cardFName + " " + cardLName;
	int size = cardFName.size() + cardLName.size();

	std::cout << "|-----------------------|" << std::endl;
	std::cout << "| Racco0n's bank        |" << std::endl;
	std::cout << "|                       |" << std::endl;

	std::cout << "|";
	for (int i = 0; i < 16 - 8; i++)
	{
		std::cout << " ";
	}
	std::cout << cardCode;
	for (int i = 0; i < 15 - 8; i++)
	{
		std::cout << " ";
	}
	std::cout << "|" << std::endl;

	std::cout << "|";
	std::cout << text;
	for (int i = 0; i < 23 - text.size() - 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "R0|" << std::endl;
	std::cout << "|-----------------------|" << std::endl;

	std::cout << std::endl;
	std::cout << "|-----------------------|" << std::endl;
	std::cout << "|                       |" << std::endl;
	std::cout << "|=======================|" << std::endl;
	std::cout << "|                    " << cardPin << "|" << std::endl;
	std::cout << "|                       |" << std::endl;
	std::cout << "|-----------------------|" << std::endl;
	pressAnyKey();
}

void BankCard::printBankAccount(int cardCode, int cardPin)
{
	if (m_vAccounts.empty())
	{
		std::cout << "The list of bank accounts is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vAccounts.size(); i++)
	{
		if (cardCode == m_vAccounts[i]->getAccCode() && cardPin == m_vAccounts[i]->getAccPin())
		{
			std::cout << m_vAccounts[i]->getAccCode() << std::endl;
			std::cout << m_vAccounts[i]->getAccPin() << std::endl;
			std::cout << "Your balance is:";
			std::cout << m_vAccounts[i]->getbalance();
			std::cout << "$" << std::endl;
			pressAnyKey();
			return;
		}
	}
	std::cout << "Bank account with this card code was not found" << std::endl;
	pressAnyKey();
}
void BankCard::addBankAccount(BankAccount* bankAccount, int egn)
{
	if (m_vAccounts.empty())
	{
		m_vAccounts.push_back(bankAccount);
		std::cout << "Bank account was added!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vAccounts.size(); i++)
	{
		if (egn == m_vAccounts[i]->getAccEGN())
		{
			std::cout << "Account with this EGN:" << egn << " already exist!" << std::endl;
			pressAnyKey();
			return;
		}
	}
	m_vAccounts.push_back(bankAccount);
	std::cout << "Bank account was added!" << std::endl;
	pressAnyKey();
}
void BankCard::eraseBankAccount(int egn)
{
	if (m_vAccounts.empty())
	{
		std::cout << "The list of bank accounts is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vAccounts.size(); i++)
	{
		if (egn == m_vAccounts[i]->getAccEGN())
		{
			m_vAccounts.erase(m_vAccounts.begin() + i);
			std::cout << "Bank account was deleted!" << std::endl;
			pressAnyKey();
			return;
		}
	}
	std::cout << "Bank account with this card code was not found!" << std::endl;
	pressAnyKey();
}

void BankCard::addCardFName(std::string cardFName)
{
	m_cardFName = cardFName;
}
std::string BankCard::getCardFName()
{
	return m_cardFName;
}

void BankCard::addCardLName(std::string cardLName)
{
	m_cardLName = cardLName;
}
std::string BankCard::getCardLName()
{
	return m_cardLName;
}

void BankCard::addCardCode(int cardCode)
{
	m_cardCode = cardCode;
}
int BankCard::getCardCode()
{
	return m_cardCode;
}

void BankCard::addCardPin(int cardPin)
{
	m_cardPin = cardPin;
}
int BankCard::getCardPin()
{
	return m_cardPin;
}

void BankCard::addCardEGN(int cardEGN)
{
	m_cardEGN = cardEGN;
}
int BankCard::getCardEGN()
{
	return m_cardEGN;
}