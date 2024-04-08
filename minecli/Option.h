#pragma once

#include "Command.h"

#include <string>
#include <vector>

namespace Minecli {

class Option {

enum class Type {
    Value,
    Flag,
    Command
};

public:
    Option(std::string name, std::string long_name)
        : m_name(name)
        , m_long_name(long_name)
    {}
    ~Option() = default;

    const Option& help(std::string help_msg);
    const Option& choices(std::vector<std::string> values);
    const Option& command(Command& command);
    Option& required(bool irequired);

    const std::string get_name() const { return m_name; }
    const std::string get_long_name() const { return m_long_name; }
    const std::string get_help() const { return m_description; }

private:
    const std::string m_name;
    const std::string m_long_name;
    const std::string m_description;

    bool m_required { false };

    std::vector<std::string> m_choices;

    std::string m_value;
    std::string m_default_value;

    Type m_type { Type::Flag };

    Command* m_command = nullptr;
};

}

