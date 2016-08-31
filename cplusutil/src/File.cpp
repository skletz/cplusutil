#include "File.h"
#include "FileIO.h"
#include "String.h"


File::File(std::string path, std::string file)
{
	mPartPath = path;
	mPartFilename = cplusutil::FileIO::getFilenameWithoutExtension(file);
	mPartFileExtension = cplusutil::FileIO::getFileExtension(file);
}

File::File(std::string path, std::string filename, std::string fileExtension)
{
	mPartPath = path;
	mPartFilename = filename;
	mPartFileExtension = fileExtension;
}

File::File(std::string file)
{
	setFile(file);
}

std::string File::getFile() const
{
	std::string conact;
	if (mPartFileExtension.find("."))
		conact = (mPartFilename + "." + mPartFileExtension);
	else
		conact = (mPartFilename + mPartFileExtension);

	boost::filesystem::path absolute{ mPartPath };
	absolute /= conact;
	return absolute.string();
}

void File::setFile(std::string file)
{
	std::string absolute = cplusutil::FileIO::getAbsolutePath(file);

	if (isDirectory())
	{
		mPartFilename = cplusutil::FileIO::getFilenameWithoutExtension(absolute);
		mPartFileExtension = cplusutil::FileIO::getFileExtension(absolute);
		mPartPath = cplusutil::FileIO::getParentDirPath(absolute);
	}
	else
	{
		mPartPath = absolute;
	}
	cplusutil::FileIO::createDirectoriesIfNotExist(mPartPath);
}

std::string File::getFilename() const
{
	return mPartFilename;
}

void File::setFilename(std::string file)
{
	if (file.find(".") != std::string::npos)
	{
		mPartFilename = cplusutil::String::split(file, '.').at(0);
		mPartFileExtension = cplusutil::String::split(file, '.').at(1);
	}

	mPartFilename = file;
}

std::string File::getFileExtension() const
{
	return mPartFileExtension;
}

void File::setFileExtension(std::string extension)
{
	mPartFileExtension = extension;

}

void File::fileparts(std::string& pathstr, std::string& name, std::string& ext) const
{
	pathstr = mPartPath;
	name = mPartFilename;
	ext = mPartFileExtension;
}

bool File::isDirectory() const
{
	return cplusutil::FileIO::isDirectory(getFile());
}

void File::extendFileName(std::string name)
{
	mPartFilename = cplusutil::String::concatCStrings("_", 2, mPartFilename.c_str(), name.c_str());
}

void File::addDirectoryToPath(std::string directory)
{
	boost::filesystem::path tmp{ mPartPath };
	tmp /= directory;
	mPartPath = tmp.string();
	cplusutil::FileIO::createDirectoriesIfNotExist(mPartPath);
}

