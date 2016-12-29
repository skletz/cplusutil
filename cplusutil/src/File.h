#ifndef __UTIL_FILE_H__
#define __UTIL_FILE_H__

#include <string>

class File
{

	//String containing the part of filename interpreted as a path 
	std::string mPartPath;
	//String containing the name of the file without extension
	std::string mPartFilename;
	//String containing the file extension only
	std::string mPartFileExtension;

	void setFile(std::string file);
	void setFilename(std::string name);
	void setFileExtension(std::string extension);

public:
	File(std::string path, std::string filename, std::string fileExtension);
	File(std::string path, std::string file);
	File(std::string file);

	std::string getFile() const;
	std::string getFilename() const;
	std::string getFileExtension() const;

	//std::string getAbsolutePath();
	//std::string getRelativePath();

	void fileparts(std::string& pathstr, std::string& name, std::string& ext) const;

	bool isDirectory() const;
	void addDirectoryToPath(std::string directory);
	void extendFileName(std::string name);

	//File& operator = (const std::string& file);
};

#endif //__UTIL_FILE_H__
