#pragma once

#include<iostream>
#include<cstring>
#include"../Encoder/Encoder.h"
#include"../Encoder/Encoder.cpp"
class Dossier{
    public:
        Dossier();
        Dossier(const char* newText, const Encoder* newDecodingTable, const size_t lenNewTable);
        Dossier(const Dossier& other);

        void addRow(const Encoder& newRow);

        void setText(const char* newText);
        const int* getText()const;

        void printText()const;

        Dossier& operator=(const Dossier& other);
        bool operator&&(const Dossier& other)const; 
        Dossier& operator+(const Dossier& other)const;

    private:
        static const size_t DEFAULT_SIZE_OF_TABLE = 16;
        size_t m_sizeOfTable = DEFAULT_SIZE_OF_TABLE;
        size_t m_numberOfRows = 0;
        size_t m_lenghtOfText = 0;;
        int* m_codedText = nullptr;
        Encoder* m_DecodingTable = nullptr;

        void resize();
        void free();
        void copyFrom(const Dossier& other);

};
