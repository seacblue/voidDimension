inline void preinit() {
	resetDim();
	resetInfDim();
}

inline void initSetAuto(int id, int x, int y) {
	rectAutoBG[id].set(x, y - 10,
	                   x + infUpgRectWidth, y + 90,
	                   RGB(100, 100, 100), RGB(100, 100, 100),
	                   RGB(0, 0, 0), true,
	                   RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                   RGB(255, 255, 255), RGB(255, 255, 255));
	rectAutoAble[id].set(x + 30, y + 65,
	                     x + infUpgRectWidth - 30, y + 85,
	                     RGB(100, 100, 100), RGB(100, 100, 100),
	                     RGB(0, 0, 0), true,
	                     RGB(0, 0, 139), RGB(139, 0, 0), RGB(139, 0, 0),
	                     RGB(255, 255, 255), RGB(255, 255, 255));
	rectAutoUpg[id].set(x + 30, y + 40,
	                    x + infUpgRectWidth - 30, y + 60,
	                    RGB(60, 179, 113), RGB(220, 20, 60),
	                    RGB(0, 0, 0), true,
	                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                    RGB(0, 192, 0), RGB(255, 255, 255));
	rectAutoSetting[id].set(x + infUpgRectWidth - 20, y + 70,
	                        x + infUpgRectWidth - 5, y + 85,
	                        RGB(100, 100, 100), RGB(100, 100, 100),
	                        RGB(0, 0, 0), true,
	                        RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                        RGB(0, 0, 0), RGB(255, 255, 255));
	rectAutoComplete[id].set(x + infUpgRectWidth - 20, y + 50,
	                         x + infUpgRectWidth - 5, y + 65,
	                         RGB(100, 100, 100), RGB(100, 100, 100),
	                         RGB(0, 0, 0), true,
	                         RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                         RGB(0, 0, 0), RGB(255, 255, 255));
}

