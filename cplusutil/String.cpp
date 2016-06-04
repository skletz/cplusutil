#include "String.h"
#include <iostream>
#include <stdarg.h>
#include <sstream>

std::string cplusutil::String::toStirng(int i)
{
	return std::to_string(i);
}

int cplusutil::String::extractIntFromString(std::string fileName)
{
	int id = 0;
	std::string numbers = "0123456789";
	std::size_t found = fileName.find_first_of(numbers.c_str());
	try
	{
		id = std::atoi(fileName.c_str());
	}
	catch (std::exception const &)
	{

		while (found != std::string::npos) {
			std::cout << found << std::endl;
			found = fileName.find_first_of(numbers.c_str(), found + 1);
		}
		//LOG(WARNING) << "Video Filename contains no Integer to generate a unique ID; Video ID is set to 0";
		return found;

	}
	return id;
}

std::string cplusutil::String::concatIntegers(std::string delemniter, int args, ...)
{
	va_list list;
	va_start(list, args);

	std::stringstream ss;
	for (int i = 0; i < args; i++)
	{
		ss << va_arg(list, int);
		if ((i + 1) != args)
			ss << delemniter;
	}
	va_end(list);
	return ss.str();
}

std::string cplusutil::String::concatCStrings(std::string delemniter, int argc, ...)
{
	va_list argPtr;
	char * temp;

	va_start(argPtr, argc);

	std::stringstream ss;

	for (int i = 0; i < argc; i++)
	{
		temp = va_arg(argPtr, char*);
		std::string str(temp);
		ss << str;
		if ((i + 1) != argc)
			ss << delemniter;
	}

	va_end(argPtr);
	return ss.str();
}

std::vector<std::string>& cplusutil::String::split(const std::string& s, char delim, std::vector<std::string>& elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> cplusutil::String::split(const std::string& s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}