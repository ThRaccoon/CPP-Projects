#pragma once

#include <iostream>
#include <stdexcept>

//Dynamic Circular Queue
template<typename T>
class CircularQueue
{
public:
	CircularQueue()
	{
		m_front = 0;
		m_back = -1;
		m_capacity = 2;
		m_size = 0;
		m_queue = new T[m_capacity];
		m_flag = true;
	}

	CircularQueue(const CircularQueue& original)
	{
		m_front = original.m_front;
		m_back = original.m_back;
		m_capacity = original.m_capacity;
		m_size = original.m_size;
		m_flag = original.m_flag;

		m_queue = new T[m_capacity];
		for (int i = 0; i < original.m_size; i++)
		{
			m_queue[i] = original.m_queue[i];
		}
	}

	CircularQueue& operator=(const CircularQueue& original)
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
			for (int i = 0; i < original.m_size; i++)
			{
				m_queue[i] = original.m_queue[i];
			}
		}
		return *this;
	}

	~CircularQueue()
	{
		delete[] m_queue;
		m_queue = nullptr;
	}

	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_queue[m_front];
	}

	T back() const
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
			throw std::range_error("Queue is empty!");
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
	T* m_queue;
	bool m_flag;

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


//====================================================================================================//


//Dynamic Linear Queue
template<typename T>
class LinearQueue
{
public:
	LinearQueue()
	{
		m_back = -1;
		m_capacity = 2;
		m_queue = new T[m_capacity];
	}

	LinearQueue(const LinearQueue& original)
	{
		m_back = original.m_back;
		m_capacity = original.m_capacity;
		 
		m_queue = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_queue[i] = original.m_queue[i];
		}
	}

	LinearQueue& operator=(const LinearQueue& original)
	{
		if (this != &original)
		{
			m_back = original.m_back;
			m_capacity = original.m_capacity;
			 
			delete[] m_queue;
			m_queue = new T[m_capacity];
			for (int i = 0; i <= original.m_back; i++)
			{
				m_queue[i] = original.m_queue[i];
			}
		}
		return *this;
	}

	~LinearQueue()
	{
		delete[] m_queue;
		m_queue = nullptr;
	}

	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_queue[0];
	}

	T back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}
		return m_queue[m_back];
	}

	void push(T element)
	{
		if (isFull())
		{
			resize();
		}
		m_queue[m_back + 1] = element;
		m_back++;
	}

	T pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Queue is empty!");
		}

		T temp = m_queue[0];

		if (m_back == 0)
		{
			m_back--;
		}
		else
		{
			for (int i = 0; i < m_back; i++)
			{
				m_queue[i] = m_queue[i + 1];
			}
			m_back--;
		}
		
		return temp;
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
	int m_back;
	int m_capacity;
	T* m_queue;

	void resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_queue = new T[new_capacity];

		for (int i = 0; i < m_capacity; i++)
		{
			new_queue[i] = m_queue[i];
		}
		delete[] m_queue;

		m_capacity = new_capacity;
		m_queue = new_queue;
	}
};