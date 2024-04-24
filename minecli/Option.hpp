#pragma once

#include "Command.hpp"

#include <string>
#include <vector>

namespace Minecli {

class Option {

public:
    enum class Type {
        Value,
        Flag,
        Command
    };

    Option(std::string name, std::string long_name)
        : m_name(name)
        , m_long_name(long_name)
    {
    }
    ~Option() = default;

    bool operator==(const std::string& value) const { return value == m_name || value == m_long_name; }

    void dump() const;

    Option* help(std::string help_msg);
    Option* choices(std::vector<std::string> values);
    Option* command(Command& command);
    Option* required(bool required);
    Option* set_type(Type type);

    bool isRequired() const;

    const std::string get_name() const { return m_name; }
    const std::string get_long_name() const { return m_long_name; }
    std::string get_help() const { return m_description; }
    Type get_type() const { return m_type; }
    Command* get_command() const { return m_command; }

private:
    const std::string m_name;
    const std::string m_long_name;
    std::string m_description;

    bool m_required { false };

    std::vector<std::string> m_choices;

    std::string m_value;
    std::string m_default_value;

    Type m_type { Type::Flag };

    Command* m_command = nullptr;

};

}

