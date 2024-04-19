#include "ArgumentException.hpp"

#include <string>

namespace Minecli {

const std::string ArgumentException::getError() const
{
    std::string errorBuild;
    errorBuild.append(what());
    errorBuild.append("Argument: ");
    errorBuild.append(argument);

    return errorBuild;
}

}
