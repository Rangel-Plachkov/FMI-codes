#pragma once

#include"Dish.h"


class MeatDish :virtual public Dish {
    public:
        void setMeatType(const char* newMeat);
        const char* getMeatType()const;
        void print()const  override;

        MeatDish(const char* newMeat);
        MeatDish();
        MeatDish(const MeatDish& other);
        virtual ~MeatDish();

        MeatDish& operator=(const MeatDish& other);
    private:
        char* m_MeatType;

        void free();
        void copyFrom(const MeatDish& other);

};