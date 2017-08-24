#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <regex>

class Json
{
public:
    Json();

    Json(std::string & /* _body */);

    void add(std::string & /* _body */);

    std::vector <std::string> version();

    std::string version(const std::string & /* _body */);

    std::vector <std::string> split(const std::string & /* data */, const char & /* decilim */);

private:
    std::string body;
};