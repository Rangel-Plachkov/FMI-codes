#include<iostream>

size_t reverseNumber(size_t n){
    size_t result = 0, remainder;
    while( n ) {
        remainder = n % 10;
        result = result * 10 + remainder;
        n = n / 10;
    }
    return result;
}
bool isPalindrome(const size_t n){
    return n == reverseNumber(n);
}

int main(){
    std::cout<<isPalindrome(12321);
}