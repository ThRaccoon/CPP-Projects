#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Stack
{
public:
	//-
	Stack()
	{
		m_capacity = 2;
		m_top = -1;
		m_arr = new T[m_capacity];	 
	}

	//-
	Stack(const Stack& original)
	{
		m_capacity = original.m_capacity;
		m_top = original.m_top;
		
		m_arr = new T[m_capacity];
		for(int i = 0; i <= original.m_top; i++)
		{
			m_arr[i] = original.m_arr[i];
		}
	}
	
	//-
	Stack& operator=(const Stack& original)
	{
		if (&original != this)
		{
			m_capacity = original.m_capacity;
			m_top = original.m_top;

			delete[] m_arr;
			m_arr = new T[m_capacity];
			for (int i = 0; i <= original.m_top; i++)
			{
				m_arr[i] = original.m_arr[i];
			}
		}
		return *this;
	}
	
	//-
	~Stack()
	{
		delete[] m_arr;
		m_arr = nullptr;
	}

	//-
	T top() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Stack is empty!"); 
		}
		return m_arr[m_top];
	}

	//-
	void push(T element)
	{
		if (isFull())
		{
			m_resize();
		}
		m_arr[m_top + 1] = element;
		m_top++;
	}

	//-
	void pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Stack is empty!");
		}
		m_top--;
	}
	
	//-
	int capacity() const
	{
		return m_capacity;
	}

	//-
	int size() const
	{
		return m_top + 1;
	}

	//-
	bool isFull() const
	{
		return m_top == m_capacity - 1;
	}

	//-
	bool isEmpty() const
	{
		return m_top == -1;
	}


private:
	int m_capacity;
	int m_top;
	T* m_arr;

	void m_resize()
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

