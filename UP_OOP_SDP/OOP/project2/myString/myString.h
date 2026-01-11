#pragma once
#include<cstring>
#include<cmath>
class myString{
    public:

        myString();
        myString(const char* newString);
        myString(const myString& other);
        myString(myString&& other);
        myString(unsigned long long number);
        myString(const char newSym);

        ~myString();

        size_t getSize()const;
        const char* get()const;
        long long getNumber()const;
        bool isEmpty()const;

        void removeFirstNsymbols(const size_t N);
        void removeLastNsymbols(const size_t N);
        size_t strstr(const myString& searchStr)const; 

        myString& operator=(const myString& other);
        myString& operator=(myString&& other);
        myString& operator+=(const myString& other);

    private:
        char* str;
        size_t size;

        void copyFrom(const myString& other);
        void free();
        void concatFrom(const myString& other);
        void makeEmpty();
       
       
};
bool operator==(const myString& left , const myString& right);
bool operator!=(const myString& left , const myString& right);