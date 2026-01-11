#include"combinedTrip.h"
#include<cstring>

void combinedTrip::setTrainTravel(const trainTravel& newTrainT){
    trainT = newTrainT;
}
void combinedTrip::setCarTravel(const carTravel& newCarT){
    carT = newCarT;
}
void combinedTrip::setCash(const double newCash){
    if(newCash < 0){
        cash = 0;
    }else{
        cash = newCash;
    }
}
const trainTravel& combinedTrip::getTrainT()const{
    return trainT;
}
const carTravel& combinedTrip::getCarT()const{
    return carT;
}
double combinedTrip::getCash()const{
    return cash;
}
double combinedTrip::getPrice()const{
    double result = 0;
    result = result + trainT.getPrice();
    result = result + carT.getPrice();
    result = result + cash;
    return result;
}
combinedTrip::combinedTrip(){
    cash = 0;
    destinations = nullptr;
    numberOfDestinations = 0;
}

void combinedTrip::setDestinations(const char** newDestinations , const size_t newNumberOfDest){
    for(int i=0; i<numberOfDestinations;i++ ){
        delete []destinations[i];
    }
    delete []destinations;


    if(newDestinations == nullptr){
        destinations = nullptr;
        numberOfDestinations = 0;
        return;
    }

    numberOfDestinations = newNumberOfDest; 
    destinations = new char*[numberOfDestinations];   
    for(int i = 0; i<newNumberOfDest ; i++){
        if(newDestinations[i] == nullptr){
            destinations[i] = nullptr;
        }else{
            destinations[i] = new char [ strlen(newDestinations[i]) + 1 ];
            strcpy(destinations[i] , newDestinations[i]);
        }
    }
}

const char** combinedTrip::getDestinations()const{
    return destinations;
}
void combinedTrip::free(){
    for(int i=0; i<numberOfDestinations; i++){
        delete []destinations[i];
    }
    delete []destinations;
}
void combinedTrip::copyFrom(const combinedTrip& other){
    trainT = other.getTrainT();
    carT = other.getCarT();
    cash = other . getCash();
    numberOfDestinations = other.numberOfDestinations;
    destinations = new char*[numberOfDestinations];
    for(int i =0 ;i<numberOfDestinations; i++){
        destinations[i] = new char[ strlen(other.getDestinations()[i]) +1  ];
        strcpy(destinations[i] , other.getDestinations()[i]);
    }
}

combinedTrip::~combinedTrip(){
    free();
}
combinedTrip::combinedTrip(const combinedTrip& other){
    copyFrom(other);
}
combinedTrip& combinedTrip::operator=(const combinedTrip& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
