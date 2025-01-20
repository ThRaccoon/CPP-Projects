#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
{
public:
	Queue()
	{
		m_front = 0;
		m_back = -1;
		m_capacity = 2;
		m_size = 0;
		m_flag = true;
		m_queue = new T[m_capacity];
	}

	Queue(const Queue& original)
	{
		m_front = original.m_front;
		m_back = original.m_back;
		m_capacity = original.m_capacity;
		m_size = original.m_size;
		m_flag = original.m_flag;

		m_queue = new T[m_capacity];
		for (int i = 0; i < original.m_capacity; i++)
		{
			m_queue[i] = original.m_queue[i];
		}
	}

	Queue& operator=(const Queue& original)
	{
		if (this != &original)
		{
			m_front = original.m_front;
			m_back = original.m_back;
			m_capacity = original.m_capacity;
			m_size = original.m_size;
			m_flag = original.m_flag;

			delete[] m_queue;
			m_queue = new T[m_capacity];
			for (int i = 0; i < original.m_capacity; i++)
			{
				m_queue[i] = original.m_queue[i];
			}
		}
		return *this;
	}

	~Queue()
	{
		delete[] m_queue;
		m_queue = nullptr;
	}

	const T& front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_queue[m_front];
	}

	const T& back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_queue[m_back];
	}

	void push(T element)
	{
		if ((m_back + 1) % m_capacity == m_front && !m_flag)
		{
			resize();
		}

		m_flag = false;

		m_back = (m_back + 1) % m_capacity;
		m_queue[m_back] = element;
		m_size++;
	}

	T pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}

		if (m_size == 1)
		{
			m_flag = true;
		}

		T temp = m_queue[m_front];
		m_front = (m_front + 1) % m_capacity;
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
	T* m_queue;

	void resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_queue = new T[new_capacity];

		int counter = 0;
		while (counter != m_capacity)
		{
			new_queue[counter] = m_queue[m_front];
			m_front = (m_front + 1) % m_capacity;
			counter++;
		}
		delete[] m_queue;

		m_front = 0;
		m_back = m_capacity - 1;
		m_capacity = new_capacity;
		m_queue = new_queue;
	}
};