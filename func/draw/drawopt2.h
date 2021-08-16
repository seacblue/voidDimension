inline void drawStat2Func() {
	int curY = 180;
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, curY, "%s", sent["stat_c_1"].c_str());
	curY += 35;
	int unt = 4;
	if (haveInfUpg[15]) {
		unt = 8;
	}
	for (re int i = 1; i <= unt; ++i) {
		std::string statOutput;
		statOutput.clear();
		statOutput = sent["cha"] + intToStr(i) + sent["colon"] +
		             sent["space"] + intToTimeStr(fastestChallengeTime[i]);
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf(WINDOW_WIDTH >> 1, curY, "%s", statOutput.c_str());
		curY += 20;
	}
}
