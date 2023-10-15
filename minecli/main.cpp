#include "ArgsParser.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	bool is_exemplo_activated = false;

	ArgsParser::add_option("exemplo1", is_exemplo_activated);
	ArgsParser argsParser(argc, argv);
	
	argsParser.parse();

	std::cout << is_exemplo_activated << std::endl;

	return EXIT_SUCCESS;
}