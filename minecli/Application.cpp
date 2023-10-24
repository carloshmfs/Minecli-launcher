#include "Application.h"
#include "Auth.h"

void Application::exec()
{

}

void Application::auth()
{
    Auth auth;
    auth.microsoft_login();
}
