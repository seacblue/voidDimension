inline void drawSleep() {
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	int h = rectp(-100, -100, 114514,
	              sent["opt_sleep_mode"].c_str());
	rectp(WINDOW_WIDTH >> 1, (WINDOW_HEIGHT - h) >> 1, 114514,
	      sent["opt_sleep_mode"].c_str());

	rectUnlockSleep.set((WINDOW_WIDTH >> 1) - 90, (WINDOW_HEIGHT >> 1) + 40,
	                    (WINDOW_WIDTH >> 1) + 90, (WINDOW_HEIGHT >> 1) + 80,
	                    RGB(96, 96, 96), RGB(96, 96, 96));
	rectUnlockSleep.changeOnFrame(msg, false);
	if (rectUnlockSleep.isClickOn(msg)) {
		optSleepMode = false;
	}
	rectUnlockSleep.draw();
	xyprintf((rectUnlockSleep.x1 + rectUnlockSleep.x2) >> 1,
	         (rectUnlockSleep.y1 + rectUnlockSleep.y2) >> 1,
	         "%s", sent["opt_unlock_sleep"].c_str());
}
