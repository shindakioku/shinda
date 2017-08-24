#include "Reader.h"

Reader::Reader(const std::string &name)
{
    filename = name;
}

int Reader::read()
{
    if (filename.empty())
        return NO_FILE_NAME;

    if (!FileSystem::fileExists(filename))
        return FILE_NOT_EXISTS;

    std::ifstream file(filename.c_str()); // use filesystem maybe
    std::string a, b;

    while (file >> a >> b)
    {
        a.erase(0, 1);
        a.erase(a.length() - 2);

        b.erase(0, 1);
        b.erase(b.length() - 1);

        addDependencies(a, b);
    }

    file.close();

    return 0;
}

std::map <std::string, std::string> Reader::getDependencies()
{
    return dependencies;
}

void Reader::addDependencies(const std::string &first, const std::string &second)
{
    dependencies.insert(std::pair<std::string, std::string>(first, second));
}