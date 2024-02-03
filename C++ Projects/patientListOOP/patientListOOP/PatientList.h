#pragma once
#include "Patient.h"

class PatientList
{
public:
	PatientList() = default;
	~PatientList();

	void addDAM(int id, int number, std::string diagnosis,
		std::string medicine, std::string date);
	void eraseDAM(int id, int number);
	void printPatientList();
	void addPatient(Patient* patient);
	void erasePatient(int id);

	std::vector<Patient*> getPatientList();

private:
	std::vector<Patient*> m_patientList;

};