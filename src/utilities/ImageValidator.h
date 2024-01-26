#ifndef IMAGE_VALIDATOR_H
#define IMAGE_VALIDATOR_H

#include <string>
#include <set>

class ImageValidator {
public:
    static bool isValidImageMIMEType(const std::string& mimeType) {
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
};

#endif // IMAGE_VALIDATOR_H
