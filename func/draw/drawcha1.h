inline void drawCha1Func() {
	setcolor(EGERGBA(255, 255, 255, 255));
	settextjustify(CENTER_TEXT, TOP_TEXT);
	int curY = 200;
	if (!infDimUnlocked) {
		xyprintf(WINDOW_WIDTH >> 1, curY - 46, "%s",
		         sent["cha_intro1"].c_str());
		xyprintf(WINDOW_WIDTH >> 1, curY - 28, "%s",
		         sent["cha_intro2"].c_str());
	}
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	for (re int i = 1; i <= 4; ++i, curY += (chaHeight + 15)) {
		color_t baseColor = RGB(0, 0, 0);
		color_t showColor = RGB(60, 60, 60);
		if (chaTimes[chaFront + i - 1]) {
			baseColor = RGB(0, 100, 0);
			showColor = RGB(34, 139, 34);
		}
		if (chaIn[chaFront + i - 1]) {
			baseColor = RGB(139, 69, 19);
			showColor = RGB(128, 128, 0);
		}
		if (chaIn[8] &&
		        (chaFront + i - 1 == 4 ||
		         chaFront + i - 1 == 6)) {
			baseColor = RGB(255, 127, 80);
			showColor = RGB(255, 160, 122);
		}
		rectCha[i].set(chaRectGap, curY - 3, WINDOW_WIDTH - chaRectGap, curY + chaHeight,
		               showColor, showColor,
		               baseColor, true,
		               RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
		               RGB(0, 192, 0), RGB(255, 255, 255));
		rectCha[i].changeOnFrame(msg, false);
		if ((rectCha[i].isClickOn(msg)) &&
		        (!chaIns || chaIn[chaFront + i - 1])) {
			if (!chaIn[chaFront + i - 1])++chaIns;
			else --chaIns;
			chaIn[chaFront + i - 1] = !chaIn[chaFront + i - 1];
			maxGetInfPoint.setRealnum(0);
			infPlayingTick = 0;
			resetInf();
			beginChallengeTime = time(NULL);
			challengeTick = 0;
			if (chaFront + i - 1 == 6 && chaIn[6])cha6capped.setRealnum(66666);
			if (chaFront + i - 1 == 8 && chaIn[8])voidPoint.setRealnum(2000);

			if (achIsOpen[8] && chaIn[chaFront + i - 1]) {
				voidPoint.setRealnum(2000000);
			}

			if (chaIns) curMenu = 1;
		}
		rectCha[i].draw();

		xyprintf(WINDOW_WIDTH >> 1, curY + 10, "%s%d",
		         sent["cha"].c_str(),
		         chaFront + i - 1);
		std::string outputString;

		if (chaFront + i - 1 == 1) {
			outputString = sent["cha_" + intToStr(chaFront + i - 1)] +
			               cha1Buff1.print(1) + sent["mult_x"] + sent["comma"] + sent["space"] +
			               cha1Buff2.print(1) + sent["mult_x"];
		} else if (chaFront + i - 1 == 5) {
			outputString = sent["cha_" + intToStr(chaFront + i - 1)] +
			               cha5Buff1.print(1) + sent["mult_x"] + sent["comma"] + sent["space"] +
			               cha5Buff2.print(1) + sent["mult_x"];
		} else {
			outputString = sent["cha_" + intToStr(chaFront + i - 1)];
		}
		int chaWidth = WINDOW_WIDTH - (chaRectGap << 1);
		int height = rectp(-100, -100, chaWidth - 20, outputString);
		rectp(WINDOW_WIDTH >> 1,
		      ((rectCha[i].y1 + rectCha[i].y2 - height) >> 1) + 18,
		      chaWidth - 20, outputString);
	}
	if (haveInfUpg[15]) {
		rectChaPageLeft.changeOnFrame(msg, false);
		if (rectChaPageLeft.isClickOn(msg) && chaFront == 5) {
			chaFront = 1;
		}
		rectChaPageLeft.draw();
		if (chaFront == 5)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectChaPageLeft.x1 + rectChaPageLeft.x2) >> 1,
		         (rectChaPageLeft.y1 + rectChaPageLeft.y2) >> 1,
		         sent["page_left"].c_str());
		setcolor(RGB(255, 255, 255));
		rectChaPageRight.changeOnFrame(msg, false);
		if (rectChaPageRight.isClickOn(msg) && chaFront == 1) {
			chaFront = 5;
		}
		rectChaPageRight.draw();
		if (chaFront == 1)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectChaPageRight.x1 + rectChaPageRight.x2) >> 1,
		         (rectChaPageRight.y1 + rectChaPageRight.y2) >> 1,
		         sent["page_right"].c_str());
		setcolor(RGB(255, 255, 255));
	}
}
