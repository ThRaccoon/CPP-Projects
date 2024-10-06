#include"Subject.h"

Subject::Subject(std::string name)
	: m_name(name)
{
};

void Subject::addName(std::string name)
{
	m_name = name;
}

std::string Subject::getName()
{
	return m_name;
}
std::string Subject::getName() const
{
	return m_name;
}

void Subject::addGrade(float grade)
{
	m_grades.push_back(grade);
}

const std::vector<float>& Subject::getGrades()
{
	return m_grades;
}

void Subject::removeGrade(float grade)
{
	auto it = std::find(m_grades.begin(), m_grades.end(), grade);
	if (*it == grade)
	{
		m_grades.erase(it);
	}
	else
	{
		std::cout << "Grade wasn't found" << std::endl;
	}
}

void Subject::print()
{
	std::cout << "Subject " << m_name << ":" << std::endl;
	for (auto grade : m_grades)
	{
		std::cout << grade << ", ";
	}
	std::cout << std::endl;
}