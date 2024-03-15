#include<iostream>
#include<cmath>

const size_t MAX_ARR_SIZE = 1024;

size_t input(){
    int input;
    std::cin>>input;
    if(input < 0){
        input = 0;
    }
    return input;
}
void inputArrays(const size_t arrLen, size_t * const arrayX, size_t * const  arrayY){
    for(size_t i = 0; i<arrLen; i++){
        arrayX[i] = input();
        arrayY[i] = input();
    }
    return;
}
double calculateDistance(const size_t arrLen, size_t * const arrayX , size_t * const arrayY){
    double result = 0;
    
    size_t currX = arrayX[0] , currY = arrayY[0];
    for(size_t i=1; i < arrLen; i++){
        result += sqrt(  pow( abs(currX - arrayX[i]), 2 ) + pow( abs(currY - arrayY[i]), 2 ) );
        currX = arrayX[i];
        currY = arrayY[i];
    }
    return result;
}

int main(){
    size_t size;
    size_t arrayX[MAX_ARR_SIZE];
    size_t arrayY[MAX_ARR_SIZE];

    std::cout<<"size1 > ";
    size = input();
    inputArrays(size, arrayX, arrayY);
    double resultOne = calculateDistance(size, arrayX, arrayY);

    std::cout<<"size2 > ";
    size = input();
    inputArrays(size, arrayX, arrayY);
    double resultTwo = calculateDistance(size, arrayX, arrayY);
    
    if(resultOne == resultTwo){
        std::cout<<"true";
        std::cout<<std::endl;
        std::cout<<resultOne;
    }else{
        std::cout<<"false";
    }
    return 0;
}

