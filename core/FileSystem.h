#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>

class FileSystem
{
public:
    static bool dirExists(const std::string & /* path */);

    static bool fileExists(const std::string & /* path */);

    static int removeDir(const std::string & /* path */);

    static void write(const std::string & /* _file */, const std::map <std::string, std::string> & /* versions */);
};