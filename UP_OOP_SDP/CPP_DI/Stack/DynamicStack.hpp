#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class DynamicStack{
public:
    DynamicStack();
    DynamicStack(const DynamicStack& other);
    ~DynamicStack();

    DynamicStack<T>& operator=(const DynamicStack& other);

    bool isEmpty()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const; 
    void pop();

private:
    static const size_t DEFAULT_STACK_SIZE = 16;
    size_t _maxSize = DEFAULT_STACK_SIZE;
    size_t _size = 0;
    T* _data = nullptr;

    void resize();
    void free();
    void copyFrom(const DynamicStack& other);
};

template<typename T>
DynamicStack<T>::DynamicStack(){
    _size = 0;
    _maxSize = DEFAULT_STACK_SIZE;
    _data = new T [_maxSize];
}
template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack& other){
    copyFrom(other);
}

template<typename T>
DynamicStack<T>::~DynamicStack(){
    free();
}

template<typename T>
DynamicStack<T>& DynamicStack<T>::operator=(const DynamicStack& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
bool DynamicStack<T>::isEmpty()const{
    return !_size;
}
template<typename T>
size_t DynamicStack<T>::size()const{
    return _size;
}

template<typename T>
void DynamicStack<T>::push(const T& newElem){
    if(_size >= _maxSize){
        resize();
    }
    _data[_size] = newElem;
    _size++;
}
template<typename T>
const T& DynamicStack<T>::peek()const{
    if(isEmpty()){
        throw std::logic_error("Empty stack");
    }
    return _data[_size - 1];
}
template<typename T>
void DynamicStack<T>::pop(){
    if(isEmpty()){
        throw std::logic_error("Empty stack");
    }
    _size--;
}


template<typename T>
void DynamicStack<T>::resize(){
    _maxSize *= 2;

    T* newData = new T[_maxSize];
    for(size_t i = 0; i < _size; i++) {
        newData[i] = _data[i];
    }

    delete []_data;
    _data = newData;
}

template<typename T>
void DynamicStack<T>::free(){
    delete []_data;
    _data = nullptr;
    _size = 0;
    _maxSize = DEFAULT_STACK_SIZE;
}

template<typename T>
void DynamicStack<T>::copyFrom(const DynamicStack& other){
    _size = other._size;
    _maxSize = other._maxSize;
    _data = new T[_maxSize];

    for(size_t i=0; i<_size; i++){
        _data[i] = other._data[i];
    }
}