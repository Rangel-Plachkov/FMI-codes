#include "MyString.h"

void myString::free(){
    delete []str;
}
void myString::copyFrom(const myString& other){
    if( !other.isEmpty() ){
        str = new char[ strlen( other.get() ) + 1];
	    strcpy(str, other.get() );
	    size = other.getSize();
    }else{
        makeEmpty();
    }
}
void myString::concatFrom(const myString& other){
    char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
    temp = nullptr;

	size = size + other.getSize();
}
myString::myString(){
    makeEmpty();
}
myString::myString(const char* newString){
    if(newString == nullptr){
        makeEmpty();
    }else{
        size = strlen(newString);
        str = new char [ size + 1 ];
        strcpy(str, newString);
        
    }
}
myString::myString(const myString& other){
    copyFrom(other);
}
myString::myString(myString&& other){
    str = other.str;
    other.str = nullptr;
    size = other.getSize();
}
size_t getNumSize(size_t number){
    size_t res = 0;
	while (number){
		res++;
		number = number / 10;
	}
	return res;
}


myString::~myString(){
    free();
}
size_t myString::getSize()const{
    return size;
}
const char* myString::get()const{
    return str;
}

myString& myString::operator=(const myString& other){
    if( this != &other){
        
        free();
        copyFrom(other);
    }
    return *this;
}

myString& myString::operator=(myString&& other){
    if( this != &other){
        free();
        str = other.str;
        other.str = nullptr;
        size = other.getSize();
    }
    return *this;
}
myString& myString::operator+=(const myString& other){
    concatFrom(other);
    return *this;
}

bool myString::isEmpty()const{
    if(str[0] == '\0' ){
        return true;
    }else{
        return false;
    }
}

bool operator==(const myString& left , const myString& right){
    return !strcmp(left.get() , right.get() );
    
}
bool operator!=(const myString& left , const myString& right){
    return strcmp(left.get() , right.get() );
    
}
void myString::removeFirstNsymbols(const size_t N){
    char* temp = new char[size-N+1];
    for(size_t i=N; i <= size; i++){
        temp[i-N] = str[i];
    }
    delete []str;
    str = temp;
    size=size-N;
    temp = nullptr;
}
void myString::removeLastNsymbols(const size_t N){
    char* temp = new char[size - N + 1];
    for(size_t i=0; i < size - N; i++){
        temp[i] = str[i];
    }
    temp[size-N] = '\0';
    delete []str;
    str = temp;
    size = size-N;
    temp = nullptr;
}
size_t myString::strstr(const myString& searchStr)const{
    
    for(size_t i=0; i<size; i++){
        for(size_t j=0; j<searchStr.size ; j++){
            if(str[i+j] != searchStr.str[j] ){

                break;
            }else{
                if(j+1 == searchStr.size){
                    return i;
                }
            }
        }
    }
    return size+1;
}

myString::myString(unsigned long long number){
    size = getNumSize(number);

    str = new char[size + 1];
    str[size] ='\0';
    
    for(size_t i=0; i < size; i++){
        str[size - 1 - i] = (number % 10) + '0';
        number = number/10;    
    }


}
myString::myString(const char newSym){
    if(newSym == '\0'){
        makeEmpty();
    }else{
        str = new char[ 2 ];
        size = 1;
        str[0] = newSym;
        str[1] = '\0';
    }
}
void myString::makeEmpty(){
    str = new char[ 1 ];
	str[0] = '\0';
	size = 0;
}
long long myString::getNumber()const{
    long long result=0;
    for(size_t i=0; i<size; i++){
        
        if( (str[size - i -1] < 48 || str[size - i -1] > 57) && str[size-i-1] == '\0'){
            return -1;
        }
        result = result + (str[size - i - 1] - '0')*pow(10, i);
        
    }
    
    return result;
}