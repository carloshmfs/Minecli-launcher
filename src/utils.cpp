#include "utils.h"

#include <string>
#include <regex>
#include <sstream>

std::string encode_uri_component(const std::string& input)
{
    std::ostringstream oss;
    std::regex r("[!'\\(\\)*-.0-9A-Za-z_~]");

    for (const char& c : input) {
        if (std::regex_match((std::string) {c}, r)) {
            oss << c;
            continue;
        }

        oss << "%" << std::uppercase << std::hex << (0xff & c);
    }

    return oss.str();
}
