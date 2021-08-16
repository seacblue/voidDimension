inline void save(char* saveFile) {
	std::ofstream saveF;
	saveF.open(saveFile);

#define pSave(x,y) saveF << pushSave(x,y) << std::endl
	pSave("voidPoint", voidPoint);
	pSave("dimMultMult", dimMultMult);
	pSave("showDims", showDims);

	pSave("showCollapse", showCollapse);
	pSave("collapseReq", collapseReq);
	pSave("collapseMult", collapseMult);
	pSave("colMult", colMult);
	pSave("basicColMult", basicColMult);
	pSave("collapseTime", collapseTime);
	pSave("normalCollapseReq", normalCollapseReq);
	pSave("slowCollapseBegin", slowCollapseBegin);
	pSave("slowCollapseReq", slowCollapseReq);
	pSave("distantCollapseBegin", distantCollapseBegin);
	pSave("distantCollapseReq", distantCollapseReq);

	pSave("showPace", showPace);
	pSave("paceReq", paceReq);
	pSave("paceMult", paceMult);
	pSave("paceTime", paceTime);
	pSave("normalPaceMult", normalPaceMult);
	pSave("slowPaceBegin", slowPaceBegin);
	pSave("slowPaceMult", slowPaceMult);
	pSave("distantPaceBegin", distantPaceBegin);
	pSave("distantPaceMult", distantPaceMult);

	pSave("beginPlayingTime", beginPlayingTime);
	pSave("lastInfTime", lastInfTime);
	pSave("fastestInfTime", fastestInfTime);
	pSave("FPS", FPS);
	for (re int i = 1; i <= maxMenu; ++i) {
		pSave("menuIsOpen" + intToStr(i), menuIsOpen[i]);
	}
	for (re int i = 1; i <= max1Menu; ++i) {
		pSave("menu1IsOpen" + intToStr(i), menu1IsOpen[i]);
	}
	for (re int i = 1; i <= max3Menu; ++i) {
		pSave("menu3IsOpen" + intToStr(i), menu3IsOpen[i]);
	}
	for (re int i = 1; i <= max5Menu; ++i) {
		pSave("menu5IsOpen" + intToStr(i), menu5IsOpen[i]);
	}
	for (re int i = 1; i <= max6Menu; ++i) {
		pSave("menu6IsOpen" + intToStr(i), menu6IsOpen[i]);
	}
	for (re int i = 1; i <= maxStat; ++i) {
		pSave("statIsOpen" + intToStr(i), statIsOpen[i]);
	}
	for (re int i = 1; i <= maxAch; ++i) {
		pSave("achIsOpen" + intToStr(i), achIsOpen[i]);
	}
	for (re int i = 1; i <= maxDims; ++i) {
		pSave("dim_val" + intToStr(i), dim[i].val);
		pSave("dim_mult" + intToStr(i), dim[i].mult);
		pSave("dim_cost" + intToStr(i), dim[i].cost);
		pSave("dim_costmult" + intToStr(i), dim[i].costmult);
		pSave("dim_infmult" + intToStr(i), dim[i].infMult);
		pSave("dim_infcost" + intToStr(i), dim[i].infCost);
		pSave("dim_bought" + intToStr(i), dim[i].bought);
	}
	for (re int i = 1; i <= infMaxDims; ++i) {
		pSave("diminf_val" + intToStr(i), infdim[i].val);
		pSave("diminf_mult" + intToStr(i), infdim[i].mult);
		pSave("diminf_cost" + intToStr(i), infdim[i].cost);
		pSave("diminf_costmult" + intToStr(i), infdim[i].costmult);
		pSave("diminf_infmult" + intToStr(i), infdim[i].infMult);
		pSave("diminf_infcost" + intToStr(i), infdim[i].infCost);
		pSave("diminf_bought" + intToStr(i), infdim[i].bought);
	}
	for (re int i = 1; i <= maxCha; ++i) {
		pSave("chaIn" + intToStr(i), chaIn[i]);
		pSave("chaTimes" + intToStr(i), chaTimes[i]);
		pSave("fastestCT" + intToStr(i), fastestChallengeTime[i]);
	}
	for (re int i = 1; i <= maxInfCha; ++i) {
		pSave("infChaIn" + intToStr(i), infChaIn[i]);
		pSave("infChaTimes" + intToStr(i), infChaTimes[i]);
		pSave("fastestICT" + intToStr(i), fastestInfChallengeTime[i]);
		pSave("infChaUnlocked" + intToStr(i), infChaUnlocked[i]);
	}

	pSave("chaIns", chaIns);
	pSave("chaInfIns", chaInfIns);
	pSave("beginCT", beginChallengeTime);
	for (re int i = 1; i <= maxInfUpg; ++i) {
		pSave("haveInfUpg" + intToStr(i), haveInfUpg[i]);
	}
	for (re int i = 1; i <= maxInfBUpg; ++i) {
		pSave("haveBInfUpg" + intToStr(i), haveBInfUpg[i]);
	}
	pSave("infPoint", infPoint);
	pSave("maxInfPoint", maxInfPoint);
	pSave("maxInfSpd", maxInfSpd);
	pSave("infTimeNew", infTime);
	pSave("infRebuyableUpgCost", infRebuyableUpgCost);
	pSave("IPRebuyMult", IPRebuyMult);
	pSave("infRebuyableUpgAffect", infRebuyableUpgAffect);
	for (re int i = 1; i <= maxAuto; ++i) {
		pSave("haveAuto" + intToStr(i), haveAuto[i]);
		pSave("activeAuto" + intToStr(i), activeAuto[i]);
		pSave("curTickAuto" + intToStr(i), curTickAuto[i]);
		pSave("maxTickAuto" + intToStr(i), maxTickAuto[i]);
		pSave("costAuto" + intToStr(i), costAuto[i]);
		pSave("costMultAuto" + intToStr(i), costMultAuto[i]);
	}
	pSave("auto7max", auto7max);
	pSave("auto8min", auto8min);
	pSave("auto9max", auto9max);
	pSave("maxCha8VoidPoint", maxCha8VoidPoint);
	pSave("dimCostGrow", dimCostGrow);
	pSave("infBRebuyableUpgCost", infBRebuyableUpgCost);
	pSave("infBRebuyableUpgCostMult", infBRebuyableUpgCostMult);

	pSave("infDimUnlocked", infDimUnlocked);
	pSave("infPower", infPower);
	pSave("infDimMultMult", infDimMultMult);
	pSave("basicInfDimMultMult", basicInfDimMultMult);
	pSave("infShowDims", infShowDims);

	pSave("playingTick", playingTick);
	pSave("challengeTick", challengeTick);
	pSave("infPlayingTick", infPlayingTick);

	for (re int i = 1; i <= maxManual; ++i) {
		pSave("enableSpoiler" + intToStr(i), enableSpoiler[i]);
	}

	pSave("voidLightUnlocked", voidLightUnlocked);
	pSave("voidLight", voidLight);
	pSave("voidLightSec", voidLightSec);
	pSave("voidLightSacrifice", voidLightSacrifice);

	for (re int i = 1; i <= maxVoidLightUpg; ++i) {
		pSave("voidLightUpgBought" + intToStr(i), voidLightUpgBought[i]);
	}

	pSave("aveFreeEle", aveFreeEle);
	pSave("avePosEle", avePosEle);
	pSave("aveNegEle", aveNegEle);
	pSave("aveCurEle", aveCurEle);

	saveF.close();
}

