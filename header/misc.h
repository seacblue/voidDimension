#ifndef _MISC_H
#include <string>
#include <cstring>

#define _MISC_H

typedef long long ll;
typedef long double ld;
#define re register

inline bool isLetter(char c) {
	if (c >= '0' && c <= '9')return true;
	if (c >= 'a' && c <= 'z')return true;
	if (c >= 'A' && c <= 'Z')return true;
	if (c == '.' || c == ',' || c == '!' || c == '?' || c == '%')return true;
	return false;
}

inline int boolToInt(bool x) {
	if (x)return 1;
	return 0;
}
inline std::string boolToStr(bool x) {
	if (x)return "1";
	return "0";
}

std::string intToStr(int x) {
	if (x >= 10) {
		std::string curStepAns = intToStr(x / 10);
		curStepAns += (x % 10 + '0');
		return curStepAns;
	}
	std::string curStepAns = "0";
	curStepAns[0] = x + '0';
	return curStepAns;
}

std::string intToStr(ll x) {
	if (x >= 10) {
		std::string curStepAns = intToStr(x / 10);
		curStepAns += (x % 10 + '0');
		return curStepAns;
	}
	std::string curStepAns = "0";
	curStepAns[0] = x + '0';
	return curStepAns;
}

std::string doubleToStr(ld x, int decimal = 2) {
	std::string intString = intToStr((int)x);
	if (decimal)intString += ".";
	x -= (int)x;
	for (re int i = 1; i <= decimal; ++i) {
		x *= 10;
		intString += (int)(x) + '0';
		x -= (int)x;
	}
	return intString;
	/*char pnm[20];
	sprintf (pnm,"%6.2f",(double)x);
	return (std::string)pnm;*/
}

inline int strToInt(std::string str) {
	int ssize = str.length();
	int base = 1, res = 0;
	for (re int i = ssize - 1; i >= 0; --i, base = (base << 3) + (base << 1)) {
		res += (str[i] ^ 48) * base;
	}
	return res;
}

inline ld strToDouble(std::string str) {
	int ssize = str.length();
	size_t dotpos = str.find(".");
	if (dotpos == str.npos){
		return (ld)strToInt(str);
	}
	int base = 1;
	ld res = 0;
	for (re int i = dotpos - 1; i >= 0; --i, base = (base << 3) + (base << 1)) {
		res += (str[i] ^ 48) * base;
	}
	ld decbase = 0.1;
	for (re int i = dotpos + 1; i < ssize; ++i, decbase *= 0.1) {
		res += (str[i] ^ 48) * decbase;
	}
	return res;
}

inline bool strToBool(std::string str) {
	if (str == "1")return true;
	return false;
}

inline std::string charToStr(char* s) {
	int len = strlen(s);
	std::string str;
	str.clear();
	for (int i = 0; i < len; ++i) {
		str += s[i];
	}
	return str;
}

#endif
