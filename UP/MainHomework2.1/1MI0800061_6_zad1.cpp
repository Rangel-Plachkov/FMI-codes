#include<iostream>

size_t pow(size_t const& base , size_t const& exp){
    size_t result = 1;
    for(size_t i = 0; i<exp; i++)
        result *= base;
    
    return result;
}
size_t digitString(size_t n){
    bool zero = false;
    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;
    bool six = false;
    bool seven = false;
    bool eight = false;
    bool nine = false;
    while(n){
        switch(n % 10){
            case 1:
                one = true;
                break;
            case 2:
                two = true;
                break;
            case 3:
                three = true;
                break;
            case 4:
                four = true;
                break;
            case 5:
                five = true;
                break;
            case 6:
                six = true;
                break;
            case 7:
                seven = true;
                break;
            case 8:
                eight = true;
                break;
            case 9:
                nine = true;
                break;
            case 0:
                zero = true;
                break;
        }
        n /= 10;
    }

    size_t result = 2*pow(10, 10);
    //2 оптред с цел дебъгване , всяка цифра различна от 0 ще работи
    result += pow(10 , 0)*zero;
    result += pow(10 , 1)*one;
    result += pow(10 , 2)*two;
    result += pow(10 , 3)*three;
    result += pow(10 , 4)*four;
    result += pow(10 , 5)*five;
    result += pow(10 , 6)*six;
    result += pow(10 , 7)*seven;
    result += pow(10 , 8)*eight;
    result += pow(10 , 9)*nine;

    return result;
}
size_t digitStringLen(size_t digitString){
    size_t result = 0;
    for(size_t i=0; i<10; i++){
        result += digitString%10;
        digitString /= 10;
    }
    return result;
}
void input(size_t& n , size_t& k){
    int tempN, tempK;
    std::cout<<"input N and K> ";
    std::cin>>tempN>>tempK;
    if(tempN < 0){
        tempN *= -1;
    }
    if(tempK <0){
        tempK *= -1;
    }
    n = tempN;
    k = tempK;
    return;
}
int compare(size_t const n, size_t const k){
    size_t digitStrN = digitString(n);
    size_t digitStrK = digitString(k);
    size_t dStrLenN = digitStringLen(digitStrN);
    size_t dStrLenK = digitStringLen(digitStrK);

    if(dStrLenN == dStrLenK){
        if(digitStrN == digitStrK){
            return 0;
        }else{
            return -1;
        }
    }else if(dStrLenN > dStrLenK){
        for(size_t i=0; i<10; i++){
            if( (digitStrK % 10 == 1) && (digitStrK % 10) != (digitStrN % 10) ){
                return -1;
            }
            digitStrN /= 10;
            digitStrK /= 10;
        }
        return 1;
    }else{
        for(size_t i=0; i<10; i++){
            if( (digitStrN % 10 == 1) && (digitStrN % 10) != (digitStrK % 10) ){
                return -1;
            }
            digitStrK /= 10;
            digitStrN /= 10;
        }
        return 2;
    }
}
void results(const size_t n, const size_t k){
    switch(compare(n,k)){
        case 0:
            std::cout<<"Equal strength";
            break;
        case -1:
            std::cout<<"Not comparable";
            break;
        case 1:
            //comare връща коя стойност е по-"силна"
            std::cout<<"Second is weaker";
            break;
        case 2:
            std::cout<<"First is weaker";
            break;
    }
    std::cout<<std::endl;
}

int main(){
    size_t n,k;
    input(n,k);
    results(n , k);

    //results(123, 3121);
    //results(12, 1523);
    //results(-43550, 340);
    //results(123, 456);
}