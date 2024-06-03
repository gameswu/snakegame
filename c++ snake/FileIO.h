#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <filesystem>
#include <string>
#include <graphics.h>
#include <cmath>
#include <windows.h>
#include <chrono>
#include <conio.h>

using namespace std;

void initialfiles();

void savesettings(string speed, string difficulty, int windowwidth, int windowheight);
void loadsettings(string& speed, string& difficulty, int& windowwidth, int& windowheight);

#endif FILEIO_H