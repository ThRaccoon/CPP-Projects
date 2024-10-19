#pragma once

#include <iostream>
#include <stdexcept>

//Dynamic Circular Deque
template<typename T>
class CircularDeque
{
public:
	CircularDeque()
	{
		m_front = 0;
		m_back = -1;
		m_capacity = 2;
		m_size = 0;
		m_deque = new T[m_capacity];
		m_flag = true;
	}

	CircularDeque(const CircularDeque& original)
	{
		m_front = original.m_front;
		m_back = original.m_back;
		m_capacity = original.m_capacity;
		m_size = original.m_size;
		m_flag = original.m_flag;
	
	    m_deque = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_deque[i] = original.m_deque[i];
		}
	}

	CircularDeque& operator=(const CircularDeque& original)
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
			for (int i = 0; i <= original.m_back; i++)
			{
				m_deque[i] = original.m_deque[i];
			}
		}
		return *this;
	}

	~CircularDeque()
	{
		delete[] m_deque;
		m_deque = nullptr;
	}

	T front() const 
	{
		if (isEmpty())
		{
			throw std::range_error("Deque is empty!");
		}
		return m_deque[m_front];
	}

	T back() const
	{
		if (isEmpty())
		{
			throw std::range_error("Deque is empty!");
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
			throw std::range_error("Deque is empty!");
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
			throw std::range_error("Deque is empty!");
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
	T* m_deque;
	bool m_flag;

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


//====================================================================================================//


//Dynamic Linear Deque
template<typename T>
class LinearDeque
{
public:
	LinearDeque()
	{
		m_back = -1;
		m_capacity = 2;
		m_deque = new T[m_capacity];
	}

	LinearDeque(const LinearDeque& original)
	{
		m_back = original.m_back;
		m_capacity = original.m_capacity;

		m_deque = new T[m_capacity];
		for (int i = 0; i <= original.m_back; i++)
		{
			m_deque[i] = original.m_deque[i];
		}
	}

	LinearDeque& operator=(const LinearDeque& original)
	{
		if (this != &original)
		{
			m_back = original.m_back;
			m_capacity = original.m_capacity;

			delete[] m_deque;
			m_deque = new T[m_capacity];
			for (int i = 0; i <= original.m_back; i++)
			{
				m_deque[i] = original.m_deque[i];
			}
		}
		return *this;
	}

	~LinearDeque()
	{
		delete[] m_deque;
		m_deque = nullptr;
	}

	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}
		return m_deque[0];
	}
	
	T back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}
		return m_deque[m_back];
	}

	void pushFront(T element)
	{
		if (isFull())
		{
			m_resize();
		}
		
		for (int i = m_back; i >= 0; i--)
		{
			m_deque[i + 1] = m_deque[i];
		}
		m_deque[0] = element;
		m_back++;
	}

	void pushBack(T element)
	{
		if (isFull())
		{
			m_resize();
		}
		m_deque[m_back + 1] = element;
		m_back++;
	}

	T popFront()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}

		T temp = m_deque[0];
		
		for (int i = 0; i <= m_back; i++)
		{
			m_deque[i] = m_deque[i + 1];
		}
		m_back--;
		
		return temp;
	}
	
	T popBack()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty!");
		}

		T temp = m_deque[m_back];
		m_back--;

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
	T* m_deque;

	void m_resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_deque = new T[new_capacity];

		for (int i = 0; i < m_capacity; i++)
		{
			new_deque[i] = m_deque[i];
		}
		delete[] m_deque;

		m_capacity = new_capacity;
		m_deque = new_deque;
	}
};