#include "functionsDeclaration.h"


void initializeField(std::vector<std::vector<char>>& vec, char simbol, int rowSize, int colSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		std::vector<char> row;
		for (int j = 0; j < colSize; j++)
		{
			row.push_back(simbol);
		}
		vec.push_back(row);
	}
}

void armField(std::vector<std::vector<char>>& vec, int minesNum)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(0, 9);

	int randRow = 0;
	int randCol = 0;

	for (int i = 0; i < minesNum; i++)
	{
		while (true)
		{
			randRow = dist(rng);
			randCol = dist(rng);

			if (vec[randRow][randCol] != '1')
			{
				vec[randRow][randCol] = '1';
				break;
			}
		}
	}
}

void updateVisibleField(std::vector<std::vector<char>>& vec, int row, int col)
{
	vec[row][col] = '0';
}

void drawField(const std::vector<std::vector<char>>& vec, int& score)
{
	int rowSize = vec.size();
	int colSize = vec[0].size();

	std::cout << " Mine field... DANGER!" << std::endl;
	std::cout << "| ";
	for (int i = 0; i < colSize; i++)
	{
		std::cout << "- ";
	}
	std::cout << "|";
	std::cout << std::endl;

	for (int i = 0; i < rowSize; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < colSize; j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	std::cout << "| ";
	for (int i = 0; i < colSize; i++)
	{
		std::cout << "- ";
	}
	std::cout << "|" << std::endl;
	std::cout << "SCORE: " << score << std::endl;
}

bool isMineHit(const std::vector<std::vector<char>>& vec, int& score, int row, int col)
{
	if (vec[row][col] == '1')
	{
		return true;
	}
	score++;
	
	return false;
}

std::string checkCoordinates(const std::vector<std::vector<char>>& vec, int ROW_SIZE, int COL_SIZE, int row, int col)
{
	if (row > ROW_SIZE)
	{
		return "Whoa! You're sweeping way past the minefield! You lost?";
	}
	if (row < 0)
	{
		return "Oops! You're sweeping before the minefield! Careful to not get lost!";
	}
	if (col > COL_SIZE)
	{
		return "Whoa! You're sweeping way to the right! Are you trying to find Narnia?";
	}
	if (col < 0)
	{
		return "Oops! You're sweeping too far to the left! Are you searching for your lost sanity?";
	}

	if (vec[row][col] == '0')
	{
		return "Uh-oh! You've swept this spot again! Are you practicing your sweeping skills safely?";
	}

	return "101";
}

void isInt(int& option)
{
	while (std::cin.fail())
	{ 
		std::cin.clear();
		std::cin.ignore();
		
		std::cin >> option;
	}
}


//-
void drawMainMenu()
{
	system("cls");
	std::cout << "MineSweeper" << std::endl;
	std::cout << "(1) Play" << std::endl;
	std::cout << "(2) Rules" << std::endl;
	std::cout << "(3) Exit" << std::endl;
	std::cout << ">"; 
}

void drawRules()
{
	system("cls");
	std::cout << "Welcome to Minesweeper!" << std::endl;
	std::cout << "The object of the game is simple.. survive by sweeping the minefield!" << std::endl;
	std::cout << "Basically, try *not* to become dust by triggering a hidden bomb." << std::endl;
	std::cout << "The game board is a 10x10 grid (100 spots total), and 10 of those spots hide bombs." << std::endl;
	std::cout << "To sweep a spot, enter the row and column numbers (between 1 and 10)." << std::endl;
	std::cout << "Your goal is to uncover all the safe spots without stepping on a bomb." << std::endl;
	std::cout << "Good luck, and try not to blow yourself up.. no pressure!" << std::endl;
	std::cout << std::endl;
	std::cout << "Type anything to go back to the main menu." << std::endl;
	std::cout << ">";
}

void drawDeathScreen()
{
	std::cout << "BOOM! Congratulations, you're now dust!" << std::endl;
	std::cout << std::endl;
	std::cout << "Type anything to fly back to the main menu.." << std::endl;
	std::cout << "No need to watch your steps anymore!" << std::endl;
	std::cout << ">";
}