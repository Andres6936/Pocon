#ifndef POCON_BASICSTOPWATCH_HPP
#define POCON_BASICSTOPWATCH_HPP

#include <string>
#include <chrono>
#include <iostream>

using namespace std::chrono;

class StopWatch
{

private:

	std::string activity = "StopWatch";

	/**
	 * Lap time (time of last stop or the creation of instance).
	 */
	system_clock::time_point start;

public:

	// Create, optionally start timing an activity.

	StopWatch() noexcept : start(system_clock::now())
	{

	}

	explicit StopWatch(std::string&& _activity) noexcept : start(system_clock::now()), activity(_activity)
	{

	}

	/**
	 * Stop and destroy a StopWatch.
	 */
	~StopWatch()
	{
		system_clock::duration diff = system_clock::now() - start;

		unsigned long timeTotal = (unsigned)duration_cast <milliseconds>(diff).count();

		std::cout << activity << ": " << timeTotal << "ms" << std::endl;
	}
};

#endif //POCON_BASICSTOPWATCH_HPP
