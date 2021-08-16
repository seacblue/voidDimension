inline void drawDim2Func() {
	// Dimensions - Infinity Generator
	int curY = 185;
	rectDimBuyMax.changeOnFrame(msg, false);
	if (rectDimBuyMax.isClickOn(msg) || keystate((int)('M'))) {
		for (re int i = infMaxDims; i >= 1; --i) {
			infBuyMaxTrigger(i);
		}
	}
	rectDimBuyMax.draw();
	settextjustify(CENTER_TEXT, TOP_TEXT);
	xyprintf(WINDOW_WIDTH >> 1, curY, "%s", sent["dim_max"].c_str());
	std::string dimString = "infdim_";
	curY = 270;
	for (int i = 1; i <= infShowDims; ++i, curY += 40) {
		dimString = "infdim_" + intToStr(i);
		bool boolOper = false;
		if (infPoint >= infdim[i].cost) {
			boolOper = true;
		}
		rectInfDim[i].changeOnFrame(msg, boolOper, boolOper);
		if (rectInfDim[i].isClickOn(msg)) {
			if (infPoint >= infdim[i].cost) {
				infBuyMax(i);
			}
		}
		rectInfDim[i].draw();
		settextjustify(LEFT_TEXT, TOP_TEXT);
		xyprintf(40, curY, "%s", sent[dimString].c_str());
		settextjustify(RIGHT_TEXT, TOP_TEXT);
		xyprintf(350, curY, "%s%s",
		         infdim[i].showMult.print(1).c_str(),
		         sent["mult_x"].c_str());
		xyprintf(600, curY, "%s", infdim[i].val.print().c_str());
		settextjustify(CENTER_TEXT, TOP_TEXT);
		xyprintf(WINDOW_WIDTH - 150, curY, "%s%s%s%s",
		         sent["cost_x"].c_str(),
		         infdim[i].cost.print().c_str(),
				 sent["space"].c_str(),
				 sent["IP"].c_str());
	}
}
