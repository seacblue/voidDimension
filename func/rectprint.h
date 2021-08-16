inline int rectpDivide(int x, int y, int w, std::string s) {
	int ssize = s.length();
	char buff[1024] = "";
	int ptr = -1, h = 0;
	for (int i = 0; i < ssize; ++i) {
		if (i < ssize - 1 && s[i] == '|' && s[i + 1] == '|') {
			xyprintf(x, y, buff);
			for (int j = 0; j <= ptr; ++j) {
				buff[j] = '\0';
			}
			ptr = -1;
			++i;
			y += curFontHeight;
			h += curFontHeight;
			continue;
		}
		if (s[i] < 0) {
			buff[++ptr] = s[i];
			buff[++ptr] = s[i + 1];
			if (textwidth(buff) >= w) {
				--ptr;
				buff[ptr] = '\0';
				xyprintf(x, y, buff);
				for (int j = 0; j <= ptr; ++j) {
					buff[j] = '\0';
				}
				ptr = -1;
				buff[++ptr] = s[i];
				buff[++ptr] = s[i + 1];
				y += curFontHeight;
				h += curFontHeight;
			}
			++i;
		} else {
			buff[++ptr] = s[i];
			if (textwidth(buff) >= w) {
				char c = buff[ptr];
				buff[ptr] = '\0';
				xyprintf(x, y, buff);
				for (int j = 0; j <= ptr; ++j) {
					buff[j] = '\0';
				}
				ptr = -1;
				buff[++ptr] = c;
				y += curFontHeight;
				h += curFontHeight;
			}
		}
	}
	if (~ptr) {
		xyprintf(x, y, buff);
		h += curFontHeight;
	}
	return h;
}

inline int rectpNotDivide(int x, int y, int w, std::string s) {
#define putline\
	xyprintf(x, y, buff); \
	int bsize = strlen(buff); \
	for (int j = 0; j < bsize; ++j) { \
		buff[j] = '\0'; \
	} \
	buffptr = 0; \
	y += curFontHeight; \
	h += curFontHeight
	int ssize = s.length();
	std::string words[1024];
	std::string gap[1024];
	int ptr = 1, h = 0;
	bool readingAscii = true;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == '|' && s[i + 1] == '|') {
			gap[ptr] += "||";
			++i;
			++ptr;
			readingAscii = true;
			continue;
		}
		if (readingAscii) {
			if (isLetter(s[i])) {
				words[ptr] += s[i];
			} else {
				gap[ptr] += s[i];
				readingAscii = false;
			}
		} else {
			if (!isLetter(s[i])) {
				gap[ptr] += s[i];
			} else {
				words[++ptr] += s[i];
				readingAscii = true;
			}
		}
	}
	int buffptr = 0;
	char buff[1024] = {'\0'};
	for (int i = 1; i <= ptr; ++i) {
		if (!buffptr && textwidth(words[i].c_str()) >= w) {
			int ssize = words[i].length();
			for (int j = 0; j < ssize; ++j) {
				buff[j] += words[i][j];
			}
			putline;
			continue;
		}
		if (textwidth(buff) + textwidth(words[i].c_str()) >= w) {
			putline;
			--i;
			continue;
		}
		int wordsize = words[i].length();
		for (int j = 0; j < wordsize; ++j, ++buffptr) {
			buff[buffptr] = words[i][j];
			if (words[i][j] < 0) {
				buff[j] += words[i][j + 1];
				++j;
			}
		}
		if (textwidth(buff) + textwidth(gap[i].c_str()) >= w) {
			putline;
			continue;
		}
		int gapsize = gap[i].length();
		for (int j = 0; j < gapsize; ++j, ++buffptr) {
			if (j < gapsize - 1 && gap[i][j] == '|' && gap[i][j + 1] == '|') {
				putline;
				break;
			}
			buff[buffptr] = gap[i][j];
		}
	}
	if (buffptr) {
		putline;
	}
	return h;
}

inline int rectp(int x, int y, int w, std::string s) {
	// If Language is English(or something else?), don't divide a single word
	if (lang != "en") {
		return rectpDivide(x, y, w, s);
	}
	return rectpNotDivide(x, y, w, s);
}

