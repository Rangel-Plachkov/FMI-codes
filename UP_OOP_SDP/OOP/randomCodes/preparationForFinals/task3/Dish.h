#pragma once

#include<cstring>
#include<iostream>

class Dish{
    public:
    
        virtual void print()const  ;
        void addIngredient(const char* newIngredient);
        void setTime(const size_t newTime);
        size_t getTime()const;
        const char* getIngrsbyId(const size_t id)const;
        
        Dish();
        Dish(const Dish& other);
        virtual ~Dish();
        
        Dish& operator=(const Dish& other);
        Dish& operator=(Dish&& other);

    private:

        static const size_t MAX_INGR_SIZE = 100;
        unsigned int m_cookTime;
        size_t m_numberOfIngr;
        char* m_Ingrs[MAX_INGR_SIZE + 1];

        void free();
        void copyFrom(const Dish& other);
        
};
