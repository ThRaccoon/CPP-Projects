#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Deque
{
public:
	Deque()
	{
		m_front = 0;
		m_back = -1;
		m_capacity = 2;
		m_size = 0;
		m_flag = true;
		m_deque = new T[m_capacity];
	}

	Deque(const Deque& original)
	{
		m_front = original.m_front;
		m_back = original.m_back;
		m_capacity = original.m_capacity;
		m_size = original.m_size;
		m_flag = original.m_flag;

		m_deque = new T[m_capacity];
		for (int i = 0; i < original.m_capacity; i++)
		{
			m_deque[i] = original.m_deque[i];
		}
	}

	Deque& operator=(const Deque& original)
	{
		if (this != &original)
		{
			m_front = original.m_front;
			m_back = original.m_back;
			m_capacity = original.m_capacity;
			m_size = original.m_size;
			m_flag = original.m_flag;

			delete[] m_deque;
			m_deque = new T[m_capacity];
			for (int i = 0; i < original.m_capacity; i++)
			{
				m_deque[i] = original.m_deque[i];
			}
		}
		return *this;
	}

	~Deque()
	{
		delete[] m_deque;
		m_deque = nullptr;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}
		return m_deque[m_front];
	}

	const T& back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}
		return m_deque[m_back];
	}

	void pushFront(T element)
	{
		if ((m_front - 1 + m_capacity) % m_capacity == m_back)
		{
			resize();
		}

		if (m_flag)
		{
			m_deque[m_front] = element;
			m_back++;
			m_flag = false;
		}
		else
		{
			m_front = (m_front - 1 + m_capacity) % m_capacity;
			m_deque[m_front] = element;
		}
		m_size++;
	}

	void pushBack(T element)
	{
		if ((m_back + 1) % m_capacity == m_front && !m_flag)
		{
			resize();
		}

		m_flag = false;

		m_back = (m_back + 1) % m_capacity;
		m_deque[m_back] = element;
		m_size++;
	}

	T popFront()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}

		if (m_size == 1)
		{
			m_flag = true;
		}

		T temp = m_deque[m_front];
		m_front = (m_front + 1) % m_capacity;
		m_size--;

		return temp;
	}

	T popBack()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}

		if (m_size == 1)
		{
			m_flag = true;
		}

		T temp = m_deque[m_back];
		m_back = (m_back - 1 + m_capacity) % m_capacity;
		m_size--;

		return temp;
	}

	int capacity() const
	{
		return m_capacity;
	}

	int size() const
	{
		return m_size;
	}

	bool isFull() const
	{
		return m_size == m_capacity;
	}

	bool isEmpty() const
	{
		return m_size == 0;
	}


private:
	int m_front;
	int m_back;
	int m_capacity;
	int m_size;
	bool m_flag;
	T* m_deque;

	void resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_deque = new T[new_capacity];

		int counter = 0;
		while (counter != m_capacity)
		{
			new_deque[counter] = m_deque[m_front];
			m_front = (m_front + 1) % m_capacity;
			counter++;
		}
		delete[] m_deque;

		m_front = 0;
		m_back = m_capacity - 1;
		m_capacity = new_capacity;
		m_deque = new_deque;
	}
};
