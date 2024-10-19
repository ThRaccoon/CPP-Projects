#pragma once

#include <iostream>
#include <stdexcept>

//Dynamic List
template<typename T>
class List
{
private:
	struct Node
	{
		T m_element;
		Node* m_next;
	};
	Node* m_head;
	int m_count;


public:
	List()
	{
		m_head = nullptr;
		m_count = 0;
	}
	
	List(const List& original)
	{
		m_head = nullptr;
		m_count = 0;
 
		if (original.m_head == nullptr)
		{
			return;
		}
		
		m_head = new Node(*original.m_head); 
		m_count++;

		Node* originalCurrent = original.m_head->m_next;  
		Node* newCurrent = m_head;  

		while (originalCurrent != nullptr)
		{
			newCurrent->m_next = new Node(*originalCurrent);   
			newCurrent = newCurrent->m_next;   
			originalCurrent = originalCurrent->m_next;   
			m_count++;
		}
		newCurrent->m_next = nullptr;  
	}

	~List()
	{
		while (m_head != nullptr)
		{
			Node* temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}
	}

	T front() const
	{
		if (m_head == nullptr)
		{
			throw std::runtime_error("List is empty!");
		}
		return m_head->m_element;
	}

	T back() const
	{
		if (m_head == nullptr)
		{
			throw std::runtime_error("List is empty!");
		}
		
		Node* temp = m_head;
		while (temp->m_next != nullptr)
		{
			temp = temp->m_next;
		}
		return temp->m_element;
	}

	void pushFront(T element)
	{
		Node* newNode = new Node();
		newNode->m_element = element;
		newNode->m_next = m_head;
		m_head = newNode;
		m_count++;
	}

	void pushBack(T element)
	{
		if (m_head == nullptr)
		{
			pushFront(element);
			return;
		}

		Node* newNode = new Node();
		newNode->m_element = element;
		newNode->m_next = nullptr;

		Node* temp = m_head;
		while (temp->m_next != nullptr)
		{
			temp = temp->m_next;
		}
		temp->m_next = newNode;
		m_count++;
	}

	void popFront()
	{
		if (m_head == nullptr)
		{
			throw std::runtime_error("List is empty!");
		}
		
		Node* oldHead = m_head;
		m_head = m_head->m_next;
		delete oldHead;
		m_count--;
	}

	void popBack()
	{
		if (m_head == nullptr)
		{
			throw std::runtime_error("List is empty!");
		}
		
		if (m_head->m_next == nullptr)
		{
			delete m_head;
			m_head = nullptr;
		}
		else
		{
			Node* temp = m_head;
			while (temp->m_next->m_next != nullptr)
			{
				temp = temp->m_next;
			}
			delete temp->m_next;
			temp->m_next = nullptr;
		}
		m_count--;
	}

	void insert(T element, int rIndex)
	{
		if (rIndex == 0)
		{
			pushFront(element);
			return;
		}

		if (rIndex - 1 == m_count)
		{
			pushBack(element);
			return;
		}

		if (rIndex < 0 || rIndex - 1 > m_count)
		{
			throw std::runtime_error("Invalid index!");
		}

		Node* temp = m_head;

		Node* newNode = new Node();
		newNode->m_element = element;

		int counter = 0;
		while (counter < rIndex - 1)
		{
			temp = temp->m_next;
			counter++;
		}

		newNode->m_next = temp->m_next;
		temp->m_next = newNode;
		m_count++;
	}

	int size() const
	{
		return m_count;
	} 

	bool isEmpty() const
	{
		return m_head == nullptr;
	}
	
	//-
	class Iterator
	{
	public:
		//-
		Iterator(Node* node) :
			m_node(node)
		{}

		//-
		T& operator*()
		{
			return m_node->m_element;
		}

		//-
		Iterator& operator++()
		{
			m_node = m_node->m_next;
			return *this;
		}

		//-
		bool operator==(const Iterator& other) const
		{
			return m_node == other.m_node;
		}

		//-
		bool operator!=(const Iterator& other) const
		{
			return m_node != other.m_node;
		}


	private:
		Node* m_node;
	};

	Iterator begin()
	{
		return Iterator(m_head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}
};