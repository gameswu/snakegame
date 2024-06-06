#ifndef UI_H
#define UI_H

#include "FileIO.h"

#define MIN_WIDTH 400
#define MIN_HEIGHT 300

using namespace std;

//定义全局变量表明绘制参量
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

void setWindowSize(int width, int height);  //设置窗口的宽度和高度
void setMaxWindowSize();  //读取屏幕允许窗口的最大宽度和高度

void getMousePosition();  //获取鼠标的位置

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
	void draw();  //绘制按钮
	bool isClicked();  //判断按钮是否被点击
	bool boolIsMouseOn();  //判断鼠标是否在按钮上
	void setAll(int x, int y, int width, int height, string text, int color, int text_color, int text_size);  //设置按钮的所有参数
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
	void draw();  //绘制滑动条
	bool isClicked();  //判断滑动条是否被点击
	bool boolIsMouseOn();  //判断鼠标是否在滑动条上
	string loadValueStr();  //读取滑动条的设置值
	void calculateTextPosition();  //计算文本的位置
	void setAll(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text, string slider_value_text);  //设置滑动条的所有参数
};

#endif UI_H