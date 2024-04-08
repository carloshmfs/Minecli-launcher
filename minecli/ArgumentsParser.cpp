#include "ArgumentsParser.h"
#include "Option.h"

#include <iostream>
#include <vector>

namespace Minecli {

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        m_cli_args.push_back(argv[i]);
}

Option& ArgumentsParser::add_option(std::string name, std::string long_name)
{
    Option* opt = new Option(name, long_name);
    m_options.push_back(opt);
    return opt;
}

void ArgumentsParser::parse() const
{
    for (const auto& opt : m_options) {
        std::cout << opt->get_name() << std::endl;
    }
}

}

