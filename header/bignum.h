#ifndef _BIGNUM_H
#include <string>
#include <cstring>
#include <cmath>

#define _BIGNUM_H

#ifndef _MISC_H
#include "misc.h"
#endif

typedef long long ll;
typedef long double ld;
#define re register

// -- Bignum
const int MAXCALDELTA = 15;

struct Bignum {
	ld base;
	int expo;
	Bignum(ld _base = 1, int _expo = 0) {
		this->base = _base;
		this->expo = _expo;
		this->maintain();
	}
	inline void setBignum(ld _base = 1, int _expo = 0) {
		this->base = _base;
		this->expo = _expo;
		this->maintain();
	}
	inline void setRealnum(ld _realnum = 1) {
		this->expo = 0;
		while (_realnum >= 10) {
			_realnum /= 10;
			++(this->expo);
		}
		this->base = _realnum;
		this->maintain();
	}
	inline std::string print(int decimal = 0) {
		if (this->expo <= 3) {
			ld realnum = this->base;
			for (re int i = 1; i <= this->expo; ++i) {
				realnum = realnum * 10;
			}
			std::string str;
			//str.clear();
			str = doubleToStr(realnum, decimal);
			//str = intToStr((int)(realnum));
			return str;
		} else {
			int selfbase = (int)(this->base * 100);
			int selfexpo = this->expo;
			std::string str = "0.00e";
			str[0] = (selfbase / 100) + '0';
			str[2] = ((selfbase % 100) / 10) + '0';
			str[3] = (selfbase % 10) + '0';
			std::string expostr;
			expostr.clear();
			expostr = intToStr(selfexpo);
			str += expostr;
			return str;
		}
		return "0";
	}
	inline std::string prnt(int decimal = 6) {
		std::string prntstr;
		prntstr = doubleToStr(this->base, decimal) +
		          "," + intToStr(this->expo);
		return prntstr;
	}
	inline void setPrnt(std::string s) {
		int commapos = s.find(",");
		std::string basestr, expostr;
		basestr = s.substr(0, commapos);
		expostr = s.substr(commapos + 1, s.size() - commapos + 1);
		this->base = strToDouble(basestr);
		this->expo = strToInt(expostr);
	}
	inline void maintain() {
		while (this->base >= 10) {
			this->base /= 10;
			++(this->expo);
		}
		while (this->base < 1 && this->expo > 0) {
			// Will "this->expo>0" cause bugs?
			// Because exponent can be lesser than 0
			--(this->expo);
			this->base *= 10;
		}
	}
};

inline Bignum operator + (Bignum x, Bignum y);
inline Bignum operator - (Bignum x, Bignum y);
inline Bignum operator * (Bignum x, Bignum y);
inline Bignum operator / (Bignum x, Bignum y);
inline Bignum operator + (Bignum x, ld y);
inline Bignum operator - (Bignum x, ld y);
inline Bignum operator * (Bignum x, ld y);
inline Bignum operator / (Bignum x, ld y);
inline Bignum operator ^ (Bignum x, ld y);
inline bool operator == (Bignum x, Bignum y);
inline bool operator > (Bignum x, Bignum y);
inline bool operator < (Bignum x, Bignum y);
inline bool operator >= (Bignum x, Bignum y);
inline bool operator <= (Bignum x, Bignum y);
inline bool operator != (Bignum x, Bignum y);
inline bool operator == (Bignum x, ld y);
inline bool operator > (Bignum x, ld y);
inline bool operator < (Bignum x, ld y);
inline bool operator >= (Bignum x, ld y);
inline bool operator <= (Bignum x, ld y);
inline bool operator != (Bignum x, ld y);

inline Bignum operator + (Bignum x, Bignum y) {
	if (x < y) {
		Bignum t = x;
		x = y;
		y = t;
	}
	int expoDelta = x.expo - y.expo;
	if (expoDelta >= MAXCALDELTA) {
		return x;
	}
	for (re int i = 1; i <= expoDelta; ++i) {
		y.base /= 10;
	}
	Bignum z;
	z.setBignum(x.base + y.base, x.expo);
	z.maintain();
	return z;
}

inline Bignum operator - (Bignum x, Bignum y) {
	if (x < y) {
		return (Bignum) {
			0, 0
		};
	}
	int expoDelta = x.expo - y.expo;
	if (expoDelta >= MAXCALDELTA) {
		return x;
	}
	for (re int i = 1; i <= expoDelta; ++i) {
		y.base /= 10;
	}
	Bignum z;
	z.setBignum(x.base - y.base, x.expo);
	z.maintain();
	return z;
}

inline Bignum operator * (Bignum x, Bignum y) {
	Bignum z;
	z.setBignum(x.base * y.base, x.expo + y.expo);
	z.maintain();
	return z;
}

inline Bignum operator / (Bignum x, Bignum y) {
	Bignum z;
	z.setBignum(x.base / y.base, x.expo - y.expo);
	z.maintain();
	return z;
}

inline Bignum operator + (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return x + _y;
}
inline Bignum operator - (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return x - _y;
}
inline Bignum operator * (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return x * _y;
}
inline Bignum operator / (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return x / _y;
}

