inline void drawReminderStack() {
	int curY = 20;
	settextjustify(LEFT_TEXT, TOP_TEXT);
	for (re int i = 1; i <= reminderStackTop; ++i, curY += 30) {
		Reminder sReminder = reminderStack[i];
		std::string achString;
		achString.clear();
		if (sReminder.id > 0) {
			achString = "ach_name_" + intToStr(sReminder.id);
		}
		if (sReminder.id == 0) {
			achString = "game_save";
		}
		if (sReminder.id == -1) {
			achString = "game_load";
		}
		if (sReminder.id == -2) {
			achString = "updated";
		}
		int width = textwidth(sent[achString].c_str()), curX;
		if (sReminder.tick <= ReminderFadeIn) {
			ld percentage = (ld)(sReminder.tick) / (ld)(ReminderFadeIn);
			curX = (WINDOW_WIDTH - 20) * percentage +
			       (WINDOW_WIDTH + 20 + width) * (1 - percentage);
		}
		if (sReminder.tick > ReminderFadeIn && sReminder.tick < ReminderWait) {
			curX = WINDOW_WIDTH - 20;
		}
		if (sReminder.tick >= ReminderWait) {
			ld percentage = (ld)(sReminder.tick - ReminderWait) /
			                (ld)(ReminderFadeOut - ReminderWait);
			curX = (WINDOW_WIDTH - 20) * (1 - percentage) +
			       (WINDOW_WIDTH + 20 + width) * percentage;
		}

		rectangle(curX - width - 9, curY - 2, curX + 9, curY + 20);
		setfillcolor(sReminder.color);
		bar(curX - width - 9 + 1, curY - 2 + 1, curX + 9 - 1, curY + 20 - 1);
		xyprintf(curX - width, curY, sent[achString].c_str());
	}
}
