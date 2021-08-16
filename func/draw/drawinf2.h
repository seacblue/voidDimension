inline void drawInf2Func() {
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	for (re int i = 1; i <= maxAuto; ++i) {
		if (haveAuto[i]) {
			rectAutoBG[i].draw();
			if (!settingAuto[i]) {
				rectAutoAble[i].changeOnFrame(msg, false);
				if (rectAutoAble[i].isClickOn(msg)) {
					activeAuto[i] = !activeAuto[i];
				}
				if (activeAuto[i]) {
					rectAutoAble[i].borderColor =
					    rectAutoAble[i].borderTrueColor =
					        rectAutoAble[i].borderFalseColor = RGB(50, 205, 50);
				} else {
					rectAutoAble[i].borderColor = RGB(0, 0, 139);
					rectAutoAble[i].borderTrueColor =
					    rectAutoAble[i].borderFalseColor = RGB(139, 0, 0);
				}
				rectAutoAble[i].draw();
				if (activeAuto[i]) {
					xyprintf((rectAutoAble[i].x1 + rectAutoAble[i].x2) >> 1,
					         (rectAutoAble[i].y1 + rectAutoAble[i].y2) >> 1,
					         sent["enable"].c_str());
				} else {
					xyprintf((rectAutoAble[i].x1 + rectAutoAble[i].x2) >> 1,
					         (rectAutoAble[i].y1 + rectAutoAble[i].y2) >> 1,
					         sent["disable"].c_str());
				}
				if (maxTickAuto[i] >= 3.60) {
					bool boolOper = false;
					if (infPoint >= costAuto[i]) boolOper = true;
					rectAutoUpg[i].changeOnFrame(msg, boolOper, boolOper);
					if (rectAutoUpg[i].isClickOn(msg)) {
						if (infPoint >= costAuto[i]) {
							infPoint = infPoint - costAuto[i];
							maxTickAuto[i] *= 0.6;
							costAuto[i] = costAuto[i] * costMultAuto[i];
						}
					}
					rectAutoUpg[i].draw();
					xyprintf((rectAutoUpg[i].x1 + rectAutoUpg[i].x2) >> 1,
					         (rectAutoUpg[i].y1 + rectAutoUpg[i].y2) >> 1,
					         (sent["cost_x"] +
					          costAuto[i].print()).c_str());
				}
				xyprintf((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
				         rectAutoBG[i].y1 + 15,
				         sent["auto_" + intToStr(i)].c_str());
				ld showTick = maxTickAuto[i];
				if (showTick < 3.60) {
					showTick = 2.99;
					if (infChaTimes[3])showTick = 0.99;
				}
				showTick /= FPS;
				int nearestTick = ceil(showTick);
				std::string outputS = "ticks";
				if (nearestTick == 1)outputS = "tick";
				if (keystate(VK_SHIFT)) {
					xyprintf((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
					         rectAutoBG[i].y1 + 35,
					         (sent["auto_interval"] +
					          doubleToStr(showTick, 2) +
					          sent["sec_short"] + sent["lef_bracket"] +
					          intToStr(nearestTick) + sent["space"] +
					          sent[outputS] + sent["rig_bracket"]).c_str());
				} else {
					xyprintf((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
					         rectAutoBG[i].y1 + 35,
					         (sent["auto_interval"] +
					          doubleToStr(showTick, 2) +
					          sent["space"] + sent["seconds"]).c_str());
				}
			} else {
				if (i == 7) {
					std::string outputString = sent["auto_setting_1"];
					int width = rectAutoBG[i].x2 - rectAutoBG[i].x1 - 20;

					rectp((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
					      rectAutoBG[i].y1 + 15,
					      width - 20, outputString);
					int ptr = 1;
					if (!firstCall[ptr]) {
						peditbox[ptr]->create(false);
						peditbox[ptr]->move(rectAutoBG[i].x1 + 25, rectAutoBG[i].y2 - 32);
						peditbox[ptr]->size(rectAutoBG[i].x2 - rectAutoBG[i].x1 - 50, 23);
						peditbox[ptr]->setbgcolor(BLACK);
						peditbox[ptr]->setcolor(WHITE);
						peditbox[ptr]->visible(true);
						peditbox[ptr]->setfont(18, 0, "consolas");
						peditbox[ptr]->setfocus();
						peditbox[ptr]->settext(auto7max.print(0).c_str());
						firstCall[ptr] = true;
					}

					peditbox[ptr]->gettext(MAXLEN, editbuff[1]);
					std::string strType = charToStr(editbuff[1]);
					if (!isValidBignum(strType)) {
						peditbox[ptr]->setbgcolor(RGB(60, 20, 220));
					} else {
						peditbox[ptr]->setbgcolor(BLACK);
					}

					rectAutoComplete[i].changeOnFrame(msg, false);
					if (rectAutoComplete[i].isClickOn(msg)) {
						peditbox[ptr]->gettext(MAXLEN, editbuff[ptr]);
						std::string strType = charToStr(editbuff[ptr]);
						if (isValidBignum(strType)) {
							auto7max = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
					}
					rectAutoComplete[i].draw();
					xyprintf((rectAutoComplete[i].x1 + rectAutoComplete[i].x2) >> 1,
					         (rectAutoComplete[i].y1 + rectAutoComplete[i].y2) >> 1,
					         sent["complete"].c_str());
				}
				if (i == 8) {
					std::string outputString = sent["auto_setting_2"];
					int width = rectAutoBG[i].x2 - rectAutoBG[i].x1 - 20;

					rectp((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
					      rectAutoBG[i].y1 + 15,
					      width - 20, outputString);
					int ptr = 2;
					if (!firstCall[ptr]) {
						peditbox[ptr]->create(false);
						peditbox[ptr]->move(rectAutoBG[i].x1 + 25, rectAutoBG[i].y2 - 32);
						peditbox[ptr]->size(rectAutoBG[i].x2 - rectAutoBG[i].x1 - 50, 23);
						peditbox[ptr]->setbgcolor(BLACK);
						peditbox[ptr]->setcolor(WHITE);
						peditbox[ptr]->visible(true);
						peditbox[ptr]->setfont(18, 0, "consolas");
						peditbox[ptr]->setfocus();
						peditbox[ptr]->settext(auto8min.print(0).c_str());
						firstCall[ptr] = true;
					}

					peditbox[ptr]->gettext(MAXLEN, editbuff[2]);
					std::string strType = charToStr(editbuff[2]);
					if (!isValidBignum(strType)) {
						peditbox[ptr]->setbgcolor(RGB(60, 20, 220));
					} else {
						peditbox[ptr]->setbgcolor(BLACK);
					}

					rectAutoComplete[i].changeOnFrame(msg, false);
					if (rectAutoComplete[i].isClickOn(msg)) {
						peditbox[ptr]->gettext(MAXLEN, editbuff[ptr]);
						std::string strType = charToStr(editbuff[ptr]);
						if (isValidBignum(strType)) {
							auto8min = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
					}
					rectAutoComplete[i].draw();
					xyprintf((rectAutoComplete[i].x1 + rectAutoComplete[i].x2) >> 1,
					         (rectAutoComplete[i].y1 + rectAutoComplete[i].y2) >> 1,
					         sent["complete"].c_str());
				}
				if (i == 9) {
					std::string outputString = sent["auto_setting_3"];
					int width = rectAutoBG[i].x2 - rectAutoBG[i].x1 - 20;

					rectp((rectAutoBG[i].x1 + rectAutoBG[i].x2) >> 1,
					      rectAutoBG[i].y1 + 15,
					      width - 20, outputString);
					int ptr = 3;
					if (!firstCall[ptr]) {
						peditbox[ptr]->create(false);
						peditbox[ptr]->move(rectAutoBG[i].x1 + 25, rectAutoBG[i].y2 - 32);
						peditbox[ptr]->size(rectAutoBG[i].x2 - rectAutoBG[i].x1 - 50, 23);
						peditbox[ptr]->setbgcolor(BLACK);
						peditbox[ptr]->setcolor(WHITE);
						peditbox[ptr]->visible(true);
						peditbox[ptr]->setfont(18, 0, "consolas");
						peditbox[ptr]->setfocus();
						peditbox[ptr]->settext(auto9max.print(0).c_str());
						firstCall[ptr] = true;
					}

					peditbox[ptr]->gettext(MAXLEN, editbuff[3]);
					std::string strType = charToStr(editbuff[3]);
					if (!isValidBignum(strType)) {
						peditbox[ptr]->setbgcolor(RGB(60, 20, 220));
					} else {
						peditbox[ptr]->setbgcolor(BLACK);
					}

					rectAutoComplete[i].changeOnFrame(msg, false);
					if (rectAutoComplete[i].isClickOn(msg)) {
						peditbox[ptr]->gettext(MAXLEN, editbuff[ptr]);
						std::string strType = charToStr(editbuff[ptr]);
						if (isValidBignum(strType)) {
							auto9max = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
					}
					rectAutoComplete[i].draw();
					xyprintf((rectAutoComplete[i].x1 + rectAutoComplete[i].x2) >> 1,
					         (rectAutoComplete[i].y1 + rectAutoComplete[i].y2) >> 1,
					         sent["complete"].c_str());
				}
			}
			if (showAutoSetting[i]) {
				rectAutoSetting[i].changeOnFrame(msg, false);
				if (rectAutoSetting[i].isClickOn(msg)) {
					settingAuto[i] = !settingAuto[i];

					if (!settingAuto[i] && i == 7) {
						firstCall[1] = false;
						peditbox[1]->gettext(MAXLEN, editbuff[1]);
						std::string strType = charToStr(editbuff[1]);
						if (isValidBignum(strType)) {
							auto7max = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
						peditbox[1]->visible(false);
					}
					if (!settingAuto[i] && i == 8) {
						firstCall[2] = false;
						peditbox[2]->gettext(MAXLEN, editbuff[2]);
						std::string strType = charToStr(editbuff[2]);
						if (isValidBignum(strType)) {
							auto8min = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
						peditbox[2]->visible(false);
					}
					if (!settingAuto[i] && i == 9) {
						firstCall[3] = false;
						peditbox[3]->gettext(MAXLEN, editbuff[3]);
						std::string strType = charToStr(editbuff[3]);
						if (isValidBignum(strType)) {
							auto9max = strToBignum(strType);
							pushReminderStack(-2, RGB(130, 0, 75));
						}
						peditbox[3]->visible(false);
					}
				}
				rectAutoSetting[i].draw();
				xyprintf((rectAutoSetting[i].x1 + rectAutoSetting[i].x2) >> 1,
				         (rectAutoSetting[i].y1 + rectAutoSetting[i].y2) >> 1,
				         sent["dot"].c_str());
			}
		}
		rectAutoAllEnable.changeOnFrame(msg, false);
		if (rectAutoAllEnable.isClickOn(msg)) {
			for (re int i = 1; i <= maxAuto; ++i) {
				if (haveAuto[i]) {
					activeAuto[i] = true;
				}
			}
		}
		rectAutoAllEnable.draw();
		xyprintf((rectAutoAllEnable.x1 + rectAutoAllEnable.x2) >> 1,
		         (rectAutoAllEnable.y1 + rectAutoAllEnable.y2) >> 1,
		         sent["auto_allenable"].c_str());

		rectAutoAllDisable.changeOnFrame(msg, false);
		if (rectAutoAllDisable.isClickOn(msg)) {
			for (re int i = 1; i <= maxAuto; ++i) {
				if (haveAuto[i]) {
					activeAuto[i] = false;
				}
			}
		}
		rectAutoAllDisable.draw();
		xyprintf((rectAutoAllDisable.x1 + rectAutoAllDisable.x2) >> 1,
		         (rectAutoAllDisable.y1 + rectAutoAllDisable.y2) >> 1,
		         sent["auto_alldisable"].c_str());
	}
}
