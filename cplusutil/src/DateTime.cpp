#include "DateTime.hpp"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <time.h>

std::string cplusutil::DateTime::getTimestampForFilename()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	//TODO localtime warning may be unsafe
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%X");

	return ss.str();
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
std::chrono::time_point<std::chrono::system_clock> cplusutil::DateTime::currentDateTime()
{
	return std::chrono::system_clock::now();
}

std::chrono::duration<double> cplusutil::DateTime::elapsedSeconds(std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> end)
{
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds;
}