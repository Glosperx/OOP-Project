#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>


class gameError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class resourceLoadError : public gameError
{
public:
	using gameError::gameError;

	resourceLoadError(const std::string& resource)
		: gameError("Failed to load resource: " + resource)
	{
	}
};

class fileNotFoundError : public gameError
{
public:
	using gameError::gameError;

	fileNotFoundError(const std::string& filePath)
		: gameError("File not found: " + filePath)
	{
	}
};

class invalidTextureError : public gameError
{
public:
	using gameError::gameError;

	invalidTextureError(const std::string& texturePath)
		: gameError("Invalid texture: " + texturePath)
	{
	}
};

class fontLoadError : public gameError
{
public:
	using gameError::gameError;

	fontLoadError(const std::string& fontPath)
		: gameError("Failed to load font: " + fontPath)
	{
	}
};

class menuBackroundLoadError : public gameError
{
public:
	menuBackroundLoadError(const std::string& backgroundPath)
		: gameError("Failed to load background: " + backgroundPath)
	{
	}
};

class musicLoadError : public gameError
{
public:
	musicLoadError(const std::string& musicPath)
		: gameError("Failed to load music: " + musicPath)
	{
	}
};

class soundtrackLoadError : public gameError
{
public:
	soundtrackLoadError(const std::string& soundtrackPath)
		: gameError("Failed to load soundtrack: " + soundtrackPath)
	{
	}
};

class backroundLoadError : public gameError
{
public:
	backroundLoadError(const std::string& backroundPath)
		: gameError("Failed to load backround: " + backroundPath)
	{
	}
};

class buttonFontLoadError : public gameError
{
public:
	buttonFontLoadError(const std::string& fontPath)
		: gameError("Failed to load button font: " + fontPath)
	{
	}
};

#endif // EXCEPTIONS_H
