#pragma once

#include "Command.hpp"

namespace Minecli {

class TestCommand : public Command {

public:
    void handle() const override;

};

}
