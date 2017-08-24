#include <iostream>
#include "Core.h"

Core::Core(const std::string &filename, const bool &_updateShinda)
    :
    updateShinda(_updateShinda),
    github(new Github),
    json(new Json),
    reader(new Reader(filename))
{
    check();
}

Core::~Core()
{
    delete github;

    delete json;

    delete reader;
}

void Core::check()
{
    using namespace std;

    auto result = reader->read();

    if (1 == result)
    {
        cout << "Enter name for file" << endl;

        return;
    }

    if (2 == result)
    {
        cout << "File not exists" << endl;

        return;
    }

    auto dependencies = reader->getDependencies();

    for (const auto &v : dependencies)
    {
        auto url = json->split(v.first, '/');
        auto checker = new Checker;

        // if vendor/%username% does not exists, program will do 'git clone'
        if (!FileSystem::dirExists("vendor/" + url[0]))
        {
            github->clone(v.first);

            if ("*" != v.second)
                github->cloneTag(v.first, v.second);

            checker->checkMore(v.first);
            setVersion(v.first, v.second);

            continue;
        }

        // if vendor/%username%/%packagename% does not exists, program will do 'git clone'
        if (!FileSystem::dirExists("vendor/" + url[0] + '/' + url[1])) // maybe v.first ?
        {
            github->clone(v.first);

            if ("*" != v.second)
                github->cloneTag(v.first, v.second);

            checker->checkMore(v.first);
            setVersion(v.first, v.second);

            continue;
        }

        if ("*" == v.second)
        {
            github->clone(v.first);
            checker->checkMore(v.first);
            setVersion(v.first, v.second);

            continue;
        }

        auto versions = github->tags(url[0], url[1]);
        auto shindaVersion = json->version(v.second);
        std::vector <std::string> version;

        json->add(versions);

        version = json->version();

        setVersion(v.first, version[0]);

        checker->check(v.first, shindaVersion, version[0], version[1]);
    }

    updateVersions();
}

void Core::setVersion(const std::string &github, const std::string &version)
{
    if (updateShinda)
        versionsToShinda.insert(std::pair<std::string, std::string>(github, version));
}

void Core::updateVersions()
{
    if (updateShinda)
        FileSystem::write("shinda.json", versionsToShinda);
}