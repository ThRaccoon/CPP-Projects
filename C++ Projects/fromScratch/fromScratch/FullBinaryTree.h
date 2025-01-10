#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class FullBinaryTree
{
public:
	class Position;

	FullBinaryTree()
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

		m_root = new Node(element);

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

	void expandExternal(const Position& position, const T& leftElement, const T& rightElement)
	{
		Node* newNode = position.m_node;

		newNode->m_left = new Node(leftElement);
		newNode->m_left->m_parent = newNode;

		newNode->m_right = new Node(rightElement);
		newNode->m_right->m_parent = newNode;

		m_size += 2;
	}

	Position removeAboveExternal(const Position& position)
	{
		Node* removeNode = position.m_node;

		if (removeNode->m_parent == nullptr)
		{
			throw std::runtime_error("The root can't be deleted!");
		}

		if (!position.isExternal())
		{
			throw std::runtime_error("Only external nodes can be deleted!");
		}

		Node* parentNode = removeNode->m_parent;
		Node* siblingNode;

		if (removeNode == parentNode->m_left)
		{
			siblingNode = parentNode->m_right;
		}
		else
		{
			siblingNode = parentNode->m_left;
		}

		if (parentNode->m_parent == nullptr)
		{
			m_root = siblingNode;
			siblingNode->m_parent = nullptr;
		}
		else
		{
			Node* grandparentNode = parentNode->m_parent;
			siblingNode->m_parent = grandparentNode;

			if (parentNode == grandparentNode->m_left)
			{
				grandparentNode->m_left = siblingNode;
			}
			else
			{
				grandparentNode->m_right = siblingNode;
			}
		}

		delete removeNode;
		delete parentNode;

		m_size -= 2;

		return Position(siblingNode);
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
	void preorderPrint(Position root, int indentLevel = 0) const
	{
		if (root.m_node == nullptr)
		{
			return;
		}

		for (int i = 0; i < indentLevel; i++)
		{
			std::cout << "|  ";
		}
		std::cout << "|-- " << root.m_node->m_element << std::endl;

		if (root.left().m_node != nullptr)
		{
			preorderPrint(root.left(), indentLevel + 1);
		}

		if (root.right().m_node != nullptr)
		{
			preorderPrint(root.right(), indentLevel + 1);
		}
	}

	void printMirrorTree(Position root, int indentLevel = 0) const
	{
		if (root.m_node == nullptr)
		{
			return;
		}

		for (int i = 0; i < indentLevel; i++)
		{
			std::cout << "|  ";
		}
		std::cout << "|-- " << root.m_node->m_element << std::endl;

		if (root.right().m_node != nullptr)
		{
			printMirrorTree(root.right(), indentLevel + 1);
		}

		if (root.left().m_node != nullptr)
		{
			printMirrorTree(root.left(), indentLevel + 1);
		}
	}

	std::vector<Position> positions() const
	{
		std::vector<Position> container;

		_positions(m_root, container);

		return container;
	}

	int depth(const Position& position) const
	{
		int depth = 0;
		Node* current = position.m_node;
		while (current->m_parent != nullptr)
		{
			current = current->m_parent;
			depth++;
		}
		return depth;
	}

	int height(const Position& position) const
	{
		return _height(position.m_node);
	}


private:
	struct Node
	{
		T m_element;
		Node* m_parent;
		Node* m_left;
		Node* m_right;

		Node(T element) : m_element(element), m_parent(nullptr), m_left(nullptr), m_right(nullptr) {}
	};
	Node* m_root;
	int m_size;

	//Helper
	void _positions(Node* node, std::vector<Position>& container) const
	{
		if (node == nullptr)
		{
			return;
		}

		container.push_back(Position(node));

		if (node->m_left != nullptr)
		{
			_positions(node->m_left, container);
		}

		if (node->m_right != nullptr)
		{
			_positions(node->m_right, container);
		}
	}

	int _height(Node* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		int leftHeight = _height(node->m_left);
		int rightHeight = _height(node->m_right);

		return 1 + std::max(leftHeight, rightHeight);
	}


public:
	class Position
	{
	public:
		Position(Node* node = nullptr) : m_node(node) {}

		Position parent() const
		{
			return Position(m_node->m_parent);
		}

		Position left() const
		{
			return Position(m_node->m_left);
		}

		Position right() const
		{
			return Position(m_node->m_right);
		}

		bool isRoot() const
		{
			return m_node->m_parent == nullptr;
		}

		bool isExternal() const
		{
			return (m_node->m_left == nullptr && m_node->m_right == nullptr);
		}

		//Getter
		Node* getNode() const
		{
			return m_node;
		}

		friend class FullBinaryTree;


	private:
		Node* m_node;
	};
};

