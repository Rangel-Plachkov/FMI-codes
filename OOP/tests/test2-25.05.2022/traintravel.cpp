#include"traintravel.h"
#include<cstring>


void trainTravel::setPrice(const double newPrice){
    if(newPrice < 0){
        this->price = 0;
    }else{
        this->price = newPrice;
    }
}
void trainTravel::setLine(const char* newLine){
    if(newLine == nullptr){
        return;
    }else{
        delete []this->trainLine;
        trainLine = new char[ strlen(newLine) +1 ];
        strcpy(trainLine , newLine);
    }
}
trainTravel::trainTravel(const char* newLane , const double newPrice){
    setPrice(newPrice);
    this->trainLine = nullptr;
    setLine(newLane);
}
const char* trainTravel::getLine()const{
    return trainLine;
}
double trainTravel::getPrice()const{
    return price;
}
trainTravel::trainTravel(){
    price = 0;
    trainLine = nullptr;
}
trainTravel::~trainTravel(){
    free();
}
void trainTravel::free(){
    delete []trainLine;
}
void trainTravel::copyFrom(const trainTravel& other){
    setPrice(other.getPrice() );
    setLine(other.getLine() );
}
trainTravel::trainTravel(const trainTravel& other){
    copyFrom(other);
}
trainTravel& trainTravel::operator=(const trainTravel& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}