#include"ComplexDefn.h"

bool ComplexDefn::validValueCheck(const char* newValue)const{
    return PramDefn::validValueCheck(newValue) && CalcDefn::validNameCheck(newValue);
}
void ComplexDefn::setValue(const char* newValue){
    SimpleDefn::setValue(newValue);
    if(ComplexDefn::validValueCheck(newValue) == false){
        std::cout<<"Invalid value\n";
    }

}
ComplexDefn::ComplexDefn(const char* newName , const char* newValue): SimpleDefn(newName, newValue){
    if(ComplexDefn::validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(CalcDefn::validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}

ComplexDefn::ComplexDefn(): SimpleDefn(){
    if(ComplexDefn::validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(CalcDefn::validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}

ComplexDefn::ComplexDefn(const ComplexDefn& other): SimpleDefn(other){
    if(ComplexDefn::validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(CalcDefn::validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}


