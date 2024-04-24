#include "TestCommand.hpp"

#include <iostream>

namespace Minecli {

void TestCommand::handle() const
{
    std::cout << "Hello World! from Testcommand::handle()" << std::endl;
}

}
