#pragma once

#include <string>
#include <unistd.h>
#include "curl/curl.h"
#include "../core/FileSystem.h"

class Github
{
public:
    Github();

    std::string tags(const std::string &, const std::string &);

    void clone(const std::string &);

    void cloneTag(const std::string &, const std::string &);

private:
    const std::string _url;

    static size_t writeCallback(void *, size_t, size_t, void *);
};