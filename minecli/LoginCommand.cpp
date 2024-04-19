#include "LoginCommand.hpp"

#include <iostream>

namespace Minecli {

void LoginCommand::handle() const
{
    std::cout << "Hello World! from LoginCommand::login()" << std::endl;
}

}
