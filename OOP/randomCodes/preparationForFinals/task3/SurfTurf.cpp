#include"SurfTurf.h"

void SurfTurf::print()const{
    std::cout<<"Sea Food: "<<SeaDish::getSeaType()<<std::endl;
    std::cout<<"Meat: "<<MeatDish::getMeatType()<<std::endl;
    this->Dish::print();
}
SurfTurf::SurfTurf(const char* MeatType , const char* SeaFoodType) : SeaDish(SeaFoodType) , MeatDish(MeatType){
    
}
