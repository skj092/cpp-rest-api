cmake_minimum_required(VERSION 3.6)
project("MyPistacheProject")

# Find Pistache
find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

# Find CURL
find_package(CURL REQUIRED)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include nlohmann/json using FetchContent
include(FetchContent)
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5) # Use the desired version tag
FetchContent_MakeAvailable(json)

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    PkgConfig::Pistache
    CURL::libcurl
    nlohmann_json::nlohmann_json
    ${OpenCV_LIBS}) # Linking OpenCV libraries
