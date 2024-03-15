#include<iostream>
#include<cstring>
#include<exception>
void concatSymvols_s(char*& s1,size_t maxNumberOfSyms, char* s2){
    if(s2 == nullptr){
        return;
    }
    
    size_t sizeSone;
    if(s1 == nullptr){
        sizeSone = 0;
    }else{
        sizeSone = strlen(s1);
    }
    size_t sizeStwo = strlen(s2);
    char* result = new char[maxNumberOfSyms];
    //strcpy(result,s1); ???
    
    for(size_t i=0; i<sizeSone; i++){
        result[i] = s1[i];
    }
    
    delete s1;
    size_t posInSt = 0;
    for(size_t i=sizeSone; i<maxNumberOfSyms; i++){
        
        while(s2[posInSt] >= '0' && s2[posInSt] <= '9'){
            posInSt++;
        }
        result[i] = s2[posInSt];
        posInSt++;
    }
    if(posInSt < sizeStwo){
        throw ("Invalid size"); //Забравих синтаксиса throw_exeption
    }
    s1 = result;
    result = nullptr;
    
}
int main(){
    char* s1 = new char[10];
    strcpy(s1, "34");
    
    char* s2 = new char[10];
    strcpy(s2, "ab5cd");

    concatSymvols_s(s1,4,s2);
    std::cout<<s1;

    delete s1;
    delete s2;

}