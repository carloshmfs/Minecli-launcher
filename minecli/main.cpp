#include "ArgsParser.h"
#include "Application.h"

#include <string>

static bool attempt_login = false;

int main(int argc, char** argv)
{
	ArgsParser argsParser(argc, argv);
    argsParser.add_option(attempt_login , "Attempt authentication", "--login", "-l");
	argsParser.parse();

    Application app;
    app.m_perform_auth = attempt_login;

    return app.exec();
}
