#include "StudentsDiary.h"
#include <iostream>
#include <fstream>

void readFromFile();
void writeToFile();

int isItInt(int& digit);
float isItFloat(float& digit);

StudentsDiary sd;

int main()
{
	readFromFile();
	system("cls");

	while (true)
	{
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "                         WELCOME                           " << std::endl;
		std::cout << "1.To add new student                              press:(1)" << std::endl;
		std::cout << "2.To add subject to already existing student      press:(2)" << std::endl;
		std::cout << "3.To add grade to already existing subject        press:(3)" << std::endl;
		std::cout << "4.To remove student                               press:(4)" << std::endl;
		std::cout << "5.To sum the average of one subject               press:(5)" << std::endl;
		std::cout << "6.To print list of students/subjects/grades       press:(6)" << std::endl;
		std::cout << "7.To clear the screen                             press:(7)" << std::endl;
		std::cout << "8.To exit                                         press:(8)" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;

		int op = 0;
		std::cin >> op;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			std::string firstName;
			std::cin.ignore();
			std::cout << "Enter student first name: " << std::endl;
			getline(std::cin, firstName);

			std::string lastName;
			std::cin.clear();
			std::cout << "Enter student last name: " << std::endl;
			getline(std::cin, lastName);

			int age = 0;
			std::cout << "Enter student age: " << std::endl;
			std::cin >> age;
			isItInt(age);

			int id = 0;
			std::cout << "Enter student ID: " << std::endl;
			std::cin >> id;
			isItInt(id);

			sd.addStudent(Student(firstName, lastName, age, id));
			break;
		}
		case 2:
		{
			std::string subjectName;
			std::cin.ignore();
			std::cout << "Please enter the name of the subject" << std::endl;
			getline(std::cin, subjectName);

			int id = 0;
			std::cout << "Please enter the ID of the student" << std::endl;
			std::cin >> id;
			isItInt(id);

			sd.addSubject(subjectName, id);
			break;
		}
		case 3:
		{
			int id = 0;
			std::cout << "Please enter the ID of the student" << std::endl;
			std::cin >> id;
			isItInt(id);

			std::string subjectName;
			std::cin.ignore();
			std::cout << "Please enter the subject name" << std::endl;
			getline(std::cin, subjectName);

			float grade = 0;
			std::cout << "Please enter the grade" << std::endl;
			std::cin >> grade;
			isItFloat(grade);

			sd.addGrade(id, subjectName, grade);
			break;
		}
		case 4:
		{
			int id;
			std::cout << "Please enter the ID of the student" << std::endl;
			std::cin >> id;
			isItInt(id);

			sd.eraseStudent(id);
			break;
		}
		case 5:
		{
			int id;
			std::cout << "Please enter the ID of the student" << std::endl;
			std::cin >> id;
			isItInt(id);

			std::string subjectName;
			std::cin.ignore();
			std::cout << "Please enter the name of the subject" << std::endl;
			getline(std::cin, subjectName);

			float average = sd.getAverage(id, subjectName);
			std::cout << average << std::endl;
			break;
		}
		case 6:
		{
			sd.print();
			break;
		}
		case 7:
		{
			system("cls");
			break;
		}
		case 8:
		{
			writeToFile();
			return 0;
			break;
		}
		default:
		{
			std::cout << "Please choose only from numbers from (1) to (8)!" << std::endl;
			break;
		}
		}
	}
	return 0;
}

void readFromFile()
{
	std::string firstName = "NA";
	std::string lastName = "NA";
	int age = 0;
	int id = 0;
	std::string subjectName = "NA";
	float grade = 0;
	int subjectSize = 0;

	std::ifstream file("file.txt");

	while (!file.eof())
	{
		file >> firstName >> lastName >> age >> id >> subjectSize;

		sd.addStudent(Student(firstName, lastName, age, id));

		for (int i = 0; i < subjectSize; i++)
		{
			file >> subjectName;
			int gradeSize = 0;
			file >> gradeSize;
			sd.addSubject(subjectName, id);
			for (int j = 0; j < gradeSize; j++)
			{
				file >> grade;
				sd.addGrade(id, subjectName, grade);
			}
		}
	}
	file.close();
}
void writeToFile()
{
	std::ofstream file("file.txt");

	auto students = sd.getStudents();

	for (int i = 0; i < students.size(); i++)
	{
		file << students[i].getFirstName() << std::endl;
		file << students[i].getLastName() << std::endl;
		file << students[i].getAge() << std::endl;
		file << students[i].getId() << std::endl;

		auto subjects = students[i].getSubejects();
		int subjectsSize = subjects.size();

		file << subjectsSize << std::endl;

		for (int j = 0; j < subjectsSize; j++)
		{
			file << subjects[j].getName() << std::endl;

			auto grades = subjects[j].getGrades();
			int gradesSize = grades.size();

			file << gradesSize << std::endl;

			for (int k = 0; k < gradesSize; k++)
			{
				file << grades[k] << std::endl;
			}
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
float isItFloat(float& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
	return digit;
}