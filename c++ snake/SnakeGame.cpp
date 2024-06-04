#include "SnakeGame.h"

SnakeGame defaultsg(20, 20, 20);
RandomSnakeGame randomsg(20, 20, 20);
GravitySnakeGame gravitysg(20, 20, 20);
EditSnakeGame editsg(20, 20, 20);
MapSnakeGame mapsg(20, 20, 20);

SnakeGame::SnakeGame(int width, int height, int blocksize)
{
	this->width = width;
	this->height = height;
	this->blocksize = blocksize;
	snake.push_back({ width / 2, height / 2 });
}

RandomSnakeGame::RandomSnakeGame(int width, int height, int blocksize) : SnakeGame(width, height, blocksize)
{
	placeobstacle();
}

GravitySnakeGame::GravitySnakeGame(int width, int height, int blocksize) : SnakeGame(width, height, blocksize)
{
	placeobstacle();
}

EditSnakeGame::EditSnakeGame(int width, int height, int blocksize) : SnakeGame(width, height, blocksize)
{
	setonlymap();
}

MapSnakeGame::MapSnakeGame(int width, int height, int blocksize) : SnakeGame(width, height, blocksize)
{
}

void SnakeGame::setAll(int width, int height, int blocksize)
{
	//������Ϸ����
	if (width * blocksize > MAX_WIDTH || height * blocksize > MAX_HEIGHT)
	{
		this->blocksize = MINBLOCKSIZE;
	}
	else
	{
		this->blocksize = max(blocksize, MINBLOCKSIZE);
	}
	if (width * blocksize > MAX_WIDTH)
	{
		this->width = max(min(MAX_WIDTH / MINBLOCKSIZE, width),MINWIDTH);
	}
	else
	{
		this->width = max(width, MINWIDTH);
	}
	if (height * blocksize > MAX_HEIGHT)
	{
		this->height = max(min(MAX_HEIGHT / MINBLOCKSIZE, width),MINWIDTH);
	}
	else
	{
		this->height = max(height, MINHEIGHT);
	}
	score = 0;
	maxscore = 0;
	lastscore = -1;
	direction = 0;
	is_specialfood_eff = false;
	Useabletimes = 0;
	snake.clear();
	snake.push_back({ width / 2, height / 2 });
	food = { -1,-1 };
	specialfood = { -1,-1 };
	isGameOver = false;
	LastsfoodPlaceTime = chrono::system_clock::now();
	speed = stod(speedstr);
	difficulty = stod(difficultystr);
	placefood();
	placespecialfood();
}

