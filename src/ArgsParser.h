#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

class ArgsParser;

struct Option {
    const std::string& shortName;
    const std::string& longName;

    bool isRequired = false;

    std::function<void(const ArgsParser&)> callback;
};

class ArgError : public std::runtime_error
{
public:
    explicit ArgError(const std::string& message, const Option& option) 
        : std::runtime_error(message)
        , m_message(message)
        , m_option(option)
    {}

    virtual const char* what() const noexcept override;

private:
    const std::string m_message;
    const Option& m_option;
};

class ArgsParser
{
public:
    ArgsParser(int argc, char* argv[]);

    void addOption(const std::string& shortName, const std::string& longName, bool required, std::function<void(const ArgsParser&)> callback);

    void parse();

private:
    bool checkArgs(const Option& option) const;
    bool checkRequiredArgs(const Option& option) const;
    bool checkNonRequiredArgs(const Option& option) const;

    std::vector<Option> m_options;

    std::vector<std::string> m_args;

    int m_raw_argc;
    char** m_raw_argv;
};
