#pragma once

#include<cstring>
#include<iostream>

#include"../Parser/Parser.h"

class Interface{
    public:
        Interface();
        Interface(bool shouldStart);
        void menu();

    private:
        static const size_t MAX_INPUT_SIZE = 256;
        Parser m_parser;
        myString m_file;
        bool m_unsavedChanges;

        
        void open(const myString& fileName);
        void close();
        void save()const;
        void saveAs(const myString& newFile);
        void help()const;
        bool exit();
        void print()const;
        void select(const myString& elementId , const myString& nameOfAtribute)const;
        void set(const myString& elementId , const myString& nameOfAtribute, const myString& newValue);
        void children(const myString& elementId)const;
        void child(const myString& elementId , const myString& key)const;
        void text(const myString& elementId)const;
        void deleteAtr(const myString& elementId, const myString& nameOfAtribute);
        void newChild(const myString& elementId);
        void xpath(const myString& elementId , const myString& xpath);
};