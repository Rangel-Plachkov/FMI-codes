#pragma once

class Vector{
    public:
        Vector();
        Vector(const int newX  , const int newY);
        Vector(const int newX);

        void setX(const int newX);
        void setY(const int newY);
        int getX()const;
        int getY()const;

        Vector& operator+=(const Vector& other);
        Vector& operator*=(const int other);
        bool operator==(const Vector& other)const;
        bool operator!=(const Vector& other)const;
        int operator[](const int other);
    private:
        int m_X;
        int m_Y;
};
Vector operator+(const Vector& left , const Vector& right);
Vector operator*(const Vector& left , const int right);
Vector operator*(const int left , const Vector& right);
double operator*(const Vector& left, const Vector& right);