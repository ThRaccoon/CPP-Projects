#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Queue
{
public:
	//-
	Queue()
	{
		m_capacity = 2;
		m_back = -1;
		m_arr = new T[m_capacity];
	}

	//-
	Queue(const Queue& original)
	{
		m_capacity = original.m_capacity;
		m_back = original.m_back;
		
		m_arr = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_arr[i] = original.m_arr[i];
		}
	}

	//-
	Queue& operator=(const Queue& original)
	{
		if(&original != this)
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

	//-
	~Queue()
	{
		delete[] m_arr;
		m_arr = nullptr;
	}

	//-
	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_arr[0];
	}
	
	//-
	T back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_arr[m_back];
	}
		
	//-
	void push(T element)
	{
		if (isFull())
		{
			resize();
		}
		m_arr[m_back + 1] = element;
		m_back++;
	}

	//-
	void pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		
		if (m_back == 0)
		{
			m_back--;
		}
		else
		{
			for (int i = 0; i < m_back; i++)
			{
				m_arr[i] = m_arr[i + 1];
			}
			m_back--;
		}	 
	}

	//-
	int capacity() const
	{
		return m_capacity;
	}

	//-
	int count() const
	{
		return m_back + 1;
	}

	//-
	bool isFull() const
	{
		return m_back == m_capacity - 1;
	}

	//-
	bool isEmpty() const
	{
		return m_back == -1;
	}
 

private: 
	int m_capacity;
	int m_back;
	T* m_arr;

	void resize(T element)
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