#include "UI.h"

// ����ȫ�ֱ����������ڵĿ�Ⱥ͸߶�
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

// ���庯�����ô��ڵĿ�Ⱥ͸߶Ȳ����ƴ���
void setWindowSize(int width, int height)
{
	setMaxWindowSize();
    WINDOW_WIDTH = min(width,MAX_WIDTH);
    WINDOW_HEIGHT = min(height,MAX_HEIGHT);
    buttongap1 = WINDOW_HEIGHT / 16;
    buttongap = WINDOW_HEIGHT / 13;
    buttonwidth = WINDOW_WIDTH / 4;
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void setMaxWindowSize()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    MAX_WIDTH = desktop.right - desktop.left;
    MAX_HEIGHT = desktop.bottom - desktop.top;
}
// ���庯����ȡ����λ��
void getMousePosition()
{
    while (MouseHit()) 
    {
        mouse = GetMouseMsg();
        MOUSE_X = mouse.x;
        MOUSE_Y = mouse.y;
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
	this->isUseable = false;
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

// ʵ�ְ�ť��Ļ��ƺ���
void Button::draw()
{
    setfillcolor(color);
    fillrectangle(x, y, x + width, y + height);
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("����"));
    settextcolor(text_color);
    outtextxy(text_x, text_y, text.c_str());
}

// ʵ�ְ�ť���������жϺ���
bool Button::isClicked()
{
    if (boolIsMouseOn() && mouse.mkLButton)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ʵ�ְ�ť��Ļ�ȡ����Ƿ��ڰ�ť�Ϻ���
bool Button::boolIsMouseOn()
{
	if (MOUSE_X >= x && MOUSE_X <= x + width && MOUSE_Y >= y && MOUSE_Y <= y + height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ʵ�ְ�ť��������ı�����
void Button::setText(string text)
{
    this->text = text;
}

// ʵ�ְ�ť��������ı���ɫ����
void Button::setTextColor(int text_color)
{
    this->text_color = text_color;
}

// ʵ�ְ�ť��������ı���С����
void Button::setTextSize(int text_size)
{
    this->text_size = text_size;
}

// ʵ�ְ�ť�������X���꺯��
void Button::setX(int x)
{
    this->x = x;
    this->text_x = x + width / 2;
}

// ʵ�ְ�ť�������Y���꺯��
void Button::setY(int y)
{
    this->y = y;
    this->text_y = y + height / 2;
}

// ʵ�ְ�ť������ÿ�Ⱥ���
void Button::setWidth(int width)
{
    this->width = width;
    this->text_x = x + width / 2;
}

// ʵ�ְ�ť������ø߶Ⱥ���
void Button::setHeight(int height)
{
    this->height = height;
    this->text_y = y + height / 2;
}

// ʵ�ְ�ť���������ɫ����
void Button::setColor(int color)
{
    this->color = color;
}

// ʵ�ְ�ť��������ı�X���꺯��
void Button::setTextX(int text_x)
{
    this->text_x = text_x;
}

// ʵ�ְ�ť��������ı�Y���꺯��
void Button::setTextY(int text_y)
{
    this->text_y = text_y;
}

void Button::setIsUseable(bool isUseable)
{
	this->isUseable = isUseable;
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
    this->slider_x = x;
    this->slider_y = y;
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
	this->isUseable = false;
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
	this->slider_x = x;
	this->slider_y = y;
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
	this->isUseable = false;
}

void Slider::setIsUseable(bool isUseable)
{
	this->isUseable = isUseable;
}

// ʵ�ֻ�������Ļ��ƺ���
void Slider::draw()
{
	if (isClicked())
	{
		setSliderButtonX(MOUSE_X - slider_button_width / 2);
		setSliderWidth(MOUSE_X - x);
	}
    calculateTextPosition();
    setfillcolor(color);
    fillrectangle(x, y, x + width, y + height);
    setfillcolor(slider_color);
    fillrectangle(slider_x, slider_y, slider_x + slider_width, slider_y + slider_height);
    setfillcolor(slider_button_color);
    fillrectangle(slider_button_x, slider_button_y, slider_button_x + slider_button_width, slider_button_y + slider_button_height);
    setbkmode(TRANSPARENT);
    settextstyle(text_size, 0, _T("����"));
    settextcolor(text_color);
    outtextxy(slider_title_x, slider_title_y, slider_title.c_str());
    outtextxy(slider_left_text_x, slider_left_text_y, slider_left_text.c_str());
    outtextxy(slider_right_text_x, slider_right_text_y, slider_right_text.c_str());
    outtextxy(slider_value_text_x, slider_value_text_y, slider_value_text.c_str());
}

// ʵ�ֻ��������������жϺ���
bool Slider::isClicked()
{
    if (boolIsMouseOn() && mouse.mkLButton)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//ʵ�ֻ�ȡ����Ƿ��ڻ������Ϻ���
bool Slider::boolIsMouseOn()
{
	if (MOUSE_X >= x && MOUSE_X <= x + width && MOUSE_Y >= y && MOUSE_Y <= y + height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ʵ�ֶ�ȡ������ֵ����
double Slider::loadValue()
{
    return atof(slider_value_text.c_str());;
}

//ʵ�ֶ�ȡ������ֵ�ַ�������
string Slider::loadValueStr()
{
	return slider_value_text;
}

// ʵ�ֻ�����������û���X���꺯��
void Slider::setSliderX(int slider_x)
{
    this->slider_x = slider_x;
}

// ʵ�ֻ�����������û���Y���꺯��
void Slider::setSliderY(int slider_y)
{
    this->slider_y = slider_y;
}

// ʵ�ֻ�����������û����Ⱥ���
void Slider::setSliderWidth(int slider_width)
{
    this->slider_width = slider_width;
}

// ʵ�ֻ�����������û���߶Ⱥ���
void Slider::setSliderHeight(int slider_height)
{
    this->slider_height = slider_height;
}

// ʵ�ֻ������������X���꺯��
void Slider::setX(int x)
{
    this->x = x;
}

// ʵ�ֻ������������Y���꺯��
void Slider::setY(int y)
{
    this->y = y;
}

// ʵ�ֻ�����������ÿ�Ⱥ���
void Slider::setWidth(int width)
{
    this->width = width;
}

// ʵ�ֻ�����������ø߶Ⱥ���
void Slider::setHeight(int height)
{
    this->height = height;
}

// ʵ�ֻ�����������û��鰴ťX���꺯��
void Slider::setSliderButtonX(int slider_button_x)
{
	this->slider_button_x = slider_button_x;
}

// ʵ�ֻ�����������û��鰴ťY���꺯��
void Slider::setSliderButtonY(int slider_button_y)
{
	this->slider_button_y = slider_button_y;
}

// ʵ�ֻ�����������û��鰴ť��Ⱥ���
void Slider::setSliderButtonWidth(int slider_button_width)
{
	this->slider_button_width = slider_button_width;
}

// ʵ�ֻ�����������û��鰴ť�߶Ⱥ���
void Slider::setSliderButtonHeight(int slider_button_height)
{
	this->slider_button_height = slider_button_height;
}

// ʵ�ֻ��������������ɫ����
void Slider::setColor(int color)
{
    this->color = color;
}

// ʵ�ֻ�����������û�����ɫ����
void Slider::setSliderColor(int slider_color)
{
    this->slider_color = slider_color;
}

// ʵ�ֻ�����������û��鰴ť��ɫ����
void Slider::setSliderButtonColor(int slider_button_color)
{
	this->slider_button_color = slider_button_color;
}

// ʵ�ֻ�������������ı���ɫ����
void Slider::setTextColor(int text_color)
{
	this->text_color = text_color;
}

//ʵ�ֻ�����������û��������⺯��
void Slider::setSliderTitle(string slider_title)
{
	this->slider_title = slider_title;
}

//ʵ�ֻ�����������û���������ı�����
void Slider::setSliderLeftText(string slider_left_text)
{
	this->slider_left_text = slider_left_text;
}

//ʵ�ֻ�����������û������Ҳ��ı�����
void Slider::setSliderRightText(string slider_right_text)
{
	this->slider_right_text = slider_right_text;
}

//ʵ�ֻ�����������û�����ֵ�ı�����
void Slider::setSliderValueText(string slider_value_text)
{
	this->slider_value_text = slider_value_text;
}

//ʵ�ֻ�����������û���������X���꺯��
void Slider::setSliderTitleX(int slider_title_x)
{
	this->slider_title_x = slider_title_x;
}

//ʵ�ֻ�����������û���������ı�X���꺯��
void Slider::setSliderLeftTextX(int slider_left_text_x)
{
	this->slider_left_text_x = slider_left_text_x;
}

//ʵ�ֻ�����������û������Ҳ��ı�X���꺯��
void Slider::setSliderRightTextX(int slider_right_text_x)
{
	this->slider_right_text_x = slider_right_text_x;
}

//ʵ�ֻ�����������û�����ֵ�ı�X���꺯��
void Slider::setSliderValueTextX(int slider_value_text_x)
{
	this->slider_value_text_x = slider_value_text_x;
}

//ʵ�ֻ�����������û���������Y���꺯��
void Slider::setSliderTitleY(int slider_title_y)
{
	this->slider_title_y = slider_title_y;
}

//ʵ�ֻ�����������û���������ı�Y���꺯��
void Slider::setSliderLeftTextY(int slider_left_text_y)
{
	this->slider_left_text_y = slider_left_text_y;
}

//ʵ�ֻ�����������û������Ҳ��ı�Y���꺯��
void Slider::setSliderRightTextY(int slider_right_text_y)
{
	this->slider_right_text_y = slider_right_text_y;
}

//ʵ�ֻ�����������û�����ֵ�ı�Y���꺯��
void Slider::setSliderValueTextY(int slider_value_text_y)
{
	this->slider_value_text_y = slider_value_text_y;
}

//ʵ�ֻ�����������ı����꺯��
void Slider::calculateTextPosition()
{
	double slider_left_text_double = atof(slider_left_text.c_str());
	double slider_right_text_double = atof(slider_right_text.c_str());
	double slider_value_text_double = atof(slider_value_text.c_str());
	slider_value_text_double = slider_left_text_double + (slider_right_text_double - slider_left_text_double) * slider_width / width;
	setSliderValueText(to_string(slider_value_text_double));
	setSliderValueTextX(slider_button_x - text_size * slider_value_text.length() / 4);
	setSliderValueTextY(y + 3 * height / 2);
}