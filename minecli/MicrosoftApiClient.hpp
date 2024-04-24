#pragma once

#include "MicrosoftResponse.hpp"

#include <string>

namespace Minecli
{

class MicrosoftApiClient {

public:
    MicrosoftApiClient();

    const MicrosoftResponse attemptAuth(const std::string& email, const std::string& password) const;

};

}
