#include "FileIO.h"
#include <boost/foreach.hpp>


std::string cplusutil::FileIO::getAbsolutePath(std::string _relativPath)
{
	fs::path absolute(fs::initial_path());
	absolute = fs::system_complete(_relativPath);
	absolute.normalize();
	return absolute.string();
}

bool cplusutil::FileIO::createDirectoriesIfNotExist(std::string _path)
{
	fs::path absolutPath = getAbsolutePath(_path);
	return fs::create_directories(absolutPath);
}

bool cplusutil::FileIO::isValidPath(std::string _path)
{
	fs::path path{ _path };
	if (fs::exists(_path))
	{
		return true;
	}

	std::string absolute = fs::absolute(_path).string();
	if (fs::exists(absolute))
	{
		return true;
	}

	return false;
}

bool cplusutil::FileIO::isDirectory(std::string _path)
{
	fs::path path{ _path };
	if (fs::is_directory(path))
	{
		return true;
	}
	return false;
}

bool cplusutil::FileIO::isValidPathToDirectory(std::string _path)
{
	return (isValidPath(_path) && isDirectory(_path));
}

bool cplusutil::FileIO::isValidPathToFile(std::string _path)
{
	return (isValidPath(_path) && !isDirectory(_path));
}

std::string cplusutil::FileIO::getCurrentWorkingDirectory()
{
	return fs::current_path().string();
}

std::string cplusutil::FileIO::getFilename(std::string filePath)
{
	fs::path p = filePath;
	return p.filename().string();
}

std::string cplusutil::FileIO::getFilenameWithoutExtension(std::string filePath)
{
	fs::path p = filePath;
	return p.filename().stem().string();
}

std::string cplusutil::FileIO::getParentDirPath(std::string filePath)
{
	fs::path p = filePath;
	return p.remove_filename().string();
}

std::string cplusutil::FileIO::getParentDirName(std::string filePath)
{
	fs::path p = filePath;
	return p.parent_path().string();
}

std::string cplusutil::FileIO::getName(std::string path)
{
	fs::path p = path;
	return p.filename().string();
}

std::string cplusutil::FileIO::getFileExtension(std::string file)
{
	fs::path p = file;
	return p.extension().string();
}

std::vector<std::string> cplusutil::FileIO::getFileListFromDirectory(std::string directory, std::string fileExtension)
{
	std::vector<std::string> files;
	fs::path path_to_directory = directory;

	fs::directory_iterator v_it(path_to_directory), eovd;

	int cnt = 0;
	BOOST_FOREACH(fs::path const &p1, std::make_pair(v_it, eovd))
	{
		if (fs::is_regular_file(p1) && v_it->path().extension() == fileExtension)
		{
			files.push_back(p1.string());
		}
	}

	return files;
}

std::vector<std::string> cplusutil::FileIO::getFileListFromDirectory(std::string directory)
{
	std::vector<std::string> files;
	fs::path path_to_directory = directory;

	fs::directory_iterator v_it(path_to_directory), eovd;

	int cnt = 0;
	BOOST_FOREACH(fs::path const &p1, std::make_pair(v_it, eovd))
	{
		files.push_back(p1.string());
	}

	return files;
}
