#include "ArgumentsParser.h"
#include "Option.h"

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

Option& ArgumentsParser::add_option(std::string name, std::string long_name)
{
    Option *opt = new Option(name, long_name);
    m_options.push_back(*opt);

    return *opt;
}

void ArgumentsParser::parse() const
{
    for (const Option& valid_opt : m_options) {
        for (const std::string& argument : m_cli_args) {
            if (valid_opt.get_name() != argument) {
                throw std::runtime_error("Unknown argument");
            }

            switch (valid_opt.get_type()) 
            {
                case Option::Type::Flag:
                    valid_opt.dump();
                    break;
                case Option::Type::Value:
                    break;
                case Option::Type::Command:
                    break;

                default:
                    throw std::logic_error("Argument dont exist");
                    break;
            }
        }
    }
}

}

