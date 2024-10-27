#include <iostream>

#include "mineSweeper.h"


void isInt(int& input);

int main()
{
	MineSweeper mineSweeper;
	
	int userInput = 0;
	int inputRow = 0;
	int inputCol = 0;

	std::string result = "";
	std::string dummy = "";

	while (true)
	{
		mineSweeper.drawMainMenu();
		
		std::cin >> userInput;
		isInt(userInput);

		switch (userInput)
		{
		case 1:
		{
			while (true)
			{
				result = "";
				while (result != "101")
				{
					mineSweeper.drawScreen(mineSweeper.getVisibleField());
					std::cout << result << std::endl;

					std::cout << "Row: ";
					std::cin >> inputRow;
					isInt(inputRow);

					std::cout << "Col: ";
					std::cin >> inputCol;
					isInt(inputCol);

					result = mineSweeper.checkInput(inputRow, inputCol);
				}
				
				mineSweeper.shouldIncrementScore(inputRow, inputCol);
				mineSweeper.shouldIncrementTries(inputRow, inputCol);
				mineSweeper.shouldRemoveTry(inputRow, inputCol);

				if (mineSweeper.checkForVictory())
				{
					mineSweeper.drawScreen(mineSweeper.getHiddenField());
					mineSweeper.drawVictoryScreen();
					mineSweeper.restart();
					
					std::cin >> dummy;
					break;
				}

				if (mineSweeper.checkForDefeat(inputRow, inputCol))
				{
					mineSweeper.drawScreen(mineSweeper.getHiddenField());
					mineSweeper.drawDefeatScreen();
					mineSweeper.restart();
					
					std::cin >> dummy;
					break;
				}
				
				mineSweeper.updateVisibleField(inputRow, inputCol);
				mineSweeper.updateHiddenField(inputRow, inputCol);
			}
		}
		break;

		case 2:
		{
			mineSweeper.drawRules();

			std::cin >> dummy;
		}
		break;

		case 3:
		{
			exit(0);
		}

		default:
		{}
		break;
		}
	}
	return 0;
}

void isInt(int& input)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();

		std::cin >> input;
	}
}
