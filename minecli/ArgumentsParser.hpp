#pragma once

#include "Option.hpp"

#include <string>
#include <vector>

namespace Minecli {

class ArgumentsParser {

public:
    virtual Option* add_option(std::string name, std::string long_name);

    ArgumentsParser(int argc, char** argv);

    void parse() const;
    const std::string getHelp() const;
    void dump() const;

private:
    std::vector<std::string> m_cli_args;
    std::vector<Option*> m_options;

};

}

