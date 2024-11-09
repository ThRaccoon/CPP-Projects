#include "hangMan.h"

#include <string>
#include <fstream>
#include <random>


HangMan::HangMan()
{
    m_tries = 7;
    m_score = 0;

    m_hiddenWord = "";
    m_visibleWord = "";

    loadWordsFromFile();
    initializeHiddenWord();
    initializeVisibleWord();
}

void HangMan::restart()
{
    m_tries = 7;
    m_score = 0;

    m_hiddenWord.clear();
    m_visibleWord.clear();

    m_correctGuesses.clear();
    m_incorrectGuesses.clear();

    initializeHiddenWord();
    initializeVisibleWord();
}


void HangMan::loadWordsFromFile()
{
    std::ifstream file("randomWords.txt");

    if (!file.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl;
    }

    m_word = "";
    while (std::getline(file, m_word))
    {
        m_words.push_back(m_word);
    }

    file.close();
}

void HangMan::initializeHiddenWord()
{
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(0, m_words.size() - 1);

    m_hiddenWord = m_words[distribution(generator)];
}

void HangMan::initializeVisibleWord()
{
    for (int i = 0; i < m_hiddenWord.size(); i++)
    {
        m_visibleWord += "_";
    }

    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(0, m_visibleWord.size() - 1);

    int randNum = distribution(generator);

    char letter = m_hiddenWord[randNum];

    for (int i = 0; i < m_visibleWord.size(); i++)
    {
        if (letter == m_hiddenWord[i])
        {
            m_visibleWord[i] = letter;
            m_score++;
        }
    }

    m_correctGuesses.push_back(letter);
}


void HangMan::updateVisibleWord(char userInput)
{
    for (int i = 0; i < m_visibleWord.size(); i++)
    {
        if (userInput == m_hiddenWord[i])
        {
            m_visibleWord[i] = userInput;
        }
    }
}


void HangMan::shouldIncrementScore(char userInput)
{
    bool flag = false;
    for (int i = 0; i < m_hiddenWord.size(); i++)
    {
        if (userInput == m_hiddenWord[i])
        {
            flag = true;
            m_score++;
        }
    }

    if (flag)
    {
        m_correctGuesses.push_back(userInput);
    }
}

void HangMan::shouldDecrementTries(char userInput)
{
    bool flag = false;
    for (int i = 0; i < m_hiddenWord.size(); i++)
    {
        if (userInput == m_hiddenWord[i])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        m_incorrectGuesses.push_back(userInput);
        m_tries--;
    }
}


bool HangMan::checkForVictory() const
{
    if (m_score == m_hiddenWord.size())
    {
        return true;
    }
    return false;
}

bool HangMan::checkForDefeat() const
{
    if (m_tries == 0)
    {
        return true;
    }
    return false;
}


std::string HangMan::checkInput(char userInput) const
{
    for (int i = 0; i < m_correctGuesses.size(); i++)
    {
        if (userInput == m_correctGuesses[i])
        {
            return "A brilliant guess... the first time. But I'm not paying for reruns.";
        }
    }

    for (int i = 0; i < m_incorrectGuesses.size(); i++)
    {
        if (userInput == m_incorrectGuesses[i])
        {
            return "Are you expecting this letter to magically become correct? Sadly, it's still incorrect.";
        }
    }

    if (isdigit(userInput))
    {
        return "Numbers? In this game, the only digits that count are the ones on your remaining tries.";
    }

    if (userInput < 65 || userInput > 90)
    {
        return "Ah, symbols. Trying to communicate with the dead, are we?";
    }

    return "101";
}


std::string& HangMan::getHiddenWord()
{
    return m_hiddenWord;
}

std::string& HangMan::getVisibleWord()
{
    return m_visibleWord;
}


void HangMan::drawScreen() const
{
    system("cls");
    if (m_tries <= 6)
    {
        std::cout << "   |   " << std::endl;
    }
    if (m_tries <= 5)
    {
        std::cout << "   O   " << std::endl;
    }
    if (m_tries == 4)
    {
        std::cout << "  /   " << std::endl;
    }
    if (m_tries == 3)
    {
        std::cout << "  /|   " << std::endl;
    }
    if (m_tries <= 2)
    {
        std::cout << "  /|\\   " << std::endl;
    }
    if (m_tries == 1)
    {
        std::cout << "  /   " << std::endl;
    }
    if (m_tries == 0)
    {
        std::cout << "  / \\   " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "TRIES: " << m_tries << std::endl;
}

void HangMan::drawHiddenWord(std::string& word) const
{
    std::cout << std::endl;
    std::cout << "Hidden word:" << std::endl;

    std::cout << " -";
    for (int i = 0; i < word.size(); i++)
    {
        std::cout << "-";
    }
    std::cout << "-" << std::endl;

    std::cout << "| " << word << " |" << std::endl;

    std::cout << " -";
    for (int i = 0; i < word.size(); i++)
    {
        std::cout << "-";
    }
    std::cout << "-" << std::endl;
}

void HangMan::drawIncorrectGuesses() const
{
    std::cout << "Incorrect guesses:" << std::endl;

    if (m_incorrectGuesses.size() > 0)
    {
        std::cout << "|";
        for (int i = 0; i < m_incorrectGuesses.size(); i++)
        {
            std::cout << m_incorrectGuesses[i] << "|";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void HangMan::drawMainMenu() const
{
    system("cls");
    std::cout << "HangMan" << std::endl;
    std::cout << "(1) Play" << std::endl;
    std::cout << "(2) Rules" << std::endl;
    std::cout << "(3) Exit" << std::endl;
    std::cout << ">";
}

void HangMan::drawRules() const
{
    system("cls");
    std::cout << "Welcome to HangMan!" << std::endl;
    std::cout << "The object of the game is simple... guess the word before you run out of tries!" << std::endl;
    std::cout << "Basically, try *not* to hang yourself by guessing wrong." << std::endl;
    std::cout << "You have 7 tries to guess the letters in the word." << std::endl;
    std::cout << "Only the first character you enter will count, and it must be a letter." << std::endl;
    std::cout << "Symbols, numbers, and extra characters are ignored." << std::endl;
    std::cout << "Good luck, and try not to hang yourself!" << std::endl;
    std::cout << std::endl;
    std::cout << "Type anything to go back to the main menu." << std::endl;
    std::cout << ">";
}

void HangMan::drawVictoryScreen() const
{
    std::cout << "Unbelievable... You actually survived the noose!" << std::endl;
    std::cout << std::endl;
    std::cout << "Looks like today isn't your day to meet the creator." << std::endl;
    std::cout << "Type anything to slip back to the main menu, 'survivor'." << std::endl;
    std::cout << ">";
}

void HangMan::drawDefeatScreen() const
{
    std::cout << "SNAP! Congratulations, you just hung!" << std::endl;
    std::cout << std::endl;
    std::cout << "Type anything to descend back to the main menu..." << std::endl;
    std::cout << "No need to keep your head up anymore!" << std::endl;
    std::cout << ">";
}