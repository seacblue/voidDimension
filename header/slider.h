#include <windows.h>
#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
#ifndef MakeAmbcmodelGreatAgain_UI_H
#define MakeAmbcmodelGreatAgain_UI_H

int openlock = 0;
int IDs = 0;

const int MAXPRES = 100;
const int ADSORB = 4;

class Slider {
	private:
		string name;
		double minn, maxn;
		double nown;
		int x, y, len; //height = 16
		int showx;
		int isopen;
		int id;
		bool visible;

		int pres;
		int pre[MAXPRES];
	public:
		void init() {
			IDs++;
			id = IDs;
		}
		void simpleinit(string nm, int nx, int ny, int nlen, double mi, double ma, double val = 0) {
			IDs++, id = IDs;
			x = nx, y = ny, len = nlen;
			showx = x;
			minn = mi;
			maxn = ma;
			name = nm;
			nown = val;
			showx = x + (double)(val - minn) / (double)(maxn - minn) * (double)len;
			visible = false;
		}
		void updata(mouse_msg msg) {
			int mx = msg.x, my = msg.y;
			if (msg.msg == mouse_msg_down) {
				if (mx >= x && mx <= x + len && my >= y - 6 && my <= y + 22 && openlock == 0) isopen = 1, openlock = id;
				if (isopen == 1 && openlock == id) {
					showx = mx;
					if (showx < x)showx = x;
					else if (showx > x + len)showx = x + len;
					nown = (double)(showx - x) / (double)len * (maxn - minn) + minn;
				}
				if (mx >= x - 4 && mx < x) {
					nown = minn;
					showx = x;
				}
				if (mx <= x + len + 4 && mx > x + len) {
					nown = maxn;
					showx = x + len;
				}
				for (re int i = 1; i <= pres; ++i) {
					int pshowx = (double)(pre[i] - minn) / (double)(maxn - minn) * len + x;
					if (mx >= pshowx - ADSORB && mx <= pshowx + ADSORB) {
						nown = pre[i];
						showx = pshowx;
					}
				}
			} else isopen = 0, openlock = 0;
		}
		void print(mouse_msg msg) {
			if (visible) {
				int mx = msg.x, my = msg.y;

				setcolor (RGB(69, 69, 69));
				for (re int i = 1; i <= pres; ++i) {
					int pshowx = (double)(pre[i] - minn) / (double)(maxn - minn) * len + x;
					line (pshowx - 1, y, pshowx - 1, y + 16);
					line (pshowx, y, pshowx, y + 16);
					line (pshowx + 1, y, pshowx + 1, y + 16);

					if (mx >= pshowx - ADSORB && mx <= pshowx + ADSORB) mx = pshowx;
				}

				if (mx >= x && mx <= x + len && my >= y - 6 && my <= y + 22) {
					setcolor (RGB(169, 169, 169));
					line (mx - 1, y, mx - 1, y + 16);
					line (mx, y, mx, y + 16);
					line (mx + 1, y, mx + 1, y + 16);
				}

				settextjustify(LEFT_TEXT, TOP_TEXT);
				setcolor (0xffffff);
				xyprintf (x + 2, y, name.c_str(), nown);
				setcolor (0x7777ff);
				line (x, y, x + len, y);
				line (x, y, x, y + 16);
				line (x + len, y, x + len, y + 16);
				line (x, y + 16, x + len, y + 16);
				setcolor (0x00ff00);
				line (showx - 1, y, showx - 1, y + 16);
				line (showx, y, showx, y + 16);
				line (showx + 1, y, showx + 1, y + 16);
				setcolor (0xffffff);
			}
		}
		double getValue() {
			return nown;
		}
		void setValue(double val) {
			nown = val;
			showx = x + (double)(val - minn) / (double)(maxn - minn) * (double)len;
		}
		void setName(string nm) {
			name = nm;
		}
		void setXYLen(int nx, int ny, int nlen) {
			x = nx, y = ny, len = nlen;
			showx = x;
		}
		double getX() {
			return x;
		}
		double getY() {
			return y;
		}
		double getLen() {
			return len;
		}
		void setMaxMin(double mi, double ma) {
			minn = mi;
			maxn = ma;
		}
		double getMax() {
			return maxn;
		}
		double getMinn() {
			return minn;
		}
		void setVisible(bool vis) {
			visible = vis;
		}
		int getVisible() {
			return visible;
		}
		void pushPre(double val) {
			++pres;
			pre[pres] = val;
		}
		void resetPre() {
			pres = 0;
		}
};

