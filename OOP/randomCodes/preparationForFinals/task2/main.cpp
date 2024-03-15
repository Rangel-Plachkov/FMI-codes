#include<iostream>
//#include"Vector2D.h"
#include"Vector2D.cpp"


int main(){
    Vector A(5, 5);
    Vector B(2,7);
    A = B;
    std::cout<< A.getX();
    
}