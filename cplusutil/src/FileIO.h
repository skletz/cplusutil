#ifndef __CplusutilFileIO_hpp__
#define __CplusutilFileIO_hpp__

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
namespace cplusutil
{
	class FileIO
	{
	public:
		static std::string getAbsolutePath(std::string _relativPath);

		static bool createDirectoriesIfNotExist(std::string _path);

		static bool isValidPath(std::string _path);

		static bool isDirectory(std::string _path);

		static bool isValidPathToDirectory(std::string _path);

		static bool isValidPathToFile(std::string _path);

		static std::string getCurrentWorkingDirectory();

		static std::string getFilename(std::string filePath);

		static std::string getFilenameWithoutExtension(std::string filePath);

		static std::string getParentDirPath(std::string filePath);

		static std::string getParentDirName(std::string filePath);

		static std::string getName(std::string path);

		static std::string getFileExtension(std::string file);

		static std::vector<std::string> getFileListFromDirectory(std::string directory, std::string fileExtension);

		static std::vector<std::string> getFileListFromDirectory(std::string directory);

	};
}

#endif //__CplusutilFileIO_hpp__