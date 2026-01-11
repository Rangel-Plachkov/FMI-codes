#include"Encoder.h"

int Encoder::getIneger()const{
    return m_Integer;
}
char Encoder::getSymbol()const{
    return m_Symbol;
}
void Encoder::setInteger(const int newInteger){
    m_Integer = newInteger;
}
void Encoder::setSymbol(const char newSymbol){
    m_Symbol = newSymbol;
}
Encoder::Encoder(){
    m_Symbol = '\0';
}
Encoder::Encoder(const char newSymbol , const int newInteger){
    setInteger(newInteger);
    setSymbol(newSymbol);
}
Encoder& Encoder::operator=(const Encoder& other){
    m_Integer = other.m_Integer;
    m_Symbol = other.m_Symbol;
}
