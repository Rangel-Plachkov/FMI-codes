#include<iostream>
#include<cstring>

const size_t MAX_MATRIX_SIZE = 1024;
bool f(char matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], size_t sizeX, size_t sizeY, const char sym,const size_t count){
    if(!count){
        return true;
    }

    //Параметър sizeY ще остане unused при вкарване на валидни данни
    char* searchFor = new char[count];
    
    for(size_t i=0; i<count;i++){
        searchFor[i] = sym;
    }
    searchFor[count] = '\0';
    for(size_t x = 0; x<sizeX; x++){
        char* result = strstr(matrix[x],searchFor);
        if(result != nullptr){
            delete searchFor;
            return true;
        }
    }
    delete searchFor;
    return false;
}

int main(){
    char matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    matrix[0][0] = 'a';
    matrix[0][1] = 'b';
    matrix[0][2] = 'b';
    matrix[1][0] = 'b';
    matrix[1][1] = 'a';
    matrix[1][2] = 'a';
    matrix[2][0] = 'b';
    matrix[2][1] = 'e';
    matrix[2][2] = 'a';

    std::cout<<f(matrix,3,3,'a',2);

}