#pragma once

#include <string>
#include <map>
#include "Checker.h"
#include "FileSystem.h"
#include "../reader/Reader.h"
#include "../reader/Json.h"
#include "../github/Github.h"

class Core
{
public:
    Core(const std::string &, const bool = true);

private:
    std::map <std::string, std::string> versionsToShinda;

    bool updateShinda;

    Github github;

    Json json;

    Reader reader;

    void check();

    void setVersion(const std::string &, const std::string &);

    void updateVersions();
};