#include<iostream>
#include<cstring>

void removeUpper(char* s){
    unsigned int size = strlen(s);
    char* temp = new char[size];
    int id=0; 
    for(int i=0; i < size; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){

        }else{
            temp[id] = s[i];
            id++;
        }
    }

    for(int i=0; i<id; i++){
        s[i] = temp[i];
    }
    if(id < size){
        s[id] = '\0';
    }

    delete temp;
}

int main(){
    char test[10];
    test[0] = 'H';
    test[1] = 'e';
    test[2] = 'L';
    test[3] = 'l';
    test[4] = 'o';
    
    removeUpper(test);
    std::cout<<test;
}