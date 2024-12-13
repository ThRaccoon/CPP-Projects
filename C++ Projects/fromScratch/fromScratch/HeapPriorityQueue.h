#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class HeapPriorityQueue
{
public:
	HeapPriorityQueue()
	{
		m_size = 0;
	}

	~HeapPriorityQueue()
	{
		for (Node* node : m_heapVector)
		{
			delete node;
		}
	}

	std::pair<T, int> top() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("PriorityQueue is empty!");
		}

		return { m_heapVector[0]->m_element, m_heapVector[0]->m_priority };
	}

	void push(T element, int priority)
	{
		m_heapVector.push_back(new Node(element, priority));

		m_size++;

		heapifyUp(size() - 1);
	}

	void pop()
	{
		if (isEmpty())
		{
			throw std::runtime_error("PriorityQueue is empty!");
		}

		m_heapVector[0] = m_heapVector[m_size - 1];
		m_heapVector.pop_back();

		m_size--;

		heapifyDown(0);
	}

	int size() const
	{
		return m_size;
	}

	bool isEmpty() const
	{
		return m_size == 0;
	}

	//---
	void printTree() const
	{
		if (isEmpty())
		{
			std::cout << "Heap is empty!" << std::endl;
			return;
		}

		printTreeHelper(0, 0);
	}
	//---


private:
	struct Node
	{
		T m_element;
		int m_priority;

		Node(T element, int priority) : m_element(element), m_priority(priority) {}
	};
	std::vector<Node*> m_heapVector;
	int m_size;

	//Helper
	void swapIndexes(int leftIndex, int rightIndex)
	{
		Node* tempNode = m_heapVector[leftIndex];
		m_heapVector[leftIndex] = m_heapVector[rightIndex];
		m_heapVector[rightIndex] = tempNode;
	}

	void heapifyUp(int childIndex)
	{
		int parentIndex;

		while (childIndex != 0)
		{
			parentIndex = (childIndex - 1) / 2;

			if (m_heapVector[childIndex]->m_priority < m_heapVector[parentIndex]->m_priority)
			{
				swapIndexes(childIndex, parentIndex);
			}
			else
			{
				break;
			}
		}
	}

	void heapifyDown(int parentIndex)
	{
		int vectorSize = m_heapVector.size();

		int parent = parentIndex;
		int leftChild;
		int rightChild;
		int smallest;

		while (true)
		{
			leftChild = 2 * parent + 1;
			rightChild = 2 * parent + 2;
			smallest = parent;

			if (leftChild < vectorSize && m_heapVector[leftChild]->m_priority < m_heapVector[smallest]->m_priority)
			{
				smallest = leftChild;
			}

			if (rightChild < vectorSize && m_heapVector[rightChild]->m_priority < m_heapVector[smallest]->m_priority)
			{
				smallest = rightChild;
			}

			if (smallest == parent)
			{
				break;
			}

			swapIndexes(parent, smallest);

			parent = smallest;
		}
	}

	//---
	void printTreeHelper(int index, int level) const
	{
		if (index >= m_heapVector.size())
		{
			return;
		}

		int rightIndex = 2 * index + 2;
		printTreeHelper(rightIndex, level + 1);


		for (int i = 0; i < level; ++i)
		{
			std::cout << "    ";
		}
		std::cout << m_heapVector[index]->m_element << "(" << m_heapVector[index]->m_priority << ")" << std::endl;;

		int leftIndex = 2 * index + 1;
		printTreeHelper(leftIndex, level + 1);
	}
	//---


public:
	using Iterator = typename std::vector<Node*>::iterator;

	Iterator begin()
	{
		return m_heapVector.begin();
	}

	Iterator end()
	{
		return m_heapVector.end();
	}
};