#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H

#pragma comment(lib, "winmm.lib")
#include <Windows.h>

#define TIMER BasicTimer::getInstance()

class BasicTimer
{
public:
	
	~BasicTimer(void);
	double getCurrentTime();
	static BasicTimer* getInstance();

private:
	LONGLONG mStartTime;
	LONGLONG mCountFrequency;
	LONGLONG mCurrentTime;
	double mTimeScale;
	BasicTimer();
	
};

#endif BASIC_TIMER_H