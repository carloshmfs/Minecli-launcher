#include "MicrosoftAuth.h"
#include "utils.h"

#include <cpr/cpr.h>
#include <httplib.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <stdexcept>
#include <string>

void MicrosoftAuth::authenticate()
{
    std::cout << "Open the link on your browser to authenticate." << std::endl << std::endl;
    std::cout << "\x1B[93m" << get_authorization_uri() << "\033[0m" << std::endl;

    handle_authorization_code();

    std::cout << "AUTHORIZATION CODE: " << m_authorization_code << std::endl; 

    getAccessToken();
    // xboxLiveAuth();
}

std::string MicrosoftAuth::get_authorization_uri() const
{
    return m_microsoft_auth_uri + "/authorize?client_id=" + m_client_id 
                 + "&response_type=" + m_response_type 
                 + "&redirect_uri=" + encode_uri_component(m_redirect_uri)
                 + "&response_mode=" + m_response_mode
                 + "&scope=" + m_scope;
}

void MicrosoftAuth::handle_authorization_code()
{
    httplib::Server svr;

    bool has_error = false;
    std::string error_msg;
    std::string authorization_code;

    svr.Get("/code", [&](const httplib::Request& request, httplib::Response& response) -> void {
        std::cout << "Request from " << request.remote_addr << " " << request.remote_port << std::endl;

        if (! request.params.find("error")->first.empty()) {
            has_error = true;
            error_msg = request.params.find("error_description")->second;
            response.set_content("An error ocurred. You can close this tab.", "text/plain");

            svr.stop();
        }

        if (! request.params.find("code")->first.empty()) {
            authorization_code = request.params.find("code")->second;
            response.set_content("You can close this tab.", "text/plain");
            svr.stop();
        }
    });

    svr.listen("localhost", 7272);

    if (has_error) {
        throw std::runtime_error("Something went wrong. " + error_msg);
    }

    m_authorization_code = authorization_code;
}

void MicrosoftAuth::getAccessToken()
{
    cpr::Response response = cpr::Post(
        cpr::Url { m_xbox_live_uri },
        cpr::Header { 
            {"Content-Type", "application/x-www-form-urlencoded"},
        },
        cpr::Payload { 
            {"client_id", m_client_id},
            {"client_secret", ""},
            {"code", m_authorization_code},
            {"grant_type", "authorization_code"},
            {"redirect_uri", "http://localhost:7272/code"},
        }
    );

    std::cout << response.status_code << std::endl;
    std::cout << response.raw_header << std::endl;
    std::cout << response.url << std::endl;
}

void MicrosoftAuth::xboxLiveAuth()
{
    nlohmann::json reqBody = {
        {"Properties", {
            { "AuthMethod", "RPS" },
            { "SiteName", "user.auth.xboxlive.com" },
            { "RpsTicket", "d=" + m_authorization_code }
        }},
        {"RelyingParty", "http://auth.xboxlive.com"},
        {"TokenType", "JWT"}
    };

    cpr::Response response = cpr::Post(
        cpr::Url { m_xbox_live_uri },
        cpr::Header { 
            {"Content-Type", "application/json"},
            {"Accept", "application/json"}
        },
        cpr::Body { reqBody.dump() }
    );

    std::cout << response.status_code << std::endl;
    std::cout << response.raw_header << std::endl;
}
