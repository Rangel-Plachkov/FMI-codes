#include"Dish.h"

Dish::Dish(){
    m_cookTime = 0;
    m_numberOfIngr = 0;
}
void Dish::addIngredient(const char* newIngredient){
    if(m_numberOfIngr > MAX_INGR_SIZE){
        return;
    }
    m_Ingrs[m_numberOfIngr] = new char [ strlen(newIngredient) +1 ];
    strcpy(m_Ingrs[m_numberOfIngr] , newIngredient);
    m_numberOfIngr++;
}

void Dish::print()const{
    std::cout<<"Cook time: "<<m_cookTime<<std::endl;
    for(size_t i=0; i<m_numberOfIngr; i++){
        std::cout<<i+1<<". "<<m_Ingrs[i]<<std::endl;
    }
}

void Dish::setTime(const size_t newTime){
    m_cookTime = newTime;
}
size_t Dish::getTime()const{
    return m_cookTime;
}
Dish::~Dish(){
    free();
}
void Dish::free(){
    for(size_t i=0; i<m_numberOfIngr; i++){
        delete []m_Ingrs[i];
    }
    
}
const char* Dish::getIngrsbyId(const size_t id)const{
    return m_Ingrs[id];
}
void Dish::copyFrom(const Dish& other){
    m_cookTime = other.m_cookTime;
    m_numberOfIngr = m_numberOfIngr;
    for(size_t i=0; i<m_numberOfIngr; i++){
        m_Ingrs[i] = new char[ strlen(other.m_Ingrs[i] ) +1 ];
        strcpy(m_Ingrs[i] , other.m_Ingrs[i]);
    }
}
Dish::Dish(const Dish& other){
    copyFrom(other);
}
Dish& Dish::operator=(const Dish& other){
    if( this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