inline void initFunc() {
	int curX = 0, curY = 220;
	for (re int i = 1; i <= maxDims; ++i, curY += 40) {
		rectDim[i].set(WINDOW_WIDTH - 240, curY - 3, WINDOW_WIDTH - 60, curY + 20,
		               RGB(60, 179, 113), RGB(220, 20, 60),
		               RGB(0, 0, 0), true,
		               RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
		               RGB(0, 192, 0), RGB(255, 255, 255));
	}
	rectDimCollapse.set(WINDOW_WIDTH - 240, curY - 3, WINDOW_WIDTH - 60, curY + 20,
	                    RGB(60, 179, 113), RGB(220, 20, 60),
	                    RGB(0, 0, 0), true,
	                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                    RGB(0, 192, 0), RGB(255, 255, 255));
	curY += 40;
	rectDimPace.set(WINDOW_WIDTH - 240, curY - 3, WINDOW_WIDTH - 60, curY + 20,
	                RGB(60, 179, 113), RGB(220, 20, 60),
	                RGB(0, 0, 0), true,
	                RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                RGB(0, 192, 0), RGB(255, 255, 255));
	rectDimReset.set((WINDOW_WIDTH >> 1) - 120, WINDOW_HEIGHT - 60,
	                 (WINDOW_WIDTH >> 1) + 120, WINDOW_HEIGHT - 20,
	                 RGB(96, 96, 96), RGB(96, 96, 96));
	curX = 0;
	curY = 270;
	for (re int i = 1; i <= infMaxDims; ++i, curY += 40) {
		rectInfDim[i].set(WINDOW_WIDTH - 240, curY - 3, WINDOW_WIDTH - 60, curY + 20,
		                  RGB(60, 179, 113), RGB(220, 20, 60),
		                  RGB(0, 0, 0), true,
		                  RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
		                  RGB(0, 192, 0), RGB(255, 255, 255));
	}

	int dimBuyMaxWidth = textwidth(sent["dim_max"].c_str());
	curY = 185;
	rectDimBuyMax.set((WINDOW_WIDTH >> 1) - (dimBuyMaxWidth >> 1) - 6, curY - 3,
	                  (WINDOW_WIDTH >> 1) + (dimBuyMaxWidth >> 1) + 6, curY + 20,
	                  RGB(96, 96, 96), RGB(96, 96, 96));

	rectDimInfinity.set((WINDOW_WIDTH - 260), 30, (WINDOW_WIDTH - 60), 80,
	                    RGB(210, 180, 140), RGB(210, 180, 140));

	menu1IsOpen[1] = true;

	// Infinity
	// Upgrade
	curY = 280;
	curX = infUpgLeft;
	for (re int i = 1, ptr = 1; i <= 3; ++i) {
		for (re int j = 1; j <= 3; ++j, ++ptr) {
			rectInfUpg[ptr].set(curX, curY - 10,
			                    curX + infUpgRectWidth, curY + 90,
			                    RGB(100, 100, 100), RGB(100, 100, 100),
			                    RGB(0, 0, 0), true,
			                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                    RGB(0, 140, 0), RGB(255, 255, 255));
			curY += 120;
		}
		curX += infUpgRectWidth + infUpgGap;
		curY = 280;
	}

	curY = 280;
	curX = infUpgLeft;
	for (re int i = 1, ptr = 10; i <= 3; ++i) {
		for (re int j = 1; j <= 2; ++j, ++ptr) {
			rectInfUpg[ptr].set(curX, curY - 10,
			                    curX + infUpgRectWidth, curY + 90,
			                    RGB(100, 100, 100), RGB(100, 100, 100),
			                    RGB(0, 0, 0), true,
			                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                    RGB(0, 140, 0), RGB(255, 255, 255));
			curY += 120;
		}
		curX += infUpgRectWidth + infUpgGap;
		curY = 280;
	}

	rectInfRebuyable.set((WINDOW_WIDTH - 450) >> 1, 190,
	                     (WINDOW_WIDTH + 450) >> 1, 250,
	                     RGB(100, 100, 100), RGB(100, 100, 100),
	                     RGB(0, 0, 0), true,
	                     RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                     RGB(0, 140, 0), RGB(255, 255, 255));

	rectInfUpgPL.set(infUpgLeft, 190,
	                 ((WINDOW_WIDTH - 450) >> 1) - 30, 250,
	                 RGB(100, 100, 100), RGB(100, 100, 100),
	                 RGB(0, 0, 0), true,
	                 RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                 RGB(60, 60, 60), RGB(255, 255, 255));
	rectInfUpgPR.set(((WINDOW_WIDTH + 450) >> 1) + 30, 190,
	                 WINDOW_WIDTH - infUpgLeft, 250,
	                 RGB(100, 100, 100), RGB(100, 100, 100),
	                 RGB(0, 0, 0), true,
	                 RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                 RGB(60, 60, 60), RGB(255, 255, 255));

	// Break Infinity
	curY = 280;
	curX = infUpgLeft;
	for (re int i = 1, ptr = 1; i <= 3; ++i) {
		for (re int j = 1; j <= 2; ++j, ++ptr) {
			rectBInfUpg[ptr].set(curX, curY - 10,
			                     curX + infUpgRectWidth, curY + 130,
			                     RGB(100, 100, 100), RGB(100, 100, 100),
			                     RGB(0, 0, 0), true,
			                     RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                     RGB(0, 140, 0), RGB(255, 255, 255));
			curY += 160;
		}
		curX += infUpgRectWidth + infUpgGap;
		curY = 280;
	}
	rectBInfUnlock.set(infUpgLeft + infUpgRectWidth + infUpgGap, 280 - 10,
	                   infUpgLeft + infUpgRectWidth * 3 + infUpgGap * 2, 280 + 130 + 160,
	                   RGB(100, 100, 100), RGB(100, 100, 100),
	                   RGB(0, 0, 0), true,
	                   RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                   RGB(0, 140, 0), RGB(255, 255, 255));
	rectBInfRebuyable.set((WINDOW_WIDTH - 450) >> 1, 190,
	                      (WINDOW_WIDTH + 450) >> 1, 250,
	                      RGB(100, 100, 100), RGB(100, 100, 100),
	                      RGB(0, 0, 0), true,
	                      RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                      RGB(0, 140, 0), RGB(255, 255, 255));

	// Automation
	curX = infUpgLeft;
	curY = 280;

	for (re int i = 1, ptr = 7; i <= 3; ++i, ++ptr) {
		initSetAuto(ptr, curX, curY);
		curX += infUpgRectWidth + infUpgGap;
	}

	curX = infUpgLeft;
	curY += 110;
	for (re int i = 1, ptr = 1; i <= 2; ++i) {
		for (re int j = 1; j <= 3; ++j, ++ptr) {
			initSetAuto(ptr, curX, curY);
			curX += infUpgRectWidth + infUpgGap;
		}
		curX = infUpgLeft;
		curY += 110;
	}

	rectAutoAllEnable.set((WINDOW_WIDTH >> 1) - 90, 185,
	                      (WINDOW_WIDTH >> 1) + 90, 215,
	                      RGB(100, 100, 100), RGB(100, 100, 100),
	                      RGB(0, 0, 0), true,
	                      RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                      RGB(0, 0, 0), RGB(255, 255, 255));
	rectAutoAllDisable.set((WINDOW_WIDTH >> 1) - 90, 220,
	                       (WINDOW_WIDTH >> 1) + 90, 250,
	                       RGB(100, 100, 100), RGB(100, 100, 100),
	                       RGB(0, 0, 0), true,
	                       RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                       RGB(0, 0, 0), RGB(255, 255, 255));

	// Void Light
	rectVoidLightSac.set((WINDOW_WIDTH >> 1) - 90, 280,
	                     (WINDOW_WIDTH >> 1) + 90, 310,
	                     RGB(96, 96, 96), RGB(96, 96, 96));
	curY = 350;
	curX = infUpgLeft;
	for (re int i = 1, ptr = 1; i <= 3; ++i) {
		for (re int j = 1; j <= 2; ++j, ++ptr) {
			rectVoidLightUpg[ptr].set(curX, curY - 10,
			                          curX + infUpgRectWidth, curY + 90,
			                          RGB(100, 100, 100), RGB(100, 100, 100),
			                          RGB(0, 0, 0), true,
			                          RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                          RGB(0, 140, 0), RGB(255, 255, 255));
			rectVoidLightUpg[ptr + 6].set(curX, curY - 10,
			                              curX + infUpgRectWidth, curY + 90,
			                              RGB(100, 100, 100), RGB(100, 100, 100),
			                              RGB(0, 0, 0), true,
			                              RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                              RGB(0, 140, 0), RGB(255, 255, 255));
			curY += 120;
		}
		curX += infUpgRectWidth + infUpgGap;
		curY = 350;
	}

	rectVoidLightPL.set(infUpgLeft + 30, 280,
	                    ((WINDOW_WIDTH - 450) >> 1), 310,
	                    RGB(100, 100, 100), RGB(100, 100, 100),
	                    RGB(0, 0, 0), true,
	                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                    RGB(60, 60, 60), RGB(255, 255, 255));
	rectVoidLightPR.set(((WINDOW_WIDTH + 450) >> 1), 280,
	                    WINDOW_WIDTH - infUpgLeft - 30, 310,
	                    RGB(100, 100, 100), RGB(100, 100, 100),
	                    RGB(0, 0, 0), true,
	                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                    RGB(60, 60, 60), RGB(255, 255, 255));

	// Manual
	curX = 20;
	curY = 20;
	for (re int i = 1; i <= maxManualPerPage; ++i, curY += 38) {
		rectManual[i].set(curX, curY, curX + 160, curY + 30,
		                  RGB(96, 96, 96), RGB(96, 96, 96));
	}
	rectManualPL.set(curX + 80 - 25, curY, curX + 80 - 5, curY + 20,
	                 RGB(96, 96, 96), RGB(96, 96, 96));
	rectManualPR.set(curX + 80 + 5, curY, curX + 80 + 25, curY + 20,
	                 RGB(96, 96, 96), RGB(96, 96, 96));
	rectManualSpoiler.set(curX, curY + 25, curX + 160, curY + 55,
	                      RGB(96, 96, 96), RGB(96, 96, 96));
	rectManualBack.set(curX, curY + 60, curX + 160, curY + 90,
	                   RGB(96, 96, 96), RGB(96, 96, 96));

	enableSpoiler[1] = true;
	enableSpoiler[2] = true;
	enableSpoiler[3] = true;

	// Achievements
	rectAchPL.set((WINDOW_WIDTH >> 1) - 120, WINDOW_HEIGHT - 60,
	              (WINDOW_WIDTH >> 1) - 5, WINDOW_HEIGHT - 20,
	              RGB(60, 60, 60), RGB(60, 60, 60),
	              RGB(0, 0, 0), true,
	              RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	              RGB(0, 192, 0), RGB(255, 255, 255));
	rectAchPR.set((WINDOW_WIDTH >> 1) + 5, WINDOW_HEIGHT - 60,
	              (WINDOW_WIDTH >> 1) + 120, WINDOW_HEIGHT - 20,
	              RGB(60, 60, 60), RGB(60, 60, 60),
	              RGB(0, 0, 0), true,
	              RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	              RGB(0, 192, 0), RGB(255, 255, 255));

	// Challenges
	curY = 200;
	for (re int i = 1; i <= 4; ++i, curY += chaHeight + 15) {
		rectCha[i].set(chaRectGap, curY - 3, WINDOW_WIDTH - chaRectGap, curY + chaHeight,
		               RGB(60, 60, 60), RGB(60, 60, 60),
		               RGB(0, 0, 0), true,
		               RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
		               RGB(0, 192, 0), RGB(255, 255, 255));
	}
	rectChaPageLeft.set(chaRectGap, curY + 10,
	                    (WINDOW_WIDTH - chaRectGap) >> 1, curY + 40,
	                    RGB(60, 60, 60), RGB(60, 60, 60),
	                    RGB(0, 0, 0), true,
	                    RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                    RGB(0, 192, 0), RGB(255, 255, 255));
	rectChaPageRight.set((WINDOW_WIDTH + chaRectGap) >> 1, curY + 10,
	                     WINDOW_WIDTH - chaRectGap, curY + 40,
	                     RGB(60, 60, 60), RGB(60, 60, 60),
	                     RGB(0, 0, 0), true,
	                     RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
	                     RGB(0, 192, 0), RGB(255, 255, 255));
	for (re int i = 1; i <= maxCha; ++i)fastestChallengeTime[i] = INF;

	// IC
	for (re int i = 1; i <= maxInfCha; ++i)fastestInfChallengeTime[i] = INF;

	// Statistics
	statIsOpen[1] = true;
	
	// Void Light
	voidLightSacrifice = 0.0;

	// Ave
	rectAveConvert1.set(WINDOW_WIDTH * 3 / 8 - 10,
	                    200,
	                    WINDOW_WIDTH * 3 / 8 + 10,
	                    220,
	                    RGB(96, 96, 96), RGB(96, 96, 96));
	rectAveConvert2.set(WINDOW_WIDTH * 5 / 8 - 10,
	                    225,
	                    WINDOW_WIDTH * 5 / 8 + 10,
	                    245,
	                    RGB(96, 96, 96), RGB(96, 96, 96));
	rectAveConvert3.set(WINDOW_WIDTH * 3 / 8 - 10,
	                    225,
	                    WINDOW_WIDTH * 3 / 8 + 10,
	                    245,
	                    RGB(96, 96, 96), RGB(96, 96, 96));
	rectAveConvert4.set(WINDOW_WIDTH * 5 / 8 - 10,
	                    200,
	                    WINDOW_WIDTH * 5 / 8 + 10,
	                    220,
	                    RGB(96, 96, 96), RGB(96, 96, 96));

	curY = 380;
	curX = infUpgLeft;
	for (re int i = 1, ptr = 1; i <= 3; ++i) {
		for (re int j = 1; j <= 2; ++j, ++ptr) {
			rectAveMilestone[ptr].set(curX, curY - 10,
			                          curX + infUpgRectWidth, curY + 90,
			                          RGB(100, 100, 100), RGB(100, 100, 100),
			                          RGB(0, 0, 0), true,
			                          RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255),
			                          RGB(0, 140, 0), RGB(255, 255, 255));
			curY += 120;
		}
		curX += infUpgRectWidth + infUpgGap;
		curY = 380;
	}

	setbkmode(TRANSPARENT);
	setcolor(RGB(255, 255, 255));
	curFontHeight = 18;

	for (int i = 1; i <= maxAutoSetting; ++i) {
		peditbox[i] = new sys_edit;
	}

	aftinit();
	initVar();
}

