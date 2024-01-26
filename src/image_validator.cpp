#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_set>

bool isValidImageFormat(const std::string& filename) {
    const std::unordered_set<std::string> supportedFormats = {"png", "jpeg", "jpg", "gif", "bmp", "tiff"};
    std::string::size_type dotPos = filename.rfind('.');
    if (dotPos == std::string::npos) {
        return false;
    }
    std::string extension = filename.substr(dotPos + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    if (supportedFormats.find(extension) == supportedFormats.end()) {
        return false;
    }
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        return false;
    }
    return true;
}
