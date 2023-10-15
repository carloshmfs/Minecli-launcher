#include "ArgsParser.h"

#include <algorithm>

ArgsParser::ArgsParser(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        m_args.push_back(argv[i]);
    }
}

void ArgsParser::parse()
{
    for (auto opt : m_args) {
        auto option_found = std::find(m_available_options.begin(), m_available_options.end(), opt);
        if (opt == option_found->name)
            option_found->is_active = true;
    }
}