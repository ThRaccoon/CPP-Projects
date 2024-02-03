#pragma once
#include <iostream>
#include <string>
#include <vector>


class DiagnosisAndMedicine
{
public:
	DiagnosisAndMedicine() = default;
	DiagnosisAndMedicine(int number, std::string diagnosis,
		std::string medicine, std::string date);

	void printDam();

	void addNumber(int number);
	void addDiagnosis(std::string diagnosis);
	void addMedicine(std::string medicine);
	void addDate(std::string date);

	int getNumber();
	std::string getDiagnosis();
	std::string getMedicine();
	std::string getDate();

private:
	std::string m_diagnosis;
	std::string m_medicine;
	std::string m_date;
	int m_number;
};