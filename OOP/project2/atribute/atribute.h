#pragma once
#include"../myString/myString.h"
class Atribute{
    public:
        Atribute() = default;
        Atribute(const char* newName , const char* newValue);
        Atribute(const char* newName);

        void setName(const char* newName);
        const char* getName()const;
        void setValue(const char* newValue);
        const char* getValue()const;
        bool withoutValue()const;
    private:
        myString name;
        myString value;
};