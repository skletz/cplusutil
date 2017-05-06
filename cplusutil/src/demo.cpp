/** CPLUSUtil (Version 2.0) ****************************
* ******************************************************
*       _    _      ()_()
*      | |  | |    |(o o)
*   ___| | _| | ooO--`o'--Ooo
*  / __| |/ / |/ _ \ __|_  /
*  \__ \   <| |  __/ |_ / /
*  |___/_|\_\_|\___|\__/___|
*
* ******************************************************
* This library provides several help classes and functions, 
* such as file input/output or string operations as well as 
* managing files and directories.
* ******************************************************
* 
* Purpose: Demo Usage
*
* @author skletz
* @version 2.0 06/05/17
*
**/

#include "../include/cplusutil.hpp"

void demoTerminal(std::string label, int _max)
{
	for (int iCounter = 0; iCounter <= _max; iCounter++)
	{
		cplusutil::Terminal::showProgress(label, iCounter, _max);
	}
}

int main(int argc, char** argv)
{
	//Terminal
	demoTerminal("Demonstration", 1000);

	return cplusutil::PROCESS_SUCCESS;
}