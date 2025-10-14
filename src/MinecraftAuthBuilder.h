#pragma once

#include "MinecraftAuth.h"

#include <string>

namespace Minecli {

class MinecraftAuthBuilder {
private:
    const std::string& m_client_id;

public:
    void client_id(const std::string& client_id) { m_client_id = client_id; }
    MinecraftAuth build() const;
};

}
