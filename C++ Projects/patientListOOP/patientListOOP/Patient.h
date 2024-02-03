#pragma once
#pragma once
#include "DiagnosisAndMedicine.h"
#include <iostream>
#include <vector>

class Patient
{
public:
	Patient() = default;
	Patient(std::string firstName, std::string lastName, int age,
		char bloodType, int id);

	void printPatient();

	void AddDam(int number, std::string diagnosis,
		std::string medicine, std::string date);
	void eraseDam(int dimNumber);


	void addFirstName(std::string firstName);
	void addSecondName(std::string secondName);
	void addAge(int age);
	void addBloodType(char bloodType);
	void addId(int id);

	std::string getFirstName();
	std::string getLastName();
	int getAge();
	char getBloodType();
	int getId();
	int getId() const;
	std::vector<DiagnosisAndMedicine> getVdam();

private:
	std::vector<DiagnosisAndMedicine> m_dam;
	std::string m_firstName;
	std::string m_lastName;
	int m_age;
	char m_bloodType;
	int m_id;
};