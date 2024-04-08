#include "Option.h"

#include <string>

namespace Minecli {

const Option& Option::help(std::string help_msg)
{
    return *this;
}

Option& Option::required(bool required)
{
    return *this;
}

}

