#include"Dossier.h"

Dossier::Dossier(){
    m_DecodingTable = new Encoder[DEFAULT_SIZE_OF_TABLE];
}

Dossier::Dossier(const char* newText , const Encoder* newDecodingTable, const size_t lenNewTable){
    m_DecodingTable = new Encoder[m_sizeOfTable];

    for(size_t i=0; i<lenNewTable; i++){
        addRow(newDecodingTable[i]);
    }
    
    setText(newText);
}
void Dossier::addRow(const Encoder& newRow){
    
    while(m_numberOfRows + 1 > m_sizeOfTable){
        resize();
    }
    m_DecodingTable[m_numberOfRows] = newRow;
    m_numberOfRows++;
        
}
void Dossier::resize(){
    m_sizeOfTable = m_sizeOfTable*2;
    Encoder* temp = new Encoder[m_sizeOfTable];
    
    for(size_t i=0 ;i<m_numberOfRows; i++){
        temp[i] = m_DecodingTable[i];
    }

    delete []m_DecodingTable;
    m_DecodingTable = temp;
    temp = nullptr;
}

void Dossier::setText(const char* newText){
    if(newText == nullptr){
        m_codedText = nullptr;
        return;
    }
    m_lenghtOfText = strlen(newText);
    delete []m_codedText;
    
    m_codedText = new int[m_lenghtOfText + 1];

    for(size_t i=0; i<m_lenghtOfText; i++){
        for(size_t j=0; j<m_sizeOfTable; j++){
            if( newText[i] == m_DecodingTable[j].getSymbol() ){
                m_codedText[i] =  m_DecodingTable[j].getIneger();
                break;
            }
            if(j == m_sizeOfTable-1 ){
                m_codedText[i] = newText[i];
            }
        }
    }

}
void Dossier::free(){
    delete []m_codedText;
    delete []m_DecodingTable;
}
void Dossier::copyFrom(const Dossier& other){
    m_numberOfRows = other.m_numberOfRows;
    m_sizeOfTable = other.m_sizeOfTable;
    m_lenghtOfText = other.m_lenghtOfText;
    m_codedText = new int[m_lenghtOfText + 1];
    for(size_t i=0; i<m_lenghtOfText; i++){
        m_codedText[i] = other.m_codedText[i];
    }
    m_DecodingTable = new Encoder[m_sizeOfTable];
    for(size_t i=0; i<m_numberOfRows; i++){
        m_DecodingTable[i] = other.m_DecodingTable[i];
    }
}
Dossier::Dossier(const Dossier& other){
    copyFrom(other);
}
Dossier& Dossier::operator=(const Dossier& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
const int* Dossier::getText()const{
    return m_codedText;
}
bool Dossier::operator&&(const Dossier& other)const{
    for(size_t i=0; i<m_numberOfRows; i++){
        for(size_t j=0; j<other.m_numberOfRows; j++){
            if(m_DecodingTable[i].getSymbol() == other.m_DecodingTable[j].getSymbol() && 
            m_DecodingTable[i].getIneger() != other.m_DecodingTable[j].getIneger()){
                return false;
            }
        }
    }
    return true;
}
void Dossier::printText()const{
    for(size_t i=0; i < m_lenghtOfText; i++){
        std::cout<<m_codedText[i]<<"_";
    }
}
/*
Dossier& Dossier::operator+(const Dossier& other)const{
    if( *this && other){

    }else{
        return 
    }
}
*/