#include "ArgumentException.hpp"
#include "ArgumentsParser.hpp"
#include "Option.hpp"

#include <iostream>
#include <string>
#include <vector>

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
    for (const auto& arg : m_cli_args) {
        findOption(arg);
    }
}

void ArgumentsParser::findOption(const std::string& argument) const
{
    for (const auto& opt : m_options) {
        if (*opt == argument) {
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
                    throw new ArgumentException("The Option has no type setted");
                    break;
            }
        }

        std::cout << argument << " " << opt->get_name() << std::endl;
        if (!opt->isRequired())
            throw new ArgumentException("qwertyasdf");
    };
}

void ArgumentsParser::sendHelp() const
{
    std::cout << "HELLO FROM sendHelp()" << std::endl;
}

void ArgumentsParser::dump() const
{
    for (const auto& opt : m_options) {
        std::cout << std::endl;
    }

    exit(1);

}

}

