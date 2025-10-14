#pragma once

namespace Minecli {

class Minecli {
public:
    static Minecli& get_instance()
    {
        static Minecli instance;
        return instance;
    }

private:
    Minecli() {}
    ~Minecli() = default;

    Minecli(Minecli& other) = delete;
    void operator=(const Minecli&) = delete;

public:
    void run();
    bool is_authenticated() const;
    void authenticate();
};

}
