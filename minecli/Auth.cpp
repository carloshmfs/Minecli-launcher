#include "Auth.h"

#include <elnormous/HTTPRequest.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>

void Auth::microsoft_login()
{
    std::string result = get(microsoft_auth_endpoint);
    std::cout << result << std::endl;
}

std::string Auth::get(std::string url)
{
    try {

        http::Request request { url };

        const auto response = request.send("GET");
        std::cout << std::string{ response.body.begin(), response.body.end() } << std::endl;
        exit(1);

    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION Auth::get(): " << e.what() << std::endl;
        exit(1);
    }
}
