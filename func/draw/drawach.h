inline void drawAchFunc() {
	if (curMenu == 4) {
		char pString[MAXLEN];
		int showFrom, showUnt;
		showFrom = (curAchPage << 3) - 7;
		showUnt = (curAchPage << 3);
		if (showUnt > maxAch) {
			showUnt = maxAch;
		}
		int curY = 180;
		for (re int i = showFrom, ptr = 1; i <= showUnt; ++i, ++ptr, curY += 30) {
			color_t baseC = RGB(0, 0, 0);
			if (i == curShowAch) {
				baseC = RGB(70, 70, 70);
			}
			rectAch[ptr].set(60, curY - 10 + 3, WINDOW_WIDTH - 60 + 1, curY + 20 - 2,
			                 RGB(100, 100, 100), RGB(100, 100, 100), baseC, false);
			rectAch[ptr].changeOnFrame(msg, false);
			rectAch[ptr].draw();
			if (rectAch[ptr].isClickOn(msg)) {
				if (i == curShowAch) {
					curShowAch = 0;
				} else {
					curShowAch = i;
				}
			}

			std::string achString = "ach_name_" + intToStr(i);
			sprintf(pString, "%s", sent[achString].c_str());
			if (i != showUnt) {
				line(60, curY + 20, WINDOW_WIDTH - 60, curY + 20);
			}
			if (achIsOpen[i]) {
				setcolor(RGB(50, 205, 50));
			} else {
				setcolor(RGB(255, 255, 255));
			}
			xyprintf(80, curY - 2, "%s", sent[achString].c_str());
			setcolor(RGB(255, 255, 255));
		}
		curY = 180 + 30 * 8;
		line(60, curY + 20, WINDOW_WIDTH - 60, curY + 20);
		line(60, curY + 28, WINDOW_WIDTH - 60, curY + 28);
		if (curShowAch) {
			std::string achString = "ach_name_" + intToStr(curShowAch);
			xyprintf(80, curY + 35, "%s", sent[achString].c_str());
			achString = "ach_info_" + intToStr(curShowAch);
			rectp(80, curY + 55, WINDOW_WIDTH - (80 << 1), sent[achString]);
			//tempFile<<achString<<' '<<sent[achString]<<std::endl;
		}
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		rectAchPL.changeOnFrame(msg, false);
		if (rectAchPL.isClickOn(msg)) {
			if (curAchPage > 1)--curAchPage;
		}
		rectAchPL.draw();
		if (curAchPage > 1)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectAchPL.x1 + rectAchPL.x2) >> 1,
		         (rectAchPL.y1 + rectAchPL.y2) >> 1,
		         sent["page_left"].c_str());
		setcolor(RGB(255, 255, 255));
		rectAchPR.changeOnFrame(msg, false);
		if (rectAchPR.isClickOn(msg)) {
			if (curAchPage < maxAchPage)++curAchPage;
		}
		rectAchPR.draw();
		if (curAchPage < maxAchPage)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectAchPR.x1 + rectAchPR.x2) >> 1,
		         (rectAchPR.y1 + rectAchPR.y2) >> 1,
		         sent["page_right"].c_str());
		setcolor(RGB(255, 255, 255));
	}
}
