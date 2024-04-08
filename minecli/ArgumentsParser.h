#pragma once

#include "IArgumentsParser.h"
#include "Option.h"

#include <string>
#include <vector>

namespace Minecli {

class ArgumentsParser : public IArgumentsParser {
public:
    virtual Option& add_option(std::string name, std::string long_name) override;

    ArgumentsParser(int argc, char** argv);

    void parse() const override;

private:
    std::vector<std::string> m_cli_args;
    std::vector<Option> m_options;
};

}

