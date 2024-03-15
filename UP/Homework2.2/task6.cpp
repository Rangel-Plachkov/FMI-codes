#include<iostream>

size_t numberOfDigits(int n){
    size_t count = 0;
    if( !n ){
        return 1;
    }
    while( n ){
        count++;
        n = n / 10;
    }
    return count;
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
    //std::cout<<isPreffix(12394385640 , 123);
}