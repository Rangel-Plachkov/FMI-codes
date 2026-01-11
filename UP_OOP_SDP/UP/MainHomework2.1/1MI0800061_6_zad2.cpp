#include<iostream>
#include<cmath>

const size_t MAX_ARR_SIZE = 1024;

bool isPrime (size_t  const n){
    if(n == 1 || n == 0){
        return false;
    }
    size_t sqrN = sqrt(n);
    for(size_t i = 2; i <= sqrN; i++){
        if( !(n % i) ){
            return false;
        }
    }
    return true;
}
size_t getInputLenght(){
    int input;
    std::cout<<"lenght > ";
    std::cin>>input;
    if(input <= 0){
        input = 1;
        return input;
    }else if (input > MAX_ARR_SIZE){
        input = MAX_ARR_SIZE;
        return input;
    }
    return input;
}
void getArrInput(size_t const  lenght, size_t * const arr){
    int input;
    for(size_t i=0; i<lenght; i++){
        std::cin>>input;
        if(input < 0){
            input *= -1;
        }
        arr[i] = input;
    }
    return;
}
bool problem(size_t const n , size_t const m){
    //return ( isPrime(n) && !isPrime(m) ) || (isPrime(n) && n > m);
    //return isPrime(n) && ( !isPrime(m) || n > m );
    return isPrime(n) && !( isPrime(m) && n <= m );
}
size_t countProblems(size_t const lenght, size_t * const arr){
    size_t result = 0;
    for(size_t i=0; i<lenght-1;i++){
        for(size_t j = i+1; j<lenght ; j++){
            result += problem(arr[i], arr[j]);
        }
    }
    return result;
}

int main(){
    size_t arr[MAX_ARR_SIZE];
    size_t lenght = getInputLenght();
    getArrInput(lenght, arr);
    std::cout<<std::endl<<countProblems(lenght, arr);
}