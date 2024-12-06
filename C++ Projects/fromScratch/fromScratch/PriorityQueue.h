#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue()
	{
		m_head = nullptr;
		m_size = 0;
	}

	~PriorityQueue()
	{
		while (m_head != nullptr)
		{
			Node* tempNode = m_head;
			m_head = m_head->m_next;
			delete tempNode;
		}
	}

	std::pair<T, int> getMinElement() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("PriorityQueue is empty!");
		}
		return { m_head->m_element, m_head->m_priority };
	}

	void insertElement(T element, int priority)
	{
		Node* newNode = new Node(element, priority);

		if (isEmpty())
		{
			newNode->m_next = m_head;
			m_head = newNode;
		}
		else
		{
			Node* prevNode = nullptr;
			Node* tempNode = m_head;

			while (tempNode != nullptr)
			{
				if (priority >= tempNode->m_priority)
				{
					prevNode = tempNode;
					tempNode = tempNode->m_next;
				}
				else
				{
					break;
				}
			}

			if (prevNode != nullptr)
			{
				prevNode->m_next = newNode;
			}
			else
			{
				m_head = newNode;
			}
			newNode->m_next = tempNode;
		}
		m_size++;
	}

	void removeMinElement()
	{
		if (isEmpty())
		{
			throw std::runtime_error("PriorityQueue is empty!");
		}

		if (m_size == 1)
		{
			delete m_head;
			m_head = nullptr;
		}
		else
		{
			Node* tempNode = m_head;
			m_head = m_head->m_next;
			delete tempNode;
		}
		m_size--;
	}

	int size() const
	{
		return m_size;
	}

	bool isEmpty() const
	{
		return m_size == 0;
	}


private:
	struct Node
	{
		T m_element;
		int m_priority;
		Node* m_next;

		Node(T element, int priority) : m_element(element), m_priority(priority), m_next(nullptr) {}
	};
	Node* m_head;
	int m_size;


public:
	class Iterator
	{
	public:
		Iterator(Node* node) : m_node(node) {}

		std::pair<T, int> operator*()
		{
			return { m_node->m_element, m_node->m_priority };
		}

		Iterator& operator++()
		{
			if (m_node != nullptr)
			{
				m_node = m_node->m_next;
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
		return Iterator(nullptr);
	}
};
