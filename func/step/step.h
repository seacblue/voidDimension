inline void stepFunc() {
	stepMiscFunc();
	stepDimFunc();
	stepInfDimFunc();
	stepInfFunc();
	stepChaFunc();
	stepAutoFunc();
	
	stepAftFunc();

	updateReminderStack();
	releaseReminderStack();
}
