//#include "stdafx.h"
//#include "pch.h"
#include "TicTacToeLib.h"
#include <stdio.h>
#include <vector>
using namespace std;


int TicTacToeLib::checkWin(int x, int y)
{
	int flag = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == 'T') flag = 1;
		}
	}
	if (flag == 0) return 2;


	if ((map[0][0] == map[0][1] && map[0][1] == map[0][2] && map[0][0] == map[x - 1][y - 1]) ||
		(map[1][0] == map[1][1] && map[1][1] == map[1][2] && map[1][0] == map[x - 1][y - 1]) ||
		(map[2][0] == map[2][1] && map[2][1] == map[2][2] && map[2][0] == map[x - 1][y - 1]) ||
		(map[0][0] == map[1][0] && map[1][0] == map[2][0] && map[0][0] == map[x - 1][y - 1]) ||
		(map[0][1] == map[1][1] && map[1][1] == map[2][1] && map[0][1] == map[x - 1][y - 1]) ||
		(map[0][2] == map[1][2] && map[1][2] == map[2][2] && map[0][2] == map[x - 1][y - 1]) ||
		(map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] == map[x - 1][y - 1]) ||
		(map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][2] == map[x - 1][y - 1]))
		return 1;
	return 0;
}

void TicTacToeLib::Draw()
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n");
		for (int j = 0; j < 3; j++)
		{
			printf(" %c ", map[i][j]);
			mapgame.push_back(map[i][j]);

		}
	}
}

void TicTacToeLib::Gameplay()
{
	printf("This is tic-tac-toe game! Play it your way!\n");

	printf("SELECT YOUR MODE: (1 - PLAY GAME, 2 - REPLAY GAME, OTHER - EXIT) - ");
	scanf("%d", &gamemode);

	if (gamemode == 1)
	{
		save_map = fopen("game.bin", "wb");

		if (!save_map) {
			return;
		}

		printf("Enter player 1 Name: ");
		scanf(" %s", &player1);

		printf("Enter player 2 Name: ");
		scanf(" %s", &player2);

		printf("P1: %s, P2: %s", player1, player2);

		while (playing == 0)
		{
			do
			{
				printf("\n%s's Turn - X: ", player1);
				scanf("%d", &pos);
				x = pos / 10;
				y = pos % 10;
			} while (map[x - 1][y - 1] != 'T');

			map[x - 1][y - 1] = 'X';
			Draw();
			playing = checkWin(x, y);
			if (playing == 1)
			{
				printf("\n%s Win!!!", player1);
				break;
			}
			if (playing == 2)
			{
				printf("\n...DRAW...");
				break;
			}

			do
			{
				printf("\n%s's Turn - O: ", player2);
				scanf("%d", &pos);
				x = pos / 10;
				y = pos % 10;
			} while (map[x - 1][y - 1] != 'T');

			map[x - 1][y - 1] = 'O';
			Draw();
			playing = checkWin(x, y);
			if (playing == 1)
			{
				printf("\n%s Win!!!", player2);
				break;
			}
			if (playing == 2)
			{
				printf("\n...DRAW...");
				break;
			}
		}
		for (int i = 0; i < mapgame.size(); i++)
		{
			fprintf(save_map, "%c", mapgame[i]);
		}

	}

	if (gamemode == 2)
	{
		save_map = fopen("game.bin", "rb");
		char old_map[100];
		fscanf(save_map, "%s", old_map);
		for (int k = 0; k < 100; k++)
		{
			if (old_map[k] == NULL)
				return;
			if (k % 3 == 0)
			{
				printf("\n");
				if (k % 9 == 0)
					printf("\n");
			}
			printf(" %c ", old_map[k]);
		}
		fclose(save_map);
	}

	fclose(save_map);
	return;
}
