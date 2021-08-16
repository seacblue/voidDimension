inline void stepAftFunc() {
	// Update inf. dim.
	infDimMultMult = basicInfDimMultMult;
	if (voidLightUpgBought[4]) {
		infDimMultMult = infDimMultMult * voidLightUpg4Reward;
		updateInfDimMult();
	}
}
