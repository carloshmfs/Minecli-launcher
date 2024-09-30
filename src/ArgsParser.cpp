#include "ArgsParser.h"

#include <iostream>
#include <string>

const char* ArgError::what() const noexcept
{
    return m_message.c_str();
}

ArgsParser::ArgsParser(int argc, char* argv[]) 
    : m_raw_argc(argc)
    , m_raw_argv(argv)
{
    for(int i = 0; i < argc; i++) {
        m_args.push_back(argv[i]);
    }
}

void ArgsParser::addOption(const std::string& shortName, const std::string& longName, bool isRequired, std::function<void(const ArgsParser&)> callback)
{
    m_options.push_back({
        .shortName = shortName,
        .longName = longName,
        .isRequired = isRequired,
        .callback = callback
    });
}

void ArgsParser::parse()
{
    for (const Option& option : m_options) {
        checkArgs(option);
    }
}

bool ArgsParser::checkArgs(const Option& option) const
{
    std::cout << "ArgsParser::checkArgs()" << option.shortName << std::endl;

    if (option.isRequired) {
        return checkRequiredArgs(option);
    }

    return checkNonRequiredArgs(option);
}

bool ArgsParser::checkRequiredArgs(const Option& option) const
{
    std::cout << "ArgsParser::checkRequiredArgs()" << option.shortName << std::endl;
    for (const std::string& arg : m_args) {
        if (arg == option.shortName || arg == option.longName) {
            option.callback(*this);
            return true;
        }
    }

    throw ArgError("Missing required argument.", option);

    return false;
}

bool ArgsParser::checkNonRequiredArgs(const Option& option) const
{
    std::cout << "ArgsParser::checkNonRequiredArgs()" << option.shortName << std::endl;
    for (const std::string& arg : m_args) {
        if (arg == option.shortName || arg == option.longName) {
            option.callback(*this);
        }
    }

    return true;
}
