#include "FunctionsDeclarations.h"

struc check(int tries, char guessLetter, std::string guessWord, std::string gameWord)
{
    struc struc1;

    int multy = 0;
    multy = tries;

    if (guessWord.size() < 1)
    {
        for (int i = 0; i < gameWord.size(); i++)
        {
            guessWord += '_';
        }
    }

    for (int i = 0; i < gameWord.size(); i++)
    {
        if (gameWord[i] == guessLetter)
        {
            guessWord[i] = gameWord[i];
            multy++;
        }
    }

    if (tries == multy)
    {
        tries--;
    }

    struc1.f_int = tries;
    struc1.f_str = guessWord;
    return struc1;
}

struc checkFirstAndSecondLine(char guessLetter, char f_from, char f_to, char s_from, char s_to, std::string firstLine, std::string secondLine)
{
    struc struc1;

    if (firstLine.size() < 1 && secondLine.size() < 1)
    {
        for (char i = f_from; i <= f_to; i++)
        {
            firstLine += i;
            firstLine += " ";
        }
        for (char j = s_from; j <= s_to; j++)
        {
            secondLine += j;
            secondLine += " ";
        }
    }

    for (int i = 0; i < firstLine.size(); i++)
    {
        if (guessLetter == firstLine[i])
        {
            firstLine[i] = '_';
        }
    }

    for (int i = 0; i < secondLine.size(); i++)
    {
        if (guessLetter == secondLine[i])
        {
            secondLine[i] = '_';
        }
    }

    struc1.s_str = firstLine;
    struc1.t_str = secondLine;
    return struc1;
}

void makeItCentred(std::string text, bool drawTop, bool drawBottom)
{
    int size = text.size();
    if (drawTop == true)
    {
        std::cout << "+---------------------------+" << std::endl;
        std::cout << "|";
    }
    else
    {
        std::cout << "|";
    }

    bool swapSpaces = true;
    for (int i = 0; i < 27 - size; i++)
    {
        if (swapSpaces)
        {
            text = " " + text;
        }
        else
        {
            text = text + " ";
        }
        swapSpaces = !swapSpaces;
    }
    std::cout << text;

    if (drawBottom == true)
    {
        std::cout << "|" << std::endl;
        std::cout << "+---------------------------+" << std::endl;
    }
    else
    {
        std::cout << "|" << std::endl;
    }
}

void drawHangMan(int tries)
{
    if (tries <= 6)
    {
        std::cout << "|             |             |" << std::endl;
    }
    if (tries <= 5)
    {
        std::cout << "|             O             |" << std::endl;
    }
    if (tries == 4)
    {
        std::cout << "|            /              |" << std::endl;
    }
    if (tries == 3)
    {
        std::cout << "|            /|             |" << std::endl;
    }
    if (tries <= 2)
    {
        std::cout << "|            /|\\            |" << std::endl;
    }
    if (tries == 1)
    {
        std::cout << "|            /              |" << std::endl;
    }
    if (tries == 0)
    {
        std::cout << "|            / \\            |" << std::endl;
    }
}

bool isItWin(std::string guessWord, std::string gameWord)
{
    if (guessWord == gameWord)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void drawBackGround()
{
    std::cout << "+---------------------------+" << std::endl;
    std::cout << "|                           |" << std::endl;
    std::cout << "|    ___________________    |" << std::endl;
    std::cout << "|    |        |        |    |" << std::endl;
    std::cout << "|    |        |        |    |" << std::endl;
    std::cout << "|    |        |        |    |" << std::endl;
    std::cout << "|    |        O        |    |" << std::endl;
    std::cout << "|    |                 |    |" << std::endl;
    std::cout << "|    |                 |    |" << std::endl;
    std::cout << "|    |                 |    |" << std::endl;
    std::cout << "|    |                 |    |" << std::endl;
    std::cout << "|    |     _______     |    |" << std::endl;
    std::cout << "|  __|_____|_____|_____|__  |" << std::endl;
    std::cout << "| |                       | |" << std::endl;
    std::cout << "| |_______________________| |" << std::endl;

}

char pickLetter(std::string gameWord)
{
    int size = gameWord.size();
    char guessLetter = '_';

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, size - 1);
    int rand = dist(rd);

    guessLetter = gameWord[rand];

    return guessLetter;
}

std::string chooseGameMode()
{
    std::string gameMode;
    makeItCentred("Choose your gamemode!", 1, 1);
    makeItCentred("1.|Animals| 2.|Fruits|", 0, 0);
    makeItCentred("3.|Colors| 4.|Materials|", 0, 0);
    makeItCentred("To pick a gamemode you have", 1, 0);
    makeItCentred("to write the name of the", 0, 0);
    makeItCentred("gamemode exactly the same!", 0, 1);
    std::cout << ">";
    std::cin >> gameMode;

    while (gameMode != "Animals" && gameMode != "Fruits" && gameMode != "Colors" && gameMode != "Materials")
    {
        system("cls");
        std::cout << "To pick a mode you have to write the name of the mode exactly the same!" << std::endl;
        std::cout << "You can pick one of this modes: Animals, Fruits, Colors, Materials" << std::endl;
        std::cout << ">";
        std::cin >> gameMode;
    }
    return gameMode;
}

std::string read(std::string gamemode)
{
    std::string text2;
    std::string text1;
    std::vector<std::string> v;

    std::fstream myFile;
    myFile.open(gamemode + ".txt", std::ios::in);
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            myFile >> text1;
            v.push_back(text1);
        }
        myFile.close();
    }
    else
    {
        std::cout << "File did not open" << std::endl;
    }

    int size = v.size();
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, size - 1);
    int rand = dist(rd);

    text2 = v.at(rand);
    return text2;
}

void isItInt(int op)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cin >> op;
    }
}