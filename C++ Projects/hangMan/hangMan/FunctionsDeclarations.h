#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream> 

struct struc
{
    int f_int;
    std::string f_str;
    std::string s_str;
    std::string t_str;
};

struc check(int tries, char guessLetter, std::string guessWord, std::string gameWord);

struc checkFirstAndSecondLine(char guessLetter, char f_from, char f_to, char s_from,
                    char s_to, std::string firstLine, std::string secondLine);

bool isItWin(std::string guessWord, std::string gameWord);

void drawHangMan(int tries);

void makeItCentred(std::string text, bool drawTop, bool drawBottom);

void drawBackGround();

char pickLetter(std::string gameWord);

std::string chooseGameMode();

std::string read(std::string);

void isItInt(int op);