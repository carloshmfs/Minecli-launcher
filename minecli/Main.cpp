#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> available_opts = { "TESTE" };

	Cli::Parser cliParser(argc, argv, available_opts);
	cliParser.handle();

	return EXIT_SUCCESS;
}