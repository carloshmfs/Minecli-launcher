#pragma once

#include <string>

class Auth
{

public:
    void microsoft_login();

private:
    std::string get(std::string url);

    std::string microsoft_auth_endpoint = "https://login.live.com/oauth20_authorize.srf?client_id=000000004C12AE6F&redirect_uri=https://login.live.com/oauth20_desktop.srf&scope=service::user.auth.xboxlive.com::MBI_SSL&display=touch&response_type=token&locale=en";

};
