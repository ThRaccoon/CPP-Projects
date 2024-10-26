#include <iostream>

#include "MineSweeper.h"


void isInt(int& input);

int main()
{
	MineSweeper mineSweeper;

	std::string result = "";
	std::string dummy = "";

	int inpRow = 0;
	int inpCol = 0;
	int userInput = 0;

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
					std::cout << std::endl;

					std::cout << "Row: ";
					std::cin >> inpRow;
					isInt(inpRow);

					std::cout << "Col: ";
					std::cin >> inpCol;
					isInt(inpCol);

					result = mineSweeper.checkInput(inpRow, inpCol);
				}

				if (mineSweeper.checkForVictory())
				{
					mineSweeper.drawScreen(mineSweeper.getHiddenField());
					mineSweeper.drawVictoryScreen();
					mineSweeper.restart();
					std::cin >> dummy;
					break;
				}

				if (mineSweeper.checkForDefeat(inpRow, inpCol))
				{
					mineSweeper.drawScreen(mineSweeper.getHiddenField());
					mineSweeper.drawDefeatScreen();
					mineSweeper.restart();
					std::cin >> dummy;
					break;
				}

				mineSweeper.incrementScore();
				mineSweeper.incrementTriesProgression();
				mineSweeper.shouldAddTry();
				mineSweeper.shouldRemoveTry(inpRow, inpCol);
				mineSweeper.updateVisibleField(inpRow, inpCol);
				mineSweeper.updateHiddenField(inpRow, inpCol);
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
