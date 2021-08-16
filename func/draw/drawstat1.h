inline void drawStat1Func() {
	int curY = 180;
	for (re int i = 1; i <= maxStat; ++i) {
		if (statIsOpen[i]) {
			std::string statOutput;
			statOutput.clear();
			if (i == 1) {
				int deltaTime = playingTick;
				statOutput = sent["stat_1"] + intToTimeStr(deltaTime);
			}
			if (i == 2) {
				statOutput = sent["stat_2"];
				statOutput += intToStr(collapseTime);
				statOutput += sent["space"];
				if (collapseTime == 1) {
					statOutput += sent["time"];
				} else {
					statOutput += sent["times"];
				}
			}
			if (i == 3) {
				statOutput = sent["stat_3"];
				statOutput += infTime.print(0);
				statOutput += sent["space"];
				if (infTime == 1) {
					statOutput += sent["time"];
				} else {
					statOutput += sent["times"];
				}
			}
			if (i == 4) {
				int deltaTime = infPlayingTick;
				statOutput = sent["stat_1"] + intToTimeStr(deltaTime)
				             + sent["space"] + sent["stat_4"];
			}
			if (i == 5) {
				statOutput = sent["stat_5"] + intToTimeStr(fastestInfTime);
			}
			if (i == 6) {
				statOutput = sent["stat_6"];
				statOutput += intToStr(paceTime);
				statOutput += sent["space"];
				if (paceTime == 1) {
					statOutput += sent["time"];
				} else {
					statOutput += sent["times"];
				}
			}
			settextjustify(CENTER_TEXT, TOP_TEXT);
			xyprintf(WINDOW_WIDTH >> 1, curY, "%s", statOutput.c_str());
			curY += 20;
		}
	}
}
