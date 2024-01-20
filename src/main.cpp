#include <pistache/endpoint.h>
#include <iostream>

using namespace Pistache;

struct HelloHandler : public Http::Handler {
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override {
        if (request.method() == Http::Method::Post) {
            // Handle the POST request here
            response.send(Http::Code::Ok, "Received a POST request: " + request.body());
        } else {
            response.send(Http::Code::Ok, "Hello, World!, this is a test");
        }
    }
};

int main() {
    Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
    return 0;
}
