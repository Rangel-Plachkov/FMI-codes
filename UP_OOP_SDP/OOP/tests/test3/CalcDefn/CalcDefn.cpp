#include"CalcDefn.h"


CalcDefn::CalcDefn(const char* newName , const char* newValue) : SimpleDefn(newName , newValue){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}
CalcDefn::CalcDefn(const CalcDefn& other) : SimpleDefn(other){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}
CalcDefn::CalcDefn() : SimpleDefn(){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
    if(validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}
bool CalcDefn::validValueCheck(const char* string)const{
    return SimpleDefn::getValue()[0] == '\'' && SimpleDefn::getValue()[strlen(SimpleDefn::getValue()) -1] == '\'';
}
void CalcDefn::setValue(const char* newValue){
    SimpleDefn::setValue(newValue);
    if(validValueCheck(newValue) == false){
        std::cout<<"Invalid value\n";
    }
}
bool CalcDefn::validNameCheck(const char* string)const{
    return  strlen(strstr(SimpleDefn::getName() , "_calc")) == strlen("_calc") ;   
}
void CalcDefn::setName(const char* newName){
    setName(newName);
    if(validNameCheck(getName()) == false){
        std::cout<<"Invalid name\n";
    }
}
void CalcDefn::printValue()const{
    const size_t valueLen = strlen( getValue() );
    size_t numberA = 0 , numberB = 0;
    bool inOperation = false;
    char opr = 0;
    char* tempText = new char [valueLen];
    for(size_t i=0; i<valueLen; i++){
        if(getValue()[i] != '{' && inOperation == false){
            std::cout<<getValue()[i];
        }
        else if(getValue()[i] == '{'){
            inOperation = true;
        }
        else if(getValue()[i] == '+' || getValue()[i] == '-' || getValue()[i] == '*'){
            opr = getValue()[i];
        }
        else if( getValue()[i] >= '0' && getValue()[i] <= '9' ){
            if(!opr){
                
            }
        }


    }
    delete []tempText;
}


