#include"Vector2D.h"

Vector::Vector(){
    setX(0);
    setY(0);
}
Vector::Vector(const int X){
    setX(X);
    setY(0);
}
Vector::Vector(const int newX , const int newY){
    setX(newX);
    setY(newY);
}
void Vector::setX(const int newX){
    m_X = newX;
}
void Vector::setY(const int newY){
    m_Y = newY;
}
int Vector::getX()const{
    return m_X;
}
int Vector::getY()const{
    return m_Y;
}
Vector operator+(const Vector& left , const Vector& right){
    Vector result(left.getX() + right.getX() , left.getY() + right.getY());
    return result;
}

Vector& Vector::operator+=(const Vector& other){
    setX(m_X + other.getX());
    setY(m_Y + other.getY());
}
Vector operator*(const Vector& left , const int right){
    Vector result(left.getX()*right , left.getY()*right);
    return result;
}
Vector operator*(const int left , const Vector& right){
    Vector result(right.getX()*left , right.getY()*left);
    return result;
}
double operator*(const Vector& left , const Vector& right){
    double result = left.getX()*right.getX() + left.getY()*right.getY();
    return result;
}
Vector& Vector::operator*=(const int other){
    setX(m_X*other);
    setY(m_Y*other);
}
bool Vector::operator==(const Vector& other)const{
    return m_X == other.m_X && m_Y == other.m_Y;
}
bool Vector::operator!=(const Vector& other)const{
    return !(m_X == other.m_X && m_Y == other.m_Y);
}
int Vector::operator[](const int other){
    if(other == 0){
        return m_X;
    }
    if(other == 1){
        return m_Y;
    }
    else{
        return 0;
    }
}