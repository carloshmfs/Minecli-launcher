#pragma once

namespace Minecli {

class Command {

public:
    virtual void handle() const = 0;

protected:
    virtual ~Command() = default;

};

}
