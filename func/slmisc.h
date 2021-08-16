inline std::string pushSave(std::string name, int val) {
	std::string base = name + "=" + intToStr(val);
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, ll val) {
	std::string base = name + "=" + intToStr(val);
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, ld val) {
	std::string base = name + "=" + doubleToStr(val, 6);
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, bool val) {
	std::string base = name + "=" + boolToStr(val);
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, Bignum val) {
	std::string base = name + "=" + val.prnt();
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, time_t val) {
	return pushSave(name, (int)val);
}

inline bool load(char* loadFile) {
	std::ifstream saveF;
	saveF.open(loadFile);
	if (!saveF.is_open())return false;

	std::string sentStr;
	while (1) {
		if (saveF.peek() == EOF) {
			break;
		}
		sentStr.clear();
		getline(saveF, sentStr);
		sentStr = scbEncode(sentStr);
		int equalpos = sentStr.find("="),
		    sentStrLen = sentStr.length();
		std::string equallef, equalrig;
		equallef = sentStr.substr(0, equalpos);
		equalrig = sentStr.substr(equalpos + 1, sentStrLen - equalpos);
		loadSetVal(equallef, equalrig);
	}

	saveF.close();
	return true;
}
