#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	Timer(const Timer &aTimer) = delete;
	Timer& operator=(const Timer &aTimer) = delete;
	void Update();
	float GetDeltaTime() const;
	double GetTotalTime() const;
private:
	float myDeltaTime;
	std::chrono::high_resolution_clock myClock;
	const std::chrono::high_resolution_clock::time_point myStartTime = myClock.now();
	std::chrono::high_resolution_clock::time_point myLastFrame;
	std::chrono::high_resolution_clock::time_point myCurrentFrame;
};