#include "Application.h"
#include "MicrosoftAuth.h"

#include <cpr/cpr.h>
#include <cpr/payload.h>

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int Application::exec()
{
    try {
        if (m_perform_auth) {
            attempt_auth();
            return EXIT_SUCCESS;
        }

    } catch (const std::runtime_error& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Application::attempt_auth() const
{ 
    MicrosoftAuth auth;
    auth.authenticate();
}