inline void loadSetVal(std::string lef, std::string rig) {
	// Single Variable
	if (lef == "voidPoint") {
		voidPoint.setPrnt(rig);
		return;
	}
	if (lef == "dimMultMult") {
		dimMultMult = strToDouble(rig);
		return;
	}
	if (lef == "showDims") {
		showDims = strToInt(rig);
		return;
	}
	if (lef == "showCollapse") {
		showCollapse = strToBool(rig);
		return;
	}
	if (lef == "collapseReq") {
		collapseReq.setPrnt(rig);
		return;
	}
	if (lef == "collapseMult") {
		collapseMult.setPrnt(rig);
		return;
	}
	if (lef == "colMult") {
		colMult = strToDouble(rig);
		return;
	}
	if (lef == "basicColMult") {
		basicColMult = strToDouble(rig);
		return;
	}
	if (lef == "collapseTime") {
		collapseTime = strToInt(rig);
		return;
	}
	if(lef == "normalCollapseReq"){
		normalCollapseReq.setPrnt(rig);
		return;
	}
	if(lef == "slowCollapseBegin"){
		slowCollapseBegin = strToInt(rig);
		return;
	}
	if(lef == "slowCollapseReq"){
		slowCollapseReq.setPrnt(rig);
		return;
	}
	if(lef == "distantCollapseBegin"){
		distantCollapseBegin = strToInt(rig);
		return;
	}
	if(lef == "distantCollapseReq"){
		distantCollapseReq.setPrnt(rig);
		return;
	}

	if (lef == "showPace") {
		showPace = strToBool(rig);
		return;
	}
	if (lef == "paceReq") {
		paceReq.setPrnt(rig);
		return;
	}
	if (lef == "paceMult") {
		paceMult = strToDouble(rig);
		return;
	}
	if (lef == "paceTime") {
		paceTime = strToInt(rig);
		return;
	}
	if (lef == "normalPaceMult") {
		normalPaceMult.setPrnt(rig);
		return;
	}
	if (lef == "slowPaceBegin") {
		slowPaceBegin = strToInt(rig);
		return;
	}
	if (lef == "slowPaceMult") {
		slowPaceMult.setPrnt(rig);
		return;
	}
	if (lef == "distantPaceBegin") {
		distantPaceBegin = strToInt(rig);
		return;
	}
	if (lef == "distantPaceMult") {
		distantPaceMult.setPrnt(rig);
		return;
	}

	if (lef == "chaIns") {
		chaIns = strToInt(rig);
		return;
	}
	if (lef == "chaInfIns") {
		chaInfIns = strToInt(rig);
		return;
	}
	if (lef == "beginCT") {
		beginChallengeTime = strToInt(rig);
		return;
	}

	if (lef == "beginPlayingTime") {
		beginPlayingTime = strToInt(rig);
		return;
	}
	if (lef == "lastInfTime") {
		lastInfTime = strToInt(rig);
		return;
	}
	if (lef == "fastestInfTime") {
		fastestInfTime = strToInt(rig);
		return;
	}

	if (lef == "infPoint") {
		infPoint.setPrnt(rig);
		return;
	}
	if (lef == "maxInfPoint") {
		maxInfPoint.setPrnt(rig);
		return;
	}
	if (lef == "maxInfSpd") {
		maxInfSpd.setPrnt(rig);
		return;
	}
	if (lef == "infTime") {
		infTimeOld = strToInt(rig);
		return;
	}
	if (lef == "infTimeNew") {
		infTime.setPrnt(rig);
		return;
	}
	if (lef == "infRebuyableUpgCost") {
		infRebuyableUpgCost.setPrnt(rig);
		return;
	}
	if (lef == "IPRebuyMult") {
		IPRebuyMult.setPrnt(rig);
		return;
	}
	if (lef == "infRebuyableUpgAffect") {
		infRebuyableUpgAffect.setPrnt(rig);
		return;
	}

	if (lef == "auto7max") {
		auto7max.setPrnt(rig);
		return;
	}
	if (lef == "auto8min") {
		auto8min.setPrnt(rig);
		return;
	}
	if (lef == "auto9max") {
		auto9max.setPrnt(rig);
		return;
	}

	if (lef == "maxCha8VoidPoint") {
		maxCha8VoidPoint.setPrnt(rig);
		return;
	}
	if (lef == "dimCostGrow") {
		dimCostGrow = strToDouble(rig);
		return;
	}
	if (lef == "infBRebuyableUpgCost") {
		infBRebuyableUpgCost.setPrnt(rig);
		return;
	}
	if (lef == "infBRebuyableUpgCostMult") {
		infBRebuyableUpgCostMult.setPrnt(rig);
		return;
	}
	if (lef == "infDimUnlocked") {
		infDimUnlocked = strToBool(rig);
		return;
	}
	if (lef == "infPower") {
		infPower.setPrnt(rig);
		return;
	}
	if (lef == "infDimMultMult") {
		infDimMultMult.setPrnt(rig);
		return;
	}
	if (lef == "basicInfDimMultMult") {
		basicInfDimMultMult.setPrnt(rig);
	}
	if (lef == "infShowDims") {
		infShowDims = strToInt(rig);
		return;
	}

	if (lef == "playingTick") {
		playingTick = strToInt(rig);
		return;
	}
	if (lef == "challengeTick") {
		challengeTick = strToInt(rig);
		return;
	}
	if (lef == "infPlayingTick") {
		infPlayingTick = strToInt(rig);
		return;
	}
	if (lef == "FPS") {
		FPS = strToInt(rig);
		return;
	}

	if (lef == "voidLightUnlocked") {
		voidLightUnlocked = strToBool(rig);
		return;
	}
	if (lef == "voidLight") {
		voidLight.setPrnt(rig);
		return;
	}
	if (lef == "voidLightSec") {
		voidLightSec.setPrnt(rig);
		return;
	}
	if (lef == "voidLightSacrifice") {
		voidLightSacrifice = strToDouble(rig);
	}

	if (lef == "aveFreeEle") {
		aveFreeEle = strToInt(rig);
		return;
	}
	if (lef == "avePosEle") {
		avePosEle = strToInt(rig);
		return;
	}
	if (lef == "aveNegEle") {
		aveNegEle = strToInt(rig);
		return;
	}
	if (lef == "aveCurEle") {
		aveCurEle = strToInt(rig);
		return;
	}
	// Array
#define findp(_,__,___) \
	searchKey = _; \
	findPos = lef.find(searchKey); \
	if (findPos != lef.npos) { \
		findPos += searchKey.length(); \
		int arrayPos = strToInt(lef.substr(findPos, lefSize - findPos + 1)); \
		if (arrayPos > __)return; \
		___; \
		return; \
	}
	size_t findPos;
	int lefSize = lef.length();
	std::string searchKey;

	findp("menuIsOpen", maxMenu, menuIsOpen[arrayPos] = strToBool(rig));
	findp("menu1IsOpen", max1Menu, menu1IsOpen[arrayPos] = strToBool(rig));
	findp("menu3IsOpen", max3Menu, menu3IsOpen[arrayPos] = strToBool(rig));
	findp("menu5IsOpen", max5Menu, menu5IsOpen[arrayPos] = strToBool(rig));
	findp("menu6IsOpen", max6Menu, menu6IsOpen[arrayPos] = strToBool(rig));
	findp("statIsOpen", maxStat, statIsOpen[arrayPos] = strToBool(rig));
	findp("achIsOpen", maxAch, achIsOpen[arrayPos] = strToBool(rig));

	findp("dim_val", maxDims, dim[arrayPos].val.setPrnt(rig));
	findp("dim_mult", maxDims, dim[arrayPos].mult.setPrnt(rig));
	findp("dim_cost", maxDims, dim[arrayPos].cost.setPrnt(rig));
	findp("dim_costmult", maxDims, dim[arrayPos].costmult.setPrnt(rig));
	findp("dim_infmult", maxDims, dim[arrayPos].infMult.setPrnt(rig));
	findp("dim_infcost", maxDims, dim[arrayPos].infCost.setPrnt(rig));
	findp("dim_bought", maxDims, dim[arrayPos].bought = strToInt(rig));

	findp("diminf_val", infMaxDims, infdim[arrayPos].val.setPrnt(rig));
	findp("diminf_mult", infMaxDims, infdim[arrayPos].mult.setPrnt(rig));
	findp("diminf_cost", infMaxDims, infdim[arrayPos].cost.setPrnt(rig));
	findp("diminf_costmult", maxDims, infdim[arrayPos].costmult.setPrnt(rig));
	findp("diminf_infmult", infMaxDims, infdim[arrayPos].infMult.setPrnt(rig));
	findp("diminf_infcost", infMaxDims, infdim[arrayPos].infCost.setPrnt(rig));
	findp("diminf_bought", infMaxDims, infdim[arrayPos].bought = strToInt(rig));

	findp("chaIn", maxCha, chaIn[arrayPos] = strToBool(rig));
	findp("chaTimes", maxCha, chaTimes[arrayPos] = strToInt(rig));
	findp("fastestCT", maxCha, fastestChallengeTime[arrayPos] = strToInt(rig));

	findp("infChaIn", maxInfCha, infChaIn[arrayPos] = strToBool(rig));
	findp("infChaTimes", maxInfCha, infChaTimes[arrayPos] = strToInt(rig));
	findp("fastestICT", maxInfCha, fastestInfChallengeTime[arrayPos] = strToInt(rig));
	findp("infChaUnlocked", maxInfCha, infChaUnlocked[arrayPos] = strToBool(rig));

	findp("haveInfUpg", maxInfUpg, haveInfUpg[arrayPos] = strToBool(rig));
	findp("haveBInfUpg", maxInfBUpg, haveBInfUpg[arrayPos] = strToBool(rig));


	findp("haveAuto", maxAuto, haveAuto[arrayPos] = strToBool(rig));
	findp("activeAuto", maxAuto, activeAuto[arrayPos] = strToBool(rig));
	findp("curTickAuto", maxAuto, curTickAuto[arrayPos] = strToInt(rig));
	findp("maxTickAuto", maxAuto, maxTickAuto[arrayPos] = strToDouble(rig));
	findp("costAuto", maxAuto, costAuto[arrayPos].setPrnt(rig));
	findp("costMultAuto", maxAuto, costMultAuto[arrayPos].setPrnt(rig));

	findp("enableSpoiler", maxManual, enableSpoiler[arrayPos] = strToBool(rig));

	findp("voidLightUpgBought", maxVoidLightUpg, voidLightUpgBought[arrayPos] = strToBool(rig));
}