void SnakeGame::drawmap()
{
	//���Ʒָ���
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
	//������ͷΪ��ɫԲ�Σ�����Ϊ��ɫ����
	setfillcolor(BLUE);
	fillcircle(snake[0].x * (blocksize + 1) + blocksize / 2, snake[0].y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	for (int i = 1; i < snake.size(); i++)
	{
		solidrectangle(snake[i].x * (blocksize + 1), snake[i].y * (blocksize + 1), (snake[i].x + 1) * (blocksize + 1), (snake[i].y + 1) * (blocksize + 1));
	}
	//��������ʳ��Ϊ��ɫԲ��
	setfillcolor(RED);
	fillcircle(specialfood.x * (blocksize + 1) + blocksize / 2, specialfood.y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	//����ʳ��Ϊ��ɫԲ��
	setfillcolor(GREEN);
	fillcircle(food.x * (blocksize + 1) + blocksize / 2, food.y * (blocksize + 1) + blocksize / 2, blocksize / 2);
	//�����ϰ���Ϊ��ɫ����
	setfillcolor(BROWN);
	for (int i = 0; i < obstacles.size(); i++)
	{
		solidrectangle(obstacles[i].x * (blocksize + 1), obstacles[i].y * (blocksize + 1), (obstacles[i].x + 1) * (blocksize + 1), (obstacles[i].y + 1) * (blocksize + 1));
	}
	//���Ʒ�������߷֣�������ɫΪ��ɫ�������СΪbuttongap1/2����ʾ����Ļ���Ҳ�
	settextcolor(WHITE);
	settextstyle(buttongap1 / 2, 0, _T("����"));
	string scorestr = "Score: " + to_string(score);
	outtextxy(width * (blocksize + 1) + buttongap1 / 2, buttongap1 / 2, scorestr.c_str());
	string maxscorestr = "Max Score: " + to_string(maxscore);
	outtextxy(width * (blocksize + 1) + buttongap1 / 2, 5 * buttongap / 2, maxscorestr.c_str());
}

void SnakeGame::snakemove() {
	//���ƶ���ѭ���߽�����
	Position head = snake[0];
	playerinput();
	switch (direction)
	{
	case 0://��
		head.y = head.y > 0 ? head.y - 1 : height - 1;
		break;
	case 1://��
		head.x = head.x < width - 1 ? head.x + 1 : 0;
		break;
	case 2://��
		head.y = head.y < height - 1 ? head.y + 1 : 0;
		break;
	case 3://��
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
	//������룬w�ϣ�d�ң�s�£�a��
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
			Useabletimes++;
			break;
		case 'd':
		case 'D':
			if (direction == 3)
			{
				break;
			}
			direction = 1;
			Useabletimes++;
			break;
		case 's':
		case 'S':
			if (direction == 0)
			{
				break;
			}
			direction = 2;
			Useabletimes++;
			break;
		case 'a':
		case 'A':
			if (direction == 1)
			{
				break;
			}
			direction = 3;
			Useabletimes++;
			break;
		case 'p':
		case 'P':
			MessageBox(NULL, _T("Press P again to continue"), _T("Pause"), MB_OK);
			while (true)
			{
				if (_kbhit())
				{
					char ch = _getch();
					if (ch == 'p' || ch == 'P')
					{
						break;
					}
				}
			}
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
	//�����������
	srand((unsigned)time(NULL));
	//�������ʳ��λ�ã������������ϰ������ʳ���غ�
	do
	{
		food.x = rand() % width;
		food.y = rand() % height;
	} while (isSnake(food) || isObstacle(food) || isSpecialFood(food));
}

void SnakeGame::placespecialfood()
{
	//����һ������ʳ�ﱻ�Ե����߳���ʱ�����ƣ�����Ϊ7�ı�����������0���������������ʳ��λ�ã������������ϰ��ʳ���غ�
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
	//��Ϸ��������ͷ��������,�ϰ���
	if (isSnakeBody(snake[0]) || isObstacle(snake[0]))
	{
		if (Useabletimes > 0) 
		{
			isGameOver = true;
			if (score > maxscore)
			{
				maxscore = score;
			}
		}
	}
}

void SnakeGame::afterEatfood()
{
	//�Ե�ʳ������������������ӣ�ʳ������
	if (isFood(snake[0]))
	{
		score++;
		snake.push_back(snake[snake.size() - 1]);
		snake.pop_back();
		placefood();
	}
	//�Ե�����ʳ��������ӣ�ʳ������
	if (isSpecialFood(snake[0]) && is_specialfood_eff == true)
	{
		//��������ֵΪ����ʳ��Lifetime-����ʱ���������3��
        score += (chrono::duration_cast<chrono::seconds>(sfoodLifeTime - (chrono::system_clock::now() - LastsfoodPlaceTime)).count()) * 3;
		lastscore = score;
		is_specialfood_eff = false;
		specialfood = { -1,-1 };
	}
	if (is_specialfood_eff && chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - LastsfoodPlaceTime) > sfoodLifeTime)
	{
		lastscore = score;
		is_specialfood_eff = false;
		specialfood = { -1,-1 };
	}
}

void SnakeGame::savescore(string mark)
{
	//�����ļ���Ϊmark_width_height.txt������Ϊwidth��height��maxscore
	ofstream file("snake/scores/" + mark + "_" + to_string(width) + "_" + to_string(height) + ".txt");
	file << maxscore << endl;
	file.close();
	file.clear();
}

void SnakeGame::loadscore(string mark)
{
	//��ȡ�ļ���Ϊmark_width_height.txt������Ϊwidth��height��score��maxscore
	ifstream file("snake/scores/" + mark + "_" + to_string(width) + "_" + to_string(height) + ".txt");
	if (!file.is_open())
	{
		maxscore = 0;
		return;
	}
	file >> maxscore;
	file.close();
	file.clear();
}

void RandomSnakeGame::placeobstacle()
{
	//��ÿһ�����0~400��������������С��difficulty*50�������ϰ���
	srand((unsigned)time(NULL));
	obstacles.clear();
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (rand() % 400 < difficulty * 50 && !isSnake({i,j}))
			{
				obstacles.push_back({ i,j });
			}
		}
	}
}

