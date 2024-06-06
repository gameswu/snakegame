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
	int lastscore = -1;  //��������ʳ��ʱ�ķ���
	int maxscore = 0;
	chrono::time_point<chrono::system_clock> LastsfoodPlaceTime;  //��������ʳ���ʱ���
	chrono::duration<double> sfoodLifeTime = chrono::seconds(6);  //����ʳ��ĳ���ʱ��
	int direction = 0;
	bool is_specialfood_eff = false;  //����ʳ���Ƿ���Ч
	vector<Position> snake;
	Position food = { -1 , -1 };
	Position specialfood = { -1 , -1 };
	vector<Position> obstacles;
public:;
	  SnakeGame(int width, int height, int blocksize);
	  bool isGameOver = false;  //��Ϸ�Ƿ����
	  double speed = 1;
	  double difficulty = 1;
	  int Useabletimes = 0;  //��Ҹı䷽�����
	  void drawmap();  //���Ƶ�ͼ
	  void drawother();  //��������
	  void snakemove();  //���ƶ�
	  void playerinput();  //�������
	  void placefood();  //����ʳ��
	  void initialsnake();  //��ʼ����
	  void placespecialfood();  //��������ʳ��
	  bool isSnake(Position pos);  //�ж��Ƿ�Ϊ��
	  bool isSnakeBody(Position pos);  //�ж��Ƿ�Ϊ����
	  bool isObstacle(Position pos);  //�ж��Ƿ�Ϊ�ϰ���
	  bool isSpecialFood(Position pos);  //�ж��Ƿ�Ϊ����ʳ��
	  bool isFood(Position pos);  //�ж��Ƿ�Ϊʳ��
	  void gameover();  //��Ϸ������Ĳ���
	  void afterEatfood();  //��ʳ���Ĳ���
	  void setAll(int width, int height, int blocksize);  //�������в���
	  void savescore(string mark);  //�������
	  void loadscore(string mark);  //��ȡ����
};

class RandomSnakeGame : public SnakeGame
{
public:
	RandomSnakeGame(int width, int height, int blocksize);
	void placeobstacle();  //�����ϰ���
};

class GravitySnakeGame : public SnakeGame
{
private:
	chrono::time_point<chrono::system_clock> LastobstacleMoveTime;  //�ϰ����ƶ���ʱ���
	chrono::duration<double> obstacleMoveTime = chrono::seconds(1);
public:
	GravitySnakeGame(int width, int height, int blocksize);
	void setmovetime();  //�����ϰ����ƶ�ʱ��
	void placeobstacle();  //�����ϰ���
	void obstaclemove();  //�ϰ����ƶ�
};

class EditSnakeGame : public SnakeGame
{
public:
	EditSnakeGame(int width, int height, int blocksize);
	void setonlymap();  //����ֻ�е�ͼ
	void placeobstacle();  //�����ϰ���
	void drawobstacle();  //�����ϰ���
	void savemap(string filename);  //�����ͼ
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