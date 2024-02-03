#include "BankUser.h"

BankUser::BankUser(std::string fName, std::string lName, std::string bDate, int egn)
	:m_fName(fName)
	, m_lName(lName)
	, m_bDate(bDate)
	, m_egn(egn)
{
}
BankUser::~BankUser()
{
	for (auto cards : m_vCards)
	{
		delete cards;
		std::cout << "Destructor was called!" << std::endl;
	}
}

void BankUser::depositIntoBankAccount(int value, int cardCode)
{
	if (m_vCards.empty())
	{
		std::cout << "List of cards is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (cardCode == m_vCards[i]->getCardCode())
		{
			m_vCards[i]->depositIntoBankAccount(value, cardCode);
			return;
		}
	}
	std::cout << "Card with this code:" << cardCode << " do not exist!" << std::endl;
	pressAnyKey();
}
void BankUser::withdrawFromBankAccount(int value, int cardCode, int cardPin)
{
	if (m_vCards.empty())
	{
		std::cout << "List of cards is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (cardCode == m_vCards[i]->getCardCode())
		{
			m_vCards[i]->withdrawFromBankAccount(value, cardCode, cardPin);
			return;
		}
	}
	std::cout << "Card with this code:" << cardCode << " do not exist!" << std::endl;
	pressAnyKey();
}

void BankUser::printBankAccount(int egn)
{
	int cardCode, cardPin;

	if (m_vCards.empty())
	{
		std::cout << "List of cards is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			cardCode = m_vCards[i]->getCardCode();
			cardPin = m_vCards[i]->getCardPin();
			m_vCards[i]->printBankAccount(cardCode, cardPin);
			return;
		}
	}
	std::cout << "Card with this egn:" << egn << " do not exist!" << std::endl;
	pressAnyKey();
}
void BankUser::addBankAccount(int egn)
{
	BankAccount* baa;
	int balance = 0, cardCode, cardPin;

	if (m_vCards.empty())
	{
		std::cout << "List of cards is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			cardCode = m_vCards[i]->getCardCode();
			cardPin = m_vCards[i]->getCardPin();
			baa = new BankAccount(balance, cardCode, cardPin, egn);
			m_vCards[i]->addBankAccount(baa, egn);
			return;
		}
	}
	std::cout << "Card with this egn:" << egn << " do not exist!" << std::endl;
}
void BankUser::eraseBankAccount(int egn)
{
	if (m_vCards.empty())
	{
		std::cout << "List of cards is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			for (auto cards : m_vCards)
			{
				cards->eraseBankAccount(egn);
				return;
			}
		}
	}

	std::cout << "Card with this egn:" << egn << " do not exist!" << std::endl;
	pressAnyKey();
}

void BankUser::printCard(std::string cardFName, std::string cardLName, int egn)
{
	if (m_vCards.empty())
	{
		std::cout << "Card list is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	int cardCode = 0;
	int cardPin = 0;

	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			cardCode = m_vCards[i]->getCardCode();
			cardPin = m_vCards[i]->getCardPin();

			for (auto cards : m_vCards)
			{
				cards->printCard(cardFName, cardLName, cardCode, cardPin);
				return;
			}
		}
	}
	std::cout << "This user don't have a card!" << std::endl;
	pressAnyKey();
	return;
}
void BankUser::addCard(BankCard* bankCard, int egn)
{
	m_vCards.push_back(bankCard);
	std::cout << "Card was added to a user with EGN:" << egn << "!" << std::endl;
	pressAnyKey();
}
void BankUser::eraseCard(int egn)
{
	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			int cardCode = m_vCards[i]->getCardCode();
			int cardPin = m_vCards[i]->getCardPin();

			m_vCards.erase(m_vCards.begin() + i);
			std::cout << "Card was deleted!" << std::endl;

			for (auto cards : m_vCards)
			{
				cards->eraseBankAccount(egn);
				return;
			}
		}
	}
	std::cout << "Card linked to this EGN: '" << egn << "' do not exist!" << std::endl;
	pressAnyKey();
}
void BankUser::eraseCardAndUser(int egn)
{
	for (int i = 0; i < m_vCards.size(); i++)
	{
		if (egn == m_vCards[i]->getCardEGN())
		{
			m_vCards.erase(m_vCards.begin() + i);
			std::cout << "The card linked to this user was deleted!" << std::endl;
			return;
		}
	}
	std::cout << "User with this EGN: '" << egn << "' do not have a card!" << std::endl;
}

int BankUser::pinGen()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(111, 999);
	int rand = dist(rd);
	return rand;
}
int BankUser::codeGen()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(11111111, 99999999);
	int rand = dist(rd);
	return rand;
}

void BankUser::printUser(std::string fName, std::string lName, std::string bDate, int egn)
{
	std::cout << "Name: " << fName << " " << lName << std::endl;
	std::cout << "Date of birth: " << bDate << std::endl;
	std::cout << "EGN: " << egn << std::endl;
	pressAnyKey();
}

void BankUser::addFName(std::string fName)
{
	m_fName = fName;
}
std::string BankUser::getFName()
{
	return m_fName;
}

void BankUser::addLName(std::string lName)
{
	m_lName = lName;
}
std::string BankUser::getLName()
{
	return m_lName;
}

void BankUser::addBDate(std::string bDate)
{
	m_bDate = bDate;
}
std::string BankUser::getBDate()
{
	return m_bDate;
}

void BankUser::addEGN(int egn)
{
	m_egn = egn;
}
int BankUser::getEGN() const
{
	return m_egn;
}
int BankUser::getEGN()
{
	return m_egn;
}