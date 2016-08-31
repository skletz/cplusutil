#ifndef __CplusutilDateTime_hpp__
#define __CplusutilDateTime_hpp__

#include <string>
#include <chrono>

namespace cplusutil
{
		class DateTime
		{

		public:
			static std::string getTimestampForFilename();

			static std::chrono::time_point<std::chrono::system_clock> currentDateTime();

			static  std::chrono::duration<double> elapsedSeconds(std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> end);
		};
}


#endif //__CplusutilDateTime_hpp__