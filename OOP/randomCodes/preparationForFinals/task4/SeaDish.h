#pragma once

#include"Dish.h"


class SeaDish :virtual public Dish {
    public:
        void setSeaType(const char* newMeat);
        const char* getSeaType()const;
        void print()const override;

        SeaDish(const char* newSeaF);
        SeaDish();
        SeaDish(const SeaDish& other);
        virtual ~SeaDish();

        SeaDish& operator=(const SeaDish& other);
    private:
        char* m_SeaType;

        void free();
        void copyFrom(const SeaDish& other);
};