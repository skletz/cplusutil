#ifndef __CplusutilMemory_h__
#define __CplusutilMemory_h__

#include <vector>

namespace cplusutil
{
	namespace memory
	{
		template <typename T>
		std::vector<T*> getPointers(std::vector<T>& source)
		{
			std::vector<T*> target(source.size());
			std::transform(source.begin(), source.end(), target.begin(), [](T& t) { return &t; });
			return target;
		}
		template <typename T>
		std::vector<T> getObjects(std::vector<T*> source)
		{
			std::vector<T> target(source.size());
			std::transform(source.begin(), source.end(), target.begin(), [](T* t)
			{
				return *t;
			});
			return target;
		}
	}
}

#endif //__CplusutilMemory_h__