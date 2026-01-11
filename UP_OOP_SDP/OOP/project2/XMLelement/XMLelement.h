 #pragma once
 
 #include<cstring>
 #include"../atribute/atribute.h"

 class XMLelement{
    public:
        static size_t uniqueIdNum;

        XMLelement();
        XMLelement(const char* newId);
        XMLelement(const XMLelement& other);
        ~XMLelement();

        void setId(const char* newId);
        const char* getId()const;

        void addAtribute(const Atribute& newAtribute);
        void deleteAtribute(const myString& name);
        const Atribute* getAtributes()const;
        const Atribute* searchAtribute(const char* searchName)const;
        const Atribute* getAtributeByIndex(const size_t number)const;
        Atribute* getAtributeByName(const myString& name)const;
        size_t getNumberOfAtributes()const;

        void setText(const char* newText);
        const char* getText()const;

        void setParent(const myString& newParentAdr);
        const myString& getParent()const;

        void addChild(const myString& newChild);
        const myString* getChildren()const;
        const myString& getChildByIndex(const size_t index)const;
        size_t getNumberOfChildren()const;
        
        XMLelement& operator=(const XMLelement& other);

    private:
        static const char UNIQUE_ID_SYMBOL = '_';
        static const size_t DEFAULT_ATRIBUTE_ARR_SIZE = 16;
        static const size_t DEFAULT_CHILD_ARR_SIZE = 16;

        
        myString parent;
        myString id;
        myString text;
        myString* children = nullptr;
        Atribute* atributes;
        size_t numberOfAtributes = 0;
        size_t sizeOfAtributeArr = DEFAULT_ATRIBUTE_ARR_SIZE;   
        size_t numberOfChilds = 0;
        size_t sizeOfChildArr = DEFAULT_CHILD_ARR_SIZE;
       

        void resizeAtributeArr();
        void resizeChildArr();
        void free();
        void copyFrom(const XMLelement& other);

 };