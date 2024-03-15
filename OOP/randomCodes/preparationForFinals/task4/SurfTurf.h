#pragma once

#include"Dish.h"
#include"SeaDish.h"
#include"MeatDish.h"

class SurfTurf : public SeaDish ,public MeatDish {
    public:
        void print()const override;
        SurfTurf(const char* MeatType , const char* SeaFoodType);
    
};