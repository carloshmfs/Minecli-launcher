#pragma once

#include "Command.h"

namespace Minecli {

class LoginCommand : public Command {
public:
    void handle() override;
};

}
