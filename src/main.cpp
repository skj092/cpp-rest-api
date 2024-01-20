#include <pistache/endpoint.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace Pistache;
using cv::Mat;
using cv::imread;


std::string getImageShape(std::string image_path) {
    Mat img = imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        return "Error: Image not loaded";
    }
    int width = img.size().width;
    int height = img.size().height;

    std::string shape = std::to_string(width) + "x" + std::to_string(height);
    return shape;
}


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
            // get the shape of the image
            std::string shape = getImageShape(path);
            // send the response in json with name and shape of image
            nlohmann::json res;
            res["name"] = path;
            res["shape"] = shape;
            // Handle the POST request here
            //response.send(Http::Code::Ok, "Received a POST request: " + res.dump());
            response.send(Pistache::Http::Code::Ok, res.dump(), MIME(Application, Json));
        } else {
            response.send(Http::Code::Ok, "Hello, World!, this is a test");
        }
    }
};

int main() {
    Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
    return 0;
}