inline Bignum operator ^ (Bignum x, ld y) {
	ld xexpo = x.expo + log10(x.base);
	y *= xexpo;
	ll yll = (ll)(y);
	x.expo = yll;
	y -= yll;
	x.base = pow(10, y);
	return x;
}

inline bool operator == (Bignum x, Bignum y) {
	return x.base == y.base && x.expo == y.expo;
}
inline bool operator > (Bignum x, Bignum y) {
	if (x.expo > y.expo)return true;
	if (x.expo < y.expo)return false;
	if (x.base > y.base)return true;
	return false;
}

inline bool operator < (Bignum x, Bignum y) {
	if (x.expo < y.expo)return true;
	if (x.expo > y.expo)return false;
	if (x.base < y.base)return true;
	return false;
}

inline bool operator >= (Bignum x, Bignum y) {
	return !(x < y);
}
inline bool operator <= (Bignum x, Bignum y) {
	return !(x > y);
}
inline bool operator != (Bignum x, Bignum y) {
	return !(x == y);
}

inline bool operator == (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x == _y);
}
inline bool operator > (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x > _y);
}
inline bool operator < (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x < _y);
}
inline bool operator >= (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x >= _y);
}
inline bool operator <= (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x <= _y);
}
inline bool operator != (Bignum x, ld y) {
	Bignum _y;
	_y.setRealnum(y);
	return (x != _y);
}

inline Bignum root(Bignum x, ld y) {
	ld xexpo = (x.expo + log10(x.base)) / y;
	ll xexpoll = (ll)(floor(xexpo));
	ld xbase = xexpo - floor(xexpo);
	x.base = pow(10, xbase);
	x.expo = xexpoll;
	x.maintain();
	return x;
}

inline Bignum root(Bignum x, Bignum y) {
	ld xexpo = x.expo + log10(x.base),
	   yexpo = y.expo + log10(y.base);
	ld xexpold = floor(xexpo / yexpo);
	ll xexpoll = (ll)(xexpold);
	ld xbase = xexpold - floor(xexpold);
	x.base = pow(10, xbase);
	x.expo = xexpoll;
	x.maintain();
	return x;
}

inline Bignum exporoot(Bignum x, Bignum y) {
	ld xexpo = x.expo + log10(x.base),
	   yexpo = y.expo + log10(y.base);
	x.base = xexpo / yexpo;
	x.expo = 0;
	x.maintain();
	return x;
}

inline Bignum exporoot(Bignum x, ld y) {
	ld xexpo = x.expo + log10(x.base);
	x.base = xexpo / y;
	x.expo = 0;
	x.maintain();
	return x;
}

inline Bignum floor(Bignum x){
	if(x.expo >= 3)return x;
	while(x.expo) {
		x.base *= 10.0;
		--x.expo;
	}
	x.base = floor(x.base);
	x.maintain();
	return x;
}

inline bool isAllow(std::string s, bool allowDecimal) {
	int ssize = s.length();
	bool hasNumber = false;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			hasNumber = true;
			break;
		}
	}
	if (!hasNumber)return false;
	int decimalTimes = 0;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == '.')++decimalTimes;
	}
	if ((decimalTimes > 1) || (decimalTimes > 0 && !allowDecimal))
		return false;
	for (int i = 1; i < ssize; ++i) {
		if (s[i] == '+')return false;
	}
	return true;
}
inline bool isValidBignum(std::string s) {
	int ssize = s.length();
	for (int i = 0; i < ssize; ++i) {
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' ||
		        s[i] == '.' || s[i] == 'e' || s[i] == 'E')
			continue;
		return false;
	}
	int etimes = 0, Etimes = 0, pos = 0;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == 'e') {
			++etimes;
			pos = i;
		}
		if (s[i] == 'E') {
			++Etimes;
			pos = i;
		}
	}
	if (etimes + Etimes > 1)return false;

	if (etimes + Etimes == 0) {
		return isAllow(s, false);
	}
	std::string s1, s2;
	s1 = s.substr(0, pos);
	s2 = s.substr(pos + 1, ssize - pos);
	return isAllow(s1, true) & isAllow(s2, false);
}

inline Bignum strIntToBignum(std::string s) {
	int ssize = s.length();
	if (ssize < 9) {
		int ix = strToInt(s);
		Bignum x;
		x.setRealnum(ix);
		return x;
	}
	ld fnt6 = 0;
	for (re int i = 6; i >= 0; --i) {
		fnt6 = fnt6 * 10 + s[i] - '0';
	}
	Bignum x;
	x.base = fnt6 / 1000000;
	x.expo = ssize - 1;
	return x;
}

inline Bignum strToBignum(std::string s) {
	int ssize = s.length();
	int etimes = 0, Etimes = 0, pos = 0;
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == 'e') {
			++etimes;
			pos = i;
		}
		if (s[i] == 'E') {
			++Etimes;
			pos = i;
		}
	}

	if (etimes + Etimes == 0) {
		Bignum x = strIntToBignum(s);
		x.maintain();
		return x;
	}
	std::string s1, s2;
	s1 = s.substr(0, pos);
	s2 = s.substr(pos + 1, ssize - pos);
	Bignum x;
	x.base = strToDouble(s1);
	x.expo = strToInt(s2);
	x.maintain();
	return x;
}

#endif
