#include <iostream>
#include <vector>
#include <algorithm>
#include <random> 

int randNumberGenerator();
void printList(std::vector<int> list);
void sortList(std::vector<int>& list);

int main()
{
	std::vector<int> list;
	int userInput = 0;
	int item = 0;

	do
	{
		std::cout << "Please choose from this three options" << std::endl;
		std::cout << "Press (1) for generation random code" << std::endl;
		std::cout << "Press (2) to see the list of all generated codes" << std::endl;
		std::cout << "Press (3) to see the list in order" << std::endl;
		std::cout << "Press (4) to exit" << std::endl;
		std::cin >> userInput;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> userInput;
		}

		switch (userInput)
		{
		case 1:
		{
			int item = randNumberGenerator();
			if (std::find(list.begin(), list.end(), item) != list.end())
			{
				std::cout << "This code was already generated! Please press (1) to generate a new one!" << std::endl;
			}
			else
			{
				list.push_back(item);
				std::cout << "----" << std::endl;
				std::cout << item << std::endl;
				std::cout << "----" << std::endl;
			}
			break;
		}
		case 2:
		{
			printList(list);
			break;
		}
		case 3:
		{
			sortList(list);
			printList(list);
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
	defaul:
		{
			std::cout << "Please use the numbers from 1 to 3" << std::endl;
			break;
		}
		}

	} while (userInput != 4);

	return 0;
}

int randNumberGenerator()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9999);
	return dist(rng);
}

void printList(std::vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << "----" << std::endl;
		std::cout << list[i] << std::endl;
	}
	std::cout << "----" << std::endl;
}

void sortList(std::vector<int>& list)
{
	bool swapp = true;
	while (swapp)
	{
		swapp = false;
		for (int i = 0; i < list.size() - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				list[i] += list[i + 1];
				list[i + 1] = list[i] - list[i + 1];
				list[i] -= list[i + 1];
				swapp = true;
			}
		}
	}
}