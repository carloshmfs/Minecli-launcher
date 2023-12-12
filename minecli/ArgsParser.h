#pragma once

#include <string>
#include <vector>

struct Option {
    const std::string long_name;
    const std::string short_name;
    const std::string help_string;

    bool& value;

    bool operator==(const std::string& value) const { return this->short_name == value || this->long_name == value; }
};

class ArgsParser
{
public:
    void add_option(bool&, std::string, std::string, std::string);

	ArgsParser(int, char**);

    void parse();

private:
	std::vector<Option> m_available_options;
    std::vector<std::string> m_args;
};
