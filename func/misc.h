inline std::string intToTimeStr(int t) {
	if (t == 0) {
		return "0 " + sent["seconds"];
	}
	if (t <= 10 * FPS) {
		std::string statOutput;
		statOutput.clear();
		ld flo = (ld)t / (ld)FPS;
		statOutput += doubleToStr(flo, 3);
		statOutput += sent["space"];
		statOutput += sent["seconds"];
		return statOutput;
	} else {
		t /= FPS;
		std::string statOutput;
		statOutput.clear();
		int curSec = t;
		int curMin = curSec / 60;
		curSec -= curMin * 60;
		int curHour = curMin / 60;
		curMin %= 60;
		int curDay = curHour / 24;
		curHour %= 24;
		if (curDay) {
			statOutput += intToStr(curDay);
			statOutput += sent["space"];
			if (curDay == 1) {
				statOutput += sent["day"];
			} else {
				statOutput += sent["days"];
			}
			statOutput += sent["space"];
		}
		if (curHour || curDay) {
			statOutput += intToStr(curHour);
			statOutput += sent["space"];
			if (curHour == 1) {
				statOutput += sent["hour"];
			} else {
				statOutput += sent["hours"];
			}
			statOutput += sent["space"];
		}
		if (curMin || curHour || curDay) {
			statOutput += intToStr(curMin);
			statOutput += sent["space"];
			if (curMin == 1) {
				statOutput += sent["minute"];
			} else {
				statOutput += sent["minutes"];
			}
			statOutput += sent["space"];
		}
		if (curSec || curMin || curHour || curDay) {
			statOutput += intToStr(curSec);
			statOutput += sent["space"];
			if (curSec == 1) {
				statOutput += sent["second"];
			} else {
				statOutput += sent["seconds"];
			}
		}
		return statOutput;
	}
	return "";
}

inline std::string bignumToLength(Bignum x) {
	std::string outputS = "cm";
	if (x > 100.0) {
		x = x / 100.0;
		outputS = "m";
	}
	if (x > 1000.0) {
		x = x / 1000.0;
		outputS = "km";
	}
	if (x > 9460730472580.0) {
		x = x / 9460730472580.0;
		outputS = "ly";
	}
	return x.print(2) + sent["space"] + sent[outputS];
}

inline void setFont(int size) {
	curFontHeight = size;
	if (lang == "en")setfont(size, 0, "consolas");
	if (lang == "ch")setfont(size, 0, "ºÚÌå");
}

inline void setFontConsolas(int size) {
	curFontHeight = size;
	setfont(size, 0, "consolas");
}

inline void backwardComp(){
	if (infTimeOld > 0) {
		infTime.setRealnum(infTimeOld);
	}
}
