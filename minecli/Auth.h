#pragma once

#include <string>

class Auth
{
public:
    Auth(std::string user_email, std::string user_password)
        : m_user_email(user_email)
        , m_user_password(user_password)
    {}

    void attempt_auth();

private:
    void get_sFTTag_value();
    void get_url_post_value();

    std::string m_user_email;
    std::string m_user_password;

    std::string m_microsoft_login_endpoint = "https://login.live.com/oauth20_authorize.srf?client_id=000000004C12AE6F&redirect_uri=https://login.live.com/oauth20_desktop.srf&scope=service::user.auth.xboxlive.com::MBI_SSL&display=touch&response_type=token&locale=en";

    std::string m_sFTTag;
    std::string m_urlPost;
};
