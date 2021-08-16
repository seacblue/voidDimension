inline void drawInf1Func() {
	settextjustify(CENTER_TEXT, TOP_TEXT);
	if (infUpgPage == 1) {
		for (re int i = 1; i <= 9; ++i) {
			settextjustify(CENTER_TEXT, TOP_TEXT);
			bool boolOper = false;
			if (infPoint >= infUpgCost[i])boolOper = true;
			rectInfUpg[i].changeOnFrame(msg, false, boolOper && (!haveInfUpg[i]));
			if (rectInfUpg[i].isClickOn(msg)) {
				if (boolOper && !haveInfUpg[i]) {
					infPoint = infPoint - infUpgCost[i];
					haveInfUpg[i] = true;
					if (i == 2) {
						dimMultMult = 2.2;
						updateDimMult();
					}
					if (i == 7) {
						colMult = 2.5;
						updateColMult();
					}
					if (i == 9) {
						menuIsOpen[5] = true;
						menu3IsOpen[2] = true;
						menu5IsOpen[1] = true;
					}
				}
			}
			if (haveInfUpg[i]) {
				rectInfUpg[i].baseColor = RGB(0, 110, 0);
				rectInfUpg[i].trueColor = RGB(0, 140, 0);
				rectInfUpg[i].falseColor = RGB(0, 140, 0);
			}
			rectInfUpg[i].draw();
			std::string infupgString = "infupg_" + intToStr(i);
			std::string specUpgString;
			specUpgString.clear();
			if (i == 3)specUpgString = doubleToStr(1 + infUpg3Reward, 2) + sent["mult_x"];
			if (i == 4 || i == 5 || i == 6) {
				Bignum showRew = infUpg4Reward + 1.0;
				specUpgString = showRew.print(1) + sent["mult_x"];
			}
			std::string outputString;
			outputString = sent[infupgString] +
			               specUpgString +
			               "||" +
			               sent["cost_x"] +
			               doubleToStr(infUpgCost[i], 0) +
			               sent["space"] +
			               sent["IP"];
			int height = rectp(-100, -100, infUpgRectWidth - 20, outputString);

			rectp((rectInfUpg[i].x1 + rectInfUpg[i].x2) >> 1,
			      (rectInfUpg[i].y1 + rectInfUpg[i].y2 - height) >> 1,
			      infUpgRectWidth - 20, outputString);
			if (keystate(VK_SHIFT)) {
				settextjustify(LEFT_TEXT, TOP_TEXT);
				xyprintf(rectInfUpg[i].x1, rectInfUpg[i].y1 - 18,
				         (sent["infupg_short"] + intToStr(i)).c_str());
			}
		}
	} else {
		for (re int i = 10; i <= 15; ++i) {
			settextjustify(CENTER_TEXT, TOP_TEXT);
			bool boolOper = false;
			if (infPoint >= infUpgCost[i])boolOper = true;
			rectInfUpg[i].changeOnFrame(msg, false, boolOper && (!haveInfUpg[i]));
			if (rectInfUpg[i].isClickOn(msg)) {
				if (boolOper && !haveInfUpg[i]) {
					infPoint = infPoint - infUpgCost[i];
					haveInfUpg[i] = true;
				}
			}
			if (haveInfUpg[i]) {
				rectInfUpg[i].baseColor = RGB(0, 110, 0);
				rectInfUpg[i].trueColor = RGB(0, 140, 0);
				rectInfUpg[i].falseColor = RGB(0, 140, 0);
			}
			rectInfUpg[i].draw();
			std::string infupgString = "infupg_" + intToStr(i);
			std::string specUpgString;
			specUpgString.clear();
			if (i == 11) {
				Bignum showReward = infUpg11Reward + 1.0;
				specUpgString = doubleToStr(infUpg11Expo, 2) +
				                sent["infupg_11_x"] +
				                showReward.print(1) +
				                'x';
			}
			if (i == 12 || i == 13 || i == 14) {
				Bignum showReward = infUpg12Reward + 1.0;
				specUpgString += doubleToStr(infUpg12Expo, 2) +
				                 sent["infupg_11_x"] +
				                 showReward.print(1) +
				                 'x';
			}
			std::string outputString;
			outputString = sent[infupgString] +
			               specUpgString +
			               "||" +
			               sent["cost_x"] +
			               doubleToStr(infUpgCost[i], 0) +
			               sent["space"] +
			               sent["IP"];
			int height = rectp(-100, -100, infUpgRectWidth - 20, outputString);

			rectp((rectInfUpg[i].x1 + rectInfUpg[i].x2) >> 1,
			      (rectInfUpg[i].y1 + rectInfUpg[i].y2 - height) >> 1,
			      infUpgRectWidth - 20, outputString);
			if (keystate(VK_SHIFT)) {
				settextjustify(LEFT_TEXT, TOP_TEXT);
				xyprintf(rectInfUpg[i].x1, rectInfUpg[i].y1 - 18,
				         (sent["infupg_short"] + intToStr(i)).c_str());
			}
		}
	}
	settextjustify(CENTER_TEXT, TOP_TEXT);
	bool boolOper = false;
	if (infPoint >= infRebuyableUpgCost)boolOper = true;
	rectInfRebuyable.changeOnFrame(msg, false, boolOper);
	if (rectInfRebuyable.isClickOn(msg)) {
		if (boolOper) {
			infPoint = infPoint - infRebuyableUpgCost;
			IPRebuyMult = IPRebuyMult * infRebuyableUpgAffect;
			infRebuyableUpgCost = infRebuyableUpgCost * 10;
		}
	}
	rectInfRebuyable.draw();
	std::string outputString = sent["infupg_rebuyable"] +
	                           IPRebuyMult.print() + sent["mult_x"] +
	                           "||" +
	                           sent["cost_x"] +
	                           infRebuyableUpgCost.print() +
	                           sent["space"] +
	                           sent["IP"];
	int rebuyableUpgWidth = rectInfRebuyable.x2 - rectInfRebuyable.x1;
	int height = rectp(-100, -100, rebuyableUpgWidth - 20, outputString);

	rectp((rectInfRebuyable.x1 + rectInfRebuyable.x2) >> 1,
	      (rectInfRebuyable.y1 + rectInfRebuyable.y2 - height) >> 1,
	      rebuyableUpgWidth - 20, outputString);

	if (chaTimes[4]) {
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		rectInfUpgPL.changeOnFrame(msg, false);
		if (rectInfUpgPL.isClickOn(msg)) {
			if (infUpgPage == 2)infUpgPage = 1;
		}
		rectInfUpgPL.draw();
		if (infUpgPage == 2)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectInfUpgPL.x1 + rectInfUpgPL.x2) >> 1,
		         (rectInfUpgPL.y1 + rectInfUpgPL.y2) >> 1,
		         sent["page_left"].c_str());
		setcolor(RGB(255, 255, 255));
		rectInfUpgPR.changeOnFrame(msg, false);
		if (rectInfUpgPR.isClickOn(msg)) {
			if (infUpgPage == 1)infUpgPage = 2;
		}
		rectInfUpgPR.draw();
		if (infUpgPage == 1)setcolor(RGB(255, 255, 255));
		else setcolor(RGB(128, 128, 128));
		xyprintf((rectInfUpgPR.x1 + rectInfUpgPR.x2) >> 1,
		         (rectInfUpgPR.y1 + rectInfUpgPR.y2) >> 1,
		         sent["page_right"].c_str());
		setcolor(RGB(255, 255, 255));
	}
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1,
	         WINDOW_HEIGHT - 26,
	         sent["inf_short_intro"].c_str());
}
