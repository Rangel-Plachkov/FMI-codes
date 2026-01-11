#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T, size_t N>
class StaticStack{
public:
    StaticStack() = default;

    bool isEmpty()const;
    bool isFull()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const;
    void pop();

private:
    T _data[N];
    size_t _size=0;
};

template<typename T, size_t N>
bool StaticStack<T, N>::isEmpty()const{
    return !_size;
}
template<typename T, size_t N>
bool StaticStack<T, N>::isFull()const{
    return _size == N;
}
template<typename T, size_t N>
size_t StaticStack<T, N>::size()const{
    return _size;
}
template<typename T, size_t N>
void StaticStack<T, N>::push(const T& newElem){
    if(isFull()){
        throw std::logic_error("Full stack");
    }
    _data[_size] = newElem;
    _size++;
}
template<typename T, size_t N>
const T& StaticStack<T, N>::peek()const{
    if(isEmpty()){
        throw std::logic_error("Empty stack");
    }
    return _data[_size-1];
}
template<typename T, size_t N>
void StaticStack<T, N>::pop(){
    if(isEmpty()){
        throw std::logic_error("Empty stack");
    }
    _size--;
}
