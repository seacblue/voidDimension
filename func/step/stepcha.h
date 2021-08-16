inline void stepChaFunc() {
	// Set InfCha Unlocked
	for (re int i = 1; i <= maxInfCha; ++i) {
		if (voidPoint >= ICReq[i]) {
			infChaUnlocked[i] = true;
		}
	}

	// Check challenge debuff
	// Challenge 5

	int c5deltaTime = challengeTick + FPS;
	Bignum c5dt;
	c5dt.setRealnum(c5deltaTime);
	c5dt = c5dt / (ld)FPS;
	Bignum af1;
	if (chaIn[5]) {
		if (dim[1].val > 100)af1 = root(dim[1].val, 1.77);
		cha5antiVP = af1 * (c5dt ^ 6.14);
	}
	if (infChaIn[3]) {
		if (dim[1].val > 100)af1 = root(dim[1].val, 1.357);
		cha5antiVP = af1 * (c5dt ^ 12.16);
	}
	// Challenge 6
	if (chaIn[6] || chaIn[8]) {
		if (dim[2].val >= 100) {
			cha6capped = 66666 + root(dim[2].val, 4.29);
		} else {
			cha6capped = 66666;
		}
		if (dim[1].val >= cha6capped) {
			dim[1].val = cha6capped;
		}
	}
	// InfCha 7
	if (infChaIn[7]) {
		for (re ll i = 1; i <= maxDims; ++i) {
			if (dim[i].val >= 7777.0) {
				dim[i].val.setRealnum(7777.0);
			}
		}
	}

	// Check challenge reward
	// Challenge 1
	cha1Buff1.setRealnum(1);
	cha1Buff2.setRealnum(1);
	if (chaTimes[1] && !chaIn[2]) {
		if (chaIn[4] || chaIn[8]) {
			if (achIsOpen[6]) {
				if (dim[1].val >= 100)cha1Buff1 = cha1Buff1 + exporoot(dim[1].val, 0.42);
				if (dim[2].val >= 100)cha1Buff2 = cha1Buff2 + exporoot(dim[2].val, 0.16);
			} else {
				if (dim[1].val >= 100)cha1Buff1 = cha1Buff1 + exporoot(dim[1].val, 0.65);
				if (dim[2].val >= 100)cha1Buff2 = cha1Buff2 + exporoot(dim[2].val, 0.35);
			}
		} else {
			if (achIsOpen[6]) {
				if (dim[1].val >= 100)cha1Buff1 = cha1Buff1 + exporoot(dim[1].val, 1.36);
				if (dim[2].val >= 100)cha1Buff2 = cha1Buff2 + exporoot(dim[2].val, 1.20);
			} else {
				if (dim[1].val >= 100)cha1Buff1 = cha1Buff1 + exporoot(dim[1].val, 1.62);
				if (dim[2].val >= 100)cha1Buff2 = cha1Buff2 + exporoot(dim[2].val, 1.43);
			}
		}
	}
	// Challenge 5
	cha5Buff1.setRealnum(1);
	cha5Buff2.setRealnum(1);
	if (chaTimes[5]) {
		if (dim[5].val >= 2)cha5Buff1 = cha5Buff1 + exporoot(dim[5].val, 0.36);
		if (dim[6].val >= 2)cha5Buff2 = cha5Buff2 + (dim[6].val ^ 2.39);
	}
	// InfCha 4
	if (infChaTimes[4]) {
		basicInfDimMultMult = 8.000001;
	}
	// InfCha 7
	if (infChaTimes[7]) {
		normalPaceMult.setBignum(1, 170);
	}
}