inline void initVar() {
	// Dimension
	normalCollapseReq.setRealnum(1.000001);
	basicNormalCollapseReq.setRealnum(1.000001);
	slowCollapseBegin = 75;
	basicSlowCollapseBegin = 75;
	slowCollapseReq.setRealnum(2.0000001);
	basicSlowCollapseReq.setRealnum(2.0000001);
	distantCollapseBegin = 200;
	basicDistantCollapseBegin = 200;
	distantCollapseReq.setRealnum(5.000001);
	basicDistantCollapseReq.setRealnum(5.000001);

	normalPaceMult.setBignum(1, 200);
	basicNormalPaceMult.setBignum(1, 200);
	slowPaceBegin = 21;
	basicSlowPaceBegin = 21;
	slowPaceMult.setBignum(1, 350);
	basicSlowPaceMult.setBignum(1, 300);
	distantPaceBegin = 51;
	basicDistantPaceBegin = 51;
	distantPaceMult.setBignum(1, 600);
	basicDistantPaceMult.setBignum(1, 450);
	// Automation
	maxTickAuto[1] = 60.0;
	maxTickAuto[2] = 90.0;
	maxTickAuto[3] = 120.0;
	maxTickAuto[4] = 180.0;
	maxTickAuto[5] = 240.0;
	maxTickAuto[6] = 300.0;
	maxTickAuto[7] = 480.0;
	maxTickAuto[8] = 1200.0;
	maxTickAuto[9] = 6000.0;
	costAuto[1].setRealnum(50.0);
	costAuto[2].setRealnum(50.0);
	costAuto[3].setRealnum(50.0);
	costAuto[4].setRealnum(50.0);
	costAuto[5].setRealnum(50.0);
	costAuto[6].setRealnum(50.0);
	costAuto[7].setRealnum(200.0);
	costAuto[8].setRealnum(200.0);
	costAuto[9].setBignum(1,7);
	costMultAuto[1].setRealnum(1.57);
	costMultAuto[2].setRealnum(1.61);
	costMultAuto[3].setRealnum(1.64);
	costMultAuto[4].setRealnum(1.67);
	costMultAuto[5].setRealnum(1.70);
	costMultAuto[6].setRealnum(2.73);
	costMultAuto[7].setRealnum(1.60);
	costMultAuto[8].setRealnum(1.67);
	costMultAuto[9].setRealnum(2.93);
	showAutoSetting[7] = true;
	showAutoSetting[8] = true;
	showAutoSetting[9] = true;
	// Void Light
	voidLightUpgCost[1] = strToBignum("2.00e2");
	voidLightUpgCost[2] = strToBignum("2.50e3");
	voidLightUpgCost[3] = strToBignum("1.00e4");
	voidLightUpgCost[4] = strToBignum("3.50e4");
	voidLightUpgCost[5] = strToBignum("1.00e5");
	voidLightUpgCost[6] = strToBignum("3.00e5");
	voidLightUpgCost[7] = strToBignum("2.50e6");
	voidLightUpgCost[8] = strToBignum("1.00e7");
	voidLightUpgCost[9] = strToBignum("4.00e8");
	voidLightUpgCost[10] = strToBignum("2.50e9");
	voidLightUpgCost[11] = strToBignum("1.00e99");
	voidLightUpgCost[12] = strToBignum("1.00e99");
	// IC
	ICReq[1]  = strToBignum("1.00e415");
	ICGoal[1] = strToBignum("1.00e318");
	ICReq[2]  = strToBignum("1.00e662");
	ICGoal[2] = strToBignum("1.00e325");
	ICReq[3]  = strToBignum("1.00e785");
	ICGoal[3] = strToBignum("1.00e262");
	ICReq[4]  = strToBignum("1.00e1000");
	ICGoal[4] = strToBignum("1.00e983");
	ICReq[5]  = strToBignum("6.00e1165");
	ICGoal[5] = strToBignum("1.00e645");
	ICReq[6]  = strToBignum("1.00e1274");
	ICGoal[6] = strToBignum("1.00e96");
	ICReq[7]  = strToBignum("1.00e1440");
	ICGoal[7] = strToBignum("1.00e208");
	ICReq[8]  = strToBignum("1.00e1530");
	ICGoal[8] = strToBignum("8.00e60");
	// Infinity
	infUpgCost[1] = 1;
	infUpgCost[2] = 1;
	infUpgCost[3] = 2;
	infUpgCost[4] = 3;
	infUpgCost[5] = 3;
	infUpgCost[6] = 3;
	infUpgCost[7] = 4;
	infUpgCost[8] = 8;
	infUpgCost[9] = 12;
	infUpgCost[10] = 100;
	infUpgCost[11] = 300;
	infUpgCost[12] = 600;
	infUpgCost[13] = 1000;
	infUpgCost[14] = 1800;
	infUpgCost[15] = 3000;
	infBUpgCost[1] = strToBignum("1.0e6");
	infBUpgCost[2] = strToBignum("7.0e6");
	infBUpgCost[3] = strToBignum("4.5e7");
	infBUpgCost[4] = strToBignum("3.8e10");
	infBUpgCost[5] = strToBignum("2.0e13");
	infBUpgCost[6] = strToBignum("4.0e17");
	infBRebuyableUpgCost = strToBignum("5.0e6");
	infBRebuyableUpgCostMult.setRealnum(200);

	infNeed1.setBignum(1, 24);
	infNeed2.setBignum(1.145, 14);
	infNeed3.setBignum(6.66, 11);
	infNeed4.setBignum(1, 16);
	infThr1 = strToBignum("1.79e308");
	infThr2 = strToBignum("1.00e900");
	infThr3 = strToBignum("1.00e2700");
	infThr4 = strToBignum("1.00e6666");
	infBUnlockCost = strToBignum("1.00e295");

	aveEleCost[1] = strToBignum("1.00e2895");
	aveEleCost[2] = strToBignum("1.00e3240");
	aveEleCost[3] = strToBignum("1.00e3600");
	aveEleCost[4] = strToBignum("1.00e4095");
	aveEleCost[5] = strToBignum("1.00e4451");
	aveEleCost[6] = strToBignum("1.00e4830");
	aveEleCost[7] = strToBignum("1.00e5140");
	aveEleCost[8] = strToBignum("1.00e5340");
	aveEleCost[9] = strToBignum("1.00e9999");

	aveMsNeedPos[1] = 1;
	aveMsNeedNeg[1] = 0;

	aveMsNeedPos[2] = 0;
	aveMsNeedNeg[2] = 1;

	aveMsNeedPos[3] = 2;
	aveMsNeedNeg[3] = 0;

	aveMsNeedPos[4] = 1;
	aveMsNeedNeg[4] = 2;

	aveMsNeedPos[5] = 3;
	aveMsNeedNeg[5] = 1;

	aveMsNeedPos[6] = 4;
	aveMsNeedNeg[6] = 4;
}

