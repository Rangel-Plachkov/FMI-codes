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
size_t reverseNumber(size_t n){
    size_t result = 0, remainder;
    while( n ) {
        remainder = n % 10;
        result = result * 10 + remainder;
        n = n / 10;
    }
    return result;
}
bool isPreffix(const size_t n , const size_t k){
    return reverseNumber(k) == ( reverseNumber(n) % pow(10 , numberOfDigits(k) ));
}

int main(){
    std::cout<<isPreffix(12394385640 , 123);
}