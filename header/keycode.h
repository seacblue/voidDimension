#ifndef _KEYCODE_H
#define _KEYCODE_H

#ifndef _BIGNUM_H
#include "bignum.h"
#endif

#include <string>
#include <cmath>
#define re register

const int ENCODELEN = 32768;

inline std::string scbDecode(std::string s) {
	int ssize = s.length();
	int fenceunt = sqrt(ssize);
	int jump = sqrt(fenceunt);

	std::string decode1, decode2;
	decode1.clear();
	decode2.clear();
	for (re int fence = 0; fence < fenceunt; ++fence) {
		for (re int i = fence; i < ssize; i += fenceunt) {
			decode1 += s[i];
		}
	}
	for (re int i = ssize - 1; i >= 0; --i) {
		decode2 += decode1[i];
	}
	for (re int i = 0, j = 1; i < ssize; ++i) {
		int c = (int)(decode2[i]) + j;
		if (c > 126)c -= (126 - 32 + 1);
		decode2[i] = c;
		j = (j + jump) % 10;
	}
	return decode2;
}

inline std::string scbEncode(std::string s) {
	int ssize = s.length();
	int fenceunt = sqrt(ssize);
	int jump = sqrt(fenceunt);
	std::string encode1, encode2;
	encode1.clear();
	encode2.clear();
	char cc[ENCODELEN] = {'\0'};

	for (re int i = 0, j = 1; i < ssize; ++i) {
		int c = (int)(s[i]) - j;
		if (c < 32)c += (126 - 32 + 1);
		s[i] = c;
		j = (j + jump) % 10;
	}
	for (re int i = ssize - 1; i >= 0; --i) {
		encode1 += s[i];
	}
	int ptr = 0;
	for (re int fence = 0; fence < fenceunt; ++fence) {
		for (re int i = fence; i < ssize; i += fenceunt, ++ptr) {
			cc[i] = encode1[ptr];
		}
	}
	encode2 = cc;
	return encode2;
}

#endif
