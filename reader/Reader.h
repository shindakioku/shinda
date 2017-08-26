#pragma once

#include <string>
#include <map>
#include <fstream>
#include <sys/stat.h>
#include "../core/FileSystem.h"

#define NO_FILE_NAME 1
#define FILE_NOT_EXISTS 2

class Reader
{
private:
    std::string filename;

    std::map <std::string, std::string> dependencies;

    /*
     first - username/packagename
     second - version of tag, if * then it will master
    */
    void addDependencies(const std::string &, const std::string &);

public:
    Reader(const std::string &);

    int read();

    std::map <std::string, std::string> getDependencies();
};
