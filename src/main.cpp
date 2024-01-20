#include <pistache/endpoint.h>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace Pistache;


// download image from url and return the path to the image
std::string downloadImage(std::string url) {
    std::string image_name = "image.jpg";
    std::string command = "wget -O " + image_name + " " + url;
    system(command.c_str());
    // return the path to the image
    return image_name;
}



struct HelloHandler : public Http::Handler {
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override {
        if (request.method() == Http::Method::Post) {
            // extract the json from the request
            std::string json = request.body();
            nlohmann::json j = nlohmann::json::parse(json);
            std::string url = j["url"];
            // download the image
            std::string path = downloadImage(url);
            // Handle the POST request here
            response.send(Http::Code::Ok, "Received a POST request: " + path);
        } else {
            response.send(Http::Code::Ok, "Hello, World!, this is a test");
        }
    }
};

int main() {
    Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
    return 0;
}
