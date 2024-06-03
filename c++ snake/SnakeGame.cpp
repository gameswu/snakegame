#include "SnakeGame.h"

bool SnakeGame::IsObstacle(const Position pos)
{
	if (food.x == pos.x && food.y == pos.y)
	{
		return true;
	}
	return false;
}

bool SnakeGame::IsSnake(const Position pos)
{
	for (const auto& segment : snake)
	{
		if (segment.x == pos.x && segment.y == pos.y)
		{
			return true;
		}
	}
	return false;
}

bool SnakeGame::IsSpecialFood(const Position pos)
{
	if (sfood.x == pos.x && sfood.y == pos.y)
	{
		return true;
	}
	return false;
}

bool SnakeGame::IsFood(const Position pos)
{
	if (food.x == pos.x && food.y == pos.y)
	{
		return true;
	}
	return false;
}

void SnakeGame::setIsGenerateFood(bool is_generate_food)
{
	this -> isGenerateFood = is_generate_food;
}

void SnakeGame::setIsGenerateSpecialFood(bool is_generate_special_food)
{
	this->isGenerateSpecialFood = is_generate_special_food;
}

void SnakeGame::generateFood()
{
	//设置随机数种子
	if (isGenerateFood)
	{
		srand((unsigned)time(NULL));
		//生成随机坐标
		do
		{
			food.x = rand() % width + 1;
			food.y = rand() % height + 1;
		} while (IsObstacle(food) || IsSnake(food) || IsSpecialFood(food));
		setIsGenerateFood(false);
	}
}

void SnakeGame::generateSpecialFood()
{
	if (isGenerateSpecialFood)
	{
		//设置随机数种子
		srand((unsigned)time(NULL));
		//生成随机坐标
		do
		{
			sfood.x = rand() % width + 1;
			sfood.y = rand() % height + 1;
			specialFoodGenerateTime = chrono::steady_clock::now();
		} while (IsObstacle(sfood) || IsSnake(sfood) || IsFood(sfood));
		setIsGenerateSpecialFood(false);
		updateSpecialFoodScore();
	}
}

void SnakeGame::updateSpecialFoodScore()
{
	//设置specialfoodscore，使其随时间变化，为剩余lifetime的3倍
	specialfoodscore = (specialFoodLifeTime - chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - specialFoodGenerateTime)).count() * 3;
	//降为0时保持为0
	if (specialfoodscore < 0)
	{
		specialfoodscore = 0;
	}
}

void SnakeGame::snakeMove()
{
	//实现贪吃蛇小游戏，获取键盘输入，控制蛇的移动
	//获取键盘输入
	if (_kbhit())
	{
		//获取键盘输入
		char input = _getch();
		//判断键盘输入
		switch (input)
		{
		case 'w':
			//判断是否向下移动
			if (snake[0].y == snake[1].y + 1)
			{
				break;
			}
			//向上移动
			snake.insert(snake.begin(), { snake[0].x, (snake[0].y - 1) % height + 1});
			break;
		case 's':
			//判断是否向上移动
			if (snake[0].y == snake[1].y - 1)
			{
				break;
			}
			//向下移动
			snake.insert(snake.begin(), { snake[0].x, (snake[0].y + 1) % height + 1});
			break;
		case 'a':
			//判断是否向右移动
			if (snake[0].x == snake[1].x + 1)
			{
				break;
			}
			//向左移动
			snake.insert(snake.begin(), { (snake[0].x - 1) % width + 1, snake[0].y });
			break;
		case 'd':
			//判断是否向左移动
			if (snake[0].x == snake[1].x - 1)
			{
				break;
			}
			//向右移动
			snake.insert(snake.begin(), { (snake[0].x + 1) % width + 1, snake[0].y });
			break;
		}
		//判断是否吃到食物
		if (IsFood(snake[0]))
		{
			//生成新的食物
			generateFood();
			//增加分数
			score += foodscore;
			//设置生成食物
			setIsGenerateFood(true);
		}
		else
		{
			//删除尾部
			snake.pop_back();
		}
		//判断是否吃到特殊食物
		if (IsSpecialFood(snake[0]))
		{
			//当此时分数为7的倍数（0除外时）生成新的特殊食物
			if (score % 7 == 0 && score != 0)
			{
				setIsGenerateSpecialFood(true);
				generateSpecialFood();
			}
		}
	}
}