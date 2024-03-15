#include<iostream>

size_t numberOfDigits(const int n){
    if(n < 10){
        return 1;
    }
    return size( n / 10 ) + 1;
}
int pow(const int base , const size_t exponent){
    int result = 1;
    for(size_t i=0; i<exponent ;i++){
        result = result * base;
    }
    return result;
}

bool isSuffix(const size_t n , const size_t k){
    return k == (n % pow(10 , numberOfDigits(k) ));
}

int main(){
    std::cout<<isSuffix(123451434523 , 0);
}