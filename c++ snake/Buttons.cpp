#include "Buttons.h"

Button defaultbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1, buttonwidth, 2 * buttongap1, "Default", WHITE, BLACK, buttongap1);
Button mapbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 4, buttonwidth, 2 * buttongap1, "Map", WHITE, BLACK, buttongap1);
Button randombutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 7, buttonwidth, 2 * buttongap1, "Random", WHITE, BLACK, buttongap1);
Button gravitybutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 10, buttonwidth, 2 * buttongap1, "Gravity", WHITE, BLACK, buttongap1);
Button backbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 13, buttonwidth, 2 * buttongap1, "Back", WHITE, BLACK, buttongap1);
Button playbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap, buttonwidth, 2 * buttongap, "Play", WHITE, BLACK, buttongap);
Button editbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, 4 * buttongap, buttonwidth, 2 * buttongap, "Edit", WHITE, BLACK, buttongap);
Button settingbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, 7 * buttongap, buttonwidth, 2 * buttongap, "Settings", WHITE, BLACK, buttongap);
Button quitbutton(WINDOW_WIDTH / 2 - buttonwidth / 2, 10 * buttongap, buttonwidth, 2 * buttongap, "Quit", WHITE, BLACK, buttongap);
Button savebutton(WINDOW_WIDTH - buttonwidth / 4, WINDOW_HEIGHT - buttongap1 / 2, buttonwidth / 4, buttongap1 / 2, "Save", WHITE, BLACK, buttongap1 / 4);
Button setwindowsizebutton(WINDOW_WIDTH / 2 - buttonwidth, 12 * buttongap1, 2 * buttonwidth, 2 * buttongap, "Set", WHITE, BLACK, buttongap);

Slider speedslider(WINDOW_WIDTH / 2 - buttonwidth, buttongap1 * 3, 2 * buttonwidth, buttongap1, BLACK, LIGHTGREEN, WHITE, WHITE, "Speed", "0.5", "1.5");
Slider difficultyslider(WINDOW_WIDTH / 2 - buttonwidth, buttongap1 * 8, 2 * buttonwidth, buttongap1, BLACK, LIGHTGREEN, WHITE, WHITE, "Difficulty", "0", "2");
string speedstr = "1";
string difficultystr = "1";

void initialButtons()
{
	defaultbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1, buttonwidth, 2 * buttongap1, "Default", WHITE, BLACK, buttongap1);
	mapbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 4, buttonwidth, 2 * buttongap1, "Map", WHITE, BLACK, buttongap1);
	randombutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 7, buttonwidth, 2 * buttongap1, "Random", WHITE, BLACK, buttongap1);
	gravitybutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 10, buttonwidth, 2 * buttongap1, "Gravity", WHITE, BLACK, buttongap1);
	backbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap1 * 13, buttonwidth, 2 * buttongap1, "Back", WHITE, BLACK, buttongap1);
	playbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, buttongap, buttonwidth, 2 * buttongap, "Play", WHITE, BLACK, buttongap);
	editbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, 4 * buttongap, buttonwidth, 2 * buttongap, "Edit", WHITE, BLACK, buttongap);
	settingbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, 7 * buttongap, buttonwidth, 2 * buttongap, "Settings", WHITE, BLACK, buttongap);
	quitbutton.setAll(WINDOW_WIDTH / 2 - buttonwidth / 2, 10 * buttongap, buttonwidth, 2 * buttongap, "Quit", WHITE, BLACK, buttongap);
	savebutton.setAll(WINDOW_WIDTH - buttonwidth / 4, WINDOW_HEIGHT - buttongap1 / 2, buttonwidth / 4, buttongap1 / 2, "Save", WHITE, BLACK, buttongap1 / 4);
	setwindowsizebutton.setAll(WINDOW_WIDTH / 2 - buttonwidth, 12 * buttongap1,2 * buttonwidth, 2 * buttongap, "Window Size", WHITE, BLACK, buttongap);
	
	speedslider.setAll(WINDOW_WIDTH / 2 - buttonwidth, buttongap1 * 3, 2 * buttonwidth, buttongap1, BLACK, LIGHTGREEN, WHITE, WHITE, "Speed", "0.5", "1.5", speedstr);
	difficultyslider.setAll(WINDOW_WIDTH / 2 - buttonwidth, buttongap1 * 8, 2 * buttonwidth, buttongap1, BLACK, LIGHTGREEN, WHITE, WHITE, "Difficulty", "0", "2", difficultystr);
}
