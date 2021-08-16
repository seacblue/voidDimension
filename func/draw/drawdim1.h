inline void drawDim1Func() {
	char pString[MAXLEN];
	// Dimensions - Generator
	int curY = 185;

	rectDimBuyMax.changeOnFrame(msg, false);
	if (rectDimBuyMax.isClickOn(msg) || keystate((int)('M'))) {
		for (re int i = showDims; i >= 1; --i) {
			buyMaxTrigger(i);
		}
	}
	rectDimBuyMax.draw();
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, curY, "%s", sent["dim_max"].c_str());
	std::string dimString = "dim_1";
	curY = 220;
	for (re int i = 1; i <= showDims; ++i, curY += 40) {
		dimString[4] = (char)(i + '0');
		bool boolOper = false;
		if (voidPoint >= dim[i].cost && (!chaIn[7] || i <= 2)) {
			boolOper = true;
		}
		if ((i > 2 && chaIn[7]) && dim[i - 2].val >= dim[i].cost) {
			boolOper = true;
		}
		rectDim[i].changeOnFrame(msg, boolOper, boolOper);
		if (rectDim[i].isClickOn(msg)) {
			if (voidPoint >= dim[i].cost && (!chaIn[7] || i <= 2)) {
				if ((!chaIn[4] && !chaIn[8]) || (i >= 1 && i <= 3)) {
					buyMax(i);
				}
			}
			if ((i > 2 && chaIn[7]) && dim[i - 2].val >= dim[i].cost) {
				buyMax(i);
			}
		}
		rectDim[i].draw();
		settextjustify(LEFT_TEXT, TOP_TEXT);
		xyprintf(40, curY, "%s", sent[dimString].c_str());
		settextjustify(RIGHT_TEXT, TOP_TEXT);
		xyprintf(350, curY, "%s%s",
		         dim[i].showMult.print(1).c_str(),
		         sent["mult_x"].c_str());
		xyprintf(600, curY, "%s", dim[i].val.print().c_str());
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf(WINDOW_WIDTH - 150, curY, "%s%s",
		         sent["cost_x"].c_str(),
		         dim[i].cost.print().c_str());
	}

	bool colHover = false, paceHover = false;

	// Dimensions - Collapse
	if (showCollapse) {
		rectDimCollapse.draw();
		settextjustify(LEFT_TEXT, TOP_TEXT);
		std::string showName = "dim_collapse_name";
		if (collapseTime >= slowCollapseBegin) {
			showName = "dim_slow_collapse_name";
		}
		if (collapseTime >= distantCollapseBegin) {
			showName = "dim_distant_collapse_name";
		}
		xyprintf(40, curY, "%s (%s)",
		         sent[showName].c_str(),
		         intToStr(collapseTime).c_str());
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf(WINDOW_WIDTH - 150, curY, "%s%s%s",
		         sent["req_x"].c_str(),
		         collapseReq.print().c_str(),
		         sent["dim_collapse_req"].c_str(),
		         sent["dim_collapse_name"].c_str());
		// Hover Event
		int wsize, hsize;
		wsize = textwidth(sent[showName].c_str());
		hsize = textheight(sent[showName].c_str());
		if (msg.x >= 40 - 5 && msg.x <= 40 + wsize + 5 &&
		        msg.y >= curY - 5 && msg.y <= curY + hsize + 5) {
			colHover = true;
		}
		// Click Button Event
		bool boolOper = false;
		if (dim[6].val >= collapseReq) {
			boolOper = true;
		}
		rectDimCollapse.changeOnFrame(msg, boolOper, boolOper);
		if (rectDimCollapse.isClickOn(msg)) {
			performGeneratorCollapse();
		}
		curY += 40;
	}

	// Dimensions - Void Pace
	if (showPace && showDims == maxDims) {
		rectDimPace.draw();
		settextjustify(LEFT_TEXT, TOP_TEXT);
		std::string showName = "dim_pace_name";
		if (paceTime >= slowPaceBegin) {
			showName = "dim_slow_pace_name";
		}
		if (paceTime >= distantPaceBegin) {
			showName = "dim_distant_pace_name";
		}
		xyprintf(40, curY, "%s (%s)",
		         sent[showName].c_str(),
		         intToStr(paceTime).c_str());
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf(WINDOW_WIDTH - 150, curY, "%s%s",
		         sent["cost_x"].c_str(),
		         paceReq.print().c_str());
		// Hover Event
		int wsize, hsize;
		wsize = textwidth(sent[showName].c_str());
		hsize = textheight(sent[showName].c_str());
		if (msg.x >= 40 - 5 && msg.x <= 40 + wsize + 5 &&
		        msg.y >= curY - 5 && msg.y <= curY + hsize + 5) {
			paceHover = true;
		}
		// Click Button Event
		bool boolOper = false;
		if (voidPoint >= paceReq) {
			boolOper = true;
		}
		rectDimPace.changeOnFrame(msg, boolOper, boolOper);
		if (rectDimPace.isClickOn(msg)) {
			performVoidPace();
		}
		curY += 40;
	}

	if (colHover) {
		settextjustify(LEFT_TEXT, TOP_TEXT);
		sprintf(pString, "%s%s%s%s",
		        sent["dim_collapse_info1"].c_str(),
		        doubleToStr(colMult).c_str(),
		        sent["mult_x"].c_str(),
		        sent["dim_collapse_info2"].c_str());
		int h = rectp(msg.x + 10, msg.y + 10, 300, pString);
		rectangle(msg.x + 6, msg.y + 8, msg.x + 300 + 8, msg.y + h + 12);
		mybar(msg.x + 7, msg.y + 9, msg.x + 300 + 7, msg.y + h + 11, RGB(0, 0, 0));
		rectp(msg.x + 10, msg.y + 10, 300, pString);
	}
	if (paceHover) {
		settextjustify(LEFT_TEXT, TOP_TEXT);
		sprintf(pString, "%s%s%s%s",
		        sent["dim_pace_info1"].c_str(),
		        doubleToStr(paceMult).c_str(),
		        sent["mult_x"].c_str(),
		        sent["dim_pace_info2"].c_str());
		int h = rectp(msg.x + 10, msg.y + 10, 300, pString);
		rectangle(msg.x + 6, msg.y + 8, msg.x + 300 + 8, msg.y + h + 12);
		mybar(msg.x + 7, msg.y + 9, msg.x + 300 + 7, msg.y + h + 11, RGB(0, 0, 0));
		rectp(msg.x + 10, msg.y + 10, 300, pString);
	}

	if (infChaIn[4]) {
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		rectDimReset.changeOnFrame(msg, false);
		if (rectDimReset.isClickOn(msg)) {
			resetCol();
		}
		rectDimReset.draw();
		int width = rectDimReset.x2 - rectDimReset.x1 - 30;
		rectp((rectDimReset.x1 + rectDimReset.x2) >> 1,
		      (rectDimReset.y1 + rectDimReset.y2) >> 1,
		      width, sent["reset"]);
	}
}
