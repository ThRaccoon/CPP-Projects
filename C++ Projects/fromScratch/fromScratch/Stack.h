#pragma once

#include <iostream>
#include <stdexcept>

//Dynamic Stack
template<typename T>
class Stack
{
public:
	//-
	Stack()
	{
		m_top = -1;
		m_capacity = 2;
		m_stack = new T[m_capacity];	 
	}

	//-
	Stack(const Stack& original)
	{
		m_top = original.m_top;
		m_capacity = original.m_capacity;
		 
		m_stack = new T[m_capacity];
		for (int i = 0; i <= original.m_top; i++)
		{
			m_stack[i] = original.m_stack[i];
		}
	}
	
	//-
	Stack& operator=(const Stack& original)
	{
		if (this != &original)
		{
			m_top = original.m_top;
			m_capacity = original.m_capacity;

			delete[] m_stack;
			m_stack = new T[m_capacity];
			for (int i = 0; i <= original.m_top; i++)
			{
				m_stack[i] = original.m_stack[i];
			}
		}
		return *this;
	}
	
	//-
	~Stack()
	{
		delete[] m_stack;
		m_stack = nullptr;
	}

	//-
	T top() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Stack is empty!"); 
		}
		return m_stack[m_top];
	}

	//-
	void push(T element)
	{
		if (isFull())
		{
			m_resize();
		}
		m_stack[m_top + 1] = element;
		m_top++;
	}

	//-
	T pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Stack is empty!");
		}
		
		T temp = m_stack[m_top];
		m_top--;
		
		return temp;
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
	int m_top;
	int m_capacity;
	T* m_stack;

	void m_resize()
	{
		int new_capacity = m_capacity * 2;
		T* new_stack = new T[new_capacity];
	
		for (int i = 0; i < m_capacity; i++)
		{
			new_stack[i] = m_stack[i];
		}
		delete[] m_stack;
	
		m_capacity = new_capacity;
		m_stack = new_stack;
	}
}; 