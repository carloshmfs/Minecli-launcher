#pragma once

#include <string>
#include <vector>

namespace Cli {

class Parser
{
public:
	Parser(int argc, char* argv[], std::vector<std::string> available_opts);
	~Parser();

	void handle();

	std::vector<std::string> getAvailableOpts() { return m_available_opts; }

private:
	std::vector<std::string> m_arg;
	std::vector<std::string> m_available_opts;
	std::vector<std::string> m_matched_opt;
};

}
