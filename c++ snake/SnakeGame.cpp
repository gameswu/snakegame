#include "SnakeGame.h"

SnakeGame defaultsg(20, 20, 20);

SnakeGame::SnakeGame(int width, int height, int blocksize)
{
	this->width = width;
	this->height = height;
	this->blocksize = blocksize;
	snake.push_back({ width / 2, height / 2 });
}

void SnakeGame::setAll(int width, int height, int blocksize)
{
	//设置游戏参数
	this->width = blocksize * width > MAX_WIDTH ? MAX_WIDTH / (MINBLOCKSIZE + 1) : max(width, MINWIDTH);
	this->height = blocksize * height > MAX_HEIGHT ? MAX_HEIGHT / (MINBLOCKSIZE + 1) : max(height, MINHEIGHT);
	if (width * blocksize > MAX_WIDTH || height * blocksize > MAX_HEIGHT)
	{
		this->blocksize = MINBLOCKSIZE;
	}
	else
	{
		this->blocksize = max(blocksize, MINBLOCKSIZE);
	}
	score = 0;
	maxscore = 0;
	lastscore = -1;
	direction = 0;
	snake.clear();
	snake.push_back({ width / 2, height / 2 });
	food = { -1,-1 };
	specialfood = { -1,-1 };
	isGameOver = false;
	LastsfoodPlaceTime = chrono::system_clock::now();
	placefood();
	placespecialfood();
}

void SnakeGame::drawmap()
{
	//绘制分割线
	setcolor(WHITE);
	for (int i = 0; i <= width; i++)
	{
		line(i * (blocksize + 1), 0, i * (blocksize + 1), height * (blocksize + 1));
	}
	for (int i = 0; i <= height; i++)
	{
		line(0, i * (blocksize + 1), width * (blocksize + 1), i * (blocksize + 1));
	}
}

void SnakeGame::drawother()
{
	//绘制蛇头为蓝色圆形，蛇身为蓝色方块
	setfillcolor(BLUE);
	fillcircle(snake[0].x * (blocksize + 1) + blocksize / 2, snake[0].y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	for (int i = 1; i < snake.size(); i++)
	{
		solidrectangle(snake[i].x * (blocksize + 1), snake[i].y * (blocksize + 1), (snake[i].x + 1) * (blocksize + 1), (snake[i].y + 1) * (blocksize + 1));
	}
	//绘制特殊食物为红色圆形
	setfillcolor(RED);
	fillcircle(specialfood.x * (blocksize + 1) + blocksize / 2, specialfood.y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	//绘制食物为绿色圆形
	setfillcolor(GREEN);
	fillcircle(food.x * (blocksize + 1) + blocksize / 2, food.y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	//绘制障碍物为棕色方块
	setfillcolor(BROWN);
	for (int i = 0; i < obstacles.size(); i++)
	{
		solidrectangle(obstacles[i].x * (blocksize + 1), obstacles[i].y * (blocksize + 1), (obstacles[i].x + 1) * (blocksize + 1), (obstacles[i].y + 1) * (blocksize + 1));
	}
	//绘制分数，最高分，文字颜色为白色，字体大小为buttongap1/2，显示在屏幕正右侧
	settextcolor(WHITE);
	settextstyle(buttongap1 / 2, 0, _T("宋体"));
	string scorestr = "Score: " + to_string(score);
	outtextxy(width * (blocksize + 1) + buttongap1 / 2, buttongap1 / 2, scorestr.c_str());
	string maxscorestr = "Max Score: " + to_string(maxscore);
	outtextxy(width * (blocksize + 1) + buttongap1 / 2, 5 * buttongap / 2, maxscorestr.c_str());
}

void SnakeGame::snakemove() {
	//蛇移动，循环边界条件
	Position head = snake[0];
	playerinput();
	switch (direction)
	{
	case 0://上
		head.y = head.y > 0 ? head.y - 1 : height - 1;
		break;
	case 1://右
		head.x = head.x < width - 1 ? head.x + 1 : 0;
		break;
	case 2://下
		head.y = head.y < height - 1 ? head.y + 1 : 0;
		break;
	case 3://左
		head.x = head.x > 0 ? head.x - 1 : width - 1;
		break;
	}
	snake.insert(snake.begin(), head);
	if (!isFood(snake[0])) {
		snake.pop_back();
	}
}

void SnakeGame::playerinput()
{
	//玩家输入，w上，d右，s下，a左
	if (_kbhit())
	{
		char ch = _getch();
		switch (ch)
		{
		case 'w':
		case 'W':
			if (direction == 2)
			{
				break;
			}
			direction = 0;
			break;
		case 'd':
		case 'D':
			if (direction == 3)
			{
				break;
			}
			direction = 1;
			break;
		case 's':
		case 'S':
			if (direction == 0)
			{
				break;
			}
			direction = 2;
			break;
		case 'a':
		case 'A':
			if (direction == 1)
			{
				break;
			}
			direction = 3;
			break;
		}
	}
}

bool SnakeGame::isFood(Position pos)
{
	return pos.x == food.x && pos.y == food.y;
}

bool SnakeGame::isSpecialFood(Position pos)
{
	return pos.x == specialfood.x && pos.y == specialfood.y;
}

bool SnakeGame::isObstacle(Position pos)
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		if (pos.x == obstacles[i].x && pos.y == obstacles[i].y)
		{
			return true;
			break;
		}
	}
	return false;
}

bool SnakeGame::isSnake(Position pos)
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (pos.x == snake[i].x && pos.y == snake[i].y)
		{
			return true;
			break;
		}
	}
	return false;
}

