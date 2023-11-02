#include "Auth.h"

#include <yhirose/httplib.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>

#define CPPHTTPLIB_OPENSSL_SUPPORT

void Auth::microsoft_login()
{
    std::string result = get(microsoft_auth_endpoint);
    std::cout << result << std::endl;
}

std::string Auth::get(std::string url)
{
    try {

        httplib::Client http { url };

        const auto response = http.Get("/asdas");
        std::cout << response->body << std::endl;
        exit(1);

    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION Auth::get(): " << e.what() << std::endl;
        exit(1);
    }
}
