#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Vector
{
public:
	Vector()
	{
		m_back = -1;
		m_capacity = 2;
		m_vector = new T[m_capacity];
	}

	Vector(const Vector& original)
	{
		m_back = original.m_back;
		m_capacity = original.m_capacity;

		m_vector = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_vector[i] = original.m_vector[i];
		}
	}

	Vector& operator=(const Vector& original)
	{
		if (this != &original)
		{
			m_back = original.m_back;
			m_capacity = original.m_capacity;

			delete[] m_vector;
			m_vector = new T[m_capacity];
			for (int i = 0; i <= original.m_back; i++)
			{
				m_vector[i] = original.m_vector[i];
			}
		}
		return *this;
	}

	T& operator[](int index)
	{
		return m_vector[index];
	}

	~Vector()
	{
		delete[] m_vector;
		m_vector = nullptr;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		return m_vector[0];
	}

	const T& back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		return m_vector[m_back];
	}

	const T& at(int index) const
	{
		if (index < 0 || index > m_back)
		{
			throw std::out_of_range("Invalid index!");
		}
		return m_vector[index];
	}
	
	void pushBack(T element)
	{
		if (isFull())
		{
			resize();
		}
		m_vector[m_back + 1] = element;
		m_back++;
	}

	T popBack()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}

		T temp = m_vector[m_back];
		m_back--;

		return temp;
	}

	void insert(T element, int index)
	{
		if (index < 0 || index > m_back)
		{
			throw std::out_of_range("Invalid index!");
		}
		
		if (isFull())
		{
			resize();
		}

		for (int i = m_back; i >= index; i--)
		{
			m_vector[i + 1] = m_vector[i];
		}
		m_vector[index] = element;
		m_back++;
	}

	void erase(int index)
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		
		if (index < 0 || index > m_back)
		{
			throw std::out_of_range("Invalid index!");
		}

		for (int i = index + 1; i <= m_back; i++)
		{
			m_vector[i - 1] = m_vector[i];
		}
	}
	
	int capacity() const
	{
		return m_capacity;
	}

	int size() const
	{
		return m_back + 1;
	}

	bool isFull() const
	{
		return m_back == m_capacity - 1;
	}

	bool isEmpty() const
	{
		return m_back == -1;
	}


private:
	int m_capacity;
	int m_back;
	T* m_vector;

	void resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_vector = new T[new_capacity];

		for (int i = 0; i < m_capacity; i++)
		{
			new_vector[i] = m_vector[i];
		}
		delete[] m_vector;

		m_capacity = new_capacity;
		m_vector = new_vector;
	}
};