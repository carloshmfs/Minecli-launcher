#pragma once

#include <string>

class Application 
{

public:
    bool m_perform_auth = { false };

    int exec();
    void attempt_auth(std::string, std::string);

private:
    std::string m_tag_endpoint = "https://login.live.com/oauth20_authorize.srf?client_id=000000004C12AE6F&redirect_uri=https://login.live.com/oauth20_desktop.srf&scope=service::user.auth.xboxlive.com::MBI_SSL&display=touch&response_type=token&locale=en";
    std::string m_tag;
    std::string m_post_url;

    void get_values();
    void retrieve_microsoft_tag(const std::string&);
    void retrieve_microsoft_post_url(const std::string&);
    void signin_microsoft(const std::string&, const std::string&);

};
