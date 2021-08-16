#include <graphics.h>
color_t *wbuf;
#include <ege/sys_edit.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <map>
#include <fstream>
#include <algorithm>
#include <cmath>

// -- Window
const int WINDOW_WIDTH = 960, WINDOW_HEIGHT = 640;
// -- FPS
int FPS = 60;

#include "header\bignum.h"
#include "header\rectpointset.h"
#include "header\generation.h"
#include "header\keycode.h"
#include "header\misc.h"
#include "header\slider.h"

#include "variable.h"

int main() {
	setcaption("Void Dimension");
	setinitmode(INIT_NOFORCEEXIT, 100, 100);
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, INIT_RENDERMANUAL);
	PIMAGE NULLL = NULL;
	wbuf = getbuffer(NULLL);

	setbkmode(TRANSPARENT);
	setcolor(RGB(255, 255, 255));
	if (lang == "en")setfont(16, 0, "consolas");
	if (lang == "ch")setfont(16, 0, "ºÚÌå");
	ege_enable_aa(true);
	curFontHeight = 18;
	randomize();

	beginPlayingTime = time(NULL);
	playingTick = 0;
	lastInfTime = time(NULL);
	infPlayingTick = 0;
	tempFile.open("tempfile.txt");

	readSent();
	preinit();
	initFunc();

	readSave();
	backwardComp();

	while (is_run()) {
		cleardevice();

		while (mousemsg()) {
			msg = getmouse();
		}
		stepFunc();
		if (optSleepMode) {
			drawSleep();
			delay_fps(60);
		} else {
			if (optManualMode) {
				drawManual();
				delay_fps(60);
			} else {
				drawFunc();
				delay_fps(FPS);
				//delay_fps(60);
			}
		}
	}
	return 0;
}
