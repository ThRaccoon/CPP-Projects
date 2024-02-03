#include "StudentsDiary.h"


StudentsDiary::StudentsDiary(std::vector<Student>& students)

	: m_students(students)
{
};

float StudentsDiary::getAverage(int id, std::string subjectName)
{
	for (auto student : m_students)
	{
		if (student.getId() == id)
		{
			auto subject = student.getSubject(subjectName);
			if (subject != nullptr)
			{
				auto grades = subject->getGrades();
				float averageGrades = 0;
				for (auto grade : grades)
				{
					averageGrades += grade;
				}
				return averageGrades / grades.size();
			}
			return -1;
		}
	}
	return -1;
}

void StudentsDiary::addGrade(int id, std::string subjectName, float grade)
{
	for (auto& student : m_students)
	{
		if (student.getId() == id)
		{
			auto subject = student.getSubject(subjectName);
			if (subject != nullptr)
			{
				subject->addGrade(grade);
			}
			else
			{
				std::cout << "This student don't have this subject" << std::endl;
			}
			return;
		}

	}
	std::cout << "This student don't exist" << std::endl;
}

void StudentsDiary::addSubject(std::string subjectName, int id)
{
	for (auto& student : m_students)
	{
		if (student.getId() == id)
		{
			student.addSubject(subjectName);
			return;
		}

	}
	std::cout << "This student don't exist" << std::endl;
}

void StudentsDiary::addStudent(Student student)
{
	if (m_students.empty())
	{
		m_students.push_back(student);
		return;
	}

	if (std::find(m_students.begin(), m_students.end(), student) != m_students.end())
	{
		std::cout << "Student with this ID :" << student.getId() << " already exist" << std::endl;
	}
	else
	{
		m_students.push_back(student);
	}
}

void StudentsDiary::eraseStudent(int id)
{
	if (m_students.empty())
	{
		std::cout << "This diary is empty" << std::endl;
		return;
	}

	for (int i = 0; i < m_students.size(); i++)
	{
		if (m_students[i].getId() == id)
		{
			m_students.erase(m_students.begin() + i);
			return;
		}
	}

	std::cout << "This student did not exist" << std::endl;
}

void StudentsDiary::print()
{
	if (m_students.empty())
	{
		std::cout << "There are no students" << std::endl;
		return;
	}

	for (auto student : m_students)
	{
		student.print();
	}
}

std::vector<Student> StudentsDiary::getStudents()
{
	return m_students;
}