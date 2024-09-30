#include "ArgsParser.h"
#include "Application.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
    bool showHelp = false;

	ArgsParser argsParser(argc, argv);
    argsParser.addOption("-h", "--help", false, [](const ArgsParser& parser) -> void {
        std::cout << "Usage: minecli [options...]" << std::endl << std::endl;
        std::cout << "OPTIONS:" << std::endl;
        std::cout << " -h\t--help\t\tShow this message." << std::endl;
        std::cout << " -l\t--login\t\tLogin with your microsoft account." << std::endl;
    });

    argsParser.addOption("-t", "--test", true, [](const ArgsParser& parser) -> void {
        std::cout << "FINALMENTE CHEGOU AQUI" << std::endl;
    });

    try {
        argsParser.parse();
    } catch (const ArgError& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    Application app;

    try {
        app.exec();
    } catch (const std::runtime_error& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
