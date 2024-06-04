#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Buttons.h"

#define MINBLOCKSIZE 20
#define MINWIDTH 5
#define MINHEIGHT 5

struct Position {
	int x;
	int y;
};

class SnakeGame 
{
private:
	int width;
	int height;
	int blocksize;
	int score = 0;
	int lastscore = -1;
	int maxscore = 0;
	chrono::time_point<chrono::system_clock> LastsfoodPlaceTime;
	chrono::duration<double> sfoodLifeTime = chrono::seconds(6);
	int direction = 0;
	bool is_specialfood_eff = false;
	vector<Position> snake;
	Position food = { -1 , -1 };
	Position specialfood = { -1 , -1 };
	vector<Position> obstacles;
public:;
	  SnakeGame(int width, int height, int blocksize);
	  bool isGameOver = false;
	  double speed = 1;
	  void drawmap();
	  void drawother();
	  void snakemove();
	  void playerinput();
	  void placefood();
	  void placespecialfood();
	  bool isSnake(Position pos);
	  bool isSnakeBody(Position pos);
	  bool isObstacle(Position pos);
	  bool isSpecialFood(Position pos);
	  bool isFood(Position pos);
	  void gameover();
	  void afterEatfood();
	  void setAll(int width, int height, int blocksize);
};

extern SnakeGame defaultsg;

#endif SNAKEGAME_H