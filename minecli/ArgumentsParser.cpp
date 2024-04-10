#include "ArgumentsParser.h"
#include "Option.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

namespace Minecli {

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        m_cli_args.push_back(argv[i]);
}

Option* ArgumentsParser::add_option(std::string name, std::string long_name)
{
    Option *opt = new Option(name, long_name);
    m_options.push_back(opt);

    return opt;
}

void ArgumentsParser::parse() const
{
    for (const auto& arg : m_cli_args)
        for (auto& opt : m_options) {
            if (*opt == arg) {
                switch (opt->get_type()) 
                {
                    case Option::Type::Flag:
                        break;
                    case Option::Type::Value:
                        break;
                    case Option::Type::Command:
                        opt->get_command()->handle();
                        break;

                    default:
                        throw std::logic_error("The Option has no type setted");
                        break;
                }
            }
        };
}

}

