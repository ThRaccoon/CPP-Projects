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
		std::vector<Position> container;

		_positions(root, container);

		return container;
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

	std::vector<T> returnNodesValuesWithSpecificNumberOfChildren(int numChildren, Position root) const
	{
		std::vector<T> container;

		_returnNodesValuesWithSpecificNumberOfChildren(numChildren, root, container);

		return container;
	}

	std::vector<T> returnNodesValuesOnSpecificLevel(int targetLevel, Position root) const
	{
		//Root level is 0

		std::vector<T> container;

		_returnNodesValuesOnSpecificLevel(targetLevel, root, container);

		return container;
	}

	void preorderPrint(Position root, int indentLevel = 0) const
	{
		for (int i = 0; i < indentLevel; i++)
		{
			std::cout << "|  ";
		}
		std::cout << "|-- " << *root << std::endl;

		for (const auto& child : root.children())
		{
			preorderPrint(child, indentLevel + 1);
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
	void _positions(Position root, std::vector<Position>& container) const
	{
		container.push_back(root);

		for (const auto& child : root.children())
		{
			_positions(child, container);
		}
	}

	void _returnNodesValuesWithSpecificNumberOfChildren(int numChildren, Position root, std::vector<T>& container) const
	{
		if (numChildren == root.children().size())
		{
			container.push_back(*root);
		}

		for (const auto& child : root.children())
		{
			_returnNodesValuesWithSpecificNumberOfChildren(numChildren, child, container);
		}
	}

	void _returnNodesValuesOnSpecificLevel(int targetLevel, Position root, std::vector<T>& container, int currentLevel = 0) const
	{
		if (currentLevel == targetLevel)
		{
			container.push_back(*root);
		}

		for (const auto& child : root.children())
		{
			_returnNodesValuesOnSpecificLevel(targetLevel, child, container, currentLevel + 1);
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