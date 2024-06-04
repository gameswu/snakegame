#include "Pages.h"

void pages(int& pagenum)
{
	loadsettings(speedstr, difficultystr, WINDOW_WIDTH, WINDOW_HEIGHT);
	setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	initialButtons();
	int val;
	if (pagenum == 0)
	{
		page0(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 1)
	{
		page1(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 2)
	{
		page2(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 3)
	{
		page3(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 4)
	{
		page4(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 5)
	{
		page5(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 6)
	{
		page6(val);
		pagenum = val;
		return pages(pagenum);
	}
	if (pagenum == 7)
	{
		page7(val);
		pagenum = val;
		return pages(pagenum);
	}
}

void page0(int& value)
{
	Sleep(100);
	BeginBatchDraw();
	cleardevice();
	playbutton.setIsUseable(true);
	editbutton.setIsUseable(true);
	settingbutton.setIsUseable(true);
	quitbutton.setIsUseable(true);
	playbutton.draw();
	editbutton.draw();
	settingbutton.draw();
	quitbutton.draw();
	EndBatchDraw();
	Sleep(100);
	while (1)
	{
		getMousePosition();
		if (playbutton.isClicked())
		{
			value = 1;
			break;
		}
		if (editbutton.isClicked())
		{
			value = 2;
			break;
		}
		if (settingbutton.isClicked())
		{
			value = 3;
			break;
		}
		if (quitbutton.isClicked())
		{
			exit(0);
		}
	}
	playbutton.setIsUseable(false);
	editbutton.setIsUseable(false);
	settingbutton.setIsUseable(false);
	quitbutton.setIsUseable(false);
}

void page1(int& value)
{
	Sleep(100);
	BeginBatchDraw();
	cleardevice();
	defaultbutton.setIsUseable(true);
	mapbutton.setIsUseable(true);
	randombutton.setIsUseable(true);
	gravitybutton.setIsUseable(true);
	backbutton.setIsUseable(true);
	defaultbutton.draw();
	mapbutton.draw();
	randombutton.draw();
	gravitybutton.draw();
	backbutton.draw();
	EndBatchDraw();
	Sleep(100);
	while (true)
	{
		getMousePosition();
		if (defaultbutton.isClicked())
		{
			value = 4;
			break;
		}
		if (mapbutton.isClicked())
		{
			value = 5;
			break;
		}
		if (randombutton.isClicked())
		{
			value = 6;
			break;
		}
		if (gravitybutton.isClicked())
		{
			value = 7;
			break;
		}
		if (backbutton.isClicked())
		{
			value = 0;
			break;
		}
	}
	defaultbutton.setIsUseable(false);
	mapbutton.setIsUseable(false);
	randombutton.setIsUseable(false);
	gravitybutton.setIsUseable(false);
	backbutton.setIsUseable(false);
}

void page2(int& value)
{
	Sleep(100);
	backbutton.setIsUseable(true);
	savebutton.setIsUseable(true);
	backbutton.setAll(0, WINDOW_HEIGHT - buttongap1 / 2, buttonwidth / 4, buttongap1 / 2, "Back", WHITE, BLACK, buttongap1 / 4);
	char widthstr[5];
	char heightstr[5];
	int width, height, blocksizeint;
	InputBox(widthstr, 5, "Input the map width");
	InputBox(heightstr, 5, "Input the map height");
	width = atoi(widthstr);
	height = atoi(heightstr);
	blocksizeint = 20;
	editsg.setAll(width, height, blocksizeint, 1, 1);
	editsg.setonlymap();
	while (true)
	{
		getMousePosition();
		BeginBatchDraw();
		cleardevice();
		backbutton.draw();
		savebutton.draw();
		editsg.drawmap();
		editsg.placeobstacle();
		editsg.drawobstacle();
		EndBatchDraw();
		if (savebutton.isClicked())
		{
			value = 0;
			char filename[20];
			InputBox(filename, 20, "Input the file name");
			editsg.savemap(filename);
			break;
		}
		if (backbutton.isClicked())
		{
			value = 0;
			MessageBox(GetHWnd(), "The map will not be saved", "Edit", MB_OK);
			break;
		}
		Sleep(70);
	}
	backbutton.setIsUseable(false);
	savebutton.setIsUseable(false);
}

void page3(int& value)
{
	int windowwidth = WINDOW_WIDTH;
	int windowheight = WINDOW_HEIGHT;
	char windowwidthstr[5];
	char windowheightstr[5];
	Sleep(100);
	savebutton.setIsUseable(true);
	backbutton.setIsUseable(true);
	setwindowsizebutton.setIsUseable(true);
	speedslider.setIsUseable(true);
	difficultyslider.setIsUseable(true);
	backbutton.setAll(0, WINDOW_HEIGHT - buttongap1 / 2, buttonwidth / 4, buttongap1 / 2, "Back", WHITE, BLACK, buttongap1 / 4);
	while (true)
	{
		getMousePosition();
		BeginBatchDraw();
		cleardevice();
		savebutton.draw();
		backbutton.draw();
		setwindowsizebutton.draw();
		speedslider.draw();
		difficultyslider.draw();
		EndBatchDraw();
		if (savebutton.isClicked())
		{
			savesettings(speedslider.loadValueStr(), difficultyslider.loadValueStr(), windowwidth, windowheight);
			value = 0;
			break;
		}
		if (backbutton.isClicked())
		{
			value = 0;
			break;
		}
		if (setwindowsizebutton.isClicked())
		{
			InputBox(windowwidthstr, 5, "Input the window width");
			InputBox(windowheightstr, 5, "Input the window height");
			windowwidth = min(max(atoi(windowwidthstr), MIN_WIDTH), MAX_WIDTH);
			windowheight = min(max(atoi(windowheightstr),MIN_HEIGHT),MAX_HEIGHT);
		}
		Sleep(10);
	}
	savebutton.setIsUseable(false);
	backbutton.setIsUseable(false);
	setwindowsizebutton.setIsUseable(false);
	speedslider.setIsUseable(false);
	difficultyslider.setIsUseable(false);
}

void page4(int& value)
{
	Sleep(100);
	char widthstr[5];
	char heightstr[5];
	char blocksize[5];
	int width, height, blocksizeint;
    InputBox(widthstr, 5, "Input the map width");
    InputBox(heightstr, 5, "Input the map height");
    InputBox(blocksize, 5, "Input the block size");
	width = atoi(widthstr);
	height = atoi(heightstr);
	blocksizeint = atoi(blocksize);
	defaultsg.setAll(width, height, blocksizeint, 1, 1);
	defaultsg.loadscore("D");
	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		defaultsg.snakemove();
		defaultsg.drawmap();
		defaultsg.drawother();
		defaultsg.afterEatfood();
		defaultsg.placespecialfood();
		defaultsg.gameover();
		if (defaultsg.isGameOver)
		{
			value = 1;
			defaultsg.savescore("D");
			MessageBox(GetHWnd(), "Game Over", "Default", MB_OK);
			break;
		}
		Sleep(100 / defaultsg.speed);
		EndBatchDraw();
	}
	return pages(value);
}

void page5(int& value)
{
	Sleep(100);
	char filename[20];
	InputBox(filename, 20, "Input the file name");
	mapsg.loadmap(filename);
	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		mapsg.snakemove();
		mapsg.drawmap();
		mapsg.drawother();
		mapsg.afterEatfood();
		mapsg.placespecialfood();
		mapsg.gameover();
		if (mapsg.isGameOver)
		{
			value = 1;
			mapsg.savescore(filename);
			MessageBox(GetHWnd(), "Game Over", "Map", MB_OK);
			break;
		}
		Sleep(100 / mapsg.speed);
		EndBatchDraw();
	}
}

void page6(int& value)
{
	Sleep(100);
	char widthstr[5];
	char heightstr[5];
	char blocksize[5];
	int width, height, blocksizeint;
	InputBox(widthstr, 5, "Input the map width");
	InputBox(heightstr, 5, "Input the map height");
	InputBox(blocksize, 5, "Input the block size");
	width = atoi(widthstr);
	height = atoi(heightstr);
	blocksizeint = atoi(blocksize);
	randomsg.setAll(width, height, blocksizeint, 1, 1);
	randomsg.loadscore("R");
	randomsg.placeobstacle();
	randomsg.placefood();
	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		randomsg.snakemove();
		randomsg.drawmap();
		randomsg.drawother();
		randomsg.afterEatfood();
		randomsg.placespecialfood();
		randomsg.gameover();
		if (randomsg.isGameOver)
		{
			value = 1;
			randomsg.savescore("R");
			MessageBox(GetHWnd(), "Game Over", "Random", MB_OK);
			break;
		}
		Sleep(100 / randomsg.speed);
		EndBatchDraw();
	}
	return pages(value);
}

void page7(int& value)
{
	Sleep(100);
	char widthstr[5];
	char heightstr[5];
	char blocksize[5];
	int width, height, blocksizeint;
	InputBox(widthstr, 5, "Input the map width");
	InputBox(heightstr, 5, "Input the map height");
	InputBox(blocksize, 5, "Input the block size");
	width = atoi(widthstr);
	height = atoi(heightstr);
	blocksizeint = atoi(blocksize);
	gravitysg.setAll(width, height, blocksizeint, 1, 1);
	gravitysg.loadscore("G");
	gravitysg.setmovetime();
	gravitysg.placeobstacle();
	gravitysg.placefood();
	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		gravitysg.snakemove();
		gravitysg.obstaclemove();
		gravitysg.drawmap();
		gravitysg.drawother();
		gravitysg.afterEatfood();
		gravitysg.placespecialfood();
		gravitysg.gameover();
		if (gravitysg.isGameOver)
		{
			value = 1;
			gravitysg.savescore("G");
			MessageBox(GetHWnd(), "Game Over", "Gravity", MB_OK);
			break;
		}
		Sleep(100 / gravitysg.speed);
		EndBatchDraw();
	}
	return pages(value);
}