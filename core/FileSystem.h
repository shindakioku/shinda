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
    static bool dirExists(const std::string &);

    static bool fileExists(const std::string &);

    static int removeDir(const std::string &);

    static void write(const std::string &, const std::map <std::string, std::string> &);
};