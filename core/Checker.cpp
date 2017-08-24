#include "Checker.h"

void Checker::check(const std::string &github,
                    const std::string &sVersion,
                    const std::string &cVersion,
                    const std::string &gVersion)
{
    using namespace std;

    auto json = new Json;
    // vsv = vector shinda version, vgv - vector github version
    auto vsv = json->split(sVersion, '.');
    auto vgv = json->split(gVersion, '.');

    delete json;

    // // a - shinda version ,b - github version
    Versions a(stoi(vsv[0]), 2 <= vsv.size() ? stoi(vsv[1]) : 0, 3 == vsv.size() ? stoi(vsv[2]) : 0);
    Versions b(stoi(vgv[0]), 2 <= vgv.size() ? stoi(vgv[1]) : 0, 3 == vgv.size() ? stoi(vgv[2]) : 0);

    if (b.version > a.version)
    {
        Github _github;

        checkMore(github);

        _github.cloneTag(github, cVersion);
    }
}

void Checker::checkMore(const std::string &github)
{
    auto path = "vendor/" + github + "/shinda/shinda.json";

    if (FileSystem::fileExists(path))
        Core core(path, false);
}