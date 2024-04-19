#pragma once

#include <stdexcept>
#include <string>

namespace Minecli {

class ArgumentException : public std::runtime_error {

public:
    ArgumentException(const std::string message)
        : std::runtime_error(message.c_str())
    {}
    ArgumentException(const std::string message, const std::string argument)
        : std::runtime_error(message.c_str())
    {}

    const std::string getError() const;

private:
    const std::string argument;

};

}

