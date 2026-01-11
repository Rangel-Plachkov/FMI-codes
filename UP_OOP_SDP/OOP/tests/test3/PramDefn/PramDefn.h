#pragma once

#include"../SimpleDefn/SimpleDefn.h"

class PramDefn :virtual public SimpleDefn{
    public:
        PramDefn();
        PramDefn(const char* newName , const char* newValue);
        PramDefn(const PramDefn& other);

        void setValue(const char* newValue)override;

        void printValue()const;
         
    protected:
        
        bool validValueCheck(const char* string)const;
    private:
        static const size_t MAX_USER_INPUT = 100;
        size_t numberOfParameters()const;
};