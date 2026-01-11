#pragma once

#include <set>
#include <string>
#include <cstddef>

class Directory{
public:
    Directory();
    Directory(const std::string& newName);
    Directory(const std::string& newName, Directory* newParent);

    bool containsSubDirectory(const std::string& name)const;
    

private:
    static const size_t MAX_NAME_SIZE = 12;
    static const char SEPARATION_CHAR = '/';

    Directory* _parent = nullptr;
    std::string _name;
    std::set<Directory*> _subDirectories;

    bool isValidDirName(const std::string& dirName)const;
};