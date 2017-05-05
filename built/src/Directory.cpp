#include "Directory.h"
#include "FileIO.h"

Directory::Directory(std::string path)
{
	mPath = cplusutil::FileIO::getAbsolutePath(path);
	cplusutil::FileIO::createDirectoriesIfNotExist(mPath.string());
	mDirName = cplusutil::FileIO::getName(mPath.string());
	for (auto& part : mPath)
	{
		directories.push_back(part.string());
	}
}

void Directory::addDirectory(std::string directory)
{
	boost::filesystem::path tmp{ mPath };
	tmp /= directory;
	mPath = tmp.string();
	directories.push_back(directory);
	cplusutil::FileIO::createDirectoriesIfNotExist(mPath.string());
	mDirName = directory;
}

std::string Directory::getPath()
{
	return mPath.string();
}
