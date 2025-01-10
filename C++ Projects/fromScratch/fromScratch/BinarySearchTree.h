#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		m_size = 0;
		m_root = nullptr;
	}

	~BinarySearchTree()
	{
		_destructor(m_root);
	}

	bool find(T value)
	{
		if (m_root == nullptr)
		{
			throw std::runtime_error("The tree is empty!");
		}

		return _find(m_root, value);
	}

	void insert(T value)
	{
		m_root = _insert(m_root, value);
	}

	void erase(T value)
	{
		if (m_root == nullptr)
		{
			throw std::runtime_error("The tree is empty!");
		}

		m_root = _erase(m_root, value);
	}

	int size() const
	{
		return m_size;
	}

	bool isEmpty() const
	{
		return m_size == 0;
	}

	//Testing
	void print() const
	{
		if (m_root == nullptr)
		{
			throw std::runtime_error("The tree is empty!");
		}

		_preorderPrint(m_root, 0);
	}

	int countLeaves() const
	{
		return _countLeaves(m_root);
	}

private:
	struct Node
	{
		T m_value;
		Node* m_leftChild;
		Node* m_rightChild;

		Node(T value) : m_value(value), m_leftChild(nullptr), m_rightChild(nullptr) {}
	};
	int m_size;
	Node* m_root;

	//Helper
	void _destructor(Node* root)
	{
		if (root != nullptr)
		{
			_destructor(root->m_leftChild);
			_destructor(root->m_rightChild);
			delete root;
		}
	}

	bool _find(Node* root, T value)
	{
		if (root == nullptr)
		{
			return false;
		}
		else if (root->m_value == value)
		{
			return true;
		}
		else if (root->m_value > value)
		{
			return _find(root->m_leftChild, value);
		}
		else if (root->m_value < value)
		{
			return _find(root->m_rightChild, value);
		}
	}

	Node* _insert(Node* root, T value)
	{
		if (root == nullptr)
		{
			Node* newNode = new Node(value);
			root = newNode;
			m_size++;
		}
		else if (root->m_value > value)
		{
			root->m_leftChild = _insert(root->m_leftChild, value);
		}
		else if (root->m_value < value)
		{
			root->m_rightChild = _insert(root->m_rightChild, value);
		}
		return root;
	}

	Node* _erase(Node* root, T value)
	{
		if (root == nullptr)
		{
			return root;
		}
		else if (root->m_value > value)
		{
			root->m_leftChild = _erase(root->m_leftChild, value);
		}
		else if (root->m_value < value)
		{
			root->m_rightChild = _erase(root->m_rightChild, value);
		}
		else
		{
			if (root->m_leftChild == nullptr && root->m_rightChild == nullptr)
			{
				delete root;
				root = nullptr;
				m_size--;
			}
			else if (root->m_leftChild == nullptr)
			{
				Node* tempNode = root;
				root = root->m_rightChild;
				delete tempNode;
				m_size--;
			}
			else if (root->m_rightChild == nullptr)
			{
				Node* tempNode = root;
				root = root->m_leftChild;
				delete tempNode;
				m_size--;
			}
			else
			{
				Node* tempNode = _findMin(root->m_rightChild);
				root->m_value = tempNode->m_value;
				root->m_rightChild = _erase(root->m_rightChild, tempNode->m_value);
			}
		}
		return root;
	}

	Node* _findMin(Node* root)
	{
		while (root->m_leftChild != nullptr)
		{
			root = root->m_leftChild;
		}
		return root;
	}

	//Testing
	void _preorderPrint(Node* root, int depth) const
	{
		if (root == nullptr)
		{
			return;
		}

		for (int i = 0; i < depth; i++)
		{
			std::cout << "|  ";
		}
		std::cout << "|-- " << root->m_value << std::endl;

		_preorderPrint(root->m_leftChild, depth + 1);
		_preorderPrint(root->m_rightChild, depth + 1);
	}

	int _countLeaves(Node* root) const
	{
		if (root == nullptr)
		{
			return 0;
		}

		if (root->m_leftChild == nullptr && root->m_rightChild == nullptr)
		{
			return 1;
		}

		return _countLeaves(root->m_leftChild) + _countLeaves(root->m_rightChild);
	}
};
