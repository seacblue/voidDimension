inline int rectpDivide(int, int, int, std::string);
inline int rectpNotDivide(int, int, int, std::string);
inline int rectp(int, int, int, std::string);

inline void readSent();
inline bool readSave();
inline std::string intToTimeStr(int);
inline void backwardComp();
inline void initSetAuto(int, int, int);
inline void setFont(int);
// ..AchStack()
inline void pushReminderStack(int, color_t);
inline void releaseReminderStack();
inline void updateReminderStack();
inline void pushAch(int);

inline void preinit();
inline void initFunc();
inline void aftinit();
inline void initVar();
inline void drawFunc();
inline void stepFunc();
inline void buyMax(int);
inline void infBuyMax(int);
// QoL
inline void buyMaxTrigger(int);
inline void infBuyMaxTrigger(int);
inline void performGeneratorCollapse();
inline void performInfinity();
inline void performVoidPace();
inline void updateDimMult();
inline void updateInfDimMult();
inline void updateColMult();
// draw..()
inline void drawTopFunc();

inline void drawMenuFunc();

inline void drawDimFunc();
inline void drawDim1Func();
inline void drawDim2Func();

inline void drawOptFunc();

inline void drawStatFunc();
inline void drawStat1Func();
inline void drawStat2Func();
inline void drawStat3Func();

inline void drawAchFunc();

inline void drawChaFunc();
inline void drawCha1Func();
inline void drawCha2Func();

inline void drawInfFunc();
inline void drawInf1Func();
inline void drawInf2Func();
inline void drawInf3Func();
inline void drawInf4Func();
inline void drawInf5Func();

inline void drawReminderStack();

inline void drawSleep();
inline void drawManual();
// step..()
inline void stepMiscFunc();
inline void stepDimFunc();
inline void stepInfDimFunc();
inline void stepInfFunc();
inline void stepChaFunc();
inline void stepAutoFunc();
inline void stepAftFunc();
// reset..()
inline void resetDimVal();
inline void resetCol();
inline void resetInf();
inline void resetPace();

inline void save(char*);
inline std::string pushSave(std::string, int);
inline std::string pushSave(std::string, ld);
inline std::string pushSave(std::string, bool);
inline std::string pushSave(std::string, Bignum);
inline std::string pushSave(std::string, time_t);
inline bool load(char*);
inline void loadSetVal(std::string, std::string);
// !-- System Function

#include "func/rectprint.h"
#include "func/readsave.h"
#include "func/misc.h"
#include "func/reminder.h"
#include "func/reset.h"
#include "func/slmisc.h"
#include "func/sl.h"

#include "func/init/init.h"

#include "func/step/step.h"
#include "func/step/stepauto.h"
#include "func/step/stepcha.h"
#include "func/step/stepdim.h"
#include "func/step/stepdiminf.h"
#include "func/step/stepinf.h"
#include "func/step/stepmisc.h"
#include "func/step/stepaft.h"

#include "func/QoL/QoL.h"

#include "func/draw/draw.h"
#include "func/draw/drawtop.h"
#include "func/draw/drawmenu.h"

#include "func/draw/drawdim.h"
#include "func/draw/drawdim1.h"
#include "func/draw/drawdim2.h"

#include "func/draw/drawopt.h"

#include "func/draw/drawstat.h"

#include "func/draw/drawstat1.h"
#include "func/draw/drawstat2.h"
#include "func/draw/drawstat3.h"

#include "func/draw/drawach.h"

#include "func/draw/drawcha.h"
#include "func/draw/drawcha1.h"
#include "func/draw/drawcha2.h"

#include "func/draw/drawinf.h"
#include "func/draw/drawinf1.h"
#include "func/draw/drawinf2.h"
#include "func/draw/drawinf3.h"
#include "func/draw/drawinf4.h"
#include "func/draw/drawinf5.h"

#include "func/draw/drawreminder.h"

#include "func/draw/drawsleep.h"
#include "func/draw/drawmanual.h"
