#include<iostream>
#include"bag.hpp"

template <typename t>
size_t bag<t>::counter = 0;

int main(){
    
    bag<int> bagOne;
    bag<int> bagTwo;
    bag<int> bagThree;
    std::cout<<bagThree.getId();
    
}