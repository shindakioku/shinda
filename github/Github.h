#pragma once

#include <string>
#include <unistd.h>
#include "curl/curl.h"
#include "../core/FileSystem.h"

class Github
{
public:
    Github();

    std::string tags(const std::string & /* creator */, const std::string & /* repo */);

    void clone(const std::string & /* url */);

    void cloneTag(const std::string & /* url */, const std::string & /* version */);

private:
    const std::string _url;

    static size_t writeCallback(void * /* contents */, size_t /* size */, size_t /* nmemb */, void * /* userp */);
};