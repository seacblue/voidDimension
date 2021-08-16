inline void drawOptFunc() {
	if (curMenu == 2) {
		SliderFPS.setVisible(true);
		settextjustify(CENTER_TEXT, TOP_TEXT);
		int curX = optRectGap, curY = 160;
		for (re int i = 1; i <= maxOpt; ++i) {
			std::string optString = "opt_" + intToStr(i);
			bool showOpt = true;
			if (i == 4)showOpt = false;
			if (i == 6 && optShowLang)showOpt = false;
			if (showOpt) {
				rectOpt[i].changeOnFrame(msg, false);
				if (rectOpt[i].isClickOn(msg)) {
					if (i == 1) {
						save(saveFileName);
						autoSaveTick = 0;
						pushReminderStack(0, RGB(170, 178, 32));
					}
					if (i == 2) {
						//load(saveFileName);
						initFunc();
						if (!load(saveFileName))preinit();
						pushReminderStack(-1, RGB(60, 120, 150));
					}
					if (i == 3) {
						optShowLang = !optShowLang;
					}
					if (i == 5) {
						optSleepMode = true;
					}
					if (i == 6) {
						optManualMode = true;
					}
				}
			}
			rectOpt[i].draw();
			if (i != 4) {
				rectp(curX + (optRectWidth >> 1), curY + 27 - (optHeight[i] >> 1),
				      optRectWidth - 32, sent[optString]);
			} else {
				rectp(curX + (optRectWidth >> 1), curY + 27 - (optHeight[i] >> 1) - 8,
				      optRectWidth - 32, sent[optString]);
			}

			if (!(i % 3)) {
				curY += 60;
				curX = optRectGap;
			} else {
				curX += optRectWidth + optRectGap;
			}
		}

		if (optShowLang) {
			settextjustify(CENTER_TEXT, CENTER_TEXT);
			for (re int i = 1; i <= maxLang; ++i) {
				std::string langString;
				std::string curLang;
				if (i == 1)curLang = "ch";
				if (i == 2)curLang = "en";
				langString = "opt_lang_" + curLang;
				rectLang[i].changeOnFrame(msg, false);
				if (rectLang[i].isClickOn(msg)) {
					if (curLang != lang) {
						lang = curLang;
						readSent();
						aftinit();
						load(saveFileName);
					}
				}
				rectLang[i].draw();
				rectp((rectLang[i].x1 + rectLang[i].x2) >> 1,
				      (rectLang[i].y1 + rectLang[i].y2) >> 1,
				      (rectLang[i].x2 - rectLang[i].x1) - 32, sent[langString]);
			}
		}

		SliderFPS.print(msg);
		SliderFPS.updata(msg);
		SliderFPS.setName("FPS: " + intToStr(FPS));
	}
}
