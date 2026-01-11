 #pragma once
 #include<cstring>
 class carTravel{
    private:
        static const size_t SIZE_OF_REG_NUM = 5;
        int* regNum;
        size_t distance;
        double price;

        void free();
        void copyFrom(const carTravel& other);
    public:
        carTravel(const int* newRegNum, const size_t newDis, const double newPric);
        carTravel();
        carTravel(const carTravel& other);
        ~carTravel();

        carTravel& operator=(const carTravel& other);

        void setPrice(const double newPrice);
        void setDistance(const size_t newDis);
        void setRegNum(const int* newRegNum);
        const int* getRegNum()const;
        double getPrice()const;
        size_t getDistance()const;
 };