#pragma once

#include <iostream>
#include <vector>

class HangMan
{
public:
	HangMan();

	void restart();

	void initializeHiddenWord();
	void initializeVisibleWord();

	void updateVisibleWord(char userInput);

	void shouldIncrementScore(char userInput);
	void shouldDecrementTries(char userInput);

	bool checkForVictory() const;
	bool checkForDefeat() const;

	std::string checkInput(char userInput) const;

	std::string& getHiddenWord();
	std::string& getVisibleWord();

	void drawScreen() const;
	void drawHiddenWord(std::string& word) const;
	void drawIncorrectGuesses() const;
	void drawMainMenu() const;
	void drawRules() const;
	void drawVictoryScreen() const;
	void drawDefeatScreen() const;


private:	
	int m_tries;
	int m_score;

	std::string m_hiddenWord;
	std::string m_visibleWord;

	std::vector<char> m_correctGuesses;
	std::vector<char> m_incorrectGuesses;
};

