inline void drawInf5Func() {
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setFont(20);
	xyprintf(WINDOW_WIDTH >> 1, 200, sent["inf_ave_free"].c_str());
	xyprintf(WINDOW_WIDTH >> 2, 200, sent["inf_ave_pos"].c_str());
	xyprintf((WINDOW_WIDTH >> 1) + (WINDOW_WIDTH >> 2), 200, sent["inf_ave_neg"].c_str());
	setFontConsolas(35);
	setcolor(RGB(255, 255, 255));
	xyprintf(WINDOW_WIDTH >> 1, 230, intToStr(aveFreeEle).c_str());
	setcolor(RGB(186 + sin(playingTick / 13) * 10,
	             85 + sin(playingTick / 13) * 15,
	             211 + sin(playingTick / 13) * 15));
	xyprintf(WINDOW_WIDTH >> 2, 230, intToStr(avePosEle).c_str());
	setcolor(RGB(237 + sin(playingTick / 13) * 15,
	             149 + sin(playingTick / 13) * 5,
	             100 + sin(playingTick / 13) * 25));
	xyprintf((WINDOW_WIDTH >> 1) + (WINDOW_WIDTH >> 2), 230, intToStr(aveNegEle).c_str());
	setcolor(RGB(255, 255, 255));
	setFont(16);

	rectAveConvert1.changeOnFrame(msg, false);
	if (rectAveConvert1.isClickOn(msg)) {
		if (aveFreeEle > 0) {
			--aveFreeEle;
			++avePosEle;
		}
	}
	rectAveConvert1.draw();
	if (aveFreeEle > 0)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectAveConvert1.x1 + rectAveConvert1.x2) >> 1,
	         (rectAveConvert1.y1 + rectAveConvert1.y2) >> 1,
	         sent["pl_short"].c_str());

	rectAveConvert2.changeOnFrame(msg, false);
	if (rectAveConvert2.isClickOn(msg)) {
		if (aveFreeEle > 0) {
			--aveFreeEle;
			++aveNegEle;
		}
	}
	rectAveConvert2.draw();
	if (aveFreeEle > 0)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectAveConvert2.x1 + rectAveConvert2.x2) >> 1,
	         (rectAveConvert2.y1 + rectAveConvert2.y2) >> 1,
	         sent["pr_short"].c_str());

	rectAveConvert3.changeOnFrame(msg, false);
	if (rectAveConvert3.isClickOn(msg)) {
		if (avePosEle > 0) {
			--avePosEle;
			++aveFreeEle;
		}
	}
	rectAveConvert3.draw();
	if (avePosEle > 0)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectAveConvert3.x1 + rectAveConvert3.x2) >> 1,
	         (rectAveConvert3.y1 + rectAveConvert3.y2) >> 1,
	         sent["pr_short"].c_str());

	rectAveConvert4.changeOnFrame(msg, false);
	if (rectAveConvert4.isClickOn(msg)) {
		if (aveNegEle > 0) {
			--aveNegEle;
			++aveFreeEle;
		}
	}
	rectAveConvert4.draw();
	if (aveNegEle > 0)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectAveConvert4.x1 + rectAveConvert4.x2) >> 1,
	         (rectAveConvert4.y1 + rectAveConvert4.y2) >> 1,
	         sent["pl_short"].c_str());
	setcolor(RGB(255, 255, 255));

	Bignum nextEle;
	if (aveCurEle < maxAveEle)nextEle = aveEleCost[aveCurEle + 1];
	else nextEle.setBignum(1, 999999999);

	xyprintf(WINDOW_WIDTH >> 1,
	         270,
	         (sent["inf_ave_nextfree1"] +
	          nextEle.print(2) +
	          sent["inf_ave_nextfree2"]).c_str());

	for (re int i = 1; i <= 6; ++i) {
		settextjustify(CENTER_TEXT, TOP_TEXT);
		rectAveMilestone[i].changeOnFrame(msg, false);
		if (aveMsUnlock[i]) {
			rectAveMilestone[i].baseColor = RGB(0, 128, 128);
			rectAveMilestone[i].trueColor = RGB(0, 139, 139);
			rectAveMilestone[i].falseColor = RGB(0, 139, 139);
		} else {
			rectAveMilestone[i].baseColor = RGB(0, 0, 0);
			rectAveMilestone[i].trueColor = RGB(64, 64, 64);
			rectAveMilestone[i].falseColor = RGB(64, 64, 64);
		}
		rectAveMilestone[i].draw();
		std::string infupgString = "inf_ave_ms" + intToStr(i);
		std::string specUpgString;
		specUpgString.clear();
		if (i == 1) {
			specUpgString = aveMs1Reward.print(2) + sent["mult_x"];
		}
		if (i == 2) {
			specUpgString = aveMs2Reward.print(2) + sent["mult_x"];
		}
		if (i == 3) {
			specUpgString = aveMs3Reward.print(2) + sent["mult_x"];
		}
		if (i == 4) {
			specUpgString = doubleToStr(aveMs4Reward,2);
		}
		std::string outputString;
		outputString = sent["req_x"];
		if (aveMsNeedPos[i]) {
			outputString += intToStr(aveMsNeedPos[i]) +
			                sent["space"] +
			                sent["inf_ave_pos"];
		}
		if (aveMsNeedPos[i] && aveMsNeedNeg[i]) {
			outputString += sent["comma"] +
			                sent["space"];
		}
		if (aveMsNeedNeg[i]) {
			outputString += intToStr(aveMsNeedNeg[i]) +
			                sent["space"] +
			                sent["inf_ave_neg"];
		}
		outputString += "||" +
		                sent[infupgString] +
		                specUpgString;
		int height = rectp(-100, -100, infUpgRectWidth - 20, outputString);

		rectp((rectAveMilestone[i].x1 + rectAveMilestone[i].x2) >> 1,
		      (rectAveMilestone[i].y1 + rectAveMilestone[i].y2 - height) >> 1,
		      infUpgRectWidth - 20, outputString);
		if (keystate(VK_SHIFT)) {
			settextjustify(LEFT_TEXT, TOP_TEXT);
			xyprintf(rectAveMilestone[i].x1, rectAveMilestone[i].y1 - 18,
			         (sent["inf_ave_ms"] + intToStr(i)).c_str());
		}
	}
}
