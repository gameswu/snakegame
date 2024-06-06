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
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);  // ��ʼ����ͼ����
}

void setMaxWindowSize()
{
	RECT desktop;  // ��ȡ���洰�ڵĴ�С
	const HWND hDesktop = GetDesktopWindow();  // ��ȡ���洰�ڵľ��
	GetWindowRect(hDesktop, &desktop);  // ��ȡ���洰�ڵĴ�С
    MAX_WIDTH = 0.9 * (desktop.right - desktop.left);
    MAX_HEIGHT = 0.9 * (desktop.bottom - desktop.top);
}

void getMousePosition()
{
	if (MouseHit())  // ����������Ϣ
	{
		mouse = GetMouseMsg();
		MOUSE_X = mouse.x;
		MOUSE_Y = mouse.y;
		FlushMouseMsgBuffer();  // ��������Ϣ������
	}
}

// ʵ�ְ�ť��Ĺ��캯��
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
	fillrectangle(x, y, x + width, y + height);  // ���ư�ť��������
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("����"));
    settextcolor(text_color);
	outtextxy(text_x, text_y, text.c_str());  // ���ư�ť�ı�
}

bool Button::isClicked()
{
	if (boolIsMouseOn() && mouse.uMsg == WM_LBUTTONDOWN)  // �������������������ڰ�ť��
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
	if (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height)  // �������ڰ�ť��
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ʵ�ֻ�������Ĺ��캯��
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
	if (isClicked())  // ��������������������»�������λ��
	{
		this->slider_button_x = (MOUSE_X - slider_button_width / 2);
		this->slider_width = (MOUSE_X - x);
	}
	calculateTextPosition();  // �����ı���λ��
    setfillcolor(color);
	fillrectangle(x, y, x + width, y + height);  // ���ƻ�������������
    setfillcolor(slider_color);
	fillrectangle(x, y, x + slider_width, y + slider_height);  // ���ƻ���������
    setfillcolor(slider_button_color);
	fillrectangle(slider_button_x, slider_button_y, slider_button_x + slider_button_width, slider_button_y + slider_button_height);  // ���ƻ�������ť
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("����"));
    settextcolor(text_color);
    outtextxy(slider_title_x, slider_title_y, slider_title.c_str());
    outtextxy(slider_left_text_x, slider_left_text_y, slider_left_text.c_str());
    outtextxy(slider_right_text_x, slider_right_text_y, slider_right_text.c_str());
	outtextxy(slider_value_text_x, slider_value_text_y, slider_value_text.c_str());  // ���ƻ������ı�
}

bool Slider::isClicked()
{
	if (boolIsMouseOn() && mouse.mkLButton)  // �������������������ڻ�������
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
	if (MOUSE_X >= x && MOUSE_X <= x + width && MOUSE_Y >= y && MOUSE_Y <= y + height)  // �������ڻ�������
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ʵ�ֶ�ȡ������ֵ�ַ���
string Slider::loadValueStr()
{
	return slider_value_text;
}

//�����ı�����
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