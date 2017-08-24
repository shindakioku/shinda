#include "Json.h"

Json::Json()
{

}

Json::Json(std::string &_body)
{
    if (!_body.empty())
        add(_body);
}

void Json::add(std::string &_body)
{
    if ('[' == _body.at(0))
        _body.erase(0, 1);

    if (']' == _body.at(_body.length() - 1))
        _body.erase(_body.length() - 1);

    body = _body;
}

std::vector <std::string> Json::version()
{
    std::vector <std::string> v;

    if (body.empty())
        return v;

    auto versions = split(body, ',');
    auto version = versions.at(versions.size() - 5);
    auto found = version.find("{\"ref\":");

    if (found != std::string::npos)
    {
        version.erase(0, 18);
        version.erase(version.length() - 1);
        v.push_back(version);

        std::smatch m;
        std::regex e("(\\d+(\\.\\d+){1,2})");
        // todo: make regular for 5-2-1 and before return change - to .

        while (std::regex_search(version, m, e))
        {
            v.push_back(m[0]);
            version = m.suffix().str();
        }
    }

    return v;
}

std::string Json::version(const std::string &_body)
{
    std::string s;
    std::smatch m;
    std::regex e("(\\d+(\\.\\d+){1,2})");
    // todo: make regular for 5-2-1 and before return change - to .

    while (std::regex_search(_body, m, e))
    {
        s = m[0];

        break;
    }

    return s;
}

std::vector <std::string> Json::split(const std::string &data, const char &decilim)
{
    std::vector <std::string> result;
    std::istringstream iss(data);

    for (std::string token; std::getline(iss, token, decilim);)
    {
        result.push_back(std::move(token));
    }

    return result;
}