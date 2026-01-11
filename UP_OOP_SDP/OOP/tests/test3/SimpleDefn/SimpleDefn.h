#pragma once

#include<cstring>
#include<iostream>
#include<exception>

class SimpleDefn{
    public:
        SimpleDefn();
        SimpleDefn(const char* newName , const char* newValue);
        SimpleDefn(const SimpleDefn& other);
        virtual ~SimpleDefn();

        virtual void setName(const char* newName);
        virtual void setValue(const char* newValue);
        
        const char* getName()const;
        const char* getValue()const;

        SimpleDefn& operator=(const SimpleDefn& other);
        SimpleDefn& operator=(SimpleDefn&& other);
         
    private:
        char* m_name = nullptr;
        char* m_value = nullptr; 

        void setEmptyName();
        void setEmptyValue();
        void free();
        void copyFrom(const SimpleDefn& other);

       bool validNameCheck(const char* string)const;
};