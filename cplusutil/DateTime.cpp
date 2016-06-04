#include "DateTime.hpp"
#include <sstream>
#include <iomanip>
#include <chrono>

std::string cplusutil::DateTime::getTimestampForFilename()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	//TODO localtime warning may be unsafe
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%X");

	return ss.str();
}