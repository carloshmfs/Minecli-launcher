#include <string>
class MicrosoftAuth
{
public:
    void authenticate();

private:
    const std::string m_url = "https://login.microsoftonline.com/common/oauth2/v2.0";
    const std::string m_client_id = "71198273-9a13-4844-b7bc-6841137509f0";
};

// https://login.microsoftonline.com/common/oauth2/v2.0/authorize?client_id=71198273-9a13-4844-b7bc-6841137509f0&response_type=code&redirect_uri=http%3A%2F%2Flocalhost%3A7272%2Fcode&response_mode=query&scope=XboxLive.signin
