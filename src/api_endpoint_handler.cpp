#include "src/image_validator.h"
// ... other includes that are part of the existing file ...

// Assuming the existence of a function that handles image uploads
void handleImageUpload(const HttpRequest& request, HttpResponse& response) {
    // Extract the uploaded file name from the request
    std::string uploadedFileName = request.getUploadedFileName();

    // Validate the image format
    if (!isValidImageFormat(uploadedFileName)) {
        // Respond with a 422 Unprocessable Entity error
        response.setStatus(422);
        response.setBody("Unprocessable Entity: The file format is not supported.");
        return;
    }

    // Proceed with the rest of the image processing logic
    // ...
}
