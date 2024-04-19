#pragma once

#include "Command.hpp"

namespace Minecli {

class LoginCommand : public Command {

public:
    void handle() const override;

};

}
