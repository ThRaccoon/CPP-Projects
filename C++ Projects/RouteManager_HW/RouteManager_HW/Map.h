#pragma once

#include "PriorityQueue.h"


class Map
{
public:
	struct Info;
	using Iterator = typename PriorityQueue<Info>::Iterator;
	 
	Map()
	{
		m_size = 0;
	}

	Iterator find(const int& distance)
	{
		for (Iterator it = m_priorityQueue.begin(); it != m_priorityQueue.end(); ++it)
		{
			if ((*it).getDistance() == distance)
			{
				return it;
			}
		}
		return m_priorityQueue.end();	 
	}

	Iterator insert(const int& distance, const std::string& name, const std::string& from, const std::string& to, int mode)
	{
		Info newInfo(distance, name, from, to);

		if (mode == 1)
		{
			for (auto it = m_priorityQueue.begin(); it != m_priorityQueue.end(); ++it)
			{
				if ((*it).getDistance() == distance)
				{
					throw std::runtime_error("This distance already exist!");
				}
			}

			m_priorityQueue.insertElement(newInfo, distance);
			m_size++;
		}
		else
		{
			bool isFound = false;

			for (auto it = m_priorityQueue.begin(); it != m_priorityQueue.end(); ++it)
			{
				if ((*it).getDistance() == distance)
				{
					m_priorityQueue.removeElement(distance);
					isFound = true;
					break;
				}
			}

			if (isFound)
			{
				m_priorityQueue.insertElement(newInfo, distance);
				m_size++;
			}
			else
			{
				throw std::runtime_error("This distance does not exist!");
			}
		}
		return find(distance);
	}

	void remove(const int& distance)
	{
		Iterator it = find(distance);
		if (it != m_priorityQueue.end())
		{
			m_priorityQueue.removeElement(distance);
			m_size--;
		}
		else
		{
			throw std::runtime_error("This distance does not exist!");
		}
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
		return m_priorityQueue.begin();
	}

	Iterator begin() const
	{
		return m_priorityQueue.begin();
	}

	Iterator end()
	{
		return m_priorityQueue.end();
	}

	Iterator end() const
	{
		return m_priorityQueue.end();
	}

	 
private:
	struct Info
	{
		int m_distance;
		std::string m_name;
		std::string m_from;
		std::string m_to;

		Info(int distance, std::string name, std::string from, std::string to) : m_distance(distance), m_name(name), m_from(from), m_to(to) {}

		//Distance
		int getDistance() const
		{
			return m_distance;
		}

		void setDistance(const int& distance)
		{
			m_distance = distance;
		}

		//Name
		std::string getName() const
		{
			return m_name;
		}

		void setName(const std::string& name)
		{
			m_name = name;
		}

		//From
		std::string getFrom() const
		{
			return m_from;
		}

		void setFrom(const std::string& from)
		{
			m_from = from;
		}

		//To
		std::string getTo() const
		{
			return m_to;
		}

		void setDistance(const std::string& to)
		{
			m_to = to;
		}

	};
	int m_size;
	PriorityQueue<Info> m_priorityQueue;
};
