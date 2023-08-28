#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>

namespace Cli {

Parser::Parser(int argc, char* argv[], std::vector<std::string> available_opts)
	: m_available_opts(available_opts)
{
	for (size_t i = 1; i < argc; i++)
		m_arg.push_back(argv[i]);
}

Parser::~Parser()
{
}

void Parser::handle()
{
	for (auto& available_opt : m_available_opts) {
		for (auto& arg : m_arg) {
			if (available_opt != arg) {
				std::cerr << "ERROR: Argument < " << arg << " > not found!"  << std::endl;
				exit(EXIT_FAILURE);
			}

			m_matched_opt.push_back(arg);
		}
	}
}

}