#include"atribute.h"

const char* Atribute::getName()const{
    return name.get();
}
const char* Atribute::getValue()const{
    return value.get();
}
void Atribute::setName(const char* newName){
    name = newName;
}
void Atribute::setValue(const char* newValue){
    value = newValue;
}
bool Atribute::withoutValue()const{
    return value.isEmpty();
}
Atribute::Atribute(const char* newName , const char* newValue){
    name = newName;
    value = newValue;
}
Atribute::Atribute(const char* newName){
    setName(newName);
}