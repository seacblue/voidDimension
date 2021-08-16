inline void pushReminderStack(int achID, color_t color) {
	if (reminderStackTop == MAXREMINDER)return;
	reminderStack[++reminderStackTop] = (Reminder) {
		achID, 0, color
	};
}
inline void releaseReminderStack() {
	while (reminderStack[reminderStackTop].tick >= ReminderFadeOut) {
		--reminderStackTop;
	}
}
inline void updateReminderStack() {
	for (re int i = 1; i <= reminderStackTop; ++i) {
		++reminderStack[i].tick;
	}
}
inline void pushAch(int achID) {
	achIsOpen[achID] = true;
	pushReminderStack(achID, RGB(30, 105, 210));
}
