#include <iostream>
 
#include "functionsDeclaration.h"


int main()
{
	int option = 0;
	while (true)
	{
		drawMainMenu();
		std::cin >> option;
		isInt(option);

		switch (option)
		{
			case 1:
			{
				//Init
				const int ROW_SIZE = 10;
				const int COL_SIZE = 10;
				const int MINES_COUNT = 10;

				std::vector<std::vector<char>> hiddenField;
				std::vector<std::vector<char>> visibleField;

				int row = 0;
				int col = 0;
				int score = 0;
				std::string result = "";

				initializeField(hiddenField, '0', ROW_SIZE, COL_SIZE);
				initializeField(visibleField, '#', ROW_SIZE, COL_SIZE);
				armField(hiddenField, MINES_COUNT);

				//Game loop
				while (true)
				{
					while (result != "101")
					{
						system("cls");
						drawField(visibleField, score);

						std::cout << result << std::endl;
						std::cout << "Row:";
						std::cin >> row;
						isInt(row);
						row -= 1;
						
						std::cout << "Col:";
						std::cin >> col;
						isInt(col);
						col -= 1;
						 
						result = checkCoordinates(visibleField, ROW_SIZE, COL_SIZE, row, col);
					}
					result = "";

					if (isMineHit(hiddenField, score, row, col))
					{
						system("cls");
						drawField(hiddenField, score);
						drawDeathScreen();
						
						std::string dummy;
						std::cin >> dummy;
						
						break;
					}
					updateVisibleField(visibleField, row, col);
				}
			}
			break;

			case 2:
			{
				drawRules();
				
				std::string dummy;
				std::cin >> dummy;
			}
			break;

			case 3:
			{
				exit(0);
			}
			break;
		
			default:
			{}
			break;
		}
	}
	return 0;
}