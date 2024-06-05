#ifndef UI_H
#define UI_H

#include "FileIO.h"

#define MIN_WIDTH 400
#define MIN_HEIGHT 300

using namespace std;

//定义全局变量表明窗口的宽度和高度
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int MAX_WIDTH;
extern int MAX_HEIGHT;
extern int MOUSE_X;
extern int MOUSE_Y;
extern int buttongap;
extern int buttongap1;
extern int buttonwidth;
extern MOUSEMSG mouse;

//定义函数设置窗口的宽度和高度
void setWindowSize(int width, int height);
void setMaxWindowSize();

//定义函数获取鼠标的位置
void getMousePosition();

//定义按钮类
class Button
{
private:
	int x, y, width, height;
	std::string text;
	int color;
	int text_color;
	int text_size;
	int text_x, text_y;
public:
	Button(int x, int y, int width, int height, string text, int color, int text_color, int text_size); 
	void draw();
	bool isClicked();
	bool boolIsMouseOn();
	void setAll(int x, int y, int width, int height, string text, int color, int text_color, int text_size);
};

//定义滑动条类
class Slider
{
private:
    int x, y, width, height;
    int color;
    int slider_color;
	int slider_button_color;
	int text_color;
    int slider_width;
    int slider_height;
    int slider_button_x;
	int slider_button_y;
	int slider_button_width;
	int slider_button_height;
	int text_size;
	int slider_title_x;
	int slider_title_y;
	int slider_left_text_x;
	int slider_left_text_y;
	int slider_right_text_x;
	int slider_right_text_y;
	int slider_value_text_x;
	int slider_value_text_y;
	string slider_title;
	string slider_left_text;
	string slider_right_text;
	string slider_value_text;
public:
    Slider(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text);
    void draw();
    bool isClicked();
	bool boolIsMouseOn();
	string loadValueStr();
	void calculateTextPosition();
	void setAll(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text, string slider_value_text);
};

#endif UI_H