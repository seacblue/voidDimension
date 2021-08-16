inline void drawMenuFunc() {
	settextjustify(LEFT_TEXT, TOP_TEXT);
	int totWidth = -10;
	for (re int i = 1; i <= maxMenu; ++i) {
		if (menuIsOpen[i]) {
			totWidth += menuWidth[i] + 10;
		}
	}
	int beginX = (WINDOW_WIDTH - totWidth) >> 1;
	for (re int i = 1; i <= maxMenu; ++i) {
		if (menuIsOpen[i]) {
			color_t baseC = RGB(0, 0, 0);
			if (i == curMenu) {
				baseC = RGB(70, 70, 70);
			}
			rectMenu[i].set(beginX - 3, 120, beginX + menuWidth[i] + 3, 140,
			                RGB(100, 100, 100), RGB(100, 100, 100), baseC);
			rectMenu[i].changeOnFrame(msg, false);
			rectMenu[i].draw();
			xyprintf(beginX - 3, 122, "%s", menuText[i]);

			beginX += menuWidth[i] + 10;
			rectMenu[i].changeOnFrame(msg, false);
			if (rectMenu[i].isClickOn(msg)) {
				curMenu = i;
			}
		}
	}

	if (curMenu == 1) {
		totWidth = -10;
		for (re int i = 1; i <= max1Menu; ++i) {
			if (menu1IsOpen[i]) {
				totWidth += menu1Width[i] + 10;
			}
		}
		beginX = (WINDOW_WIDTH - totWidth) >> 1;
		for (re int i = 1; i <= max1Menu; ++i) {
			if (menu1IsOpen[i]) {
				color_t baseC = RGB(0, 0, 0);
				if (i == cur1Menu) {
					baseC = RGB(70, 70, 70);
				}
				rect1Menu[i].set(beginX - 3, 150, beginX + menu1Width[i] + 3, 170,
				                 RGB(100, 100, 100), RGB(100, 100, 100), baseC);
				rect1Menu[i].changeOnFrame(msg, false);
				rect1Menu[i].draw();
				xyprintf(beginX - 3, 152, "%s", menu1Text[i]);

				beginX += menu1Width[i] + 10;
				rect1Menu[i].changeOnFrame(msg, false);
				if (rect1Menu[i].isClickOn(msg)) {
					cur1Menu = i;
				}
			}
		}
	}

	if (curMenu == 3) {
		totWidth = -10;
		for (re int i = 1; i <= max3Menu; ++i) {
			if (menu3IsOpen[i]) {
				totWidth += menu3Width[i] + 10;
			}
		}
		beginX = (WINDOW_WIDTH - totWidth) >> 1;
		for (re int i = 1; i <= max3Menu; ++i) {
			if (menu3IsOpen[i]) {
				color_t baseC = RGB(0, 0, 0);
				if (i == cur3Menu) {
					baseC = RGB(70, 70, 70);
				}
				rect3Menu[i].set(beginX - 3, 150, beginX + menu3Width[i] + 3, 170,
				                 RGB(100, 100, 100), RGB(100, 100, 100), baseC);
				rect3Menu[i].changeOnFrame(msg, false);
				rect3Menu[i].draw();
				xyprintf(beginX - 3, 152, "%s", menu3Text[i]);

				beginX += menu3Width[i] + 10;
				rect3Menu[i].changeOnFrame(msg, false);
				if (rect3Menu[i].isClickOn(msg)) {
					cur3Menu = i;
				}
			}
		}
	}

	if (curMenu == 5 && infDimUnlocked) {
		totWidth = -10;
		for (re int i = 1; i <= max5Menu; ++i) {
			if (menu5IsOpen[i]) {
				totWidth += menu5Width[i] + 10;
			}
		}
		beginX = (WINDOW_WIDTH - totWidth) >> 1;
		for (re int i = 1; i <= max5Menu; ++i) {
			if (menu5IsOpen[i]) {
				color_t baseC = RGB(0, 0, 0);
				if (i == cur5Menu) {
					baseC = RGB(70, 70, 70);
				}
				rect5Menu[i].set(beginX - 3, 150, beginX + menu5Width[i] + 3, 170,
				                 RGB(100, 100, 100), RGB(100, 100, 100), baseC);
				rect5Menu[i].changeOnFrame(msg, false);
				rect5Menu[i].draw();
				xyprintf(beginX - 3, 152, "%s", menu5Text[i]);

				beginX += menu5Width[i] + 10;
				rect5Menu[i].changeOnFrame(msg, false);
				if (rect5Menu[i].isClickOn(msg)) {
					cur5Menu = i;
				}
			}
		}
	}

	if (curMenu == 6) {
		totWidth = -10;
		for (re int i = 1; i <= max6Menu; ++i) {
			if (menu6IsOpen[i]) {
				totWidth += menu6Width[i] + 10;
			}
		}
		beginX = (WINDOW_WIDTH - totWidth) >> 1;
		for (re int i = 1; i <= max6Menu; ++i) {
			if (menu6IsOpen[i]) {
				color_t baseC = RGB(0, 0, 0);
				if (i == cur6Menu) {
					baseC = RGB(70, 70, 70);
				}
				rect6Menu[i].set(beginX - 3, 150, beginX + menu6Width[i] + 3, 170,
				                 RGB(100, 100, 100), RGB(100, 100, 100), baseC);
				rect6Menu[i].changeOnFrame(msg, false);
				rect6Menu[i].draw();
				xyprintf(beginX - 3, 152, "%s", menu6Text[i]);

				beginX += menu6Width[i] + 10;
				rect6Menu[i].changeOnFrame(msg, false);
				if (rect6Menu[i].isClickOn(msg)) {
					cur6Menu = i;
				}
			}
		}
	}
}
