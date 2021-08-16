inline void drawTopFunc() {
	setbkmode(TRANSPARENT);
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, 60, "%s%s%s",
	         sent["top_1"].c_str(),
	         voidPoint.print(1).c_str(),
	         sent["top_2"].c_str());
	xyprintf(WINDOW_WIDTH >> 1, 80, "%s%s%s",
	         sent["top_3"].c_str(),
	         voidPointSec.print().c_str(),
	         sent["top_4"].c_str());
	if (chaIn[5] || infChaIn[3]) {
		xyprintf(WINDOW_WIDTH >> 1, 40, "%s%s%s",
		         sent["top_5"].c_str(),
		         cha5antiVP.print(1).c_str(),
		         sent["top_6"].c_str());
	}
	if (chaIn[6] || chaIn[8]) {
		xyprintf(WINDOW_WIDTH >> 1, 40, "%s%s",
		         sent["top_7"].c_str(),
		         cha6capped.print(3).c_str());
	}
	if (chaIn[8]) {
		xyprintf(WINDOW_WIDTH >> 1, 20, "%s%s",
		         sent["top_8"].c_str(),
		         maxCha8VoidPoint.print().c_str());
	}

	if (curMenu == 1 && cur1Menu == 2) {
		xyprintf(WINDOW_WIDTH >> 1, 220, "%s%s%s%s%s%s",
		         sent["top_5"].c_str(),
		         infPower.print().c_str(),
		         sent["top_9"].c_str(),
		         infPowerTranslate.print().c_str(),
		         sent["mult_x"].c_str(),
		         sent["top_10"].c_str());
		xyprintf(WINDOW_WIDTH >> 1, 240, "%s%s%s",
		         sent["top_3"].c_str(),
		         infPowerSec.print().c_str(),
		         sent["top_11"].c_str());
	}
	bool infButtonPress = false;
	Bignum infNeed;
	infNeed.setBignum(1, 24);
	for (re int i = 1; i <= maxInfCha; ++i) {
		if (infChaIn[i]) {
			infNeed = ICGoal[i];
		}
	}
	if (voidPoint >= infNeed)infButtonPress = true;
	std::string showoper = "pers";
	Bignum tempInfSpd = curInfSpd;
	if(tempInfSpd < 0.01){
		tempInfSpd = tempInfSpd * 60.0;
		showoper = "perm";
	}
	if(tempInfSpd < 0.01){
		tempInfSpd = tempInfSpd * 60.0;
		showoper = "perh";
	}
	if (infButtonPress || infTime > 0) {
		rectDimInfinity.changeOnFrame(msg, false);
		if (rectDimInfinity.isClickOn(msg) && infButtonPress) {
			performInfinity();
		}
		rectDimInfinity.draw();
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		if (infTime == 0) {
			xyprintf((rectDimInfinity.x1 + rectDimInfinity.x2) >> 1,
			         (rectDimInfinity.y1 + rectDimInfinity.y2) >> 1,
			         "%s",
			         sent["top_inf_name"].c_str());
		} else {
			if (voidPoint >= infNeed) {
				xyprintf((rectDimInfinity.x1 + rectDimInfinity.x2) >> 1,
				         ((rectDimInfinity.y1 + rectDimInfinity.y2) >> 1) - 10,
				         "%s%s%s",
				         sent["top_inf_info1"].c_str(),
				         maxGetInfPoint.print().c_str(),
				         sent["top_inf_info2"].c_str());
				xyprintf((rectDimInfinity.x1 + rectDimInfinity.x2) >> 1,
				         ((rectDimInfinity.y1 + rectDimInfinity.y2) >> 1) + 10,
				         "%s%s",
				         tempInfSpd.print(2).c_str(),
				         sent[showoper].c_str());
			} else {
				std::string outputString = sent["top_inf_info3"] +
				                           infNeed.print() +
				                           sent["top_inf_info4"];

				int rectWidth = rectDimInfinity.x2 - rectDimInfinity.x1;
				int height = rectp(-100, -100, rectWidth - 20, outputString);

				rectp((rectDimInfinity.x1 + rectDimInfinity.x2) >> 1,
				      ((rectDimInfinity.y1 + rectDimInfinity.y2 - height) >> 1) + 8,
				      rectWidth - 20, outputString);
			}
		}
	}
	if (infTime > 0) {
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf((rectDimInfinity.x1 + rectDimInfinity.x2) >> 1,
		         rectDimInfinity.y2 + 4,
		         "%s%s%s",
		         sent["top_5"].c_str(),
		         infPoint.print().c_str(),
		         sent["top_inf_info2"].c_str());
	}
}
