inline void stepMiscFunc() {
	++playingTick;
	++challengeTick;
	++infPlayingTick;

	if (curMenu != 4) {
		curShowAch = 0;
	}

	// Update statistics
	if (haveInfUpg[9]) menu3IsOpen[2] = true;
	if (infDimUnlocked) menu3IsOpen[3] = true;

	// Update challenges
	if (infDimUnlocked) menu5IsOpen[2] = true;

	// Update infinity
	if (chaTimes[8]) menu6IsOpen[2] = menu6IsOpen[3] = true;
	if (haveBInfUpg[6]) {
		menu6IsOpen[4] = true;
		voidLightUnlocked = true;
	}
	if (voidLightUpgBought[6]) menu6IsOpen[5] = true;

	if (chaTimes[8]) {
		menu6IsOpen[2] = true;
		menu6IsOpen[3] = true;
		for (re int i = 1; i <= 8; ++i)haveAuto[i] = true;
	}

	++autoSaveTick;
	if (autoSaveTick == autoSaveMaxTick) {
		autoSaveTick = 0;
		save(saveFileName);
		pushReminderStack(0, RGB(170, 178, 32));
	}

	// Check achievements
	// Ach 3
	if (voidPoint >= strToBignum("1.00e12") && !achIsOpen[3])pushAch(3);
	// Ach 9
	if (voidPoint >= strToBignum("1.79e308") && !achIsOpen[9])pushAch(9);
	// Ach 16
	if (voidPoint >= strToBignum("9.99e999") && !achIsOpen[16])pushAch(16);
	// Ach 17
	if (voidPoint >= strToBignum("1.00e1437") && !achIsOpen[17])pushAch(17);
	// Ach 12
	if (voidPoint >= strToBignum("1.00e80") &&
	        chaIn[8] &&
	        !achIsOpen[12])pushAch(12);
	// Ach 14
	if (infPower >= strToBignum("1.00e12") && !achIsOpen[14])pushAch(14);
	// Ach 21
	if (menu6IsOpen[4] && !achIsOpen[21])pushAch(21);
	// Ach 22
	if (voidLightUpgBought[3] && !achIsOpen[22])pushAch(22);
	// Ach 23
	if (voidPoint >= strToBignum("1.79e308") && chaIn[8] && !achIsOpen[23])pushAch(23);
	// Ach 24
	if (voidLightRealSec >= strToBignum("5.00e1") && !achIsOpen[24])pushAch(24);
	// Ach 25
	if (aveFreeEle >= 1 && !achIsOpen[25])pushAch(25);
	// Ach 26
	if (aveFreeEle + avePosEle + aveNegEle >= 3 && !achIsOpen[26])pushAch(26);
	// Ach 27
	if (infTime >= strToBignum("1.00e8") && !achIsOpen[27])pushAch(27);

	// Ach 16 Reward
	if (voidPoint >= strToBignum("1.00e24")){
		if (voidPoint >= 100) ach16Reward = exporoot(voidPoint, 0.15);
		else ach16Reward = 0.0;
	}
	// Ach 20 Reward
	if (achIsOpen[20] && chaTimes[4])chaTimes[8] = true;

	// Update maximum void points in challenge 8
	if (chaIn[8]) {
		if (voidPoint > maxCha8VoidPoint) {
			maxCha8VoidPoint = voidPoint;
		}
	}

	// Close sys_edit when out of Automation
	if (curMenu != 6 || cur6Menu != 2) {
		for (re int i = 1; i <= maxAutoSetting; ++i) {
			peditbox[i]->visible(false);
		}
		for (re int i = 1; i <= maxAuto; ++i) {
			settingAuto[i] = false;
			firstCall[i] = false;
		}
	}

	// Close setting misc when out of setting
	if (curMenu != 2) {
		optShowLang = false;
		optShowFPS = false;
		SliderFPS.setVisible(false);
	}

	FPS = SliderFPS.getValue();
	ReminderFadeIn = 35;
	ReminderWait = ReminderFadeIn + 120;
	ReminderFadeOut = ReminderWait + 20;
	ReminderFadeIn = ReminderFadeIn * FPS / 60;
	ReminderWait = ReminderWait * FPS / 60;
	ReminderFadeOut = ReminderFadeOut * FPS / 60;

	// Spoiler
	if (showCollapse) enableSpoiler[4] = true;
	if (infTime > 0.9) enableSpoiler[5] = true;
	if (haveInfUpg[9]) enableSpoiler[6] = true;
	if (chaTimes[8]) enableSpoiler[7] = true;
	if (chaTimes[8]) enableSpoiler[8] = true;
	if (infDimUnlocked) enableSpoiler[9] = true;
	if (infDimUnlocked) enableSpoiler[10] = true;
	if (showPace) enableSpoiler[11] = true;
	if (menu6IsOpen[4]) enableSpoiler[12] = true;
	if (collapseTime >= slowCollapseBegin) enableSpoiler[13] = true;
	if (voidLightUpgBought[6]) enableSpoiler[14] = true;
}