// Last Version
/*
inline int rectpDivide(int x, int y, int w, std::string s) {
	int ssize = s.length();
	char buff[1024] = "";
	int ptr = -1, h = 0;
	for (int i = 0; i < ssize; ++i) {
		if (i < ssize - 1 && s[i] == '|' && s[i + 1] == '|') {
			xyprintf(x, y, buff);
			for (int j = 0; j <= ptr; ++j) {
				buff[j] = '\0';
			}
			ptr = -1;
			++i;
			y += curFontHeight;
			h += curFontHeight;
			continue;
		}
		if (s[i] < 0) {
			buff[++ptr] = s[i];
			buff[++ptr] = s[i + 1];
			if (textwidth(buff) >= w) {
				--ptr;
				char c = buff[ptr];
				buff[ptr] = '\0';
				xyprintf(x, y, buff);
				for (int j = 0; j <= ptr; ++j) {
					buff[j] = '\0';
				}
				ptr = -1;
				buff[++ptr] = c;
				y += curFontHeight;
				h += curFontHeight;
			} else {
				++i;
			}
		} else {
			buff[++ptr] = s[i];
			if (textwidth(buff) >= w) {
				char c = buff[ptr];
				buff[ptr] = '\0';
				xyprintf(x, y, buff);
				for (int j = 0; j <= ptr; ++j) {
					buff[j] = '\0';
				}
				ptr = -1;
				buff[++ptr] = c;
				y += curFontHeight;
				h += curFontHeight;
			}
		}
	}
	if (~ptr) {
		xyprintf(x, y, buff);
		h += curFontHeight;
	}
	return h;
}

inline int rectpNotDivide(int x, int y, int w, std::string s) {
#define putline\
	xyprintf(x, y, buff); \
	int bsize = strlen(buff); \
	for (int j = 0; j < bsize; ++j) { \
		buff[j] = '\0'; \
	} \
	buffptr = 0; \
	y += curFontHeight; \
	h += curFontHeight
	int ssize = s.length();
	std::string words[1024];
	std::string gap[1024];
	int ptr = 1, h = 0;
	bool readingAscii = true;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == '|' && s[i + 1] == '|') {
			gap[ptr] += "||";
			++i;
			++ptr;
			readingAscii = true;
			continue;
		}
		if (readingAscii) {
			if (isLetter(s[i])) {
				words[ptr] += s[i];
				if (s[i] < 0) {
					words[ptr] += s[i + 1];
					++i;
				}
			} else {
				gap[ptr] += s[i];
				if (s[i] < 0) {
					gap[ptr] += s[i + 1];
					++i;
				}
				readingAscii = false;
			}
		} else {
			if (!isLetter(s[i])) {
				gap[ptr] += s[i];
				if (s[i] < 0) {
					gap[ptr] += s[i + 1];
					++i;
				}
			} else {
				words[++ptr] += s[i];
				if (s[i] < 0) {
					words[ptr] += s[i + 1];
					++i;
				}
				readingAscii = true;
			}
		}
	}
	int buffptr = 0;
	char buff[1024] = {'\0'};
	for (int i = 1; i <= ptr; ++i) {
		if (!buffptr && textwidth(words[i].c_str()) >= w) {
			int ssize = words[i].length();
			for (int j = 0; j < ssize; ++j) {
				buff[j] += words[i][j];
				if (words[i][j] < 0) {
					buff[j] += words[i][j + 1];
					++j;
				}
			}
			putline;
			continue;
		}
		if (textwidth(buff) + textwidth(words[i].c_str()) >= w) {
			putline;
			--i;
			continue;
		}
		int wordsize = words[i].length();
		for (int j = 0; j < wordsize; ++j, ++buffptr) {
			buff[buffptr] = words[i][j];
			if (words[i][j] < 0) {
				buff[j] += words[i][j + 1];
				++j;
			}
		}
		if (textwidth(buff) + textwidth(gap[i].c_str()) >= w) {
			putline;
			continue;
		}
		int gapsize = gap[i].length();
		for (int j = 0; j < gapsize; ++j, ++buffptr) {
			if (j < gapsize - 1 && gap[i][j] == '|' && gap[i][j + 1] == '|') {
				putline;
				break;
			}
			buff[buffptr] = gap[i][j];
		}
	}
	if (buffptr) {
		putline;
	}
	return h;
}
*/
