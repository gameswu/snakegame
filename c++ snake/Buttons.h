#ifndef BUTTONS_H
#define BUTTONS_H

#include "UI.h"

extern Button playbutton;
extern Button editbutton;
extern Button settingbutton;
extern Button quitbutton;
extern Button defaultbutton;
extern Button mapbutton;
extern Button randombutton;
extern Button gravitybutton;
extern Button backbutton;
extern Button savebutton;
extern Button setwindowsizebutton;

extern Slider speedslider;
extern Slider difficultyslider;

extern string speedstr;
extern string difficultystr;

void initialButtons();  //初始化按钮和滑动条

#endif TITLEPAGE_H