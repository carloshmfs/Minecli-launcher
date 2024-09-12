#include "Application.h"

#include <cpr/cpr.h>
#include <cpr/payload.h>

#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <regex>

int Application::exec()
{
    try {
        if (m_perform_auth) {
            attempt_auth("", "");
            return EXIT_SUCCESS;
        }

    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Application::get_values()
{
    cpr::Response r = cpr::Get( cpr::Url { m_tag_endpoint } );

    if (r.status_code != 200)
        throw std::runtime_error("Unable to retrieve the sFTTag value. Failed the api request.");

    retrieve_microsoft_tag(r.text);
    retrieve_microsoft_post_url(r.text);
}

void Application::retrieve_microsoft_post_url(const std::string& api_response_body)
{
    std::smatch match;
    if ( ! std::regex_search( api_response_body, match, std::regex("urlPost:'(.+?)'") ) )
        throw std::runtime_error("Unable to retrieve the postUrl value. Value not found.");

    if (match.size() < 1)
        throw std::runtime_error("Unable to retrieve the postUrl value. Empty Value.");
    
#ifdef DEBUG
    std::cout << "POST URL: " << match[1] << std::endl;
#endif
    m_post_url = match[1];
}

void Application::retrieve_microsoft_tag(const std::string& api_response_body)
{
    std::smatch match;
    if ( ! std::regex_search( api_response_body, match, std::regex("value=\"(.+?)\"") ) )
        throw std::runtime_error("Unable to retrieve the sFTTag value. Value not found.");

    if (match.size() < 1)
        throw std::runtime_error("Unable to retrieve the sFTTag value. Empty Value.");
    
#ifdef DEBUG
    std::cout << "TAG: " << match[1] << std::endl;
#endif
    m_tag = match[1];
}

void Application::signin_microsoft(const std::string& email, const std::string& password)
{
    cpr::Response r = cpr::Post(
        cpr::Url { m_post_url },
        cpr::Payload { 
            {"login", email},
            {"loginfmt", email},
            {"passwd", password},
            {"PPFT", m_tag},
        }
    );

    std::cout << m_post_url << std::endl;
    std::cout << r.text << std::endl;
}

void Application::attempt_auth(const std::string email, const std::string password)
{ 
    get_values();
    signin_microsoft(email, password);
}

