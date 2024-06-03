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
}

void savesettings(string speed, string difficulty, int windowwidth, int windowheight)
{
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
	ifstream file("snake/settings/settings.txt");
	if (!file.is_open())
	{
		savesettings("1", "1", 800, 600);
		file.open("snake/settings/settings.txt");
	}
	file >> windowwidth;
	file >> windowheight;
	file >> difficulty;
	file >> speed;
	file.close();
	file.clear();
}