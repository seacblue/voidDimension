inline void resetDimCost() {
	if (chaIn[3]) {
		dim[1].cost = strToBignum("100");
		dim[1].costmult = strToBignum("9.0e5");
		dim[2].cost = strToBignum("1.2e5");
		dim[2].costmult = strToBignum("1.0e7");
		dim[3].cost = strToBignum("9.0e9");
		dim[3].costmult = strToBignum("3.0e9");
		dim[4].cost = strToBignum("1.0e14");
		dim[4].costmult = strToBignum("1.0e12");
		dim[5].cost = strToBignum("1.0e20");
		dim[5].costmult = strToBignum("7.0e13");
		dim[6].cost = strToBignum("1.0e30");
		dim[6].costmult = strToBignum("3.0e16");
	} else {
		if (chaTimes[3]) {
			dim[1].cost = strToBignum("10");
			dim[1].costmult = strToBignum("95") * dimCostGrow;
			dim[2].cost = strToBignum("50");
			dim[2].costmult = strToBignum("950") * dimCostGrow;
			dim[3].cost = strToBignum("1800");
			dim[3].costmult = strToBignum("9500") * dimCostGrow;
			dim[4].cost = strToBignum("15000");
			dim[4].costmult = strToBignum("9.5e6") * dimCostGrow;
			dim[5].cost = strToBignum("5.0e6");
			dim[5].costmult = strToBignum("9.5e7") * dimCostGrow;
			dim[6].cost = strToBignum("9.0e8");
			dim[6].costmult = strToBignum("9.5e9") * dimCostGrow;
		} else {
			dim[1].cost = strToBignum("10");
			dim[1].costmult = strToBignum("100") * dimCostGrow;
			dim[2].cost = strToBignum("50");
			dim[2].costmult = strToBignum("1000") * dimCostGrow;
			dim[3].cost = strToBignum("2000");
			dim[3].costmult = strToBignum("10000") * dimCostGrow;
			dim[4].cost = strToBignum("20000");
			dim[4].costmult = strToBignum("1.0e7") * dimCostGrow;
			dim[5].cost = strToBignum("6.0e6");
			dim[5].costmult = strToBignum("1.0e8") * dimCostGrow;
			dim[6].cost = strToBignum("1.0e9");
			dim[6].costmult = strToBignum("1.0e10") * dimCostGrow;
		}
	}

	if (chaIn[7]) {
		dim[1].cost = strToBignum("1.5e1");
		dim[1].costmult = strToBignum("1.00e60");
		dim[2].cost = strToBignum("1.0e2");
		dim[2].costmult = strToBignum("1.00e60");
		dim[3].cost = strToBignum("8.0e7");
		dim[3].costmult = strToBignum("1.00e9");
		dim[4].cost = strToBignum("1.0e8");
		dim[4].costmult = strToBignum("2.00e10");
		dim[5].cost = strToBignum("1.0e30");
		dim[5].costmult = strToBignum("1.00e60");
		dim[6].cost = strToBignum("1.0e48");
		dim[6].costmult = strToBignum("1.00e70");
	}
}

inline void resetDimVal() {
	for (re int i = 1; i <= maxDims; ++i) {
		dim[i].mult.setRealnum(0.5);
		dim[i].val.setRealnum(0.0);
	}
}

inline void resetDim() {
	resetDimVal();
	resetDimCost();
}

inline void resetInfDimCost() {
	infdim[1].cost = strToBignum("1.0e7");
	infdim[1].costmult = strToBignum("1.00e4");
	infdim[2].cost = strToBignum("3.0e8");
	infdim[2].costmult = strToBignum("1.00e6");
	infdim[3].cost = strToBignum("1.0e10");
	infdim[3].costmult = strToBignum("4.00e7");
	infdim[4].cost = strToBignum("5.0e12");
	infdim[4].costmult = strToBignum("1.00e9");
	infdim[5].cost = strToBignum("8.0e16");
	infdim[5].costmult = strToBignum("6.00e11");
	infdim[6].cost = strToBignum("6.0e20");
	infdim[6].costmult = strToBignum("1.00e13");
}

inline void resetInfDimVal() {
	for (re int i = 1; i <= infMaxDims; ++i) {
		infdim[i].mult.setRealnum(0.5);
		infdim[i].val.setRealnum(0.0);
	}
}

inline void resetInfDim() {
	resetInfDimVal();
	resetInfDimCost();
}

inline void resetCol() {
	for (re int i = 1; i <= maxDims; ++i) {
		dim[i].val = 0;
		dim[i].mult = dim[i].infMult;
		dim[i].cost = dim[i].infCost;
		dim[i].bought = 0;
	}
	showCollapse = false;
	showDims = 1;
	if (achIsOpen[4])voidPoint.setRealnum(100);
	else voidPoint.setRealnum(10);
	if (achIsOpen[8] && chaIns) {
		voidPoint.setRealnum(2000000);
	}
	voidPointSec.setRealnum(0);
	resetDim();
}
inline void resetInf() {
	collapseReq.setBignum(1, 0);
	collapseMult.setBignum(1, 0);
	colMult = basicColMult;
	collapseTime = 0;
	collapseReq = 1;
	showCollapse = false;

	paceReq = basicPaceReq;
	paceTime = 0;
	showPace = false;
	if (haveInfUpg[8]) {
		++collapseTime;
		collapseReq = collapseReq + 1.00001;
		collapseMult = collapseMult * colMult;
	}
	resetCol();
}
inline void resetPace() {
	collapseReq.setBignum(1, 0);
	collapseMult.setBignum(1, 0);
	collapseTime = 0;
	collapseReq = 1;
	showCollapse = false;
	if (haveInfUpg[8]) {
		++collapseTime;
		collapseReq = collapseReq + 1.00001;
		collapseMult = collapseMult * colMult;
	}
	haveAuto[9] = true;
	statIsOpen[6] = true;
	resetCol();
}
