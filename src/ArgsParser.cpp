#include "ArgsParser.h"

#include <string>

ArgsParser::ArgsParser(int argc, char* argv[]) 
    : m_raw_argc(argc)
    , m_raw_argv(argv)
{
    for(int i = 0; i < argc; i++) {
        m_args.push_back(argv[i]);
    }
}

void ArgsParser::addOption(const std::string& option, std::function<void(const ArgsParser&)> callback)
{
    m_options[option] = callback;
}

void ArgsParser::parse()
{
    for (const std::string& arg : m_args) {
        if (const std::function<void(const ArgsParser&)>& callback = m_options[arg]) {
            callback(*this);
        }
    }
}
