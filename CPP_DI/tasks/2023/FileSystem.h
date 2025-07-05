#pragma once

#include <string>
#include "Directory.h"

class FileSystem {
public:
    FileSystem();
    FileSystem(const std::string& rootName);
    ~FileSystem();

    Directory* getRoot() const;

    bool createDirectory(const std::string& path);
    bool directoryExists(const std::string& path) const;

private:
    Directory* _root = nullptr;

    Directory* findDirectory(const std::string& path) const;
    bool isValidPath(const std::string& path) const;

    void freeDirectoryTree(Directory* dir);
};