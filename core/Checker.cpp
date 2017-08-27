#include "Checker.h"

void Checker::check(std::string const& githubUrl,
                    std::string const& shindaVersion,
                    std::string const& cVersion,
                    std::string const& githubVersion)
{
    Json json;
    // vsv = vector shinda version, vgv - vector github version
    auto vsv = json.split(shindaVersion, '.');
    auto vgv = json.split(githubVersion, '.');

    Versions shinda(std::stoi(vsv[0]), 2 <= vsv.size() ? std::stoi(vsv[1]) : 0, 3 == vsv.size() ? std::stoi(vsv[2]) : 0);
    Versions github(std::stoi(vgv[0]), 2 <= vgv.size() ? std::stoi(vgv[1]) : 0, 3 == vgv.size() ? std::stoi(vgv[2]) : 0);

    if (github.version > shinda.version)
    {
        Github _github;

        checkMore(githubUrl);

        _github.cloneTag(githubUrl, cVersion);
    }
}

void Checker::checkMore(const std::string &github)
{
    auto path = "vendor/" + github + "/shinda/shinda.json";

    if (FileSystem::fileExists(path)) {
        Core(path, false).check();
    }
}