inline void aftinit() {
	int curX, curY;
	// Menu
	std::string menuString = "menu_1";
	for (re int i = 1; i <= maxMenu; ++i) {
		menuString = "menu_" + intToStr(i);

		sprintf(menuText[i], "%s",
		        sent[menuString].c_str());
		menuWidth[i] = textwidth(menuText[i]);
	}
	menuIsOpen[1] = true;
	menuIsOpen[2] = true;
	menuIsOpen[3] = true;
	menuIsOpen[4] = true;
	curMenu = 1;
	// Menu1
	menuString = "menu_1_";
	for (re int i = 1; i <= max1Menu; ++i) {
		menuString = "menu_1_" + intToStr(i);
		sprintf(menu1Text[i], "%s",
		        sent[menuString].c_str());
		menu1Width[i] = textwidth(menu1Text[i]);
	}
	// Menu3
	menu3IsOpen[1] = true;
	menuString = "menu_3_";
	for (re int i = 1; i <= max3Menu; ++i) {
		menuString = "menu_3_" + intToStr(i);
		sprintf(menu3Text[i], "%s",
		        sent[menuString].c_str());
		menu3Width[i] = textwidth(menu3Text[i]);
	}
	// Menu5
	menu5IsOpen[1] = true;
	menuString = "menu_5_";
	for (re int i = 1; i <= max5Menu; ++i) {
		menuString = "menu_5_" + intToStr(i);
		sprintf(menu5Text[i], "%s",
		        sent[menuString].c_str());
		menu5Width[i] = textwidth(menu5Text[i]);
	}
	// Menu6
	menuString = "menu_6_";
	for (re int i = 1; i <= max6Menu; ++i) {
		menuString = "menu_6_" + intToStr(i);
		sprintf(menu6Text[i], "%s",
		        sent[menuString].c_str());
		menu6Width[i] = textwidth(menu6Text[i]);
	}

	// Option
	std::string optString = "opt_1";
	curX = optRectGap;
	curY = 160;
	for (re int i = 1; i <= maxOpt; ++i) {
		optString = "opt_" + intToStr(i);
		int width = textwidth(sent[optString].c_str());
		if (width <= optRectWidth - 32) {
			optHeight[i] = curFontHeight;
		} else {
			optHeight[i] = rectp(0, 0, optRectWidth - 32, sent[optString]);
		}
		rectOpt[i].set(curX, curY, curX + optRectWidth, curY + 50,
		               RGB(96, 96, 96), RGB(96, 96, 96));

		if (i == 3) {
			int ptr3 = 0;
			for (re int j = 1; j <= maxLang; ++j) {
				rectLang[j].set(curX + 32,
				                curY + 50 + ptr3 + 4,
				                curX + optRectWidth - 32,
				                curY + 50 + ptr3 + 4 + 36,
				                RGB(96, 96, 96), RGB(96, 96, 96));
				ptr3 += 40;
			}
		}

		if (i == 4) {
			SliderFPS.simpleinit("FPS: ", curX + 24, curY + 50 - 20, optRectWidth - 48,
			                     10, 120, FPS);
			SliderFPS.pushPre(10);
			SliderFPS.pushPre(30);
			SliderFPS.pushPre(60);
			SliderFPS.pushPre(120);
		}

		if (!(i % 3)) {
			curY += 60;
			curX = optRectGap;
		} else {
			curX += optRectWidth + optRectGap;
		}
	}

	voidLightSacSet.simpleinit("", 200, 250, WINDOW_WIDTH - 400,
	                           0, 100, 0);
	voidLightSacSet.setVisible(true);
	voidLightSacSet.pushPre(0);
	voidLightSacSet.pushPre(25);
	voidLightSacSet.pushPre(50);
	voidLightSacSet.pushPre(75);
	voidLightSacSet.pushPre(100);

	setFont(16);

	updateDimMult();
	updateInfDimMult();
}
