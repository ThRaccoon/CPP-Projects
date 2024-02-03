#include "Patient.h"

Patient::Patient(std::string firstName, std::string lastName, int age,
	char bloodType, int id)

	: m_firstName(firstName)
	, m_lastName(lastName)
	, m_age(age)
	, m_bloodType(bloodType)
	, m_id(id)
{
}

void Patient::AddDam(int number, std::string diagnosis, std::string medicine, std::string date)
{
	for (auto dam : m_dam)
	{
		if (number == dam.getNumber())
		{
			std::cout << "This patient already have DAM on this number!" << std::endl;
			return;
		}
	}
	m_dam.push_back(DiagnosisAndMedicine(number, diagnosis, medicine, date));
}

void Patient::eraseDam(int dimNumber)
{
	if (m_dam.empty())
	{
		std::cout << "This list is empty" << std::endl;
		return;
	}

	for (int i = 0; i < m_dam.size(); i++)
	{
		if (m_dam[i].getNumber() == dimNumber)
		{
			m_dam.erase(m_dam.begin() + i);
			std::cout << "DAM was deleted!" << std::endl;
			std::cout << "Press any key to continue!" << std::endl;
			std::cout << ">";
			char op;
			std::cin >> op;
		}
	}
}

void Patient::printPatient()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Blood type: " << getBloodType() << std::endl;
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "--------------------------" << std::endl;

	for (auto dam : m_dam)
	{
		dam.printDam();
	}
}

void Patient::addFirstName(std::string firstName)
{
	m_firstName = firstName;
}
void Patient::addSecondName(std::string lastName)
{
	m_lastName = lastName;
}
void Patient::addAge(int age)
{
	m_age = age;
}
void Patient::addBloodType(char bloodType)
{
	m_bloodType = bloodType;
}
void Patient::addId(int id)
{
	m_id = id;
}

std::string Patient::getFirstName()
{
	return m_firstName;
}
std::string Patient::getLastName()
{
	return m_lastName;
}
int Patient::getAge()
{
	return m_age;
}
char Patient::getBloodType()
{
	return m_bloodType;
}
int Patient::getId() const
{
	return m_id;
}
int Patient::getId()
{
	return m_id;
}
std::vector<DiagnosisAndMedicine> Patient::getVdam()
{
	return m_dam;
}