inline void costNextStop(int i) {
	dim[i].cost = dim[i].cost * dim[i].costmult;
	if (dim[i].cost > strToBignum("1.00e80") &&
	        dim[i].cost < strToBignum("1.00e420")) {
		if (dimCostGrow > 8.6) dim[i].costmult = dim[i].costmult * 8;
		else dim[i].costmult = dim[i].costmult * 0.8 * dimCostGrow;
	}
	if (dim[i].cost > strToBignum("1.00e420")) dim[i].costmult = dim[i].costmult * 0.6 * dimCostGrow;
}

inline void buyMax(int i) {
	if (chaIn[7] && i > 2) {
		dim[i - 2].val = dim[i - 2].val - dim[i].cost;
	} else {
		voidPoint = voidPoint - dim[i].cost;
	}
	dim[i].val = dim[i].val + (ld)(1.00001);
	dim[i].mult = dim[i].mult * dimMultMult;
	++dim[i].bought;
	if (chaTimes[2])dim[i].mult = dim[i].mult * 1.05;
	if (i >= showDims)showDims = i + 1;
	if (showDims > maxDims)showDims = maxDims;
	if (i == maxDims) showCollapse = true;

	if (infChaIn[4]) {
		for (re int j = 1; j <= maxDims; ++j) {
			if (i == j)continue;
			if (dim[j].cost < dim[i].cost) {
				costNextStop(j);
			}
		}
	}

	costNextStop(i);

	if (i == 1 && !achIsOpen[1]) pushAch(1);
	if (i == 6 && !achIsOpen[2]) pushAch(2);
	if (i == 6 && chaIn[7] && !achIsOpen[11]) pushAch(11);

	if (infChaIn[1]) {
		for (re int j = 1; j < i; ++j) {
			dim[j].val.setRealnum(0);
		}
	}
}

inline void infBuyMax(int i) {
	infPoint = infPoint - infdim[i].cost;
	infdim[i].cost = infdim[i].cost * infdim[i].costmult;
	infdim[i].val = infdim[i].val + (ld)(1.00001);
	infdim[i].mult = infdim[i].mult * infDimMultMult;
	++infdim[i].bought;
	if (i >= infShowDims)infShowDims = i + 1;
	if (infShowDims > infMaxDims)infShowDims = infMaxDims;
}

inline void updateDimMult() {
	Bignum dimMM;
	dimMM.setRealnum(dimMultMult);
	for (re int i = 1; i <= maxDims; ++i) {
		dim[i].mult = dimMM ^ (ld)(dim[i].bought);
	}
}

inline void updateInfDimMult() {
	Bignum infDimMM;
	infDimMM = infDimMultMult;
	for (re int i = 1; i <= infMaxDims; ++i) {
		infdim[i].mult = infDimMM ^ (ld)(infdim[i].bought);
	}
}

inline void updateColMult() {
	Bignum colM;
	colM.setRealnum(colMult);
	collapseMult = colM ^ (ld)(collapseTime);
}

inline void buyMaxTrigger(int i) {
	while (voidPoint >= dim[i].cost && (!chaIn[7] || i <= 2)) {
		if ((!chaIn[4] && !chaIn[8]) || (i >= 1 && i <= 3)) {
			buyMax(i);
		} else {
			return;
		}
	}
	while ((i > 2 && chaIn[7]) && dim[i - 2].val >= dim[i].cost) {
		buyMax(i);
	}
}

inline void infBuyMaxTrigger(int i) {
	while (infPoint >= infdim[i].cost) {
		infBuyMax(i);
	}
}

inline void performGeneratorCollapse() {
	if (dim[6].val >= collapseReq) {
		statIsOpen[2] = true;
		++collapseTime;
		if (collapseTime < slowCollapseBegin) {
			collapseReq = collapseReq + normalCollapseReq;
		}
		if (collapseTime >= slowCollapseBegin &&
		        collapseTime < distantCollapseBegin) {
			collapseReq = collapseReq + slowCollapseReq;
		}
		if (collapseTime >= distantCollapseBegin) {
			collapseReq = collapseReq + distantCollapseReq;
		}
		collapseMult = collapseMult * colMult;
		if (!voidLightUpgBought[2]) resetCol();
	}
}
inline void performInfinity() {
	infPoint = infPoint + maxGetInfPoint;
	statIsOpen[3] = true;
	statIsOpen[4] = true;
	statIsOpen[5] = true;
	menuIsOpen[6] = true;
	menu6IsOpen[1] = true;
	Bignum basicInfTime(1.000001, 0);
	Bignum x1(1, 0);
	// x1 - avems1
	if (aveMsUnlock[1])x1 = aveMs1Reward;
	infTime = infTime + basicInfTime * x1;
	if (fastestInfTime > infPlayingTick) {
		fastestInfTime = infPlayingTick;
	}
	infPlayingTick = 0;
	maxGetInfPoint.setRealnum(0);
	if (!achIsOpen[4]) {
		pushAch(4);
	}
	for (int i = 1; i <= maxCha; ++i) {
		if (chaIn[i]) {
			chaTimes[i] = 1;
			chaIn[i] = false;
			--chaIns;
			if (fastestChallengeTime[i] > challengeTick) {
				fastestChallengeTime[i] = challengeTick;
			}
			if (i == 1 && !achIsOpen[5])pushAch(5);
			if (i == 4 && !achIsOpen[6])pushAch(6);
			if (i == 5 && !achIsOpen[7])pushAch(7);
			if (i == 8 && !achIsOpen[8]) {
				pushAch(8);
				menu6IsOpen[2] = true;
				menu6IsOpen[3] = true;
				for (re int i = 1; i <= 8; ++i)haveAuto[i] = true;
			}
		}
	}
	for (int i = 1; i <= maxInfCha; ++i) {
		if (infChaIn[i]) {
			infChaTimes[i] = 1;
			infChaIn[i] = false;
			--chaInfIns;
			if (fastestInfChallengeTime[i] > challengeTick) {
				fastestInfChallengeTime[i] = challengeTick;
			}
			if (i == 1 && !achIsOpen[13])pushAch(13);
			if (i == 3 && !achIsOpen[15])pushAch(15);
			if (i == 4) {
				infDimMultMult = 8.000001;
				updateInfDimMult();
			}
			if (i == 5 && !achIsOpen[19]) pushAch(19);
			if (i == 8 && !achIsOpen[20]) pushAch(20);
		}
	}
	resetInf();
}
inline void performVoidPace() {
	if (voidPoint >= paceReq) {
		statIsOpen[6] = true;
		++paceTime;
		if (paceTime < slowPaceBegin) {
			paceReq = paceReq * normalPaceMult;
		}
		if (paceTime >= slowPaceBegin && paceTime < distantPaceBegin) {
			paceReq = paceReq * slowPaceMult;
		}
		if (paceTime >= distantPaceBegin) {
			paceReq = paceReq * distantPaceMult;
		}
		colMult *= paceMult;

		if (!achIsOpen[18])pushAch(18);
		resetPace();
	}
}
