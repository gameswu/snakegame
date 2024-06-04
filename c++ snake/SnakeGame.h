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
protected:
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
	  double difficulty = 1;
	  int Useabletimes = 0;
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
	  void setspeed(double speed);
	  void setdifficulty(double difficulty);
	  void gameover();
	  void afterEatfood();
	  void setAll(int width, int height, int blocksize, double speed, double difficulty);
};

class RandomSnakeGame : public SnakeGame
{
public:
	RandomSnakeGame(int width, int height, int blocksize);
	void placeobstacle();
};

class GravitySnakeGame : public SnakeGame
{
private:
	chrono::time_point<chrono::system_clock> LastobstacleMoveTime;
	chrono::duration<double> obstacleMoveTime = chrono::seconds(5);
public:
	GravitySnakeGame(int width, int height, int blocksize);
	void setmovetime();
	void placeobstacle();
	void obstaclemove();
};

extern SnakeGame defaultsg;
extern RandomSnakeGame randomsg;
extern GravitySnakeGame gravitysg;

#endif SNAKEGAME_H