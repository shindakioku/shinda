#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "../reader/Json.h"
#include "Core.h"

union Versions
{
    struct
    {
        uint8_t tNeverUsingMaybe, tBuild, tMinor, tMajor;
    };
    uint32_t version;
    Versions(uint8_t vMajor, uint8_t aMinor, uint8_t aBuild, uint8_t aNever = 0)
        : tMajor(vMajor), tMinor(aMinor), tBuild(aBuild), tNeverUsingMaybe(aNever) {}
};

class Checker
{
public:
    /*
     sVersion - shinda version (so, version from shinda.json)
     cVersion - clone version (only numbers)
     gVersion - github version (last version from tags)
    */
    void check(const std::string &,
               const std::string & /* sVersion */,
               const std::string & /* cVersion */,
               const std::string & /* gVersion */);

    void checkMore(const std::string &);
};