#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>


template <typename K, typename V>
class HashMap
{
public:
	struct Pair;
	class Iterator;
	using BucketIterator = typename std::vector<std::list<Pair>>::iterator;
	using ListIterator = typename std::list<Pair>::iterator;


	HashMap() : m_buckets(10)
	{
		m_size = 0;
		m_index = 0;
	}

	Iterator find(const K& key, const V& value)
	{
		m_index = hashFunction(key);
		for (auto it = m_buckets[m_index].begin(); it != m_buckets[m_index].end(); ++it)
		{
			if (it->m_key == key && it->m_value == value)
			{
				return Iterator(m_buckets.begin() + m_index, m_buckets.end(), it);
			}
		}
		return end();
	}

	void insert(const K& key, const V& value)
	{
		m_index = hashFunction(key);
		m_buckets[m_index].push_back(Pair(key, value));
		m_size++;
	}

	void erase(const K& key, const V& value)
	{
		if (isEmpty())
		{
			throw std::runtime_error("Map is empty!");
		}

		m_index = hashFunction(key);
		auto& bucket = m_buckets[m_index];

		for (auto it = bucket.begin(); it != bucket.end(); ++it)
		{
			if (it->m_key == key && it->m_value == value)
			{
				bucket.erase(it);
				m_size--;

				break;
			}
		}
	}

	Iterator eraseWithIterator(Iterator it)
	{
		auto bucketIt = it.m_bucketIt;
		auto listIt = it.m_listIt;

		listIt = bucketIt->erase(listIt);

		if (bucketIt->empty())
		{
			bucketIt++;
			while (bucketIt != m_buckets.end() && bucketIt->empty())
			{
				bucketIt++;
			}
		}

		if (bucketIt == m_buckets.end())
		{
			return Iterator(bucketIt, m_buckets.end(), ListIterator());
		}

		if (bucketIt != m_buckets.end() && !bucketIt->empty())
		{
			listIt = bucketIt->begin();
		}

		return Iterator(bucketIt, m_buckets.end(), listIt);
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
	void print() const
	{
		for (int i = 0; i < m_buckets.size(); i++)
		{
			std::cout << "Bucket " << i << ": ";
			for (const auto& pair : m_buckets[i])
			{
				std::cout << "[" << pair.m_key << ": " << pair.m_value << "] ";
			}
			std::cout << std::endl;
		}
	}

	void removeOddBuckets()
	{
		for (auto it = m_buckets.begin(); it != m_buckets.end();)
		{
			if (it->size() % 2 != 0)   
			{
				*it = std::list<Pair>();
				++it;
			}
			else
			{
				++it;
			}
		}
	}


private:
	struct Pair
	{
		K m_key;
		V m_value;

		Pair(const K& key, const V& value) : m_key(key), m_value(value) {}
	};
	int m_size;
	int m_index;
	std::vector<std::list<Pair>> m_buckets;

	int hashFunction(const K& key) const
	{
		return key % m_buckets.size();
	}


public:
	class Iterator
	{
	public:
		Iterator(BucketIterator bucketIt, BucketIterator endBucketIt, ListIterator listIt)
			: m_bucketIt(bucketIt), m_endBucketIt(endBucketIt), m_listIt(listIt) {}

		Pair& operator*() const
		{
			return *m_listIt;
		}

		Iterator& operator++()
		{
			m_listIt++;

			if (m_listIt == m_bucketIt->end() && m_bucketIt != m_endBucketIt)
			{
				m_bucketIt++;
				while (m_bucketIt != m_endBucketIt && m_bucketIt->empty())
				{
					m_bucketIt++;
				}

				if (m_bucketIt != m_endBucketIt)
				{
					m_listIt = m_bucketIt->begin();
				}
				else
				{
					m_listIt = ListIterator();
				}
			}
			return *this;
		}

		bool operator==(const Iterator& other) const
		{
			return m_bucketIt == other.m_bucketIt && m_listIt == other.m_listIt;
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}

		friend class HashMap;

	private:
		BucketIterator m_bucketIt;
		BucketIterator m_endBucketIt;
		ListIterator m_listIt;
	};

	Iterator begin()
	{
		for (auto it = m_buckets.begin(); it != m_buckets.end(); ++it)
		{
			if (!it->empty())
			{
				return Iterator(it, m_buckets.end(), it->begin());
			}
		}
		return end();
	}

	Iterator end()
	{
		return Iterator(m_buckets.end(), m_buckets.end(), ListIterator());
	}
};
