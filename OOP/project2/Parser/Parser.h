#pragma once

#include<cstring>
#include<fstream>
#include<iostream>

#include"../XMLelement/XMLelement.h"
class Parser{
    public:
        Parser();
        Parser(const Parser& other);
        ~Parser();
        Parser& operator=(const Parser& other);

        void addElement(const XMLelement& newElement);
        XMLelement* getElementByIndex(const size_t index)const;
        size_t findIndexById(const myString& searchedId)const;
        const myString findParent(const myString& childId)const;
        const myString* getChildren(const myString& parentId)const;

        XMLelement* xPath(const myString& elementId ,const myString& command);

        void incertFile(const char* file);
        void exportToFile(const char* file)const;
        void print()const;
        void cleanUp();
        
    private:
        static const myString BASE_ID;
        static const size_t DEFAULT_ELEMENTS_ARR_SIZE = 16;
        XMLelement* m_XMLelements;
        size_t m_numberOfElements;
        size_t m_sizeOfElementsArr;
        
        
        void free();
        void setDefaultValues();
        void copyFrom(const Parser& other);
        void resizeXMLelementArr();
        const myString fileInput(std::ifstream& iFile)const; 
        void writeElement(std::ofstream& oFile ,const myString& elementId, const size_t subCount)const; 
        void tabInNtimes(std::ofstream& oFile , const size_t N)const;
};