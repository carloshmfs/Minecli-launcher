#pragma once

#include <string>
#include <vector>

class ArgsParser
{

private:
    struct Option {
        std::string name;
        bool& is_active;

        bool operator==(const std::string& value) const { return this->name == value; }
    };

public:
    static void add_option(std::string option, bool& value) {
		m_available_options.push_back({ .name = option, .is_active = value });
	}

	ArgsParser(int argc, char* argv[]);

    void parse();

private:
	inline static std::vector<Option> m_available_options;

	std::vector<std::string> m_args;

};
