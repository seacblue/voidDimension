inline void drawStat3Func() {
	int curY = 180;
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, curY, "%s", sent["stat_c_2"].c_str());
	curY += 35;
	int unt = 8;
	for (re int i = 1; i <= unt; ++i) {
		if (infChaUnlocked[i]){
			std::string statOutput;
			statOutput.clear();
			statOutput = sent["infcha"] + intToStr(i) +
			             sent["colon"] + sent["space"] + 
						 intToTimeStr(fastestInfChallengeTime[i]);
			settextjustify(CENTER_TEXT, TOP_TEXT);
			xyprintf(WINDOW_WIDTH >> 1, curY, "%s", statOutput.c_str());
			curY += 20;
		}
	}
}
