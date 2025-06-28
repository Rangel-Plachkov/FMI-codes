#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T, size_t N>
class StaticQueue{
public:
    StaticQueue() = default;

    bool isFull()const;
    bool isEmpty()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const;
    void pop();

private:
    T _data[N];
    size_t _writeId = 0, _readId = 0;
    size_t _size = 0;
};

template<typename T, size_t N>
bool StaticQueue<T, N>::isEmpty()const{
    return _size == 0;
}
template<typename T, size_t N>
bool StaticQueue<T, N>::isFull()const{
    return _size == N;
}
template<typename T, size_t N>
size_t StaticQueue<T, N>::size()const{
    return _size;
}
template<typename T, size_t N>
void StaticQueue<T, N>::push(const T& newElem){
    if(isFull()){
        throw std::logic_error("Full queue\n");
    }
    _data[_writeId] = newElem;
    _size++;
    _writeId = (_writeId + 1) % N;
}
template<typename T, size_t N>
const T& StaticQueue<T, N>::peek()const{
    if(isEmpty()){
        throw std::logic_error("Empty queue\n");
    }
    return _data[_readId];
}
template<typename T, size_t N>
void StaticQueue<T, N>::pop(){
    if(isEmpty()){
        throw std::logic_error("Empty queue\n");
    }
    _readId = (_readId + 1) % N;
    _size--;
}