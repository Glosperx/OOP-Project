#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>


class gameError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class resourceLoadError : public gameError {
public:
    using gameError::gameError;
    resourceLoadError(const std::string& resource)
       : gameError("Failed to load resource: " + resource) {}
};

class fileNotFoundError : public gameError {
public:
    using gameError::gameError;
    fileNotFoundError(const std::string& filePath)
        : gameError("File not found: " + filePath) {}
};

class invalidTextureError : public gameError {
public:
    using gameError::gameError;
    invalidTextureError(const std::string& texturePath)
        : gameError("Invalid texture: " + texturePath) {}
};

#endif // EXCEPTIONS_H
