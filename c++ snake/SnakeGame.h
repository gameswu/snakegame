#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Buttons.h"
#include <chrono>
#include <vector>

#define MINBLOCKSIZE 20
#define MINLINESIZE 2

struct Position {
	int x;
	int y;
};

struct StaticObject {
	Position pos;
	char type = 'S';
};

struct DynamicObject {
	Position initialpos;
	char type = 'D';
	vector<Position> path;
	bool isDisappeared = false;
};

struct NormalFood {
	Position pos;
	int score = 1;
	bool isDisappeared = false;
};

struct SpecialFood {
	Position pos;
	int score;
	bool isDisappeared = false;
};

class SnakeGame 
{
private:
	int blocksize;
	int linesize;
	int width;
	int height;
	int score = 0;
	int maxscore;
	bool isUseable = false;
	bool isGameOver = false;
	vector<Position> snake;
	vector<StaticObject> sto;
	NormalFood food;
	SpecialFood sfood;
public:
	SnakeGame(int blocksize, int linesize, int width, int height);
	void draw();
	void generateFood(NormalFood& food);
	void generateSpecialFood();
	void updateSpecialFoodScore();
	void snakeMove();
	void setIsGameOver(bool is_game_over);
	bool IsGameOver();
	void setIsUseable(bool is_useable);
	void setAll(int blocksize, int linesize, int width, int height);
};

#endif SNAKEGAME_H