inline void drawManual() {
	int frm = (manualPage - 1) * maxManualPerPage + 1;
	int unt = manualPage * maxManualPerPage;
	if (unt > maxManual) unt = maxManual;

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	for (re int i = frm, ptr = 1; i <= unt; ++i, ++ptr) {
		bool showName = true;
		if (manualSpoiler && !enableSpoiler[i]) showName = false;

		if (showName) {
			rectManual[ptr].changeOnFrame(msg, false);
			if (rectManual[ptr].isClickOn(msg)) {
				if (curShowManual != i) {
					curShowManual = i;
				} else {
					curShowManual = 0;
				}
			}
			rectManual[ptr].draw();

			std::string showString = "man_show_" + intToStr(i);
			xyprintf((rectManual[ptr].x1 + rectManual[ptr].x2) >> 1,
			         (rectManual[ptr].y1 + rectManual[ptr].y2) >> 1,
			         sent[showString].c_str());
		}
	}

	rectManualPL.changeOnFrame(msg, false);
	if (rectManualPL.isClickOn(msg)) {
		if (manualPage > 1) {
			--manualPage;
		}
	}
	rectManualPL.draw();
	if (manualPage > 1)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectManualPL.x1 + rectManualPL.x2) >> 1,
	         (rectManualPL.y1 + rectManualPL.y2) >> 1,
	         sent["pl_short"].c_str());
	setcolor(RGB(255, 255, 255));

	rectManualPR.changeOnFrame(msg, false);
	if (rectManualPR.isClickOn(msg)) {
		if (manualPage < maxManualPage) {
			++manualPage;
		}
	}
	rectManualPR.draw();
	if (manualPage < maxManualPage)setcolor(RGB(255, 255, 255));
	else setcolor(RGB(128, 128, 128));
	xyprintf((rectManualPR.x1 + rectManualPR.x2) >> 1,
	         (rectManualPR.y1 + rectManualPR.y2) >> 1,
	         sent["pr_short"].c_str());
	setcolor(RGB(255, 255, 255));

	rectManualSpoiler.changeOnFrame(msg, false);
	if (rectManualSpoiler.isClickOn(msg)) {
		manualSpoiler = !manualSpoiler;
	}
	rectManualSpoiler.draw();
	std::string showString = "man_enable_spoiler";
	if (manualSpoiler) showString = "man_disable_spoiler";
	xyprintf((rectManualSpoiler.x1 + rectManualSpoiler.x2) >> 1,
	         (rectManualSpoiler.y1 + rectManualSpoiler.y2) >> 1,
	         sent[showString].c_str());

	rectManualBack.changeOnFrame(msg, false);
	if (rectManualBack.isClickOn(msg)) {
		optManualMode = false;
	}
	rectManualBack.draw();
	xyprintf((rectManualBack.x1 + rectManualBack.x2) >> 1,
	         (rectManualBack.y1 + rectManualBack.y2) >> 1,
	         sent["man_back"].c_str());

	rectangle(215, 35, WINDOW_WIDTH - 60 + 5, WINDOW_HEIGHT - 35);
	if (curShowManual) {
		settextjustify(LEFT_TEXT, TOP_TEXT);
		setFont(20);
		showString = "man_info_" + intToStr(curShowManual);
		rectp(220, 40, WINDOW_WIDTH - 220 - 60, sent[showString]);
		setFont(16);
	}
}
