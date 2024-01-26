#include "ImageValidator.h"

bool ImageValidator::isValidImageMIMEType(const std::string& mimeType) {
    static const std::set<std::string> allowedMIMETypes = {
        "image/jpeg",
        "image/png",
        "image/gif",
        "image/webp",
        "image/tiff",
        "image/bmp"
    };

    return allowedMIMETypes.find(mimeType) != allowedMIMETypes.end();
}
