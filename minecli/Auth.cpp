#include "Auth.h"

#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <iostream>

void Auth::microsoft_login()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});

    std::cout << r.text << std::endl;

    std::cout << "Auth::microsoft_login()" << std::endl;
}