bool SnakeGame::isSnakeBody(Position pos)
{
	for (int i = 1; i < snake.size(); i++)
	{
		if (pos.x == snake[i].x && pos.y == snake[i].y)
		{
			return true;
			break;
		}
	}
	return false;
}

void SnakeGame::placefood()
{
	//设置随机种子
	srand((unsigned)time(NULL));
	//随机生成食物位置，不能与蛇身、障碍物，特殊食物重合
	do
	{
		food.x = rand() % width;
		food.y = rand() % height;
	} while (isSnake(food) || isObstacle(food) || isSpecialFood(food));
}

void SnakeGame::placespecialfood()
{
	//当上一个特殊食物被吃掉或者超过时间限制，分数为7的倍数（不包括0），随机生成特殊食物位置，不能与蛇身、障碍物、食物重合
	if (score % 7 == 0 && score != 0 && lastscore != score && !is_specialfood_eff)
	{
		srand((unsigned)time(NULL));
		do
		{
			specialfood.x = rand() % width;
			specialfood.y = rand() % height;
		} while (isSnake(specialfood) || isObstacle(specialfood) || isFood(specialfood));
		LastsfoodPlaceTime = chrono::system_clock::now();
		is_specialfood_eff = true;
	}
}

void SnakeGame::gameover()
{
	//游戏结束，蛇头碰到蛇身,障碍物
	if (isSnakeBody(snake[0]) || isObstacle(snake[0]))
	{
		isGameOver = true;
		if (score > maxscore)
		{
			maxscore = score;
		}
	}
}

void SnakeGame::afterEatfood()
{
	//吃到食物，蛇身增长，分数增加，食物重置
	if (isFood(snake[0]))
	{
		score++;
		snake.push_back(snake[snake.size() - 1]);
		snake.pop_back();
		placefood();
	}
	//吃到特殊食物，分数增加，食物重置
	if (isSpecialFood(snake[0]) && is_specialfood_eff == true)
	{
		//分数增加值为特殊食物Lifetime-存在时间的秒数的3倍
		score += chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - LastsfoodPlaceTime).count() * 3;
		lastscore = score;
		is_specialfood_eff = false;
		specialfood = { -1,-1 };
	}
	if (is_specialfood_eff && chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - LastsfoodPlaceTime) > sfoodLifeTime)
	{
		is_specialfood_eff = false;
		specialfood = { -1,-1 };
	}
}