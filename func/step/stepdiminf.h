inline void stepInfDimFunc() {
	for (re int i = 1; i <= infMaxDims; ++i) {
		ld c1 = 1, c2 = 1;
		// c1 - InfCha 5
		// c2 - vlu8
		if (infChaTimes[5] && i == 1) c1 = 100;
		if (voidLightUpgBought[8]) c2 = 5;
		infdim[i].showMult = infdim[i].mult * c1 * c2;
	}

	infPowerSec = infdim[1].val * infdim[1].showMult;
	infPower = infPower + infPowerSec / (ld)(FPS);
	for (re int i = 2; i <= infMaxDims; ++i) {
		infdim[i - 1].val = infdim[i - 1].val +
		                    infdim[i].val * infdim[i].showMult / (ld)(FPS);
	}
}
