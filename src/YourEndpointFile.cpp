#include "ImageValidator.h"
// ... (other includes and namespace declarations if necessary)

// ... (other functions and class members)

void processFile(const std::string& filePath) {
    // ... (existing logic to retrieve the MIME type of the uploaded file)
    std::string mimeType = "retrieved_mime_type"; // Placeholder for actual MIME type retrieval logic

    if (!ImageValidator::isValidImageMIMEType(mimeType)) {
        returnErrorResponse(422, "The provided file is not a valid image.");
        return;
    }

    // ... (existing logic to process the file if it is a valid image)
}

void returnErrorResponse(int statusCode, const std::string& errorMessage) {
    // ... (logic to create and return an error response with the given status code and error message)
    // This function should set the response status code and include the error message in the response body.
}
