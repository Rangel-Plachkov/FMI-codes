#include<iostream>
//#include"Dish.h"

#include"Dish.cpp"
#include"MeatDish.cpp"
#include"SeaDish.cpp"
#include"SurfTurf.cpp"

int main(){

    SurfTurf T("pork", "chicken");
    
    T.setTime(100);
    T.print();

}