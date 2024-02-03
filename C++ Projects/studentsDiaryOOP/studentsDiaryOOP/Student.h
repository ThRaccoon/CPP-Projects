#pragma once
#include "Subject.h"
#include <string>
#include <vector>

class Student
{
public:
	Student() = default;
	Student(std::string firstName, std::string lastName,
		int age, int id);

	bool operator==(const Student& a);
	bool isHaveSubject(std::string name);

	Subject* getSubject(std::string name);

	void addSubject(std::string name);
	void addSubject(Subject sub);

	std::vector<Subject> getSubejects();

	std::vector<float> getSubjectGrades(std::string name);

	void addSubjectGrade(std::string name, float grade);

	void print();

	void setFirstName(std::string firstName);
	void setSecondName(std::string lastName);
	void setAge(int age);
	void setId(int id);

	std::string getFirstName();
	std::string getLastName();
	int getAge();
	int getId();
	int getId() const;

private:
	std::vector<Subject> m_subjects;
	std::string m_firstName;
	std::string m_lastName;
	int m_age;
	int m_id;


};