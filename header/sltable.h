#ifndef _SLTABLE_H

#define _SLTABLE_H

#include "keycode.h"

inline std::string pushSave(std::string, int);
inline std::string pushSave(std::string, ld);
inline std::string pushSave(std::string, bool);
inline std::string pushSave(std::string, Bignum);
inline std::string pushSave(std::string, time_t);

inline std::string pushSave(std::string name, int val) {
	std::string base = name + "=" + intToStr(val);
	std::string decode = scbDecode(base);
	return decode;
}
inline std::string pushSave(std::string name, ld val) {
	std::string base = name + "=" + doubleToStr(val);
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

#endif
