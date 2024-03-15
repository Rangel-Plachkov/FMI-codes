#include"PramDefn.h"

bool PramDefn::validValueCheck(const char* string)const{
    const char* positionOfDS = strstr(string, "#");
    
    if(positionOfDS == nullptr){
        return false;
    }
    const size_t remainigSyms = strlen(positionOfDS);
    
    for(size_t i = 1 ; i<remainigSyms; i++){
        if(positionOfDS[i] == ' '){
            return true;
        }
        if( (positionOfDS[i] < '1' || positionOfDS[i] > '9') && i == remainigSyms-1 ){
            return false;
        }
    }
    return true;
}
PramDefn::PramDefn(const char* newName , const char* newValue) : SimpleDefn(newName , newValue){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
}
PramDefn::PramDefn(const PramDefn& other) : SimpleDefn(other){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
}
PramDefn::PramDefn() : SimpleDefn(){
    if(validValueCheck(getValue()) == false){
        std::cout<<"Invalid value\n";
    }
}
void PramDefn::setValue(const char* newValue){
    SimpleDefn::setValue(newValue);
    if(validValueCheck(newValue) == false){
        std::cout<<"Invalid value\n";
    }
}
size_t PramDefn::numberOfParameters()const{
    const size_t valueLen = strlen( SimpleDefn::getValue() ) + 1 ;
    bool findDS = false;
    size_t pramCounter = 0;
    for(size_t i = 0; i<valueLen; i++){
        if(SimpleDefn::getValue()[i] == '#'){
            findDS = true;
        }
        else if( (SimpleDefn::getValue()[i] == ' ') && ( findDS == true )){
            pramCounter++;
        }
        else if( SimpleDefn::getValue()[i] < '1' || SimpleDefn::getValue()[i] > '9' ){
            findDS = false;
        }
    }
    if(findDS == true){
        pramCounter++;
    }
    return pramCounter;
}
void PramDefn::printValue()const{
    size_t parametersCount = numberOfParameters();
    //char** prValue = new char* [numberOfParameters + 1];

    for(size_t i=0; i<parametersCount; i++){
        //cin.getline(prValue , MAX_USER_INPUT);    
    }
}

