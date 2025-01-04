#pragma once

#include <iostream>
#include <stdexcept>
#include <list>

template <typename K, typename V>
class ListMap
{
public:
	struct Pair;
	using Iterator = typename std::list<Pair>::iterator;
	 
	ListMap()
	{
		m_size = 0;
	}

	Iterator find(const K& key)
	{
		for (auto it = m_pairList.begin(); it != m_pairList.end(); ++it)
		{
			if (it->getKey() == key)
			{
				return it;
			}
		}
		
		return m_pairList.end();
	}

	Iterator put(const K& key, const V& value)
	{
		for (auto it = m_pairList.begin(); it != m_pairList.end(); ++it)
		{
			if (it->getKey() == key)
			{
				it->setValue(value);
				return it;
			}
		}
		
		m_pairList.push_back(Pair(key, value));
		m_size++;
		return std::prev(m_pairList.end());
	}

	void eraseWithKey(const K& key)
	{
		if (isEmpty())
		{
			throw std::runtime_error("Map is empty!");
		}

		for (auto it = m_pairList.begin(); it != m_pairList.end(); ++it)
		{
			if (it->getKey() == key)
			{
				m_pairList.erase(it);
				m_size--;
				return;
			}
		}

		throw std::runtime_error("Key not found!");
	}

	void eraseWithIterator(const Iterator& it)
	{
		if (isEmpty())
		{
			throw std::runtime_error("Map is empty!");
		}

		if (it == m_pairList.end())
		{
			throw std::runtime_error("Invalid iterator!");
		}

		m_pairList.erase(it);
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

	Iterator begin()
	{
		return m_pairList.begin();
	}

	Iterator end()
	{
		return m_pairList.end();
	}


private:
	struct Pair
	{
		K m_key;
		V m_value;

		Pair(K key, V value) : m_key(key), m_value(value) {}

		K getKey() const
		{
			return m_key;
		}

		void setKey(const K& key)
		{
			m_key = key;
		}

		V getValue() const
		{
			return m_value;
		}

		void setValue(const V& value)
		{
			m_value = value;
		}
	};
	int m_size;
	std::list<Pair> m_pairList;
};