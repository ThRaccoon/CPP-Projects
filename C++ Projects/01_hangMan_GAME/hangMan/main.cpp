#include <iostream>

#include "hangMan.h"


void isInt(int& input);

int main()
{
	HangMan hangMan;
	
	int userInput = 0;
	
	char userLetter = ' ';

	std::string result = "";
	std::string dummy = "";
	 
	while (true)
	{
		hangMan.drawMainMenu();
		
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
					hangMan.drawScreen();
					hangMan.drawHiddenWord(hangMan.getVisibleWord());
					hangMan.drawIncorrectGuesses();
					std::cout << result << std::endl;
					std::cout << ">";
					 
					std::cin >> userLetter;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					userLetter = toupper(userLetter);
					 
					result = hangMan.checkInput(userLetter);	 
				}
				hangMan.updateVisibleWord(userLetter);
				hangMan.shouldIncrementScore(userLetter);
				hangMan.shouldDecrementTries(userLetter);

				if (hangMan.checkForVictory())
				{
					hangMan.drawScreen();
					hangMan.drawHiddenWord(hangMan.getHiddenWord());
					hangMan.drawIncorrectGuesses();
					hangMan.drawVictoryScreen();
					hangMan.restart();

					std::cin >> dummy;
					break;
				}
				
				if (hangMan.checkForDefeat())
				{
					hangMan.drawScreen();
					hangMan.drawHiddenWord(hangMan.getHiddenWord());
					hangMan.drawIncorrectGuesses();
					hangMan.drawDefeatScreen();
					hangMan.restart();

					std::cin >> dummy;
					break;
				}
			}
		}
		break;

		case 2:
		{
			hangMan.drawRules();
			
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