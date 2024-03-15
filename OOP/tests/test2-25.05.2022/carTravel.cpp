#include<carTravel.h>
#include <cstring>

void carTravel::setPrice(const double newPrice){
    if(newPrice < 0){
        this->price = 0;
    }else{
        this->price = newPrice;
    }
}
void carTravel::setDistance(const size_t newDis){
    distance = newDis;
}
void carTravel::setRegNum(const int* newRegNum){
    if(newRegNum == nullptr){
        regNum = nullptr;
    }else{
        delete []regNum;
        regNum = new int[SIZE_OF_REG_NUM];
        for(int i = 0; i<SIZE_OF_REG_NUM; i++){
            regNum[i] = newRegNum[i];
        }
    }
}
double carTravel::getPrice()const{
    return price;
}
size_t carTravel::getDistance()const{
    return distance;
}
const int* carTravel::getRegNum()const{
    //return regNum;
}
carTravel::carTravel(){
    distance = 0;
    price = 0;
    regNum = nullptr;
}
carTravel::carTravel(const int* newRegNum, const size_t newDis, const double newPrice){
    setPrice (newPrice);
    setDistance(newDis);
    regNum = nullptr;
    setRegNum(newRegNum);
}
void carTravel::free(){
    delete[]regNum;
}
void carTravel::copyFrom(const carTravel& other){
    setDistance(other.getDistance());
    setPrice(other.getPrice());
    setRegNum(other.getRegNum());
}
carTravel::~carTravel(){
    free();
}
carTravel::carTravel(const carTravel& other){
    regNum = nullptr;
    copyFrom(other);
}
carTravel& carTravel::operator=(const carTravel& other){
    if(this != &other){
        copyFrom(other);
    }
    return *this;
}
