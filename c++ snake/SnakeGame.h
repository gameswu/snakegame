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

class SnakeGame 
{
private:
	int blocksize;
	int linesize;
	int width;
	int height;
	int score = 0;
	int foodscore = 1;
	int specialfoodscore;
	int maxscore;
	chrono::time_point<chrono::steady_clock> specialFoodGenerateTime;
	const chrono::seconds specialFoodLifeTime = chrono::seconds(6);
	bool isUseable = false;
	bool isGameOver = false;
	vector<Position> snake;
	vector<StaticObject> sto;
	Position food;
	Position sfood;
	
	bool IsObstacle(Position pos);
	bool IsSnake(Position pos);
	bool IsSpecialFood(Position pos);
	bool IsFood(Position pos);
	void generateFood();
	void generateSpecialFood();
	bool isGenerateSpecialFood = false;
	bool isGenerateFood = true;
	void updateSpecialFoodScore();
	void setIsGenerateSpecialFood(bool is_generate_special_food);
	void setIsGenerateFood(bool is_generate_food);
public:
	SnakeGame(int blocksize, int linesize, int width, int height);
	void draw();
	void snakeMove();
	void setIsGameOver(bool is_game_over);
	bool IsGameOver();
	void setIsUseable(bool is_useable);
	void setAll(int blocksize, int linesize, int width, int height);
};

#endif SNAKEGAME_H