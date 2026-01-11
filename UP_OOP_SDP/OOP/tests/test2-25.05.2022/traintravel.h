#pragma once
class trainTravel{
    private:
        char* trainLine;
        double price;

        void free();
        void copyFrom(const trainTravel& other);
    public:
        trainTravel(const char* newLane , const double newPrice);
        trainTravel();
        trainTravel(const trainTravel& other);
        ~trainTravel();

        trainTravel& operator=(const trainTravel& other);

        void setPrice(const double newPrice);
        void setLine(const char* newName);
        const char* getLine()const;
        double getPrice()const;
 };