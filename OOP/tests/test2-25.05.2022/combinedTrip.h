#pragma once
#include"traintravel.h"
#include"carTravel.h"
class combinedTrip{
    private:    
        trainTravel trainT;
        carTravel carT;
        double cash;
        char** destinations;
        size_t numberOfDestinations;

        void free();
        void copyFrom(const combinedTrip& other);
        
    public:
        combinedTrip();
        ~combinedTrip();
        
        combinedTrip& operator=(const combinedTrip& other);

        double getPrice()const;

        void setTrainTravel(const trainTravel& newTrainT);
        void setCarTravel(const carTravel& newCarT);
        void setCash(const double newCash);
        void setDestinations(const char** newDestinations, const size_t numberOfDest);

        const trainTravel& getTrainT()const;
        const carTravel& getCarT()const;
        double getCash()const;
        const char** getDestinations()const;

};