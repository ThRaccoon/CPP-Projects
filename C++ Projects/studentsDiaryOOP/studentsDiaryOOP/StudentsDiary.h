#pragma once
#include "Student.h"
#include <string>
#include <vector>

class StudentsDiary
{
public:
	StudentsDiary() = default;
	StudentsDiary(std::vector<Student>& students);

	float getAverage(int id, std::string subjectName);

	void addGrade(int id, std::string subjectName, float grade);

	void addSubject(std::string subjectName, int id);

	void addStudent(Student student);

	void eraseStudent(int id);

	void print();

	std::vector<Student> getStudents();

private:
	std::vector<Student> m_students;

};