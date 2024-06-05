#include "Pages.h"

void pages(int& pagenum)
{
	loadsettings(speedstr, difficultystr, WINDOW_WIDTH, WINDOW_HEIGHT);
	setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	initialButtons();
	switch (pagenum)
	{
	case 0:
		return page0(pagenum);
		break;
	case 1:
		return page1(pagenum);
		break;
	case 2:
		return page2(pagenum);
		break;
	case 3:
		return page3(pagenum);
		break;
	case 4:
		return page4(pagenum);
		break;
	case 5:
		return page5(pagenum);
		break;
	case 6:
		return page6(pagenum);
		break;
	case 7:
		return page7(pagenum);
		break;
	}
}

void page0(int& value)
{
	Sleep(100);
	BeginBatchDraw();
	cleardevice();
	playbutton.draw();
	editbutton.draw();
	settingbutton.draw();
	quitbutton.draw();
	EndBatchDraw();
	Sleep(100);
	while (true)
	{
		getMousePosition();
		if (playbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 1;
			break;
		}
		if (editbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 2;
			break;
		}
		if (settingbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 3;
			break;
		}
		if (quitbutton.isClicked())
		{
			exit(0);
		}
	}
	closegraph();
	Sleep(100);
	return pages(value);
}

void page1(int& value)
{
	Sleep(100);
	BeginBatchDraw();
	cleardevice();
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
			Sleep(100);
			getMousePosition();
			value = 4;
			break;
		}
		if (mapbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 5;
			break;
		}
		if (randombutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 6;
			break;
		}
		if (gravitybutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 7;
			break;
		}
		if (backbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 0;
			break;
		}
	}
	closegraph();
	return pages(value);
}

void page2(int& value)
{
	Sleep(100);
	backbutton.setAll(0, WINDOW_HEIGHT - buttongap1 / 2, buttonwidth / 4, buttongap1 / 2, "Back", WHITE, BLACK, buttongap1 / 4);
	char widthstr[5];
	char heightstr[5];
	int width, height, blocksizeint;
	InputBox(widthstr, 5, "Input the map width");
	InputBox(heightstr, 5, "Input the map height");
	width = atoi(widthstr);
	height = atoi(heightstr);
	blocksizeint = 20;
	editsg.setAll(width, height, blocksizeint);
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
	closegraph();
	return pages(value);
}

void page3(int& value)
{
	int windowwidth = WINDOW_WIDTH;
	int windowheight = WINDOW_HEIGHT;
	char windowwidthstr[5];
	char windowheightstr[5];
	Sleep(100);
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
			Sleep(100);
			getMousePosition();
			savesettings(speedslider.loadValueStr(), difficultyslider.loadValueStr(), windowwidth, windowheight);
			value = 0;
			break;
		}
		if (backbutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			value = 0;
			break;
		}
		if (setwindowsizebutton.isClicked())
		{
			Sleep(100);
			getMousePosition();
			InputBox(windowwidthstr, 5, "Input the window width");
			InputBox(windowheightstr, 5, "Input the window height");
			windowwidth = min(max(atoi(windowwidthstr), MIN_WIDTH), MAX_WIDTH);
			windowheight = min(max(atoi(windowheightstr),MIN_HEIGHT),MAX_HEIGHT);
		}
		Sleep(10);
	}
	closegraph();
	return pages(value);
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
	defaultsg.setAll(width, height, blocksizeint);
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
	closegraph();
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
	closegraph();
	return pages(value);
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
	randomsg.setAll(width, height, blocksizeint);
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
	closegraph();
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
	gravitysg.setAll(width, height, blocksizeint);
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
	closegraph();
	return pages(value);
}