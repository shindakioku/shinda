#include "Checker.h"

void Checker::check(const std::string &github,
                    const std::string &sVersion,
                    const std::string &cVersion,
                    const std::string &gVersion)
{
    Json json;
    // vsv = vector shinda version, vgv - vector github version
    auto vsv = json.split(sVersion, '.');
    auto vgv = json.split(gVersion, '.');

    // // a - shinda version ,b - github version
    Versions a(std::stoi(vsv[0]), 2 <= vsv.size() ? std::stoi(vsv[1]) : 0, 3 == vsv.size() ? std::stoi(vsv[2]) : 0);
    Versions b(std::stoi(vgv[0]), 2 <= vgv.size() ? std::stoi(vgv[1]) : 0, 3 == vgv.size() ? std::stoi(vgv[2]) : 0);

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

    if (FileSystem::fileExists(path)) {
        Core core(path, false);
    }
}
