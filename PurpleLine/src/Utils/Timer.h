#pragma once
#include <Windows.h>
namespace PurpleLine {
	class Timer {
	private:
		LARGE_INTEGER startTime;
		double frequency;

	public:
		Timer()
		{
			QueryPerformanceCounter(&startTime);
			LARGE_INTEGER freq;
			QueryPerformanceFrequency(&freq);
			frequency = 1.0f / freq.QuadPart;
		}

		void Reset()
		{
			QueryPerformanceCounter(&startTime);
		}

		float Elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - startTime.QuadPart;
			return (float)(cycles * frequency);
		}
	};
}