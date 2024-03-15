#include"SeaDish.h"

void SeaDish::setSeaType(const char* newSea){
    if(newSea == nullptr){
        delete []m_SeaType;
        m_SeaType = new char[1];
        m_SeaType[0] = '\0';
    }else{
        delete []m_SeaType;
        m_SeaType = new char[strlen(newSea) + 1];
        strcpy(m_SeaType , newSea);
    }
    
}
const char* SeaDish::getSeaType()const{
    return m_SeaType;
}
void SeaDish::print()const{
    std::cout<<m_SeaType<<std::endl;
    this->Dish::print();

}
SeaDish::SeaDish(const char* newSea){
    m_SeaType = nullptr;
    setSeaType(newSea);
}
SeaDish::SeaDish(){
    setSeaType(nullptr);
}
SeaDish::SeaDish(const SeaDish& other) : Dish(other) {
    copyFrom(other);
}
SeaDish& SeaDish::operator=(const SeaDish& other){
    if(this != &other){
        Dish::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

void SeaDish::free(){
    delete []m_SeaType;
}
SeaDish::~SeaDish(){
    free();
}
void SeaDish::copyFrom(const SeaDish& other){
    m_SeaType = new char[strlen(other.m_SeaType) + 1];
    strcpy(m_SeaType , other.m_SeaType);
}
