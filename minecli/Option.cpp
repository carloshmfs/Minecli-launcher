#include "Option.h"

#include <iostream>
#include <string>

namespace Minecli {

void Option::dump() const
{
    std::cout << "Option::Type: " << m_long_name << std::endl
        << m_description << std::endl
        << m_required << std::endl
        << m_name << std::endl;

    switch (m_type) {
        case Type::Flag:
            std::cout << "FLAG" << std::endl;
            break;
        case Type::Value:
            std::cout << "Value" << std::endl;
            break;
        case Type::Command:
            std::cout << "Command" << std::endl;
            break;
    }
}

Option* Option::help(std::string help_msg)
{
    m_description = help_msg;
    return this;
}

Option* Option::required(bool required)
{
    m_required = required;
    return this;
}

Option* Option::set_type(Type type)
{
    m_type = type;
    return this;
}

}

