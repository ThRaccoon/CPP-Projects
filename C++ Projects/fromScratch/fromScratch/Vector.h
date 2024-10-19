#pragma once

#include <iostream>
#include <stdexcept>

//Dynamic Vector
template<typename T>
class Vector
{
public:
	Vector()
	{
		m_capacity = 2;
		m_back = -1;
		m_arr = new T[m_capacity];
	}
	
	Vector(const Vector& original)
	{
		m_capacity = original.m_capacity;
		m_back = original.m_back;
	
		m_arr = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_arr[i] = original.m_arr[i];
		}
	}

	Vector& operator=(const Vector& original)
	{
		if (&original != this)
		{
			m_capacity = original.m_capacity;
			m_back = original.m_back;

			delete[] m_arr;
			m_arr = new T[m_capacity];
			for (int i = 0; i <= original.m_back; i++)
			{
				m_arr[i] = original.m_arr[i];
			}
		}
		return *this;
	}

	T& operator[](int index)
	{
		if (index < 0 || index > m_back)
		{
			throw std::runtime_error("Invalid index!");
		}
		return m_arr[index];
	}

	~Vector()
	{
		delete[] m_arr;
		m_arr = nullptr;
	}

	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		return m_arr[0];
	}

	T back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		return m_arr[m_back];
	}

	void pushBack(T element) 
	{
		if (isFull())
		{
			resize();
		}	
		m_arr[m_back + 1] = element;
		m_back++;
	}

	T popBack() 
	{
		if (isEmpty())
		{
			throw std::runtime_error("Vector is empty!");
		}
		
		T temp = m_arr[m_back];
		m_back--;
		
		return temp;
	}

	void insert(T element, int index)
	{
		if (isFull())
		{
			resize();
		}
		
		for (int i = m_back; i >= index; i--)
		{
			m_arr[i + 1] = m_arr[i];
		}
		m_arr[index] = element;
		m_back++;
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

	T* begin()
	{
		return m_arr;
	}
	
	T* end()
	{
		return m_arr + m_back + 1;
	}
	

private:
	int m_capacity;
	int m_back;
	T* m_arr;
	
	void resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_arr = new T[new_capacity];

		for (int i = 0; i < m_capacity; i++)
		{
			new_arr[i] = m_arr[i];
		}
		delete[] m_arr;

		m_capacity = new_capacity;
		m_arr = new_arr;
	}
};