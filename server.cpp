#include "crow_all.h"
#include <fstream>

9
int main()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")
    ([](const request &req, response &res) {
        ifstream in("index.html",
            ifstream::in);
        if (in) {
            ostringstream contents;
            contents << in.rdbuf();
            in.close();
            res.write(contents.str());
        }
        else {
            res.write("Not Found");
        }
        res.end();
    });

    CROW_ROUTE (app, "/product/<int>")
    ([](const request &req, response &res, int

    app.port(27000).multithreaded().run();

    return 1;
}