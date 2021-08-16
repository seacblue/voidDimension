inline void drawStatFunc() {
	if (curMenu == 3) {
		if (cur3Menu == 1) {
			drawStat1Func();
		}
		if (cur3Menu == 2) {
			drawStat2Func();
		}
		if (cur3Menu == 3) {
			drawStat3Func();
		}
		xyprintf(WINDOW_WIDTH >> 1, WINDOW_HEIGHT - 50, "%s", sent["end_game"].c_str());
		xyprintf(WINDOW_WIDTH >> 1, WINDOW_HEIGHT - 30, "%s", sent["version"].c_str());
	}
}
