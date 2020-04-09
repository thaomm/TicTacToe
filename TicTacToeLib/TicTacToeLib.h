#pragma once
#include <stdio.h>
#include <vector>

class TicTacToeLib
{
public:
	char map[3][3] = { { 'T','T','T' }, { 'T','T','T' }, { 'T','T','T' } };
	std::vector <char> mapgame;
	FILE* save_map;
	int gamemode;
	char player1[10];
	char player2[10];
	int playing = 0;
	int pos;
	int x, y;

	int checkWin(int x, int y);
	void Draw();
	void Gameplay();
};

