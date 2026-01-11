#pragma once

#include"../SimpleDefn/SimpleDefn.h"

class CalcDefn :virtual public SimpleDefn{
    public:
        CalcDefn();
        CalcDefn(const char* newName , const char* newValue);
        CalcDefn(const CalcDefn& other);
      
        void setValue(const char* newValue)override;
        void setName(const char* newName)override;
        void printValue()const;
    protected:
        bool validValueCheck(const char* string)const;
        bool validNameCheck(const char* string)const;
};