#pragma once

#include <iostream>
#include <vector>


class MineSweeper
{
public:
	MineSweeper();

	void restart();

	void initializeField(std::vector<std::vector<char>>& vec, char simbol);
	void initializeMines(std::vector<std::vector<char>>& vec);

	void updateHiddenField(int row, int col);
	void updateVisibleField(int row, int col);

	void incrementScore();
	void incrementTriesProgression();
	void shouldAddTry();
	void shouldRemoveTry(int row, int col);

	bool checkForVictory() const;
	bool checkForDefeat(int row, int col) const;

	std::string checkInput(int row, int col) const;

	const std::vector<std::vector<char>>& getHiddenField();
	const std::vector<std::vector<char>>& getVisibleField();

	void drawScreen(const std::vector<std::vector<char>>& vec) const;
	void drawMainMenu() const;
	void drawRules() const;
	void drawVictoryScreen() const;
	void drawDefeatScreen() const;


private:
	int m_rowSize;
	int m_colSize;
	int m_minesCount;

	int m_score;
	int m_tries;
	int m_triesProgression;

	std::vector<std::vector<char>> m_hiddenField;
	std::vector<std::vector<char>> m_visibleField;
};


