#include "ArgumentsParser.h"
#include "Option.h"
#include "LoginCommand.h"

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
        ->set_type(Option::Type::Command)
        ->command(*new LoginCommand)
        ->required(true)
        ->help("Nice Description");


    try {
        argsParser.parse();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
