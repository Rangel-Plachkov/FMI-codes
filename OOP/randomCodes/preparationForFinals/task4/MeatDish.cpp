#include"MeatDish.h"

void MeatDish::setMeatType(const char* newMeat){
    
    if(newMeat == nullptr){
        delete[] newMeat;
        m_MeatType = new char[1];
        m_MeatType[0] = '\0';
        return;
    }
    if( ! ( strcmp(newMeat , "pork") && strcmp(newMeat , "beef") &&  strcmp(newMeat , "duck") && strcmp(newMeat , "chicken") ) ){
        
        delete []m_MeatType;
        m_MeatType = new char [strlen(newMeat) + 1];
        strcpy(m_MeatType, newMeat);
        return;
    }else{
        
        delete[] m_MeatType;
        m_MeatType = new char[1];
        m_MeatType[0] = '\0';
        return;
    }
}
const char* MeatDish::getMeatType()const{
    return m_MeatType;
}
void MeatDish::print()const{
    std::cout<<m_MeatType<<std::endl;
    this->Dish::print();

}
MeatDish::MeatDish(const char* newMeat){
    m_MeatType = nullptr;
    setMeatType(newMeat);
}
MeatDish::MeatDish(){
    setMeatType(nullptr);
}
void MeatDish::free(){
    delete []m_MeatType;
}
void MeatDish::copyFrom(const MeatDish& other){
    m_MeatType = new char[ strlen(other.m_MeatType) + 1];
    strcpy(m_MeatType , other.m_MeatType);
}
MeatDish::MeatDish(const MeatDish& other) : Dish(other){
    copyFrom(other);
}
MeatDish& MeatDish::operator=(const MeatDish& other){
    if(this != &other){
        Dish::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}
MeatDish::~MeatDish(){
    free();
}
