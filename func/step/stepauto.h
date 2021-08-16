inline void stepAutoFunc() {
	// Automation
	for (re int i = 1; i <= maxAuto; ++i) {
		if (maxTickAuto[i] < 3.60) {
			maxTickAuto[i] = 2.99;
			if (infChaTimes[3])maxTickAuto[i] = 0.99;
		}

		if (activeAuto[i]) {
			++curTickAuto[i];
			if (curTickAuto[i] >= maxTickAuto[i]) {
				curTickAuto[i] -= maxTickAuto[i];
				if (i <= 6 && showDims >= i) {
					buyMaxTrigger(i);
				}
				if (i == 7) {
					if (voidLightUpgBought[5]) {
						while (collapseTime < auto7max && dim[6].val >= collapseReq) {
							performGeneratorCollapse();
						}
					} else {
						if (collapseTime < auto7max && dim[6].val >= collapseReq) {
							performGeneratorCollapse();
						}
					}
				}
				if (i == 8) {
					bool canPerform = true;
					if (voidPoint < infNeed1)canPerform = false;
					if (maxGetInfPoint < auto8min)canPerform = false;
					for (re int j = 1; j <= maxInfCha; ++j) {
						if (infChaIn[j] && voidPoint < ICGoal[j]) {
							canPerform = false;
							break;
						}
					}
					if (canPerform) {
						performInfinity();
					}
				}
				if (i == 9) {
					if (paceTime < auto9max) {
						performVoidPace();
					}
				}
			}
		}
	}
}
