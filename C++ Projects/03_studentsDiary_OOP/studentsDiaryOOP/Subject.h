#pragma once
#include <string> 
#include <vector>
#include <iostream>

class Subject
{
public:
	Subject() = default;
	Subject(std::string name);

	void addName(std::string name);

	std::string getName();
	std::string getName() const;

	void addGrade(float grade);

	const std::vector<float>& getGrades();

	void removeGrade(float grade);

	void print();

private:
	std::string m_name;
	std::vector<float> m_grades;
};