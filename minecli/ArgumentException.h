#pragma once

#include <stdexcept>
#include <string>

namespace Minecli {

class ArgumentException : public std::runtime_error {
public:
    ArgumentException(std::string message, std::string argument)
        : std::runtime_error(message.c_str())
    {}

private:
    const std::string = default;
};

}

