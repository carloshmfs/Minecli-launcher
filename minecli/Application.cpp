#include "Application.h"

#include <cpr/cpr.h>

#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <regex>

int Application::exec()
{
    try {
        if (m_perform_auth) {
            attempt_auth();
            return EXIT_SUCCESS;
        }

    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Application::retrieve_microsoft_tag()
{
    cpr::Response r = cpr::Get( cpr::Url { m_tag_endpoint } );

    if (r.status_code != 200)
        throw std::runtime_error("Unable to retrieve the sFTTag value. Failed the api request.");

    std::smatch match;
    if ( ! std::regex_search( r.text, match, std::regex("value=\"(.+?)\"") ) )
        throw std::runtime_error("Unable to retrieve the sFTTag value. Value not found.");

    if (match.size() < 1)
        throw std::runtime_error("Unable to retrieve the sFTTag value. Empty Value.");
    
    m_tag = match[1];
}

void Application::attempt_auth()
{ 
    retrieve_microsoft_tag();
}

