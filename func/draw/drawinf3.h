inline void drawInf3Func() {
	int unt = 6;
	if (!infDimUnlocked) unt = 2;
	for (re int i = 1; i <= unt; ++i) {
		settextjustify(CENTER_TEXT, TOP_TEXT);
		bool boolOper = false;
		if (infPoint >= infBUpgCost[i])boolOper = true;
		rectBInfUpg[i].changeOnFrame(msg, false, boolOper && (!haveBInfUpg[i]));
		if (rectBInfUpg[i].isClickOn(msg)) {
			if (boolOper && !haveBInfUpg[i]) {
				infPoint = infPoint - infBUpgCost[i];
				haveBInfUpg[i] = true;
				if (i == 3 && !achIsOpen[10])pushAch(10);
				if (i == 5) {
					colMult = 4.00001;
					updateColMult();
				}
			}
		}
		if (haveBInfUpg[i]) {
			rectBInfUpg[i].baseColor = RGB(0, 110, 0);
			rectBInfUpg[i].trueColor = RGB(0, 140, 0);
			rectBInfUpg[i].falseColor = RGB(0, 140, 0);
		}
		rectBInfUpg[i].draw();
		std::string infupgString = "infbupg_" + intToStr(i);
		std::string specUpgString;
		specUpgString.clear();
		if (i == 1) {
			Bignum showReward = infBUpg1Reward + 1.0;
			specUpgString = showReward.print(1) + sent["mult_x"];
		}
		if (i == 2) {
			Bignum showReward = infBUpg2Reward + 1.0;
			specUpgString = showReward.print(1) + sent["mult_x"];
			if (infBUpg2RewardHardcapped) {
				specUpgString += sent["hardcapped"];
			}
		}

		std::string outputString;
		outputString = sent[infupgString] +
		               specUpgString +
		               "||" +
		               sent["cost_x"] +
		               infBUpgCost[i].print() +
		               sent["space"] +
		               sent["IP"];
		int height = rectp(-100, -100, infUpgRectWidth - 20, outputString);

		rectp((rectBInfUpg[i].x1 + rectBInfUpg[i].x2) >> 1,
		      (rectBInfUpg[i].y1 + rectBInfUpg[i].y2 - height) >> 1,
		      infUpgRectWidth - 20, outputString);
		if (keystate(VK_SHIFT)) {
			settextjustify(LEFT_TEXT, TOP_TEXT);
			xyprintf(rectBInfUpg[i].x1, rectBInfUpg[i].y1 - 18,
			         (sent["infbupg_short"] + intToStr(i)).c_str());
		}
	}
	settextjustify(CENTER_TEXT, TOP_TEXT);
	if (infPoint >= infBRebuyableUpgCost) {
		rectBInfRebuyable.baseColor = RGB(0, 0, 0);
		rectBInfRebuyable.trueColor = RGB(100, 100, 100);
		rectBInfRebuyable.falseColor = RGB(100, 100, 100);
		rectBInfRebuyable.borderColor = RGB(0, 110, 0);
		rectBInfRebuyable.borderTrueColor = RGB(255, 255, 255);
		rectBInfRebuyable.borderFalseColor = RGB(255, 255, 255);
	} else {
		rectBInfRebuyable.baseColor = RGB(0, 0, 0);
		rectBInfRebuyable.trueColor = RGB(64, 64, 64);
		rectBInfRebuyable.falseColor = RGB(64, 64, 64);
		rectBInfRebuyable.borderColor = RGB(255, 255, 255);
		rectBInfRebuyable.borderTrueColor = RGB(255, 255, 255);
		rectBInfRebuyable.borderFalseColor = RGB(255, 255, 255);
	}
	if (dimCostGrow <= 5.01) {
		rectBInfRebuyable.baseColor = RGB(0, 110, 0);
		rectBInfRebuyable.trueColor = RGB(0, 140, 0);
		rectBInfRebuyable.falseColor = RGB(0, 140, 0);
		rectBInfRebuyable.borderColor = RGB(255, 255, 255);
		rectBInfRebuyable.borderTrueColor = RGB(255, 255, 255);
		rectBInfRebuyable.borderFalseColor = RGB(255, 255, 255);
	}
	bool boolOper = false;
	if (infPoint >= infBRebuyableUpgCost && dimCostGrow > 5.01)boolOper = true;
	rectBInfRebuyable.changeOnFrame(msg, boolOper, false);
	if (rectBInfRebuyable.isClickOn(msg)) {
		if (boolOper) {
			infPoint = infPoint - infBRebuyableUpgCost;
			dimCostGrow -= 0.5;
			infBRebuyableUpgCost = infBRebuyableUpgCost * infBRebuyableUpgCostMult;
		}
	}
	rectBInfRebuyable.draw();
	std::string outputString = sent["infbupg_rebuyable"] +
	                           doubleToStr(dimCostGrow, 2);
	if (dimCostGrow > 5.01) {
		outputString += "||" +
		                sent["cost_x"] +
		                infBRebuyableUpgCost.print() +
		                sent["space"] +
		                sent["IP"];
	}
	int rebuyableUpgWidth = rectBInfRebuyable.x2 - rectBInfRebuyable.x1;
	int height = rectp(-100, -100, rebuyableUpgWidth - 20, outputString);

	rectp((rectBInfRebuyable.x1 + rectBInfRebuyable.x2) >> 1,
	      (rectBInfRebuyable.y1 + rectBInfRebuyable.y2 - height) >> 1,
	      rebuyableUpgWidth - 20, outputString);

	if (!infDimUnlocked) {
		bool boolOper = false;
		if (voidPoint >= infBUnlockCost)boolOper = true;
		rectBInfUnlock.changeOnFrame(msg, false, boolOper);
		if (rectBInfUnlock.isClickOn(msg)) {
			if (boolOper) {
				voidPoint = voidPoint - infBUnlockCost;
				infDimUnlocked = true;
				menu1IsOpen[2] = true;
			}
		}
		rectBInfUnlock.draw();
		std::string outputString = sent["infbupg_unlock"] +
		                           "||" +
		                           sent["cost_x"] +
		                           infBUnlockCost.print() +
		                           sent["space"] +
		                           sent["void_point"];
		int rebuyableUpgWidth = rectBInfUnlock.x2 - rectBInfUnlock.x1;
		int height = rectp(-100, -100, rebuyableUpgWidth - 20, outputString);

		rectp((rectBInfUnlock.x1 + rectBInfUnlock.x2) >> 1,
		      (rectBInfUnlock.y1 + rectBInfUnlock.y2 - height) >> 1,
		      rebuyableUpgWidth - 20, outputString);
	}
}
