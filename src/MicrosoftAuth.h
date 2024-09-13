#pragma once

#include <string>

class MicrosoftAuth
{
public:
    void authenticate();

private:
    std::string m_authorization_code;

    const std::string m_uri = "https://login.microsoftonline.com/consumers/oauth2/v2.0";
    const std::string m_client_id = "71198273-9a13-4844-b7bc-6841137509f0";
    const std::string m_response_type = "code";
    const std::string m_redirect_uri = "http://localhost:7272/code";
    const std::string m_response_mode = "query";
    const std::string m_scope = "XboxLive.signin";

    std::string get_authorization_uri() const;
    void handle_authorization_code();
};
