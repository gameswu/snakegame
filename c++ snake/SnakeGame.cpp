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
	//�������������
	if (isGenerateFood)
	{
		srand((unsigned)time(NULL));
		//�����������
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
		//�������������
		srand((unsigned)time(NULL));
		//�����������
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
	//����specialfoodscore��ʹ����ʱ��仯��Ϊʣ��lifetime��3��
	specialfoodscore = (specialFoodLifeTime - chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - specialFoodGenerateTime)).count() * 3;
	//��Ϊ0ʱ����Ϊ0
	if (specialfoodscore < 0)
	{
		specialfoodscore = 0;
	}
}

void SnakeGame::snakeMove()
{
	//ʵ��̰����С��Ϸ����ȡ�������룬�����ߵ��ƶ�
	//��ȡ��������
	if (_kbhit())
	{
		//��ȡ��������
		char input = _getch();
		//�жϼ�������
		switch (input)
		{
		case 'w':
			//�ж��Ƿ������ƶ�
			if (snake[0].y == snake[1].y + 1)
			{
				break;
			}
			//�����ƶ�
			snake.insert(snake.begin(), { snake[0].x, (snake[0].y - 1) % height + 1});
			break;
		case 's':
			//�ж��Ƿ������ƶ�
			if (snake[0].y == snake[1].y - 1)
			{
				break;
			}
			//�����ƶ�
			snake.insert(snake.begin(), { snake[0].x, (snake[0].y + 1) % height + 1});
			break;
		case 'a':
			//�ж��Ƿ������ƶ�
			if (snake[0].x == snake[1].x + 1)
			{
				break;
			}
			//�����ƶ�
			snake.insert(snake.begin(), { (snake[0].x - 1) % width + 1, snake[0].y });
			break;
		case 'd':
			//�ж��Ƿ������ƶ�
			if (snake[0].x == snake[1].x - 1)
			{
				break;
			}
			//�����ƶ�
			snake.insert(snake.begin(), { (snake[0].x + 1) % width + 1, snake[0].y });
			break;
		}
		//�ж��Ƿ�Ե�ʳ��
		if (IsFood(snake[0]))
		{
			//�����µ�ʳ��
			generateFood();
			//���ӷ���
			score += foodscore;
			//��������ʳ��
			setIsGenerateFood(true);
		}
		else
		{
			//ɾ��β��
			snake.pop_back();
		}
		//�ж��Ƿ�Ե�����ʳ��
		if (IsSpecialFood(snake[0]))
		{
			//����ʱ����Ϊ7�ı�����0����ʱ�������µ�����ʳ��
			if (score % 7 == 0 && score != 0)
			{
				setIsGenerateSpecialFood(true);
				generateSpecialFood();
			}
		}
	}
}