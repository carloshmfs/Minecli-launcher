#include "ArgumentException.hpp"
#include "ArgumentsParser.hpp"
#include "LoginCommand.hpp"
#include "Option.hpp"

#include <iostream>

using namespace Minecli;

int main(int argc, char** argv)
{
    ArgumentsParser argsParser(argc, argv);

    argsParser.add_option("-e", "--exemplo")
        ->set_type(Option::Type::Value)
        ->required(true)
        ->help("Comando do tipo Option::Type::Value de exemplo");

    argsParser.add_option("-l", "--login")
        ->set_type(Option::Type::Command )
        ->command(*new LoginCommand)
        ->required(true)
        ->help("Nice Description");

    try {
        argsParser.dump();
        argsParser.parse();
    } 

    catch (const ArgumentException& e) {
        std::cerr << "ERROR: " << e.getError() << std::endl;
        return 1;
    }

    return 0;
}
