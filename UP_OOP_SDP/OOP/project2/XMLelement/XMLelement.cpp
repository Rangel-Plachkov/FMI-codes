 #include"XMLelement.h"


void XMLelement::setId(const char* newId){
    myString result(newId);
    if( strstr(newId , "_") ){
        result = "_";
        result += uniqueIdNum;
        uniqueIdNum++;
    }
    id = result.get();
}
 const char* XMLelement::getId()const{
    return id.get();
 }
 XMLelement::XMLelement(){
    setId("_");
    atributes = new Atribute [DEFAULT_ATRIBUTE_ARR_SIZE];
    children = new myString [DEFAULT_CHILD_ARR_SIZE];
 }
void XMLelement::addAtribute(const Atribute& newAtribute){
    while(numberOfAtributes + 1 >= sizeOfAtributeArr){
        resizeAtributeArr();
    }
    atributes[numberOfAtributes] = newAtribute;
    numberOfAtributes++;
 }  
void XMLelement::resizeAtributeArr(){
    sizeOfAtributeArr = sizeOfAtributeArr * 2;
    Atribute* temp = new Atribute [ sizeOfAtributeArr ];

    for(size_t i=0; i<sizeOfAtributeArr/2 ;i++){
        temp[i] = atributes[i];
    }

    delete []atributes;
    atributes = temp;
    temp = nullptr;

 }
const Atribute* XMLelement::getAtributes()const{
    return atributes;
}
const Atribute* XMLelement::searchAtribute(const char* searchText)const{
    for(size_t i = 0; i<numberOfAtributes; i++){
        if( atributes[i].getName() == searchText ){
            return &atributes[i];
        }
    }
    return nullptr;
 }
const Atribute* XMLelement::getAtributeByIndex(const size_t number)const{
    if(number > numberOfAtributes){
        return nullptr;
    }else{
        return &atributes[number];
    }
 }
size_t XMLelement::getNumberOfAtributes()const{
    return numberOfAtributes;
}
void XMLelement::setText(const char* newText){
    
    text = newText;
    
 }
const char* XMLelement::getText()const{
    return text.get();
}
void XMLelement::free(){
    delete []atributes;
    delete []children;
}
XMLelement::~XMLelement(){
    free();
}
void XMLelement::copyFrom(const XMLelement& other){

    id = other.id;
    text = other.text;

    numberOfAtributes = other.numberOfAtributes;
    sizeOfAtributeArr = other.sizeOfAtributeArr;
    atributes = new Atribute [sizeOfAtributeArr];
    for(size_t i=0 ; i<sizeOfAtributeArr; i++){
        atributes[i] = other.atributes[i];
    }

    parent = other.getParent();

    numberOfChilds= other.numberOfChilds;
    sizeOfChildArr = other.sizeOfChildArr;

    children = new myString [sizeOfChildArr];
    for(size_t i=0; i<sizeOfChildArr;i++){
        children[i] = other.children[i];
    }
    

}
XMLelement::XMLelement(const XMLelement& other){
    copyFrom(other);
}
XMLelement& XMLelement::operator=(const XMLelement& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
void XMLelement::setParent(const myString& newParentId){
    parent = newParentId;
}
const myString& XMLelement::getParent()const{
    return parent;
}
void XMLelement::addChild(const myString& newChild){
    while(numberOfChilds + 1 >= sizeOfChildArr){
        resizeChildArr();
    }
    children[numberOfChilds] = newChild;
    numberOfChilds++;
}
void XMLelement::resizeChildArr(){
    sizeOfChildArr = sizeOfChildArr * 2;
    myString* temp = new myString [ sizeOfChildArr ];

    for(size_t i=0; i<sizeOfChildArr/2 ;i++){
        temp[i] = children[i];
    }

    delete []children;
    children = temp;
    temp = nullptr;

}
const myString* XMLelement::getChildren()const{
    return children;
}
const myString& XMLelement::getChildByIndex(const size_t index)const{
    return children[index];
}
XMLelement::XMLelement(const char* newId){
    atributes = new Atribute [DEFAULT_ATRIBUTE_ARR_SIZE];
    children = new myString [DEFAULT_CHILD_ARR_SIZE];
    setId(newId);
}
size_t XMLelement::getNumberOfChildren()const{
    return numberOfChilds;
}
Atribute* XMLelement::getAtributeByName(const myString& name)const{
    for(size_t i=0; i<numberOfAtributes; i++){
        if(atributes[i].getName() == name ){
            return &atributes[i];
        }
    }
    return nullptr;
}
void XMLelement::deleteAtribute(const myString& name){
    for(size_t i=0; i<numberOfAtributes; i++){
        if(name == atributes[i].getName()){
            for(size_t j=i; j<numberOfAtributes-1; j++){
                atributes[j] = atributes[j+1];
            }
            numberOfAtributes--;
            break;
        }
    }
}