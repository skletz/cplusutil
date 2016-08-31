#ifndef __CplusutilTerminal_hpp__
#define __CplusutilTerminal_hpp__

#include <cstdio>
#include <string>

namespace cplusutil
{
	class Terminal
	{
	public:
		static void showProgress(std::string label, int step, int _total);
	};
}

#endif //__CplusutilTerminal_hpp__