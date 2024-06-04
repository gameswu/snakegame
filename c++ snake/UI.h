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
	void setText(string text);
	void setTextColor(int text_color);
	void setTextSize(int text_size);
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setColor(int color);
	void setTextX(int text_x);
	void setTextY(int text_y);
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
    int slider_x;
    int slider_y;
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
	double loadValue();
	string loadValueStr();
    void setSliderX(int slider_x);
    void setSliderY(int slider_y);
    void setSliderWidth(int slider_width);
    void setSliderHeight(int slider_height);
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
	void setSliderButtonX(int slider_button_x);
	void setSliderButtonY(int slider_button_y);
	void setSliderButtonWidth(int slider_button_width);
	void setSliderButtonHeight(int slider_button_height);
    void setColor(int color);
    void setSliderColor(int slider_color);
	void setSliderButtonColor(int slider_button_color);
	void setTextColor(int text_color);
	void setSliderTitle(string slider_title);
	void setSliderLeftText(string slider_left_text);
	void setSliderRightText(string slider_right_text);
	void setSliderValueText(string slider_value_text);
	void setSliderTitleX(int slider_title_x);
	void setSliderTitleY(int slider_title_y);
	void setSliderLeftTextX(int slider_left_text_x);
	void setSliderLeftTextY(int slider_left_text_y);
	void setSliderRightTextX(int slider_right_text_x);
	void setSliderRightTextY(int slider_right_text_y);
	void setSliderValueTextX(int slider_value_text_x);
	void setSliderValueTextY(int slider_value_text_y);
	void calculateTextPosition();
	void setAll(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text, string slider_value_text);
};

#endif UI_H