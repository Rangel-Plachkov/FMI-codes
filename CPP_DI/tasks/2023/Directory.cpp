#include "Directory.h"

#include <stdexcept>
#include <cctype>
#include <algorithm>

Directory::Directory() 
    : _name(""), _parent(nullptr) {}

Directory::Directory(const std::string& newName)
    : _name(newName), _parent(nullptr) {
    if (!isValidDirName(newName)) {
        throw std::invalid_argument("Invalid directory name");
    }
}
Directory::Directory(const std::string& newName, Directory* newParent)
    : _name(newName), _parent(newParent) {
    if (!isValidDirName(newName)) {
        throw std::invalid_argument("Invalid directory name");
    }
}

bool Directory::isValidDirName(const std::string& name)const{
    return std::all_of(name.begin(), name.end(), [](char ch) {
        return std::isalpha(ch) || std::isdigit(ch) || ch == '.';
    });
}
bool Directory::containsSubDirectory(const std::string& name)const{
    for (const Directory* dir : _subDirectories) {
        if (dir->_name == name) {
            return true;
        }
    }
    return false;
}