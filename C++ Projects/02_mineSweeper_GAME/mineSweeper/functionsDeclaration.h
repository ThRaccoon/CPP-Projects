#pragma once

#include <iostream>
#include <vector>
#include <random>

void initializeField(std::vector<std::vector<char>>& vec, char simbol, int rowSize, int colSize);
 
void armField(std::vector<std::vector<char>>& vec, int minesNum);
 
void updateVisibleField(std::vector<std::vector<char>>& vec, int row, int col);
 
void drawField(const std::vector<std::vector<char>>& vec, int& score);

bool isMineHit(const std::vector<std::vector<char>>& vec, int& score, int row, int col);
 
std::string checkCoordinates(const std::vector<std::vector<char>>& vec, int ROW_SIZE, int COL_SIZE, int row, int col);

void isInt(int& option);
  

//-
void drawMainMenu();

void drawRules();

void drawDeathScreen();