#include<iostream>
#include<cmath>

/*####################################
Проблема в тази задача е с нулите
Ако имаш числото 1010 в даден момент ще искаш да провериш дали да прибавиш 010 към резултата
Ако изпратиш 010 на haveDifferentDigits() то ще върне true понеже преобразува 010 -> 10

Решението ми е в removeDegitsPosBasedBinary да връща double вместо unsigned int, 
където цялата част представлява върнатото число,а ако се окаже че има 0 в началото ще прибавя +0.1

При сумиране на сумите правя конвертиране от double към size_t ако числата са еднакви значи няма нула в началото

1010 -> ___0 + __1_ + __10 + _0__ + _01_ + 1___ + 1__0 + 10__ = 33

####################################*/


size_t digitCount(const size_t& number){
    if( number/10 )
        return 1 + digitCount(number/10); // :)
    
    return 1;
}

size_t input(){
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    return input;
}
bool haveDifferentDigits(int number, bool zeroFront){
    if(number < 0){
        number *= -1;
    }
    bool zero = zeroFront;
    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;
    bool six = false;
    bool seven = false;
    bool eight = false;
    bool nine = false;
    while(number){
        switch(number % 10){
            case 1:
                if(!one){
                    one = true;
                    break;
                }else{
                    return false;
                }
            case 2:
                if(!two){
                    two = true;
                    break;
                }else{
                    return false;
                }
            case 3:
                if(!three){
                    three = true;
                    break;
                }else{
                    return false;
                }
            case 4:
                if(!four){
                    four = true;
                    break;
                }else{
                    return false;
                }
            case 5:
                if(!five){
                    five = true;
                    break;
                }else{
                    return false;
                }
            case 6:
                if(!six){
                    six = true;
                    break;
                }else{
                    return false;
                }
            case 7:
                if(!seven){
                    seven = true;
                    break;
                }else{
                    return false;
                }
            case 8:
                if(!eight){
                    eight = true;
                    break;
                }else{
                    return false;
                }
            case 9:
                if(!nine){
                    nine = true;
                    break;
                }else{
                    return false;
                }
            case 0:
                if(!zero){
                    zero = true;
                    break;
                }else{
                    return false;
                }
        }
        number /= 10;
    }
    return true;
}

size_t convertBinToDec(size_t binNumber){
    size_t result = 0;
    for(size_t pow = 1; binNumber; (binNumber /= 10 , pow *= 2)){
        result += pow * (binNumber%10);
    }
    return result;
}
size_t convertDectoBin(size_t decNumber){
    size_t result = 0;
	for (size_t pow = 1 ; decNumber ; (decNumber /= 2 , pow *= 10)){
		result += pow * (decNumber % 2);
	}
    return result;

}
size_t binaryAddOne(size_t binNumber){
    return convertDectoBin (convertBinToDec(binNumber) + 1);
}
double removeDegitsPosBasedBinary(size_t number, size_t bin){
    double  result = 0;
    size_t numberLen = digitCount(bin);
    size_t step = 0;
    double lastNum;
    for(size_t i = 0; i < numberLen; i++){
        result += pow(10, step)*(bin%10)*(number%10);
        lastNum = number%10;
        step += bin % 10;
        bin /= 10;
        number /=10;
    }
    if( !lastNum ){
        //std::cout<<lastNum<<" ";
        result += 0.1;
    }
    return result;
}   


size_t sumTaskFour(const size_t number){
    const size_t maxN = pow (2 , digitCount(number)) ;
    size_t binStr = 0;
    size_t result = 0;

    for(size_t i=0; i < maxN; i++){

        double currNumber = removeDegitsPosBasedBinary(number, binStr);
        size_t convCurr = currNumber;
        if( haveDifferentDigits( currNumber , !(currNumber == convCurr )) ){
            //std::cout<<currNumber<<"\n";
            result += currNumber;
        }
        binStr = binaryAddOne(binStr);
    }
    return result;
}

int main(){
    size_t N = input();
    std::cout<<sumTaskFour(N)<<std::endl;

    //std::cout<<sumTaskFour(123)<<std::endl;
    //std::cout<<sumTaskFour(11211)<<std::endl;
    //std::cout<<sumTaskFour(1010)<<std::endl;

}

