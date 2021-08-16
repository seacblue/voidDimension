#ifndef _GENERATION_H
#ifndef _BIGNUM_H
#include "bignum.h"
#endif

#define _GENERATION_H

struct DimGen {
	Bignum mult, val, cost, costmult;
	Bignum showMult;
	Bignum infCost, infMult;
	Bignum basicCost, basicMult;
	ll bought;
	DimGen(Bignum _mult, Bignum _val, Bignum _cost, Bignum _costmult) {
		this->mult = this->showMult = _mult;
		this->val = _val;
		this->cost = _cost;
		this->costmult = _costmult;
		this->basicCost = this->infCost = _cost;
		this->basicMult = this->infMult = _mult;
		this->bought = 0;
	}
	DimGen(ld _mult = 1, ld _val = 0, ld _cost = 10, ld _costmult = 1) {
		this->mult = this->showMult = _mult;
		this->val = _val;
		this->cost = _cost;
		this->costmult = _costmult;
		this->basicCost = this->infCost = _cost;
		this->basicMult = this->infMult = _mult;
		this->bought = 0;
	}
	inline void set(Bignum _mult, Bignum _val, Bignum _cost, Bignum _costmult) {
		this->mult = this->showMult = _mult;
		this->val = _val;
		this->cost = _cost;
		this->costmult = _costmult;
		this->basicCost = this->infCost = _cost;
		this->basicMult = this->infMult = _mult;
		this->bought = 0;
	}
	inline void set(ld _mult = 1, ld _val = 0, ld _cost = 10, ld _costmult = 1) {
		this->mult = this->showMult = _mult;
		this->val = _val;
		this->cost = _cost;
		this->costmult = _costmult;
		this->basicCost = this->infCost = _cost;
		this->basicMult = this->infMult = _mult;
		this->bought = 0;
	}
} dim[7], infdim[7];

#endif
