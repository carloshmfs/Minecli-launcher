#pragma once

#include "MinecraftAuthBuilder.h"

namespace Minecli {

class MinecraftAuth {
public:
    static MinecraftAuthBuilder& builder() {
        MinecraftAuthBuilder builder();
        return builder;
    }

public:
    void login();
};

}
