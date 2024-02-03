#include "PatientList.h"
#include <iostream>
#include <fstream>

PatientList ps;
Patient* p;

void readFromFile();
void writeToFile();

int isItInt(int& digit);

int main()
{
	readFromFile();

	std::string firstName, lastName, diagnosis, medicine, date;
	int age, id, number;
	int op = 0;
	char bloodType;

	while (true)
	{
		system("cls");
		std::cout << "(1). Add new patient." << std::endl;
		std::cout << "(2). Add diagnosis and medicine list to already existing patient." << std::endl;
		std::cout << "(3). Remove diagnosis and medici list from a patient." << std::endl;
		std::cout << "(4). Remove patient from the patient list." << std::endl;
		std::cout << "(5). Show patient and DAM list." << std::endl;
		std::cout << "(6). Exit." << std::endl;
		std::cout << ">";
		std::cin >> op;
		isItInt(op);

		switch (op)
		{
		case 1:
		{
			system("cls");
			std::cin.ignore();
			std::cout << "Enter patient first name: " << std::endl;
			getline(std::cin, firstName);
			std::cout << "Enter patient last name: " << std::endl;
			getline(std::cin, lastName);
			std::cout << "Enter patient age: " << std::endl;
			std::cin >> age;
			isItInt(age);
			std::cout << "Enter patient blood type: " << std::endl;
			std::cin >> bloodType;
			std::cout << "Create patient ID: " << std::endl;
			std::cin >> id;
			isItInt(id);

			p = new Patient(firstName, lastName, age, bloodType, id);
			ps.addPatient(p);
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Enter patient id: " << std::endl;
			std::cin >> id;
			isItInt(id);
			std::cout << "Create patient DAM list number: " << std::endl;
			std::cin >> number;
			isItInt(number);
			std::cin.ignore();
			std::cout << "Enter patient diagnosis: " << std::endl;
			getline(std::cin, diagnosis);
			std::cout << "Enter patient medicine: " << std::endl;
			getline(std::cin, medicine);
			std::cout << "Enter the date of the patient diagnosis: " << std::endl;
			getline(std::cin, date);

			ps.addDAM(id, number, diagnosis, medicine, date);
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Enter the ID of the patient that DAM you want to delete" << std::endl;
			std::cin >> id;
			isItInt(id);
			std::cout << "Enter the number of the DAM you want to delete" << std::endl;
			std::cin >> number;
			isItInt(number);

			ps.eraseDAM(id, number);
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "Enter the ID of the patient you want to delete" << std::endl;
			std::cin >> id;
			isItInt(id);

			ps.erasePatient(id);
			break;
		}
		case 5:
		{
			system("cls");
			ps.printPatientList();
			std::cout << "Press (0) to go back" << std::endl;
			int a = 0;
			while (op != 0)
			{
				system("cls");
				ps.printPatientList();
				std::cout << "Press (0) to go back" << std::endl;
				std::cin >> op;
			}
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "You sure you want to exit the program ?" << std::endl;
			std::cout << "Enter 1.YES and 2.NO" << std::endl;
			std::cin >> op;
			isItInt(op);

			if (op == 1)
			{
				writeToFile();
				std::cout << "Thanks for using my program!" << std::endl;
				return 0;
			}
			else if (op == 2)
			{
				break;
			}
			break;
		}
		default:
		{
			system("cls");
			std::cout << "Please use only numbers from (1 to 6)!" << std::endl;
			std::cout << ">";
			std::cin >> op;
		}
		}
	}
}

void readFromFile()
{
	std::string firstName = "NA";
	std::string lastName = "NA";
	std::string diagnosis = "NA";
	std::string medicine = "NA";
	std::string date = "NA";
	int age = 0;
	int id = 0;
	int number = 0;
	int damSize = 0;
	char bloodType = '?';

	std::ifstream file("file.txt");

	while (!file.eof())
	{
		file >> firstName >> lastName >> age >> bloodType >> id >> damSize;
		if (id == 0)
		{
			return;
		}
		p = new Patient(firstName, lastName, age, bloodType, id);
		ps.addPatient(p);

		for (int i = 0; i < damSize; i++)
		{
			file >> number >> diagnosis >> medicine >> date;
			ps.addDAM(id, number, diagnosis, medicine, date);
		}
	}
	file.close();
}

void writeToFile()
{
	std::ofstream file("file.txt");

	auto list = ps.getPatientList();

	for (int i = 0; i < list.size(); i++)
	{
		file << list[i]->getFirstName() << std::endl;
		file << list[i]->getLastName() << std::endl;
		file << list[i]->getAge() << std::endl;
		file << list[i]->getBloodType() << std::endl;
		file << list[i]->getId() << std::endl;

		auto dam = list[i]->getVdam();
		int damSize = dam.size();

		file << damSize << std::endl << std::endl;

		for (int i = 0; i < damSize; i++)
		{
			file << dam[i].getNumber() << std::endl;
			file << dam[i].getDiagnosis() << std::endl;
			file << dam[i].getMedicine() << std::endl;
			file << dam[i].getDate() << std::endl;
		}
	}
	file.close();
}

int isItInt(int& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
	return digit;
}