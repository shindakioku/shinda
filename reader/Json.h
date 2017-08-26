#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <regex>

class Json
{
public:
    Json();

    Json(std::string &);

    void add(std::string &);

    std::vector <std::string> version();

    std::string version(const std::string &);

    std::vector <std::string> split(const std::string &, const char);

private:
    std::string body;
};