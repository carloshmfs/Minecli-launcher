#include "ArgsParser.h"

#include <algorithm>

ArgsParser::ArgsParser(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) {
        m_args.emplace_back(argv[i]);
    }
}

void ArgsParser::add_option(bool& value, std::string help_string, std::string long_name, std::string short_name)
{
    m_available_options.emplace_back<Option>({ long_name, short_name, help_string, value });
}

void ArgsParser::parse()
{
    for (const auto& opt : m_args) {
        auto option_found = std::find(m_available_options.begin(), m_available_options.end(), opt);
        if (option_found->long_name == opt || option_found->short_name == opt)
            option_found->value = true;
    }
}
