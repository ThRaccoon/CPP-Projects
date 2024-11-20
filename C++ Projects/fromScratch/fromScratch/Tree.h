#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Tree
{
public:
	class Position;
	struct Node;

	Tree()
	{
		m_root = nullptr;
		m_size = 0;
	}

	void createRoot(T element)
	{
		if (m_root != nullptr)
		{
			throw std::runtime_error("The tree can have only one root!");
		}

		Node* newNode = new Node(element);
		m_root = newNode;

		m_size++;
	}

	Position getRootPosition() const
	{
		if (m_root == nullptr)
		{
			throw std::runtime_error("The tree does not have a root yet!");
		}

		return Position(m_root);
	}

	std::vector<Position> positions(Position root) const
	{
		std::vector<Position> positionsVector;

		preorderPositionsSearch(root, positionsVector);

		return positionsVector;
	}

	void insert(T element, Position parent)
	{
		Node* newNode = new Node(element);
		Node* parentNode = parent.m_node;

		newNode->m_parent = parentNode;
		parentNode->m_children.push_back(newNode);

		m_size++;
	}

	int size() const
	{
		return m_size;
	}

	bool isEmpty() const
	{
		return m_size == 0;
	}

	//Helper
	int NumberSearch(int number, Position root) const
	{
		int counter = 0;

		if (number == *root)
		{
			counter++;
		}

		for (const auto& child : root.children())
		{
			counter += preorderNumberSearch(number, child);
		}

		return counter;
	}

	bool checkIfNodeWithSpecificNumberOfChildrenExist(int numChildren, Position root) const
	{
		if (numChildren == root.children().size())
		{
			return true;
		}

		for (const auto& child : root.children())
		{
			if (checkIfNodeWithSpecificNumberOfChildrenExist(numChildren, child))
			{
				return true;
			}
		}

		return false;
	}

	std::vector<T>& returnNodesValuesWithSpecificNumberOfChildren(int numChildren, std::vector<T>& container, Position root) const
	{
		if (numChildren == root.children().size())
		{
			container.push_back(*root);
		}

		for (const auto& child : root.children())
		{
			returnNodesValuesWithSpecificNumberOfChildren(numChildren, container, child);
		}

		return container;
	}

	void preorderPrint(Position root) const
	{
		std::cout << *root << " ";

		for (const auto& child : root.children())
		{
			preorderPrint(child);
		}
	}


private:
	struct Node
	{
		T m_element;
		Node* m_parent;
		std::vector<Node*> m_children;

		Node(T element) : m_element(element), m_parent(nullptr) {}
	};
	Node* m_root;
	int m_size;

	//Helper
	void preorderPositionsSearch(Position root, std::vector<Position>& positionsVector) const
	{
		positionsVector.push_back(root);

		for (const auto& child : root.children())
		{
			preorderPositionsSearch(child, positionsVector);
		}
	}


public:
	class Position
	{
	public:
		Position(Node* node) : m_node(node) {}

		T& operator*()
		{
			return m_node->m_element;
		}

		Position parent()
		{
			if (m_node->m_parent == nullptr)
			{
				throw std::runtime_error("The root does not have a parent!");
			}

			return Position(m_node->m_parent);
		}

		std::vector<Position> children()
		{
			std::vector<Position> childrenVector;
			for (const auto& child : m_node->m_children)
			{
				childrenVector.push_back(Position(child));
			}

			return childrenVector;
		}

		bool isRoot() const
		{
			return m_node->m_parent == nullptr;
		}

		bool isExternal() const
		{
			return m_node->m_children.empty();
		}

		friend class Tree;


	private:
		Node* m_node;
	};
};