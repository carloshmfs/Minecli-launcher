#pragma once

namespace Minecli {

class Command {
public:
    virtual void handle() = 0;

protected:
    virtual ~Command() = default;
};

}
