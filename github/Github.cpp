#include "Github.h"

Github::Github()
    :
    _url("https://github.com/")
{

}

std::string Github::tags(const std::string &creator, const std::string &repo)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();

    if (curl)
    {
        auto s = "https://api.github.com/repos/" + creator + "/" + repo + "/git/refs/tags";

        curl_easy_setopt(curl, CURLOPT_URL, s.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Awesome-Shinda-App");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return readBuffer;
    }

    return "";
}

void Github::clone(const std::string &url)
{
    auto s = "git clone " + _url + url + " vendor/" + url;

    if (FileSystem::dirExists("vendor/" + url))
        FileSystem::removeDir("vendor/" + url);

    system(s.c_str());
}

void Github::cloneTag(const std::string &url, const std::string &version)
{
    auto s = "git checkout tags/" + version;
    auto d = "vendor/" + url;

    chdir(d.c_str());
    system(s.c_str());
    chdir("../../../");
}

size_t Github::writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *) userp)->append((char *) contents, size * nmemb);

    return size * nmemb;
}