#include<iostream>
#include<cstring>

bool od(char* number){
    if(number == nullptr){
        return true;
    }
    size_t size = strlen(number);
    for(size_t i=0; i<size;i++){
        int temp = number[i] - '0';
        if(temp % 2){
            return false;
        }
    }
    return true;
}
int main(){
    //std::cout<<od(nullptr);
    std::cout<<od("123")<<std::endl;
    //std::cout<<od("222")<<std::endl;
    //std::cout<<od("133")<<std::endl;
    //std::cout<<od("202")<<std::endl;

    /*
    for(int i=0; i<128; i++){
        char sym = i;
        std::cout<<i<<" "<<sym<<"\n";
    }*/
    
}