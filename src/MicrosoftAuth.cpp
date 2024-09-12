#include "MicrosoftAuth.h"

#include <cpr/cpr.h>

#include <iostream>

void MicrosoftAuth::authenticate()
{
    cpr::Response response = cpr::Get(
        cpr::Url { m_url + "/authorize" },
        cpr::Parameters {
            { "client_id", m_client_id },
            { "response_type", "code" },
            { "redirect_uri", "http://localhost:8000/code" },
            { "response_mode", "query" },
            { "scope", "XboxLive.signin" },
        }
    );

    auto params = cpr::Parameters {
        { "client_id", m_client_id },
        { "response_type", "code" },
        { "redirect_uri", "http://localhost:8000/code" },
        { "response_mode", "query" },
        { "scope", "XboxLive.signin" },
    };

    // std::cout << response.raw_header << std::endl;
    std::cout << params.GetContent() << std::endl;
}
