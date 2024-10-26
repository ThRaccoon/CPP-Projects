#include "mineSweeper.h"

#include <random>


MineSweeper::MineSweeper()
{
	m_rowSize = 10;
	m_colSize = 10;
	m_minesCount = 10;

	m_score = 0;
	m_tries = 0;
	m_triesProgression = 0;

	initializeField(m_hiddenField, '0');
	initializeField(m_visibleField, '#');
	initializeMines(m_hiddenField);
}

void MineSweeper::restart()
{
	m_rowSize = 10;
	m_colSize = 10;
	m_minesCount = 10;

	m_score = 0;
	m_tries = 0;
	m_triesProgression = 0;

	m_hiddenField.clear();
	m_visibleField.clear();

	initializeField(m_hiddenField, '0');
	initializeField(m_visibleField, '#');
	initializeMines(m_hiddenField);
}


void MineSweeper::initializeField(std::vector<std::vector<char>>& vec, char simbol)
{
	for (int i = 0; i < m_rowSize; i++)
	{
		std::vector<char> temp(m_colSize, simbol);
		vec.push_back(temp);
	}
}

void MineSweeper::initializeMines(std::vector<std::vector<char>>& vec)
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(0, 9);

	int m_randRow = 0;
	int m_randCol = 0;

	for (int i = 0; i < m_minesCount; i++)
	{
		while (true)
		{
			m_randRow = distribution(generator);
			m_randCol = distribution(generator);

			if (vec[m_randRow][m_randCol] != '1')
			{
				vec[m_randRow][m_randCol] = '1';
				break;
			}
		}
	}
}


void MineSweeper::updateHiddenField(int row, int col)
{
	if (m_hiddenField[row][col] == '1')
	{
		m_hiddenField[row][col] = 'X';
	}
}

void MineSweeper::updateVisibleField(int row, int col)
{
	m_visibleField[row][col] = m_hiddenField[row][col];
}


void MineSweeper::incrementScore()
{
	m_score++;
}

void MineSweeper::incrementTriesProgression()
{
	m_triesProgression++;
}

void MineSweeper::shouldAddTry()
{
	if (m_triesProgression == 10)
	{
		m_tries++;
		m_triesProgression = 0;
	}
}

void MineSweeper::shouldRemoveTry(int row, int col)
{
	if (m_hiddenField[row][col] == '1')
	{
		m_tries--;
	}
}


bool MineSweeper::checkForVictory() const
{
	if (m_score == 90)
	{
		return true;
	}
	return false;
}

bool MineSweeper::checkForDefeat(int row, int col) const
{
	if (m_hiddenField[row][col] == '1' && m_tries <= 0)
	{
		return true;
	}
	return false;
}


std::string MineSweeper::checkInput(int row, int col) const
{
	if (row > m_rowSize)
	{
		return "Whoa! You're sweeping way past the minefield! You lost?";
	}
	if (row < 0)
	{
		return "Oops! You're sweeping before the minefield! Careful to not get lost!";
	}
	if (col > m_colSize)
	{
		return "Whoa! You're sweeping way to the right! Are you trying to find Narnia?";
	}
	if (col < 0)
	{
		return "Oops! You're sweeping too far to the left! Are you searching for your lost sanity?";
	}

	if (m_visibleField[row][col] == '0')
	{
		return "Uh-oh! You've swept this spot again! Are you practicing your sweeping skills safely?";
	}
	if (m_visibleField[row][col] == '1')
	{
		return "Sorry, but that mine's already been disturbed. Try your luck somewhere else!";
	}

	return "101";
}


const std::vector<std::vector<char>>& MineSweeper::getHiddenField()
{
	return m_hiddenField;
}

const std::vector<std::vector<char>>& MineSweeper::getVisibleField()
{
	return m_visibleField;
}


void MineSweeper::drawScreen(const std::vector<std::vector<char>>& vec) const
{
	system("cls");
	std::cout << "   ";
	for (int i = 0; i < m_colSize; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "   ";
	for (int i = 0; i < m_colSize; i++)
	{
		std::cout << "- ";
	}
	std::cout << std::endl;

	for (int i = 0; i < m_rowSize; i++)
	{
		std::cout << i << "| ";
		for (int j = 0; j < m_colSize; j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}

	std::cout << "   ";
	for (int i = 0; i < m_colSize; i++)
	{
		std::cout << "- ";
	}
	std::cout << std::endl;

	std::cout << "SCORE: " << m_score << " | BONUS TRIES: " << m_tries << std::endl;
}

void MineSweeper::drawMainMenu() const
{
	system("cls");
	std::cout << "MineSweeper" << std::endl;
	std::cout << "(1) Play" << std::endl;
	std::cout << "(2) Rules" << std::endl;
	std::cout << "(3) Exit" << std::endl;
	std::cout << ">";
}

void MineSweeper::drawRules() const
{
	system("cls");
	std::cout << "Welcome to Minesweeper!" << std::endl;
	std::cout << "The object of the game is simple... survive by sweeping the minefield!" << std::endl;
	std::cout << "Basically, try *not* to become dust by triggering a hidden mine." << std::endl;
	std::cout << "The game board is a 10x10 grid (100 spots total), and 10 of those spots hide mines." << std::endl;
	std::cout << "To sweep a spot, enter the row and column numbers (between 1 and 10)." << std::endl;
	std::cout << "Your goal is to uncover all the safe spots without stepping on a mine." << std::endl;
	std::cout << "Every 10 points you score, you'll earn one bonus try to help you survive longer." << std::endl;
	std::cout << "Good luck, and try not to blow yourself up... no pressure!" << std::endl;
	std::cout << std::endl;
	std::cout << "Type anything to go back to the main menu." << std::endl;
	std::cout << ">";
}

void MineSweeper::drawVictoryScreen() const
{
	std::cout << "Unbelievable... You actually made it out alive!" << std::endl;
	std::cout << std::endl;
	std::cout << "Guess today's not your day to become dust. Enjoy the victory... while it lasts." << std::endl;
	std::cout << "Type anything to crawl back to the main menu, 'survivor'." << std::endl;
	std::cout << ">";
}

void MineSweeper::drawDefeatScreen() const
{
	std::cout << "BOOM! Congratulations, you're now dust!" << std::endl;
	std::cout << std::endl;
	std::cout << "Type anything to fly back to the main menu..." << std::endl;
	std::cout << "No need to watch your steps anymore!" << std::endl;
	std::cout << ">";
}