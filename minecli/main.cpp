#include "ArgsParser.h"
#include "Application.h"

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	bool auth_with_microsoft = false;

	ArgsParser::add_option("-l", auth_with_microsoft);
	ArgsParser argsParser(argc, argv);
	
	argsParser.parse();

    if (auth_with_microsoft) {
        Application::auth();
        return EXIT_SUCCESS;
    }

    try {
        Application app;
        app.exec();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}