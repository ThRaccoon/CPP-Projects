#include "Student.h"

Student::Student(std::string firstName, std::string secondName,
	int age, int id)
	: m_firstName(firstName)
	, m_lastName(secondName)
	, m_age(age)
	, m_id(id)
{
}

bool Student::operator==(const Student& a)
{
	return m_id == a.getId();
}

bool Student::isHaveSubject(std::string name)
{
	for (auto subject : m_subjects)
	{
		if (subject.getName() == name)
		{
			return true;
		}
	}
	return false;
}

Subject* Student::getSubject(std::string name)
{
	for (auto& subject : m_subjects)
	{
		if (subject.getName() == name)
		{
			return &subject;
		}
	}
	return nullptr;
}

void Student::addSubject(std::string name)
{
	if (isHaveSubject(name) == false)
	{
		m_subjects.push_back(Subject(name));
	}
	else
	{
		std::cout << "This subject already exist!" << std::endl;
	}
}
void Student::addSubject(Subject sub)
{
	if (isHaveSubject(sub.getName()) == false)
	{
		m_subjects.push_back(sub);
		return;
	}
	std::cout << "This student already have this subject" << std::endl;
}

std::vector<Subject> Student::getSubejects()
{
	return m_subjects;
}

std::vector<float> Student::getSubjectGrades(std::string name)
{
	for (auto subject : m_subjects)
	{
		if (subject.getName() == name)
		{
			return subject.getGrades();
		}
	}
	return std::vector<float>(1, -1);
}

void Student::addSubjectGrade(std::string name, float grade)
{
	for (auto& subject : m_subjects)
	{
		if (subject.getName() == name)
		{
			subject.addGrade(grade);
			return;
		}
	}
	addSubject(name);
	addSubjectGrade(name, grade);
}

void Student::print()
{
	if (m_id == 0)
	{
		return;
	}
	else
	{
		std::cout << "First name: " << m_firstName << std::endl;
		std::cout << "Last name: " << m_lastName << std::endl;
		std::cout << "Age: " << m_age << std::endl;
		std::cout << "ID: " << m_id << std::endl;

		for (auto subject : m_subjects)
		{
			subject.print();
		}
	}
}

void Student::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}
void Student::setSecondName(std::string secondName)
{
	m_lastName = secondName;
}
void Student::setAge(int age)
{
	m_age = age;
}
void Student::setId(int id)
{
	m_id = id;
}

std::string Student::getFirstName()
{
	return m_firstName;
}
std::string Student::getLastName()
{
	return m_lastName;
}
int Student::getAge()
{
	return m_age;
}
int Student::getId()
{
	return m_id;
}
int Student::getId() const
{
	return m_id;
}