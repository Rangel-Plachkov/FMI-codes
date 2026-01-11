#include"SimpleDefn.h"

SimpleDefn::SimpleDefn(){
    m_name = nullptr;
    m_value = nullptr;
    setEmptyName();
    setEmptyValue();
}
SimpleDefn::SimpleDefn(const char* newName , const char* newValue){
    setName(newName);
    setValue(newValue);
}
void SimpleDefn::setName(const char* newName){
    if(newName == nullptr){
        setEmptyName();
        std::cout<<"Empty name\n";
        return;
    }
    delete []m_name;
    m_name = new char[strlen(newName) + 1];
    strcpy(m_name , newName);

    if(validNameCheck(m_name) == false){
        std::cout<<"Invalid name\n";
    }
}
void SimpleDefn::setEmptyName(){
    delete []m_name;
    m_name = new char [1];
    m_name[0] = '\0';
}
void SimpleDefn::setValue(const char* newValue){
    if(newValue == nullptr){
        setEmptyValue();
        return;
    }
    delete []m_value;
    m_value = new char[strlen(newValue) + 1];
    strcpy(m_value , newValue);
}
void SimpleDefn::setEmptyValue(){
    delete []m_value;
    m_value = new char [1];
    m_value[0] = '\0';
}
void SimpleDefn::free(){
    delete []m_name;
    delete []m_value;
}
const char* SimpleDefn::getName()const{
    return m_name;
}
const char* SimpleDefn::getValue()const{
    return m_value;
}
SimpleDefn::~SimpleDefn(){
    free();
}
void SimpleDefn::copyFrom(const SimpleDefn& other){
    m_name = new char [ strlen(other.m_name)+1 ];
    strcpy(m_name , other.m_value);

    m_value = new char [ strlen(other.m_value)+1 ];
    strcpy(m_value , other.m_value);
}
SimpleDefn& SimpleDefn::operator=(const SimpleDefn& other){
    if( this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
SimpleDefn::SimpleDefn(const SimpleDefn& other){
    copyFrom(other);
}
bool SimpleDefn::validNameCheck(const char* string)const{
    const size_t len = strlen(string);
    for(size_t i=0; i < len ; i++){
        if( !(string[i] >= 'a' && string[i] <= 'z') ){
            if(string[i] == '_' ){
                if(i == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
SimpleDefn& SimpleDefn::operator=(SimpleDefn&& other){
    if(this != &other){
        free();
        /*
        m_name = new char [ strlen(other.m_name)+1 ];
        strcpy(m_name , other.m_value);

        m_value = new char [ strlen(other.m_value)+1 ];
        strcpy(m_value , other.m_value);
        other.n_name = nullptr;
        other.m_value = nullprt
        */
        copyFrom(other);
    }
    return *this;
}