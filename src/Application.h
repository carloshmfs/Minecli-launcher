#pragma once

#include <string>

class Application  
{
public:
    bool m_perform_auth = { false };

    int exec();
    void attempt_auth() const;
};
