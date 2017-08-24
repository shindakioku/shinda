#include "FileSystem.h"

bool FileSystem::dirExists(const std::string &path)
{
    struct stat info;

    if (0 != stat(path.c_str(), &info))
        return false; // cannot access;
    else if (info.st_mode & S_IFDIR)
        return true;

    return false;
}

bool FileSystem::fileExists(const std::string &path)
{
    struct stat buffer;

    return (0 == stat(path.c_str(), &buffer));
}

int FileSystem::removeDir(const std::string &path)
{
    auto s = "sudo rm -rf " + path;
    system(s.c_str());
}

void FileSystem::write(const std::string &_file, const std::map <std::string, std::string> &versions)
{
    if (!fileExists(_file))
        return;

    std::ofstream file;
    file.open(_file, std::ofstream::out);
    char s = '"';

    for (const auto &v : versions)
    {
        auto z = s + v.first + s + ": " + s + v.second + s;

        file << z << std::endl;
    }

    file.close();
}