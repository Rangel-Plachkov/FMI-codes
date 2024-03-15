#include<iostream>

size_t numberOfDigits(const int n){
    if(n < 10){
        return 1;
    }
    return size( n / 10 ) + 1;
}


int main(){
    std::cout<<numberOfDigits(1874);
}