#include "DiagnosisAndMedicine.h"

DiagnosisAndMedicine::DiagnosisAndMedicine(int number, std::string diagnosis,
	std::string medicine, std::string date)

	: m_number(number)
	, m_diagnosis(diagnosis)
	, m_medicine(medicine)
	, m_date(date)
{
}

void DiagnosisAndMedicine::printDam()
{
	std::cout << "Date: " << getDate() << std::endl;
	std::cout << "#" << getNumber() << std::endl;
	std::cout << "Diagnosis: " << getDiagnosis() << std::endl;
	std::cout << "Medicine: " << getMedicine() << std::endl;
	std::cout << "--------------------------" << std::endl;
}

void DiagnosisAndMedicine::addNumber(int number)
{
	m_number = number;
}
void DiagnosisAndMedicine::addDiagnosis(std::string diagnosis)
{
	m_diagnosis = diagnosis;
}
void DiagnosisAndMedicine::addMedicine(std::string medicine)
{
	m_medicine = medicine;
}
void DiagnosisAndMedicine::addDate(std::string date)
{
	m_date = date;
}

int DiagnosisAndMedicine::getNumber()
{
	return m_number;
}
std::string DiagnosisAndMedicine::getDiagnosis()
{
	return m_diagnosis;
}
std::string DiagnosisAndMedicine::getMedicine()
{
	return m_medicine;
}
std::string DiagnosisAndMedicine::getDate()
{
	return m_date;
}