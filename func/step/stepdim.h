inline void stepDimFunc() {
	for (re int i = 1; i <= maxDims; ++i) {
		ld x1 = 0, x2 = 0, x4 = 0;
		Bignum x3(0, 0);
		Bignum x5(0, 0), x6(0, 0), c1(1, 0);
		Bignum x7(0, 0), x8(0, 0), x9(0, 0);
		Bignum x10(0, 0), a1(0, 0), x11(1, 0);
		// x1 - infUpg 1
		// x2 - infUpg 3
		// x3 - infUpg 4,5,6
		// x4 - infUpg 10
		// x5 - infUpg 11
		// x6 - infUpg 12,13,14
		// c1 - challenge 1
		// x7 - breakInfUpg 1
		// x8 - breakInfUpg 2
		// x9 - vlu 9
		// x10 - infinity power
		// a1 - achievement 16
		// x11 - avems5
		if (haveInfUpg[1])x1 = 1;
		if (i == 1 && haveInfUpg[3])x2 = infUpg3Reward;
		if (((i == 1 || i == 6) && haveInfUpg[4]) ||
		        ((i == 2 || i == 5) && haveInfUpg[5]) ||
		        ((i == 3 || i == 4) && haveInfUpg[6])) {
			x3 = infUpg4Reward;
		}
		if (haveInfUpg[10])x4 = 2;
		if (i == 1 && haveInfUpg[11])x5 = infUpg11Reward;
		if (((i == 1 || i == 6) && haveInfUpg[12]) ||
		        ((i == 2 || i == 5) && haveInfUpg[13]) ||
		        ((i == 3 || i == 4) && haveInfUpg[14])) {
			x6 = infUpg12Reward;
		}

		if (i == 1 && chaTimes[1])c1 = cha1Buff1;
		if (i == 2 && chaTimes[1])c1 = cha1Buff2;

		if (haveBInfUpg[1])x7 = infBUpg1Reward;
		if (haveBInfUpg[2])x8 = infBUpg2Reward;
		if (voidLightUpgBought[9]) {
			if (i == 1)x9 = infBUpg6Reward1;
			if (i == 3)x9 = infBUpg6Reward2;
			if (i == 5)x9 = infBUpg6Reward3;
		}

		x10 = infPowerTranslate;

		if (achIsOpen[16] && i == 1)a1 = ach16Reward;
		if (aveMsUnlock[5] && i == 1)x11.setBignum(1, 15);

		if (infChaIn[5] || infChaIn[8]) {
			x1 = 0.0;
			x2 = 0.0;
			x3.setRealnum(0.0);
			x4 = 0.0;
			x5.setRealnum(0.0);
			x6.setRealnum(0.0);
			x7.setRealnum(0.0);
			x8.setRealnum(0.0);
			x9.setRealnum(0.0);
		}

		dim[i].showMult = dim[i].mult * collapseMult *
		                  (x1 + 1) * (x2 + 1) * (x3 + 1) *
		                  (x4 + 1) * (x5 + 1) * (x6 + 1) *
		                  c1 * (x7 + 1) * (x8 + 1) * (x9 + 1) *
		                  x10 * (a1 + 1) * x11;
		if (infChaIn[2]) {
			dim[i].showMult = dim[i].mult * x10;
		}
	}

	if (chaIn[1]) {
		dim[1].showMult.setRealnum(1);
		dim[2].showMult.setRealnum(1);
	}
	if (chaIn[7]) {
		dim[1].showMult.setRealnum(1);
	}

	voidPointSec = dim[1].val * dim[1].showMult;
	if (chaIn[7]) voidPointSec = voidPointSec + dim[2].val * dim[2].showMult;
	if (chaIn[5] || infChaIn[3]) {
		if (voidPointSec >= 1000) {
			voidPointSec = voidPointSec / cha5antiVP;
		}
	}
	if (infChaTimes[6]) voidPointSec = voidPointSec ^ 1.035;
	if (infChaIn[6] || infChaIn[8]) voidPointSec = voidPointSec ^ 0.1;
	voidPoint = voidPoint + voidPointSec / (ld)(FPS);
	for (re int i = 2; i <= maxDims; ++i) {
		dim[i - 1].val = dim[i - 1].val +
		                 dim[i].val * dim[i].showMult / (ld)(FPS);
	}

	// Infinity Generators
	infPowerTranslate = (infPower ^ 1.82) * 9.41 + 1.0;
	if (infChaTimes[1]) infPowerTranslate = (infPower ^ 3.16) * 3.04 + 1.0;
	if (infChaIn[1]) infPowerTranslate = 1.0;

	// Void Pace
	if (voidPoint >= strToBignum("1.00e1000"))showPace = true;

	// vlu7
	slowCollapseBegin = basicSlowCollapseBegin;
	if (voidLightUpgBought[7]) slowCollapseBegin = 80;
}
