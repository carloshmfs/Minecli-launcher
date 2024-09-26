#pragma once

#include <functional>
#include <string>
#include <vector>
#include <map>

class ArgsParser
{
public:
    ArgsParser(int argc, char* argv[]);

    void addOption(const std::string& option, std::function<void(const ArgsParser&)> callback);

    void parse();

private:
    std::map<const std::string, std::function<void(const ArgsParser&)>> m_options;

    std::vector<std::string> m_args;

    int m_raw_argc;
    char** m_raw_argv;
};
