#include "ArgumentsParser.h"
#include <iostream>

int main(int argc, char** argv)
{
    Minecli::ArgumentsParser argsParser(argc, argv);
    argsParser.add_option("-e", "--exemplo")
        .required(true)
        .help("Command de exemplo");
    
    try {
        argsParser.parse();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
