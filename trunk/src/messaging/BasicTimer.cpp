#include "BasicTimer.h"

BasicTimer::BasicTimer()
{
	QueryPerformanceFrequency( (LARGE_INTEGER*) &mCountFrequency);
	mTimeScale = 1.0/mCountFrequency;
	QueryPerformanceCounter( (LARGE_INTEGER*) &mStartTime);
}

BasicTimer::~BasicTimer(void)
{
}

BasicTimer* BasicTimer::getInstance()
{
	static BasicTimer instance;

	return &instance;
}

double BasicTimer::getCurrentTime()
{
	QueryPerformanceCounter((LARGE_INTEGER* ) &mCurrentTime);
	return (mCurrentTime-mStartTime) * mTimeScale;
}
