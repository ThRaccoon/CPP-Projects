#include "PatientList.h"

PatientList::~PatientList()
{
	for (auto patient : m_patientList)
	{
		delete patient;
		std::cout << "Destructor was called!" << std::endl;
	}
}

bool operator==(const Patient& a, const int& b)
{
	return b == a.getId();
}


void PatientList::addDAM(int id, int number, std::string diagnosis,
	std::string medicine, std::string date)
{
	for (auto list : m_patientList)
	{
		if (list->getId() == id)
		{
			list->AddDam(number, diagnosis, medicine, date);
			return;
		}
	}
	std::cout << "Patient with this ID: " << id << " did not exist!" << std::endl;
}
void PatientList::eraseDAM(int id, int number)
{
	if (m_patientList.empty())
	{
		std::cout << "The DAM list is empty" << std::endl;
	}

	for (auto list : m_patientList)
	{
		if (id == list->getId())
		{
			list->eraseDam(number);
		}
	}
}

void PatientList::printPatientList()
{
	if (m_patientList.empty())
	{
		std::cout << "This list is empty!" << std::endl;
		return;
	}

	for (auto list : m_patientList)
	{
		list->printPatient();
	}
}
void PatientList::addPatient(Patient* patient)
{
	if (m_patientList.empty())
	{
		m_patientList.push_back(patient);
		return;
	}

	for (int i = 0; i < m_patientList.size(); i++)
	{
		if (*patient == m_patientList[i]->getId())
		{
			std::cout << "This patient already exist!" << std::endl;
			return;
		}
	}
	m_patientList.push_back(patient);
}
void PatientList::erasePatient(int id)
{
	if (m_patientList.empty())
	{
		std::cout << "The patient list is empty!" << std::endl;
		return;
	}

	for (int i = 0; i < m_patientList.size(); i++)
	{
		if (id == m_patientList[i]->getId())
		{
			m_patientList.erase(m_patientList.begin() + i);
			std::cout << "Patient was deleted!" << std::endl;
			std::cout << "Press any key to continue!" << std::endl;
			std::cout << ">";
			char op;
			std::cin >> op;
		}
	}
}

std::vector<Patient*> PatientList::getPatientList()
{
	return m_patientList;
}