#include "crow_all.h"
#include <fstream>

int main()
{
    crow::SimpleApp app;

    // Root route
    CROW_ROUTE(app, "/")([](){
        std::ifstream file("html/index.html");
        std::string content((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());
        return content;
    });

    app.port(27000).multithreaded().run();
}