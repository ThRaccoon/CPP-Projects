#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class SingleLinkedList
{
public:
	 SingleLinkedList()
	 {
		 m_head = nullptr;
		 m_tail = nullptr;
		 m_size = 0;
	 }

	 SingleLinkedList(const SingleLinkedList& original)
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
			 tempCopy = tempCopy->m_next; 
		 }
		 m_tail = tempCopy;
	 }

	 SingleLinkedList& operator=(const SingleLinkedList& original)
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
				tempCopy = tempCopy->m_next;
			}
			m_tail = tempCopy;
		}
		return *this;
	 }

	 ~SingleLinkedList()
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
			Node* tempNode = m_head;
			while (tempNode->m_next->m_next != nullptr)
			{
				tempNode = tempNode->m_next;
			}
			delete tempNode->m_next;
			tempNode->m_next = nullptr;
			m_tail = tempNode;
		 }
		 m_size--;
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
	
		Node(T element) : m_element(element), m_next(nullptr) {}
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
