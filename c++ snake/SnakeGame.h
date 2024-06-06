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
	int lastscore = -1;  //生成特殊食物时的分数
	int maxscore = 0;
	chrono::time_point<chrono::system_clock> LastsfoodPlaceTime;  //生成特殊食物的时间点
	chrono::duration<double> sfoodLifeTime = chrono::seconds(6);  //特殊食物的持续时间
	int direction = 0;
	bool is_specialfood_eff = false;  //特殊食物是否有效
	vector<Position> snake;
	Position food = { -1 , -1 };
	Position specialfood = { -1 , -1 };
	vector<Position> obstacles;
public:;
	  SnakeGame(int width, int height, int blocksize);
	  bool isGameOver = false;  //游戏是否结束
	  double speed = 1;
	  double difficulty = 1;
	  int Useabletimes = 0;  //玩家改变方向次数
	  void drawmap();  //绘制地图
	  void drawother();  //绘制其他
	  void snakemove();  //蛇移动
	  void playerinput();  //玩家输入
	  void placefood();  //生成食物
	  void initialsnake();  //初始化蛇
	  void placespecialfood();  //生成特殊食物
	  bool isSnake(Position pos);  //判断是否为蛇
	  bool isSnakeBody(Position pos);  //判断是否为蛇身
	  bool isObstacle(Position pos);  //判断是否为障碍物
	  bool isSpecialFood(Position pos);  //判断是否为特殊食物
	  bool isFood(Position pos);  //判断是否为食物
	  void gameover();  //游戏结束后的操作
	  void afterEatfood();  //吃食物后的操作
	  void setAll(int width, int height, int blocksize);  //设置所有参数
	  void savescore(string mark);  //保存分数
	  void loadscore(string mark);  //读取分数
};

class RandomSnakeGame : public SnakeGame
{
public:
	RandomSnakeGame(int width, int height, int blocksize);
	void placeobstacle();  //生成障碍物
};

class GravitySnakeGame : public SnakeGame
{
private:
	chrono::time_point<chrono::system_clock> LastobstacleMoveTime;  //障碍物移动的时间点
	chrono::duration<double> obstacleMoveTime = chrono::seconds(1);
public:
	GravitySnakeGame(int width, int height, int blocksize);
	void setmovetime();  //设置障碍物移动时间
	void placeobstacle();  //生成障碍物
	void obstaclemove();  //障碍物移动
};

class EditSnakeGame : public SnakeGame
{
public:
	EditSnakeGame(int width, int height, int blocksize);
	void setonlymap();  //设置只有地图
	void placeobstacle();  //放置障碍物
	void drawobstacle();  //绘制障碍物
	void savemap(string filename);  //保存地图
};

class MapSnakeGame : public SnakeGame
{
public:
	MapSnakeGame(int width, int height, int blocksize);
	void loadmap(string filename);
};

extern SnakeGame defaultsg;
extern RandomSnakeGame randomsg;
extern GravitySnakeGame gravitysg;
extern EditSnakeGame editsg;
extern MapSnakeGame mapsg;

#endif SNAKEGAME_H