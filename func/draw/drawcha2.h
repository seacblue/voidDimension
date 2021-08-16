inline void drawCha2Func() {
	setcolor(EGERGBA(255, 255, 255, 255));
	int curY = 200;
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	for (re int i = 1; i <= 4; ++i, curY += (chaHeight + 15)) {
		if (infChaUnlocked[infChaFront + i - 1]) {
			color_t baseColor = RGB(0, 0, 0);
			color_t showColor = RGB(60, 60, 60);
			if (infChaTimes[infChaFront + i - 1]) {
				baseColor = RGB(0, 100, 0);
				showColor = RGB(34, 139, 34);
			}
			if (infChaIn[infChaFront + i - 1]) {
				baseColor = RGB(139, 69, 19);
				showColor = RGB(128, 128, 0);
			}
			if (infChaIn[8] &&
			        (infChaFront + i - 1 == 5 ||
			         infChaFront + i - 1 == 6)) {
				baseColor = RGB(255, 127, 80);
				showColor = RGB(255, 160, 122);
			}
			rectInfCha[i].set(chaRectGap, curY - 3, WINDOW_WIDTH - chaRectGap, curY + chaHeight,
			                  showColor, showColor,
			                  baseColor, true,
			                  RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                  RGB(0, 192, 0), RGB(255, 255, 255));
			rectInfCha[i].changeOnFrame(msg, false);
			if ((rectInfCha[i].isClickOn(msg)) &&
			        (!chaInfIns || infChaIn[infChaFront + i - 1])) {
				if (!infChaIn[infChaFront + i - 1])++chaInfIns;
				else --chaInfIns;
				infChaIn[infChaFront + i - 1] = !infChaIn[infChaFront + i - 1];
				maxGetInfPoint.setRealnum(0);
				infPlayingTick = 0;
				resetInf();
				beginChallengeTime = time(NULL);
				challengeTick = 0;

				if (chaInfIns) curMenu = 1;
			}
			rectInfCha[i].draw();

			xyprintf(WINDOW_WIDTH >> 1, curY + 10, "%s%d",
			         sent["infcha"].c_str(),
			         infChaFront + i - 1);
			std::string outputString;

			outputString = sent["infcha_" + intToStr(infChaFront + i - 1)] +
			               "||" +
			               sent["infcha_goal"] +
			               ICGoal[infChaFront + i - 1].print(2) +
			               sent["space"] + sent["void_point"];
			int chaWidth = WINDOW_WIDTH - (chaRectGap << 1);
			int height = rectp(-100, -100, chaWidth - 20, outputString);
			rectp(WINDOW_WIDTH >> 1,
			      ((rectCha[i].y1 + rectCha[i].y2 - height) >> 1) + 18,
			      chaWidth - 20, outputString);
		} else {
			rectInfCha[i].set(chaRectGap, curY - 3, WINDOW_WIDTH - chaRectGap, curY + chaHeight,
			                  RGB(60, 60, 60), RGB(60, 60, 60),
			                  RGB(20, 20, 20), true,
			                  RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                  RGB(0, 192, 0), RGB(255, 255, 255));
			rectInfCha[i].changeOnFrame(msg, false);
			rectInfCha[i].draw();
			xyprintf((rectInfCha[i].x1 + rectInfCha[i].x2) >> 1,
			         (rectInfCha[i].y1 + rectInfCha[i].y2) >> 1,
			         "%s%s%s",
			         sent["infcha_need1"].c_str(),
			         ICReq[infChaFront + i - 1].print(2).c_str(),
			         sent["infcha_need2"].c_str());
		}
	}

	rectChaPageLeft.changeOnFrame(msg, false);
	if (rectChaPageLeft.isClickOn(msg) && infChaFront == 5) {
		infChaFront = 1;
	}
	rectChaPageLeft.draw();
	if (infChaFront == 5)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectChaPageLeft.x1 + rectChaPageLeft.x2) >> 1,
	         (rectChaPageLeft.y1 + rectChaPageLeft.y2) >> 1,
	         sent["page_left"].c_str());
	setcolor(RGB(255, 255, 255));
	rectChaPageRight.changeOnFrame(msg, false);
	if (rectChaPageRight.isClickOn(msg) && infChaFront == 1) {
		infChaFront = 5;
	}
	rectChaPageRight.draw();
	if (infChaFront == 1)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectChaPageRight.x1 + rectChaPageRight.x2) >> 1,
	         (rectChaPageRight.y1 + rectChaPageRight.y2) >> 1,
	         sent["page_right"].c_str());
	setcolor(RGB(255, 255, 255));
}
