#pragma once

#include"../SimpleDefn/SimpleDefn.h"
#include"../CalcDefn/CalcDefn.h"
#include"../PramDefn/PramDefn.h"

class ComplexDefn :virtual public CalcDefn ,virtual public PramDefn {
    public:
    
        ComplexDefn();
        ComplexDefn(const char* newName , const char* newValue);
        ComplexDefn(const ComplexDefn& other);
      
        void setValue(const char* newValue) final;
        
    private:
        bool validValueCheck(const char* newValue)const;
};