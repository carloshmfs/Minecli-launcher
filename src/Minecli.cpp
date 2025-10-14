#include "Minecli.h"
#include "MinecraftAuth.h"

#include <cpr/cpr.h>
#include <cpr/payload.h>

#include <iostream>

namespace Minecli {

bool Minecli::is_authenticated() const
{
    return false;
}

void Minecli::authenticate()
{
    // auto auth = MinecraftAuth::builder().client_id();
}

void Minecli::run()
{
    if (!is_authenticated()) {
        authenticate();
    }
}

}
