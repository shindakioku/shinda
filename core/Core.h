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
    Core(const std::string & /* filename */, const bool & = true /* _updateShinda */);

    ~Core();

private:
    std::map <std::string, std::string> versionsToShinda;

    bool updateShinda;

    Github *github;

    Json *json;

    Reader *reader;

    void check();

    void setVersion(const std::string & /* github */, const std::string & /* version */);

    void updateVersions();
};