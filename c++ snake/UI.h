#ifndef UI_H
#define UI_H

#include "FileIO.h"

#define MIN_WIDTH 400
#define MIN_HEIGHT 300

using namespace std;

//����ȫ�ֱ����������Ʋ���
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

void setWindowSize(int width, int height);  //���ô��ڵĿ�Ⱥ͸߶�
void setMaxWindowSize();  //��ȡ��Ļ�����ڵ�����Ⱥ͸߶�

void getMousePosition();  //��ȡ����λ��

//���尴ť��
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
	void draw();  //���ư�ť
	bool isClicked();  //�жϰ�ť�Ƿ񱻵��
	bool boolIsMouseOn();  //�ж�����Ƿ��ڰ�ť��
	void setAll(int x, int y, int width, int height, string text, int color, int text_color, int text_size);  //���ð�ť�����в���
};

//���廬������
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
	void draw();  //���ƻ�����
	bool isClicked();  //�жϻ������Ƿ񱻵��
	bool boolIsMouseOn();  //�ж�����Ƿ��ڻ�������
	string loadValueStr();  //��ȡ������������ֵ
	void calculateTextPosition();  //�����ı���λ��
	void setAll(int x, int y, int width, int height, int color, int slider_color, int slider_button_color, int text_color, string slider_title, string slider_left_text, string slider_right_text, string slider_value_text);  //���û����������в���
};

#endif UI_H