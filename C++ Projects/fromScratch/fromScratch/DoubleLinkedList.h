#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList()
	{
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
	}

	DoubleLinkedList(const DoubleLinkedList& original)
	{
		m_size = original.m_size;

		if (original.m_head == nullptr)
		{
			m_head = nullptr;
			m_tail = nullptr;
			return;
		}

		Node* tempOriginal = original.m_head;
		m_head = new Node(tempOriginal->m_element);
		Node* tempCopy = m_head;

		while (tempOriginal->m_next != nullptr)
		{
			tempOriginal = tempOriginal->m_next;
			tempCopy->m_next = new Node(tempOriginal->m_element);
			tempCopy->m_next->m_previous = tempCopy;
			tempCopy = tempCopy->m_next;
		}
		m_tail = tempCopy;
	}

	DoubleLinkedList& operator=(const DoubleLinkedList& original)
	{
		if (this != &original)
		{
			while (m_head != nullptr)
			{
				Node* tempNode = m_head;
				m_head = m_head->m_next;
				delete tempNode;
			}

			m_size = original.m_size;

			if (original.m_head == nullptr)
			{
				m_head = nullptr;
				m_tail = nullptr;
				return *this;
			}

			Node* tempOriginal = original.m_head;
			m_head = new Node(tempOriginal->m_element);
			Node* tempCopy = m_head;

			while (tempOriginal->m_next != nullptr)
			{
				tempOriginal = tempOriginal->m_next;
				tempCopy->m_next = new Node(tempOriginal->m_element);
				tempCopy->m_next->m_previous = tempCopy;
				tempCopy = tempCopy->m_next;
			}
			m_tail = tempCopy;
		}
		return *this;
	}

	~DoubleLinkedList()
	{
		while (m_head != nullptr)
		{
			Node* tempNode = m_head;
			m_head = m_head->m_next;
			delete tempNode;
		}
	}

	T front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}
		return m_head->m_element;
	}

	T back() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}
		return m_tail->m_element;
	}

	void pushFront(T element)
	{
		if (m_size == 0)
		{
			Node* newNode = new Node(element);
			m_head = newNode;
			m_tail = newNode;
		}
		else
		{
			Node* newNode = new Node(element);
			newNode->m_next = m_head;
			m_head->m_previous = newNode;
			m_head = newNode;
		}
		m_size++;
	}

	void pushBack(T element)
	{
		if (m_size == 0)
		{
			pushFront(element);
			return;
		}

		Node* newNode = new Node(element);
		newNode->m_previous = m_tail;
		m_tail->m_next = newNode;
		m_tail = newNode;
		m_size++;
	}

	void popFront()
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

		if (m_size == 1)
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			Node* tempNode = m_head;
			m_head = m_head->m_next;
			delete tempNode;
		}
		m_size--;
	}

	void popBack()
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

		if (m_size == 1)
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			Node* tempNode = m_tail;
			m_tail = m_tail->m_previous;
			delete tempNode;
		}
		m_size--;
	}

	void insert(T element, int index)
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

		if (index < 0 || index > m_size)
		{
			throw std::out_of_range("Invalid index!");
		}

		if (index == 0)
		{
			pushFront(element);
			return;
		}
		else
		{
			int counter = 1;
			Node* tempNode = m_head;

			while (counter < index)
			{
				tempNode = tempNode->m_next;
				counter++;
			}

			Node* newNode = new Node(element);
			newNode->m_next = tempNode->m_next;
			newNode->m_previous = tempNode;

			if (tempNode->m_next != nullptr)
			{
				tempNode->m_next->m_previous = newNode;
			}
			tempNode->m_next = newNode;
		}
		m_size++;
	}

	void erase(int index)
	{
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

		if (index < 0 || index > m_size - 1)
		{
			throw std::out_of_range("Invalid index!");
		}

		if (index == 0)
		{
			popFront();
			return;
		}
		else
		{
			int counter = 1;
			Node* tempNode = m_head;

			while (counter < index)
			{
				tempNode = tempNode->m_next;
				counter++;
			}

			Node* nodeToDelete = tempNode->m_next;
			tempNode->m_next = nodeToDelete->m_next;

			if (nodeToDelete->m_next != nullptr)
			{
				nodeToDelete->m_next->m_previous = tempNode;
			}

			delete nodeToDelete;
			m_size--;
		}
	}

	int size() const
	{
		return m_size;
	}

	bool isEmpty() const
	{
		return m_head == nullptr;
	}


private:
	struct Node
	{
		T m_element;
		Node* m_next;
		Node* m_previous;

		Node(T element) : m_element(element), m_next(nullptr), m_previous(nullptr) {}
	};
	Node* m_head;
	Node* m_tail;
	int m_size;


public:
	class Iterator
	{
	public:
		Iterator(Node* node) :
			m_node(node) {}

		T& operator*()
		{
			return m_node->m_element;
		}

		Iterator& operator++()
		{
			if (m_node != nullptr)
			{
				m_node = m_node->m_next;
			}
			return *this;
		}

		Iterator& operator--()
		{
			if (m_node != nullptr)
			{
				m_node = m_node->m_previous;
			}
			return *this;
		}

		bool operator==(const Iterator& original) const
		{
			return m_node == original.m_node;
		}

		bool operator!=(const Iterator& original) const
		{
			return m_node != original.m_node;
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
		return Iterator(m_tail);
	}
};
