#include "UI.h"

int WINDOW_WIDTH = 1080;
int WINDOW_HEIGHT = 960;
int MOUSE_X;
int MOUSE_Y;
int buttongap1 = 960 / 16;
int buttongap = 960 / 13;
int buttonwidth = 1080 / 4;
int MAX_WIDTH = 1080;
int MAX_HEIGHT = 960;
MOUSEMSG mouse;

void setWindowSize(int width, int height)
{
	setMaxWindowSize();
    WINDOW_WIDTH = min(width,MAX_WIDTH);
    WINDOW_HEIGHT = min(height,MAX_HEIGHT);
    buttongap1 = WINDOW_HEIGHT / 16;
    buttongap = WINDOW_HEIGHT / 13;
    buttonwidth = WINDOW_WIDTH / 4;
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);  // 初始化绘图窗口
}

void setMaxWindowSize()
{
	RECT desktop;  // 获取桌面窗口的大小
	const HWND hDesktop = GetDesktopWindow();  // 获取桌面窗口的句柄
	GetWindowRect(hDesktop, &desktop);  // 获取桌面窗口的大小
    MAX_WIDTH = 0.9 * (desktop.right - desktop.left);
    MAX_HEIGHT = 0.9 * (desktop.bottom - desktop.top);
}

void getMousePosition()
{
	if (MouseHit())  // 如果有鼠标消息
	{
		mouse = GetMouseMsg();
		MOUSE_X = mouse.x;
		MOUSE_Y = mouse.y;
		FlushMouseMsgBuffer();  // 清空鼠标消息缓冲区
	}
}

// 实现按钮类的构造函数
Button::Button(int x, int y, int width, int height, string text, int color, int text_color, int text_size)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->text = text;
    this->color = color;
    this->text_color = text_color;
    this->text_size = text_size;
    this->text_x = x + width / 2 - text_size * text.length() / 4;
    this->text_y = y + height / 2 - text_size / 2;
}

void Button::setAll(int x, int y, int width, int height, string text, int color, int text_color, int text_size)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->text = text;
	this->color = color;
	this->text_color = text_color;
	this->text_size = text_size;
	this->text_x = x + width / 2 - text_size * text.length() / 4;
	this->text_y = y + height / 2 - text_size / 2;
}

void Button::draw()
{
    setfillcolor(color);
	fillrectangle(x, y, x + width, y + height);  // 绘制按钮背景矩形
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("宋体"));
    settextcolor(text_color);
	outtextxy(text_x, text_y, text.c_str());  // 绘制按钮文本
}

bool Button::isClicked()
{
	if (boolIsMouseOn() && mouse.uMsg == WM_LBUTTONDOWN)  // 如果鼠标左键按下且鼠标在按钮上
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Button::boolIsMouseOn()
{
	if (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height)  // 如果鼠标在按钮上
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 实现滑动条类的构造函数
Slider::Slider(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    this->slider_color = slider_color;
	this->slider_button_color = slider_button_color;
	this->text_color = text_color;
    this->slider_width = width / 2;
    this->slider_height = height;
	this->slider_button_x = x + slider_width - width / 20;
	this->slider_button_y = y - height / 4;
	this->slider_button_width = width / 10;
	this->slider_button_height = 1.5 * height;
	this->text_size = height;
	this->slider_title = slider_title;
	this->slider_left_text = slider_left_text;
	this->slider_right_text = slider_right_text;
    this->slider_value_text = "";
    this->slider_title_x = x + width / 2 - text_size * slider_title.length() / 4;
	this->slider_title_y = y - 3 * height / 2;
	this->slider_left_text_x = x - width / 10 - text_size * slider_left_text.length() / 2;
	this->slider_left_text_y = y;
	this->slider_right_text_x = x + 11 * width / 10;
	this->slider_right_text_y = y;
	this->slider_value_text_x = slider_button_x - text_size * slider_value_text.length() / 4;
	this->slider_value_text_y = y + 3 * height / 2;
}

void Slider::setAll(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text, string slider_value_text)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->slider_color = slider_color;
	this->slider_button_color = slider_button_color;
	this->text_color = text_color;
	this->slider_width = width * (stod(slider_value_text) - stod(slider_left_text)) / (stod(slider_right_text) - stod(slider_left_text));
	this->slider_height = height;
	this->slider_button_x = x + slider_width - width / 20;
	this->slider_button_y = y - height / 4;
	this->slider_button_width = width / 10;
	this->slider_button_height = 1.5 * height;
	this->text_size = height;
	this->slider_title = slider_title;
	this->slider_left_text = slider_left_text;
	this->slider_right_text = slider_right_text;
	this->slider_value_text = "";
	this->slider_title_x = x + width / 2 - text_size * slider_title.length() / 4;
	this->slider_title_y = y - 3 * height / 2;
	this->slider_left_text_x = x - width / 10 - text_size * slider_left_text.length() / 2;
	this->slider_left_text_y = y;
	this->slider_right_text_x = x + 11 * width / 10;
	this->slider_right_text_y = y;
	this->slider_value_text_x = slider_button_x - text_size * slider_value_text.length() / 4;
	this->slider_value_text_y = y + 3 * height / 2;
}

void Slider::draw()
{
	if (isClicked())  // 如果滑动条被点击，则更新滑动条的位置
	{
		this->slider_button_x = (MOUSE_X - slider_button_width / 2);
		this->slider_width = (MOUSE_X - x);
	}
	calculateTextPosition();  // 计算文本的位置
    setfillcolor(color);
	fillrectangle(x, y, x + width, y + height);  // 绘制滑动条背景矩形
    setfillcolor(slider_color);
	fillrectangle(x, y, x + slider_width, y + slider_height);  // 绘制滑动条矩形
    setfillcolor(slider_button_color);
	fillrectangle(slider_button_x, slider_button_y, slider_button_x + slider_button_width, slider_button_y + slider_button_height);  // 绘制滑动条按钮
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("宋体"));
    settextcolor(text_color);
    outtextxy(slider_title_x, slider_title_y, slider_title.c_str());
    outtextxy(slider_left_text_x, slider_left_text_y, slider_left_text.c_str());
    outtextxy(slider_right_text_x, slider_right_text_y, slider_right_text.c_str());
	outtextxy(slider_value_text_x, slider_value_text_y, slider_value_text.c_str());  // 绘制滑动条文本
}

bool Slider::isClicked()
{
	if (boolIsMouseOn() && mouse.mkLButton)  // 如果鼠标左键按下且鼠标在滑动条上
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Slider::boolIsMouseOn()
{
	if (MOUSE_X >= x && MOUSE_X <= x + width && MOUSE_Y >= y && MOUSE_Y <= y + height)  // 如果鼠标在滑动条上
	{
		return true;
	}
	else
	{
		return false;
	}
}

//实现读取滑动条值字符串
string Slider::loadValueStr()
{
	return slider_value_text;
}

//计算文本坐标
void Slider::calculateTextPosition()
{
	double slider_left_text_double = atof(slider_left_text.c_str());
	double slider_right_text_double = atof(slider_right_text.c_str());
	double slider_value_text_double = atof(slider_value_text.c_str());
	slider_value_text_double = slider_left_text_double + (slider_right_text_double - slider_left_text_double) * slider_width / width;
	this->slider_value_text = (to_string(slider_value_text_double));
	this-> slider_value_text_x = (slider_button_x - text_size * slider_value_text.length() / 4);
	this-> slider_value_text_y = (y + 3 * height / 2);
}