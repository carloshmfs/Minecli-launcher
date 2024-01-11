#include "Application.h"
#include "Auth.h"

#include <cstdlib>
#include <iostream>
#include <exception>

int Application::exec()
{
    try {
        if (m_perform_auth) {
            Auth auth("", "");
            auth.attempt_auth();
            return EXIT_SUCCESS;
        }

    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
