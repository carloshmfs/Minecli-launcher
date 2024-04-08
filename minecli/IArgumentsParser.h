#pragma once

#include "Option.h"

#include <string>

namespace Minecli {

class IArgumentsParser {
public:
    virtual Option& add_option(std::string name, std::string long_name) = 0;

    void virtual parse() const = 0;

protected:
    virtual ~IArgumentsParser();
};

}

