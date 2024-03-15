#pragma once

class Encoder{
    public:
        void setSymbol(const char newSymbol);
        void setInteger(const int newInteger);
        int getIneger()const;
        char getSymbol()const;

        Encoder();
        Encoder(const char newSymbol , const int newInteger);
        Encoder& operator=(const Encoder& other);

    private:
        char m_Symbol;
        int m_Integer;
};