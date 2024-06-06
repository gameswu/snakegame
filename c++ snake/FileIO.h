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
#include <iostream>
#include <vector>

using namespace std;

void initialfiles();  //初始化文件系统

void savesettings(string speed, string difficulty, int windowwidth, int windowheight);	//保存设置
void loadsettings(string& speed, string& difficulty, int& windowwidth, int& windowheight);	//读取设置

#endif FILEIO_H