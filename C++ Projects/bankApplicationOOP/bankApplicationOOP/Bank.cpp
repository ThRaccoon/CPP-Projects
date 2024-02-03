#include "Bank.h"

Bank::~Bank()
{
	for (auto users : m_vUsers)
	{
		delete users;
		std::cout << "Destructor was called!" << std::endl;
	}
}

bool operator==(const BankUser& a, const int& b)
{
	return b == a.getEGN();
}

void Bank::depositIntoBankAccount(int value, int cardCode, int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "List of user is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->depositIntoBankAccount(value, cardCode);
				return;
			}
		}
	}
	std::cout << "User with this EGN:" << egn << " do not exist!" << std::endl;
	pressAnyKey();
}
void Bank::withdrawFromBankAccount(int value, int cardCode, int cardPin, int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "List of user is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->withdrawFromBankAccount(value, cardCode, cardPin);
				return;
			}
		}
	}
	std::cout << "User with this EGN:" << egn << " do not exist!" << std::endl;
	pressAnyKey();
}


void Bank::printBankAccout(int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "List of user is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->printBankAccount(egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN:" << egn << " do not exist!" << std::endl;
}
void Bank::addBankAccount(int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "List of user is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->addBankAccount(egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN:" << egn << " do not exist!" << std::endl;
}
void Bank::eraseBankAccount(int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "List of user is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->eraseBankAccount(egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN:" << egn << " do not exist!" << std::endl;
	pressAnyKey();
}

void Bank::printCard(int egn)
{
	std::string cardFName, cardLName;

	if (m_vUsers.empty())
	{
		std::cout << "User list is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			cardFName = m_vUsers[i]->getFName();
			cardLName = m_vUsers[i]->getLName();

			for (auto users : m_vUsers)
			{
				users->printCard(cardFName, cardLName, egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN do not exist!" << std::endl;
	pressAnyKey();
}
void Bank::addCard(int egn)
{
	BankCard* bcc;
	std::string fName, lName;
	int cardCode, cardPin;

	if (m_vUsers.empty())
	{
		std::cout << "User list is empty! You need a user to add a card!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			fName = m_vUsers[i]->getFName();
			lName = m_vUsers[i]->getLName();
			cardCode = m_vUsers[i]->codeGen();
			cardPin = m_vUsers[i]->pinGen();

			bcc = new BankCard(fName, lName, cardCode, cardPin, egn);

			for (auto users : m_vUsers)
			{
				users->addCard(bcc, egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN: '" << egn << "' do not exist!" << std::endl;
	pressAnyKey();
}
void Bank::eraseCard(int egn)
{
	if (m_vUsers.empty())
	{
		std::cout << "User list is empty! You need a user to erase a card!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			for (auto users : m_vUsers)
			{
				users->eraseCard(egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN: '" << egn << "' do not exist or do not have a card!" << std::endl;
	pressAnyKey();
}
void Bank::eraseCardAndUser(int egn)
{
	for (auto users : m_vUsers)
	{
		users->eraseCardAndUser(egn);
	}
}

void Bank::printUsers()
{
	if (m_vUsers.empty())
	{
		std::cout << "The list is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	std::string fName, lName, bDate;
	int egn;

	std::cout << "Enter the EGN of the user you want to see: " << std::endl;
	std::cout << ">";
	std::cin >> egn;

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			fName = m_vUsers[i]->getFName();
			lName = m_vUsers[i]->getLName();
			bDate = m_vUsers[i]->getBDate();

			for (auto users : m_vUsers)
			{
				users->printUser(fName, lName, bDate, egn);
				return;
			}
		}
	}
	std::cout << "User with this EGN: '" << egn << "' do not exist!" << std::endl;
	pressAnyKey();
}
void Bank::addUser(BankUser* bankUser)
{
	if (m_vUsers.empty())
	{
		m_vUsers.push_back(bankUser);
		std::cout << "User was added!" << std::endl;
		pressAnyKey();
		return;
	}

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (*bankUser == m_vUsers[i]->getEGN())
		{
			std::cout << "This EGN is already taken!" << std::endl;
			pressAnyKey();
			return;
		}
	}
	m_vUsers.push_back(bankUser);
	std::cout << "User was added!" << std::endl;
	pressAnyKey();
}
void Bank::eraseUser()
{
	if (m_vUsers.empty())
	{
		std::cout << "List of users is empty!" << std::endl;
		pressAnyKey();
		return;
	}

	int egn = 0;
	std::cout << "Enter the EGN of the user you want to delete: " << std::endl;
	std::cout << ">";
	std::cin >> egn;

	for (int i = 0; i < m_vUsers.size(); i++)
	{
		if (egn == m_vUsers[i]->getEGN())
		{
			eraseCardAndUser(egn);
			m_vUsers.erase(m_vUsers.begin() + i);
			std::cout << "User with EGN '" << egn << "' was deleted!" << std::endl;
			pressAnyKey();
			return;
		}
	}
	std::cout << "User with EGN '" << egn << "' do not exist!" << std::endl;
	pressAnyKey();
}