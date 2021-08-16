inline void drawFunc() {
	drawTopFunc();
	drawMenuFunc();
	drawDimFunc();
	drawOptFunc();
	drawStatFunc();
	drawAchFunc();
	drawChaFunc();
	drawInfFunc();
	drawReminderStack();

	settextjustify(LEFT_TEXT, BOTTOM_TEXT);
	xyprintf(3, WINDOW_HEIGHT - 3, "%.1lf%s%s",
	         getfps(),
	         sent["space"].c_str(),
	         sent["FPS"].c_str());
}