class ADSR {
	private:
		int x, y;
		double A, D, S, R;
		int Ax, Dx, Sy, Rx;
		int idA, idDS, idR;
		int isopen = 1;
	public:
		void init(int inx, int iny) {
			x = inx, y = iny;
			Ax = 32;
			Dx = 64;
			Sy = 16;
			Rx = 200;
			idA = IDs + 1;
			idDS = IDs + 2;
			idR = IDs + 3;
			IDs += 3;
		}
		void print() {
			setcolor (0x7777ff);
			line (x, y, x + 256, y);
			line (x, y, x, y + 32);
			line (x + 256, y, x + 256, y + 32);
			line (x, y + 32, x + 256, y + 32);
			setcolor (0xAAAAff);
			line (x + Dx, y + 1, x + Dx, y + 32);
			setcolor(0xffff00);
			setfillcolor(0x00ff00);
			bar(x + Ax - 8, y - 4, x + Ax + 8, y + 4);
			line (x, y + 32, x + Ax, y);
			bar(x + Dx - 8, y + 32 - Sy - 4, x + Dx + 8, y + 32 - Sy + 4);
			line (x + Ax, y, x + Dx, y + 32 - Sy);
			bar(x + Rx - 8, y + 32 - 4, x + Rx + 8, y + 32 + 4);
			line (x + Dx, y + 32 - Sy, x + Rx, y + 32);
			circle(x + Ax, y, 4);
			circle(x + Dx, y + 32 - Sy, 4);
			circle(x + Rx, y + 32, 4);
		}
		void updata(int mx, int my, int msg) {
			if (msg == 513) {
				if (isopen == 0) {
					if (mx >= x + Ax - 8 && mx <= x + Ax + 8 && my >= y - 4 && my <= y + 4)isopen = 1, openlock = idA;
					if (mx >= x + Dx - 8 && mx <= x + Dx + 8 && my >= y + 32 - Sy - 4 && my <= y + 32 - Sy + 4)isopen = 1, openlock = idDS;
					if (mx >= x + Rx - 8 && mx <= x + Rx + 8 && my >= y + 32 - 4 && my <= y + 32 + 4)isopen = 1, openlock = idR;
				}
				if (isopen == 1) {
					if (openlock == idA) {
						Ax = mx - x;
						if (Ax < 0)Ax = 0;
						if (Ax > Dx)Ax = Dx;
					}
					if (openlock == idDS) {
						Dx = mx - x;
						Sy = 32 - my + y;
						if (Dx < Ax)Dx = Ax;
						if (Dx > Rx)Dx = Rx;
						if (Sy < 0)Sy = 0;
						if (Sy > 32)Sy = 32;
					}
					if (openlock == idR) {
						Rx = mx - x;
						if (Rx < Dx)Rx = Dx;
						if (Rx > 256)Rx = 256;
					}
				}
			} else isopen = 0, openlock = 0;
		}
		double rtA() {
			return (double)(Dx - Ax) / (double)Dx;
		}
		double rtD() {
			return (double)Ax / (double)Dx;
		}
		double rtS() {
			return (double)Sy / 32.0;
		}
		double rtR() {
			if (Rx == 256)return 0;
			return (double)(257 - Rx) / (double)(257 - Dx);
		}

};

#endif
