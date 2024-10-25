#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class List
{
public:
	 List()
	 {
		 m_head = nullptr;
		 m_size = 0;
	 }

	 List(const List& original)
	 {
		 m_size = original.m_size;

		 if (original.m_head == nullptr)
		 {
			 m_head = nullptr;
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
	 }

	 List& operator=(const List& original)
	 {
		if (this != &original)
		{
			while (m_head != nullptr)
			{
				Node* temp = m_head;
				m_head = m_head->m_next;
				delete temp;
			}
			
			m_size = original.m_size;

			if (original.m_head == nullptr)
			{
				m_head = nullptr;
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
		}
		return *this;
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
		 
		 Node* temp = m_head;
		 while (temp->m_next != nullptr)
		 {
			 temp = temp->m_next;
		 }
		 return temp->m_element;
	 }

	 void pushFront(T element)
	 {
		Node* newNode = new Node(element);
		newNode->m_next = m_head;
		m_head = newNode;
		m_size++;
	 }

	 void pushBack(T element)
	 {
		if (m_head == nullptr)
		{
			pushFront(element);
			return;
		}
		
		Node* temp = m_head;
		while (temp->m_next != nullptr)
		{
			temp = temp->m_next;
		}

		Node* newNode = new Node(element);
		temp->m_next = newNode;
		m_size++;
	 }

	 void popFront()
	 {
		if (isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}
	 
		Node* temp = m_head;
		m_head = m_head->m_next; 
		
		delete temp;
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
	int m_size;
};
