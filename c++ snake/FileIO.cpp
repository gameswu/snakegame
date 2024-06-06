#include "FileIO.h"
#include <filesystem>

void initialfiles()
{
	if (!filesystem::exists("snake"))
	{
		filesystem::create_directory("snake");
	}
	if (!filesystem::exists("snake/settings"))
	{
		filesystem::create_directory("snake/settings");
	}
	if (!filesystem::exists("snake/settings/settings.txt"))
	{
		savesettings("1", "1", 800, 600);
	}
	if (!filesystem::exists("snake/scores"))
	{
		filesystem::create_directory("snake/scores");
	}
	if (!filesystem::exists("snake/maps"))
	{
		filesystem::create_directory("snake/maps");
	}
}

void savesettings(string speed, string difficulty, int windowwidth, int windowheight)
{
	//保存窗口的宽度和高度，以及游戏的速度和难度
    ofstream file("snake/settings/settings.txt");
	file << windowwidth << endl;
	file << windowheight << endl;    
    file << difficulty << endl;
    file << speed << endl;
    file.close();
    file.clear();
}

void loadsettings(string& speed, string& difficulty, int& windowwidth, int& windowheight)
{
	//读取窗口的宽度和高度，以及游戏的速度和难度
	ifstream file("snake/settings/settings.txt");
	if (!file.is_open())
	{
		savesettings("1", "1", 800, 600);  //如果文件不存在则创建默认文件
		file.open("snake/settings/settings.txt");
	}
	file >> windowwidth;
	file >> windowheight;
	file >> difficulty;
	file >> speed;
	file.close();
	file.clear();
}