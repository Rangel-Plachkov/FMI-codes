#pragma once

#include<cstring>

class Set {
    private:
        
        int* lenghtOfWord = new int [numberOfWords + 1];
        char* words = new char [numberOfWords + 1];

        void addWord(char* word);
        
    public:
    unsigned int numberOfWords = 0;
        Set();
        
};