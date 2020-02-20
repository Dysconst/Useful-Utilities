#include "Timer.hpp"

Timer::Timer()
{
	myDeltaTime = 0;
	myLastFrame = myClock.now();
	myCurrentFrame = myClock.now();
}

void Timer::Update()
{
	myLastFrame = myCurrentFrame;
	myCurrentFrame = myClock.now();
	myDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(myCurrentFrame - myLastFrame).count() / 1000.f;
}

float Timer::GetDeltaTime() const
{
	return myDeltaTime;
}

double Timer::GetTotalTime() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(myCurrentFrame - myStartTime).count() / 1000.;
}