void GravitySnakeGame::placeobstacle()
{
	//�����ÿһ�����0~1000��������������С��difficulty*50�������ϰ���
	srand((unsigned)time(NULL));
	obstacles.clear();
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (rand() % 1000 < difficulty * 50 && !isSnake({ i,j }))
			{
				obstacles.push_back({ i,j });
			}
		}
	}
}

void GravitySnakeGame::setmovetime()
{
	//�����ϰ����ƶ�ʱ��
	int time = speed / difficulty;
	obstacleMoveTime = chrono::seconds(time);
}

void GravitySnakeGame::obstaclemove()
{
	//�ϰ����ƶ���ÿ���ƶ�һ���ƶ��������ʱ��ʧ
	if (chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - LastobstacleMoveTime) > obstacleMoveTime)
	{
		for (int i = 0; i < obstacles.size(); i++)
		{
			if (obstacles[i].y == height - 1)
			{
				obstacles[i].y = 0;
			}
			else
			{
				obstacles[i].y++;
			}
		}
		LastobstacleMoveTime = chrono::system_clock::now();
	}
}

void EditSnakeGame::setonlymap()
{
	//ֻ�е�ͼ��û���ߡ�ʳ��ϰ���
	snake.clear();
	food = { -1,-1 };
	specialfood = { -1,-1 };
	obstacles.clear();
}

void EditSnakeGame::placeobstacle()
{
	//�ڵ�ͼ���������������λ�������ϰ���
	if (mouse.x < width * (MINBLOCKSIZE + 1) && mouse.y < height * (MINBLOCKSIZE + 1) && mouse.uMsg == WM_LBUTTONDOWN)
	{
		Position pos = { mouse.x / (MINBLOCKSIZE + 1), mouse.y / (MINBLOCKSIZE + 1) };
		if (!isObstacle(pos))
		{
			obstacles.push_back(pos);
		}
		else
		{
			for (int i = 0; i < obstacles.size(); i++)
			{
				if (pos.x == obstacles[i].x && pos.y == obstacles[i].y)
				{
					obstacles.erase(obstacles.begin() + i);
					break;
				}
			}
		}
	}
}

void EditSnakeGame::savemap(string filename)
{
	//�����ͼ���ļ���Ϊmap_width_height.txt������Ϊwidth��height��obstacles
	ofstream file("snake/maps/" + filename + ".txt");
	file << width << endl;
	file << height << endl;
	for (int i = 0; i < obstacles.size(); i++)
	{
		file << obstacles[i].x << " " << obstacles[i].y << endl;
	}
	file.close();
	file.clear();
}

void EditSnakeGame::drawobstacle()
{
	//���vector��Ϊ�գ������ϰ���
	if (obstacles.size() > 0)
	{
		setfillcolor(BROWN);
		for (int i = 0; i < obstacles.size(); i++)
		{
			solidrectangle(obstacles[i].x * (blocksize + 1), obstacles[i].y * (blocksize + 1), (obstacles[i].x + 1) * (blocksize + 1), (obstacles[i].y + 1) * (blocksize + 1));
		}
	}
}

void MapSnakeGame::loadmap(string filename)
{
	//��ȡ��ͼ���ļ���Ϊmap_width_height.txt������Ϊwidth��height��obstacles
	ifstream file("snake/maps/" + filename + ".txt");
	if (!file.is_open())
	{
		return;
	}
	file >> width;
	file >> height;
	obstacles.clear();
	do
	{
		Position pos;
		file >> pos.x;
		file >> pos.y;
		obstacles.push_back(pos);
	} while (!file.eof());
	file.close();
	file.clear();
	loadscore(filename);
	//��ʼ����������
	score = 0;
	lastscore = -1;
	direction = 0;
	is_specialfood_eff = false;
	Useabletimes = 0;
	snake.clear();
	snake.push_back({ width / 2, height / 2 });
	food = { -1,-1 };
	specialfood = { -1,-1 };
	isGameOver = false;
	LastsfoodPlaceTime = chrono::system_clock::now();
	speed = stod(speedstr);
	difficulty = stod(difficultystr);
	placefood();
	placespecialfood();
}