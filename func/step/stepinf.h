inline void stepInfFunc() {
	Bignum curInfPoint1(0, 0);
	Bignum curInfPoint2(0, 0);
	Bignum curInfPoint3(0, 0);
	Bignum curInfPoint4(0, 0);

	int cap1ColTime = collapseTime;
	if (cap1ColTime > 75) cap1ColTime = 75;

	ld c1 = 1;
	Bignum x1(1, 0);
	// c1 - InfCha 8
	// x1 - vlu3
	if (infChaTimes[8]) c1 = 31.4159;
	if (voidLightUpgBought[3]) x1 = voidLightUpg3RealReward;

	if (voidPoint <= infThr1) {
		curInfPoint1 = exporoot(voidPoint, infNeed1);
	}
	if (voidPoint > infThr1) {
		curInfPoint1 = exporoot(infThr1, infNeed1);
	}

	if (voidPoint > infThr1 && voidPoint <= infThr2) {
		curInfPoint2 = exporoot(voidPoint, infNeed2);
	}
	if (voidPoint > infThr2) {
		curInfPoint2 = exporoot(infThr2, infNeed2);
	}

	if (voidPoint > infThr2 && voidPoint <= infThr3) {
		curInfPoint3 = exporoot(voidPoint, infNeed3) ^ 0.82;
	}
	if (voidPoint > infThr3) {
		curInfPoint3 = exporoot(infThr3, infNeed3) ^ 0.82;
	}

	if (voidPoint > infThr3 && voidPoint <= infThr4) {
		curInfPoint4 = exporoot(voidPoint, infNeed4) ^ 0.833;
	}
	if (voidPoint > infThr4) {
		curInfPoint4 = exporoot(infThr4, infNeed4) ^ 0.833;
	}

	if (!infChaTimes[2]) {
		curInfPoint1 = (curInfPoint1 ^ (1.87)) * IPRebuyMult * pow(1.23, (ld)(cap1ColTime));
		curInfPoint2 = (curInfPoint2 ^ (3.11)) * IPRebuyMult;
		curInfPoint3 = (curInfPoint3 ^ (3.44)) * IPRebuyMult;
		curInfPoint4 = (curInfPoint4 ^ (4.98)) * IPRebuyMult * pow(1.02, (ld)(collapseTime));
	} else {
		curInfPoint1 = (curInfPoint1 ^ (2.06)) * IPRebuyMult * pow(1.31, (ld)(cap1ColTime));
		curInfPoint2 = (curInfPoint2 ^ (3.46)) * IPRebuyMult * 2.72;
		curInfPoint3 = (curInfPoint3 ^ (3.91)) * IPRebuyMult * 4.81 * pow(1.12, (ld)(collapseTime) / 3.63);
		curInfPoint4 = (curInfPoint4 ^ (5.19)) * IPRebuyMult * pow(1.03, (ld)(collapseTime));
	}

	Bignum curInfPoint = (curInfPoint1 + curInfPoint2 + curInfPoint3 + curInfPoint4) *
	                     c1 * x1;

	curInfPoint = floor(curInfPoint);

	//xyprintf(10, 20, "cIP1=%s", curInfPoint1.print(2).c_str());
	//xyprintf(10, 36, "cIP2=%s", curInfPoint2.print(2).c_str());
	//xyprintf(10, 52, "cIP3=%s", curInfPoint3.print(2).c_str());
	//xyprintf(10, 68, "cIP4=%s", curInfPoint4.print(2).c_str());

	if (curInfPoint > maxGetInfPoint)maxGetInfPoint = curInfPoint;
	if (infPoint > maxInfPoint)maxInfPoint = infPoint;
	ld temptime = (ld)infPlayingTick / (ld)FPS;
	curInfSpd = maxGetInfPoint / temptime;
	if (curInfSpd > maxInfSpd) maxInfSpd = curInfSpd;

	// Check Upgrade Reward
	// dimmultmult
	dimMultMult = 2.0000001;
	if (haveInfUpg[2])dimMultMult = 2.2000001; // infUpg 2
	if (chaTimes[7])dimMultMult = 2.4000001;   // challenge 7
	if (chaIn[2])dimMultMult = 1.000001;       // (debuff) C1
	// infupg11expo
	infUpg11Expo = 0.450001;
	if (chaIn[8]) infUpg11Expo = 0.700001;       // cha 8 in
	if (chaTimes[8]) infUpg11Expo = 1.120001;    // cha 8
	if (haveBInfUpg[3]) infUpg11Expo = 1.23001;  // breakinfupg 3
	if (voidLightUpgBought[1]) infUpg11Expo = 2.45001; // vlu1
	// breakInfUpg 4
	infUpg12Expo = 0.28001;
	if (chaIn[8]) infUpg12Expo = 0.400001;       // cha 8 in
	if (chaTimes[8]) infUpg12Expo = 0.80001;     // cha 8 rew
	if (haveBInfUpg[4]) infUpg12Expo = 1.10001;  // breakinfupg 4
	if (aveMsUnlock[4]) infUpg12Expo = aveMs4Reward;   // avems4

	// infUpg 3
	time_t curTime = time(NULL);
	int deltaTime = curTime - beginPlayingTime;
	infUpg3Reward = pow(log10(deltaTime), 1.6);
	// infUpg 4,5,6
	Bignum infTimeB;
	infTimeB = infTime;
	infUpg4Reward = infTimeB * 0.2;
	if (infChaTimes[3]) infUpg4Reward = infTimeB ^ 5.2;
	// infUpg 7
	basicColMult = 2.00001;
	if (haveInfUpg[7])basicColMult = 2.50001;  // infUpg 7
	if (chaTimes[6])basicColMult = 2.80001;    // challenge 6
	if (haveBInfUpg[5])basicColMult = 4.00001; // breakInfUpg 5
	// infUpg 11
	infUpg11Reward = infPoint ^ infUpg11Expo;
	if (achIsOpen[15]) infUpg11Reward = maxInfPoint ^ infUpg11Expo;
	// infUpg 12
	infUpg12Reward = infPoint ^ infUpg12Expo;
	if (achIsOpen[15]) infUpg12Reward = maxInfPoint ^ infUpg12Expo;

	// breakInfUpg 1
	infBUpg1Reward = exporoot(voidPoint, 1.07) ^ 2.95;
	// breakInfUpg 2
	infBUpg2Reward = (exporoot(maxCha8VoidPoint, 0.143) ^ 3.92) / 377;
	if (infBUpg2Reward > strToBignum("1.00e11")) {
		infBUpg2Reward = strToBignum("1.00e11");
		infBUpg2RewardHardcapped = true;
	}
	// breakInfUpg 6
	if (dim[2].val >= 100)infBUpg6Reward1 = exporoot(dim[2].val, 0.243) ^ 5.79;
	if (dim[4].val >= 100)infBUpg6Reward2 = exporoot(dim[4].val, 0.220) ^ 5.96;
	if (dim[6].val >= 3)  infBUpg6Reward3 = ((dim[6].val * 1.24) ^ 13.32);

	// Void Light
	voidLightSacIP = infPoint * voidLightSacrifice / 100.0;
	voidLightCanGet = (voidLightSacIP ^ 0.322) / 492893;
	x1.setRealnum(1); // Reuse
	// x1 - avems2
	if (aveMsUnlock[2]) x1 = aveMs2Reward;

	voidLightRealSec = voidLightSec * x1;
	voidLightRealCanGet = voidLightCanGet * x1;
	voidLight = voidLight + voidLightRealSec / FPS;

	// vlu3
	if (voidLight >= 60)voidLightUpg3Reward = exporoot(voidLight, 1.084);
	else voidLightUpg3Reward = 1.0000001;
	voidLightUpg3RealReward = voidLightUpg3Reward;
	if (aveMsUnlock[3]) voidLightUpg3RealReward = voidLightUpg3RealReward * aveMs3Reward;

	// vlu4
	if (voidLight >= 4000)voidLightUpg4Reward = exporoot(voidLight, 1.198) / 2.44;
	else voidLightUpg4Reward = 1.0000001;

	// vlu6
	if (voidLightUpgBought[6]) {
		infPoint = infPoint + maxInfSpd / (ld)(FPS);
	}

	// Ave
	Bignum nextEle;
	if (aveCurEle < maxAveEle)nextEle = aveEleCost[aveCurEle + 1];
	else nextEle.setBignum(1, 999999999);
	while (voidPoint > nextEle) {
		++aveCurEle;
		if (aveCurEle < maxAveEle)nextEle = aveEleCost[aveCurEle + 1];
		else nextEle.setBignum(1, 999999999);
		++aveFreeEle;
	}

	for (re int i = 1; i <= maxAveMilestone; ++i) {
		aveMsUnlock[i] = false;
		if (avePosEle >= aveMsNeedPos[i] &&
		        aveNegEle >= aveMsNeedNeg[i]) {
			aveMsUnlock[i] = true;
		}
	}

	int aveTotEle = aveFreeEle + avePosEle + aveNegEle;
	Bignum atebignum, afebignum, apebignum, anebignum;
	atebignum.setRealnum(aveTotEle);
	afebignum.setRealnum(aveFreeEle);
	apebignum.setRealnum(avePosEle);
	anebignum.setRealnum(aveNegEle);
	// avems1
	aveMs1Reward = (atebignum + 1.46) ^ 4.000001;
	// avems2
	aveMs2Reward = (atebignum + 0.81) ^ 2.527242;
	// avems3
	aveMs3Reward = (apebignum + 0.2) ^ 2.415209;
	// avems4
	if (!voidLightUpgBought[10]) aveMs4Reward = 1.10 + pow(aveNegEle / 1.72, 0.3652) / 5.4;
	else aveMs4Reward = 1.10 + pow(aveNegEle / 1.72, 0.5321) / 3.78;
}
