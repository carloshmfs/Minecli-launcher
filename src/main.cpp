#include "ArgsParser.h"
#include "Minecli.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
    bool showHelp = false;

	ArgsParser argsParser(argc, argv);
    // argsParser.addOption("-h", "--help", false, [](const ArgsParser& parser) -> void {
    //     std::cout << "Usage: minecli [options...]" << std::endl << std::endl;
    //     std::cout << "OPTIONS:" << std::endl;
    //     std::cout << " -h\t--help\t\tShow this message." << std::endl;
    //     std::cout << " -l\t--login\t\tLogin with your microsoft account." << std::endl;
    // });

    // argsParser.addOption("-t", "--test", true, [](const ArgsParser& parser) -> void {
    //     std::cout << "FINALMENTE CHEGOU AQUI" << std::endl;
    // });

    try {
        argsParser.parse();
        Minecli::Minecli::get_instance().run();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
