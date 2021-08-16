#ifndef _RECTPOINTSET_H
#define _RECTPOINTSET_H

#include <graphics.h>

// -- Rect
typedef long double ld;

int rectMaxOnFrame = 15;

inline void mybar(int x1, int y1, int x2, int y2, color_t col) {
	for (register int i = x1; i < x2; ++i)
		for (register int j = y1; j < y2; ++j)
			wbuf[i + WINDOW_WIDTH * j] = col;
}

inline color_t colorPercentage(color_t x, color_t y, ld percent) {
	int getxr = EGEGET_R(x),
	    getxg = EGEGET_G(x),
	    getxb = EGEGET_B(x),
	    getyr = EGEGET_R(y),
	    getyg = EGEGET_G(y),
	    getyb = EGEGET_B(y);
	int zr, zg, zb;
	zr = getxr * (1 - percent) + getyr * percent;
	zg = getxg * (1 - percent) + getyg * percent;
	zb = getxb * (1 - percent) + getyb * percent;
	return RGB(zr, zg, zb);
}

#define defset(a,b,c,d,e,f,g,h,i,j,k,l,m) \
	this->x1 = a;\
	this->y1 = b;\
	this->x2 = c;\
	this->y2 = d;\
	this->trueColor = e;\
	this->falseColor = f;\
	this->baseColor = g;\
	this->curFillColor = this->baseColor;\
	this->isBorder = h;\
	this->borderColor = i;\
	this->borderTrueColor = j;\
	this->borderFalseColor = k;\
	this->borderStaticTrueColor = l;\
	this->borderStaticFalseColor = m;\
	this->curFillBorderColor = this->borderColor

struct RectPointSet {
	int x1, y1, x2, y2;
	color_t curFillColor, curFillBorderColor;
	color_t baseColor;
	color_t trueColor;
	color_t falseColor;
	color_t borderColor;
	color_t borderTrueColor;
	color_t borderFalseColor;
	color_t borderStaticTrueColor;
	color_t borderStaticFalseColor;
	int onFrame, staticOnFrame;
	bool isClicked, isBorder;
	inline RectPointSet(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0,
	                    color_t _trueColor = RGB(0, 0, 0),
	                    color_t _falseColor = RGB(0, 0, 0),
	                    color_t _baseColor = RGB(0, 0, 0),
	                    bool _isBorder = true,
	                    color_t _borderColor = RGB(255, 255, 255),
	                    color_t _borderTrueColor = RGB(255, 255, 255),
	                    color_t _borderFalseColor = RGB(255, 255, 255),
	                    color_t _borderStaticTrueColor = RGB(255, 255, 255),
	                    color_t _borderStaticFalseColor = RGB(255, 255, 255)) {
		this->onFrame = 0;
		this->staticOnFrame = 0;
		this->isClicked = false;
		defset(_x1, _y1, _x2, _y2,
		       _trueColor, _falseColor, _baseColor,
		       _isBorder, _borderColor, _borderTrueColor, _borderFalseColor,
		       _borderStaticTrueColor, _borderStaticFalseColor);
	}
	inline void set(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0,
	                color_t _trueColor = RGB(0, 0, 0),
	                color_t _falseColor = RGB(0, 0, 0),
	                color_t _baseColor = RGB(0, 0, 0),
	                bool _isBorder = true,
	                color_t _borderColor = RGB(255, 255, 255),
	                color_t _borderTrueColor = RGB(255, 255, 255),
	                color_t _borderFalseColor = RGB(255, 255, 255),
	                color_t _borderStaticTrueColor = RGB(255, 255, 255),
	                color_t _borderStaticFalseColor = RGB(255, 255, 255)) {
		defset(_x1, _y1, _x2, _y2,
		       _trueColor, _falseColor, _baseColor,
		       _isBorder, _borderColor, _borderTrueColor, _borderFalseColor,
		       _borderStaticTrueColor, _borderStaticFalseColor);
	}
	inline void draw() {
		if (this->isBorder) {
			//setfillcolor(this->curFillBorderColor);
			setcolor(this->curFillBorderColor);
			rectangle(this->x1, this->y1, this->x2, this->y2);
			setcolor(RGB(255, 255, 255));
		}
		//setfillcolor(this->curFillColor);
		//bar(this->x1 + 1, this->y1 + 1, this->x2 - 1, this->y2 - 1);
		mybar(this->x1 + 1, this->y1 + 1, this->x2 - 1, this->y2 - 1, this->curFillColor);
	}
	inline bool checkMouse(mouse_msg msg) {
		return msg.x >= this->x1 && msg.x <= this->x2 &&
		       msg.y >= this->y1 && msg.y <= this->y2;
	}
	inline void changeOnFrame(mouse_msg msg, bool boolOper, bool boolOper1 = false) {
		if (checkMouse(msg)) {
			++(this->onFrame);
		} else {
			--(this->onFrame);
		}
		if (this->onFrame > rectMaxOnFrame) {
			this->onFrame = rectMaxOnFrame;
		}
		if (this->onFrame < 0) {
			this->onFrame = 0;
		}

		if (boolOper1) {
			++(this->staticOnFrame);
		} else {
			--(this->staticOnFrame);
		}
		if (this->staticOnFrame > rectMaxOnFrame) {
			this->staticOnFrame = rectMaxOnFrame;
		}
		if (this->staticOnFrame < 0) {
			this->staticOnFrame = 0;
		}

		color_t staticBorderColor;
		if (boolOper1) {
			staticBorderColor = colorPercentage(
			                        this->borderColor, this->borderStaticTrueColor,
			                        (ld)(this->staticOnFrame) / (ld)(rectMaxOnFrame)
			                    );
		} else {
			staticBorderColor = colorPercentage(
			                        this->borderColor, this->borderStaticFalseColor,
			                        (ld)(this->staticOnFrame) / (ld)(rectMaxOnFrame)
			                    );
		}

		if (boolOper == true) {
			this->curFillColor = colorPercentage(
			                         this->baseColor, this->trueColor,
			                         (ld)(this->onFrame) / (ld)(rectMaxOnFrame));
			this->curFillBorderColor = colorPercentage(
			                               staticBorderColor, this->borderTrueColor,
			                               (ld)(this->onFrame) / (ld)(rectMaxOnFrame));
		} else {
			this->curFillColor = colorPercentage(
			                         this->baseColor, this->falseColor,
			                         (ld)(this->onFrame) / (ld)(rectMaxOnFrame));
			this->curFillBorderColor = colorPercentage(
			                               staticBorderColor, this->borderFalseColor,
			                               (ld)(this->onFrame) / (ld)(rectMaxOnFrame));
		}
	}
	inline bool isClickOn(mouse_msg msg) {
		if (msg.is_left() && msg.is_down()
		        && this->checkMouse(msg)) {
			if (!isClicked) {
				isClicked = true;
				return true;
			}
		} else {
			isClicked = false;
		}
		return false;
	}
};

#endif
