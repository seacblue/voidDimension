#ifndef _INPUTBOX_H
#define _INPUTBOX_H

#include <graphics.h>

#define defset(a,b,c,d,e,f,g,h,i,j) \
	this->x1 = a;\
	this->y1 = b;\
	this->x2 = c;\
	this->y2 = d;\
	this->trueColor = e;\
	this->falseColor = f;\
	this->baseColor = g;\
	this->curFillColor = this->baseColor;\
	this->borderColor = h;\
	this->borderTrueColor = i;\
	this->borderFalseColor = j;\
	this->curFillBorderColor = this->borderColor

struct InputBox {
	int x1, y1, x2, y2;
	color_t curFillColor, curFillBorderColor;
	color_t baseColor;
	color_t trueColor;
	color_t falseColor;
	color_t borderColor;
	color_t borderTrueColor;
	color_t borderFalseColor;
	bool isFocused;

	inline InputBox(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0,
	                color_t _trueColor = RGB(0, 0, 0),
	                color_t _falseColor = RGB(0, 0, 0),
	                color_t _baseColor = RGB(0, 0, 0),
	                color_t _borderColor = RGB(255, 255, 255),
	                color_t _borderTrueColor = RGB(255, 255, 255),
	                color_t _borderFalseColor = RGB(255, 255, 255)) {
		this->isFocused = false;
		defset(_x1, _y1, _x2, _y2,
		       _trueColor, _falseColor, _baseColor,
		       _borderColor, _borderTrueColor, _borderFalseColor);
	}

	inline void set(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0,
	                color_t _trueColor = RGB(0, 0, 0),
	                color_t _falseColor = RGB(0, 0, 0),
	                color_t _baseColor = RGB(0, 0, 0),
	                color_t _borderColor = RGB(255, 255, 255),
	                color_t _borderTrueColor = RGB(255, 255, 255),
	                color_t _borderFalseColor = RGB(255, 255, 255)) {
		this->isFocused = false;
		defset(_x1, _y1, _x2, _y2,
		       _trueColor, _falseColor, _baseColor,
		       _borderColor, _borderTrueColor, _borderFalseColor);
	}

	inline void draw() {
		setcolor(this->curFillBorderColor);
		rectangle(this->x1, this->y1, this->x2, this->y2);
		setcolor(RGB(255, 255, 255));
		setfillcolor(this->curFillColor);
		bar(this->x1 + 1, this->y1 + 1, this->x2 - 1, this->y2 - 1);
		
	}
};

#endif
