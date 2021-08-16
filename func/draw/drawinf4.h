inline void drawInf4Func() {
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, 190, (
	             sent["inf_vl_mile"] +
	             bignumToLength(voidLight)).c_str());
	xyprintf(WINDOW_WIDTH >> 1, 210, (
	             sent["inf_vl_speed"] +
	             bignumToLength(voidLightRealSec) +
	             sent["ps"]).c_str());

	Bignum canGetSpeed(0, 0);
	if (voidLightRealCanGet > voidLightRealSec) {
		canGetSpeed = voidLightRealCanGet - voidLightRealSec;
	}

	voidLightSacSet.updata(msg);
	voidLightSacSet.print(msg);
	voidLightSacrifice = voidLightSacSet.getValue();

	settextjustify(CENTER_TEXT, CENTER_TEXT);

	xyprintf(WINDOW_WIDTH >> 1, 230, (
	             sent["inf_vl_sac1"] +
	             doubleToStr(voidLightSacrifice, 1) +
	             sent["inf_vl_sac2"] +
	             voidLightSacIP.print(2) +
	             sent["inf_vl_sac3"] +
	             bignumToLength(canGetSpeed) +
	             sent["ps"] +
	             sent["inf_vl_sac4"]).c_str());

	rectVoidLightSac.changeOnFrame(msg, false);
	if (rectVoidLightSac.isClickOn(msg)) {
		infPoint = infPoint - voidLightSacIP;
		if (voidLightCanGet > voidLightSec) {
			voidLightSec = voidLightCanGet;
		}
	}
	rectVoidLightSac.draw();
	xyprintf((rectVoidLightSac.x1 + rectVoidLightSac.x2) >> 1,
	         (rectVoidLightSac.y1 + rectVoidLightSac.y2) >> 1,
	         sent["inf_vl_sac"].c_str());

	for (re int i = vlufront; i < vlufront + 6; ++i) {
		settextjustify(CENTER_TEXT, TOP_TEXT);
		bool boolOper = false;
		if (voidLight >= voidLightUpgCost[i])boolOper = true;
		rectVoidLightUpg[i].changeOnFrame(msg, false, boolOper && (!voidLightUpgBought[i]));
		if (rectVoidLightUpg[i].isClickOn(msg)) {
			if (boolOper == true) {
				voidLight = voidLight - voidLightUpgCost[i];
				voidLightUpgBought[i] = true;
			}
		}
		if (voidLightUpgBought[i]) {
			rectVoidLightUpg[i].baseColor = RGB(0, 110, 0);
			rectVoidLightUpg[i].trueColor = RGB(0, 140, 0);
			rectVoidLightUpg[i].falseColor = RGB(0, 140, 0);
		}
		rectVoidLightUpg[i].draw();
		std::string infupgString = "inf_vl_upg" + intToStr(i);
		std::string specUpgString;
		specUpgString.clear();
		if (i == 3) {
			specUpgString = voidLightUpg3RealReward.print(2) + sent["mult_x"];
		}
		if (i == 4) {
			specUpgString = voidLightUpg4Reward.print(2) + sent["mult_x"];
		}
		if (i == 6) {
			Bignum showSpd = maxInfSpd;
			specUpgString = showSpd.print(2) + sent["space"] + sent["IP"] + sent["pers"];
		}
		if (i == 9) {
			Bignum showReward1 = infBUpg6Reward1 + 1.0;
			Bignum showReward2 = infBUpg6Reward2 + 1.0;
			Bignum showReward3 = infBUpg6Reward3 + 1.0;
			specUpgString =
			    showReward1.print(1) + sent["mult_x"] + sent["comma"] + sent["space"] +
			    showReward2.print(1) + sent["mult_x"] + sent["comma"] + sent["space"] +
			    showReward3.print(1) + sent["mult_x"];
		}
		std::string outputString;
		outputString = sent[infupgString] +
		               specUpgString +
		               "||" +
		               sent["cost_x"] +
		               bignumToLength(voidLightUpgCost[i]);
		int height = rectp(-100, -100, infUpgRectWidth - 20, outputString);

		rectp((rectVoidLightUpg[i].x1 + rectVoidLightUpg[i].x2) >> 1,
		      (rectVoidLightUpg[i].y1 + rectVoidLightUpg[i].y2 - height) >> 1,
		      infUpgRectWidth - 20, outputString);
		if (keystate(VK_SHIFT)) {
			settextjustify(LEFT_TEXT, TOP_TEXT);
			xyprintf(rectVoidLightUpg[i].x1, rectVoidLightUpg[i].y1 - 18,
			         (sent["inf_vl_upg"] + intToStr(i)).c_str());
		}
	}

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	rectVoidLightPL.changeOnFrame(msg, false);
	if (rectVoidLightPL.isClickOn(msg)) {
		if (vlufront == 7)vlufront = 1;
	}
	rectVoidLightPL.draw();
	if (vlufront == 7)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectVoidLightPL.x1 + rectVoidLightPL.x2) >> 1,
	         (rectVoidLightPL.y1 + rectVoidLightPL.y2) >> 1,
	         sent["page_left"].c_str());
	setcolor(RGB(255, 255, 255));
	rectVoidLightPR.changeOnFrame(msg, false);
	if (rectVoidLightPR.isClickOn(msg)) {
		if (vlufront == 1)vlufront = 7;
	}
	rectVoidLightPR.draw();
	if (vlufront == 1)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectVoidLightPR.x1 + rectVoidLightPR.x2) >> 1,
	         (rectVoidLightPR.y1 + rectVoidLightPR.y2) >> 1,
	         sent["page_right"].c_str());
	setcolor(RGB(255, 255, 255));
}
