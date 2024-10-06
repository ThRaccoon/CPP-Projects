#include "FunctionsDeclarations.h"
#include <iostream>

int main()
{
	struc struc1;
	std::string firstLine;
	std::string secondLine;
	std::string gamemode;
	std::string gameWord;
	std::string guessWord;
	char guessLetter = '_';
	bool isItTrue = false;
	int tries = 0;
	int op = 0;

	while (true)
	{
		system("cls");
		isItTrue = false;
		tries = 7;
		guessWord.clear();
		firstLine.clear();
		secondLine.clear();

		makeItCentred("HANG MAN", 1, 0);
		drawBackGround();
		std::cout << "(1).Play" << std::endl;
		std::cout << "(2).Rules" << std::endl;
		std::cout << "(3).Leave" << std::endl;
		std::cout << ">";
		std::cin >> op;
		isItInt(op);

		switch (op)
		{
		case 1:
		{
			system("cls");
			gamemode = chooseGameMode();
			gameWord = read(gamemode);
			guessLetter = pickLetter(gameWord);
			system("cls");

			while (tries > 0 && isItTrue == false)
			{
				struc1 = check(tries, guessLetter, guessWord, gameWord);
				guessWord = struc1.f_str;
				struc1 = checkFirstAndSecondLine(guessLetter, 'A', 'M', 'N', 'Z', firstLine, secondLine);
				firstLine = struc1.s_str;
				secondLine = struc1.t_str;
				makeItCentred("HANG MAN", 1, 1);
				drawHangMan(tries);
				makeItCentred("AVAILABLE LATTERS:", 1, 1);
				makeItCentred(firstLine, 1, 0);
				makeItCentred(secondLine, 0, 1);
				makeItCentred(guessWord, 1, 1);

				std::cin >> guessLetter;
				if (guessLetter < 123 && guessLetter > 96)
				{
					guessLetter -= 32;
				}
				struc1 = check(tries, guessLetter, guessWord, gameWord);
				tries = struc1.f_int;
				guessWord = struc1.f_str;
				isItTrue = isItWin(guessWord, gameWord);
				system("cls");
			}

			if (tries <= 0)
			{
				drawHangMan(0);
				makeItCentred("YOU LOSED!", 1, 1);
				std::cout << "(1).Back to main menu" << std::endl;
				std::cin >> op;
				isItInt(op);
			}
			else
			{
				drawHangMan(tries);
				makeItCentred("YOU WIN!", 1, 1);
				std::cout << "(1).Back to main menu" << std::endl;
				std::cin >> op;
				isItInt(op);
			}
			break;

		}
		case 2:
		{
			system("cls");
			std::cout << "|The object of hangman is to guess the secret|" << std::endl;
			std::cout << "|word before the stick figure is hung.       |" << std::endl;
			std::cout << "|You can make only 7 mistakes!               |" << std::endl;
			std::cout << "|USE ONLY UPPER LATTERS!                     |" << std::endl;
			std::cout << "(1).Back to main menu" << std::endl;
			std::cout << ">";
			std::cin >> op;
			isItInt(op);
			break;
		}
		case 3:
		{
			system("cls");
			makeItCentred("Thanks for playing!", 1, 1);
			exit(0);
			break;
		}
		}
	}

	return 0;
}