#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class DynamicQueue{
public:
    DynamicQueue();
    DynamicQueue(const DynamicQueue& other);
    ~DynamicQueue();

    DynamicQueue<T>& operator=(const DynamicQueue& other);

    bool isEmpty()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const;
    void pop();


private:
    static const size_t DEFAULT_QUEUE_SIZE = 32;
    size_t _maxSize = DEFAULT_QUEUE_SIZE;
    size_t _size = 0;
    size_t _readIdx = 0, _writeIdx = 0;
    T* _data = nullptr;

    void free();
    void resize();
    void copyFrom(const DynamicQueue& other);

};
template<typename T>
DynamicQueue<T>::DynamicQueue(){
    _size = 0;
    _readIdx = 0;
    _writeIdx = 0;
    _maxSize = DEFAULT_QUEUE_SIZE;
    _data = new T[_maxSize];
}
template<typename T>
DynamicQueue<T>::DynamicQueue(const DynamicQueue& other){
    copyFrom(other);
}

template<typename T>
DynamicQueue<T>::~DynamicQueue(){
    free();
}
template<typename T>
DynamicQueue<T>& DynamicQueue<T>::operator=(const DynamicQueue& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
template<typename T>
bool DynamicQueue<T>::isEmpty()const{
    return _size == 0;
}
template<typename T>
size_t DynamicQueue<T>::size()const{
    return _size;
}
template<typename T>
void DynamicQueue<T>::push(const T& newElem){
    if(_writeIdx == _maxSize){
        resize();
    }
    _data[_writeIdx] = newElem;
    _size++;
    _writeIdx++;
}
template<typename T>
const T& DynamicQueue<T>::peek()const{
    if(isEmpty()){
        throw std::logic_error("Empty queue\n");
    }
    return _data[_readIdx];
}
template<typename T>
void DynamicQueue<T>::pop(){
    if(isEmpty()){
        throw std::logic_error("Empty queue\n");
    }
    _readIdx++;
    _size--;
    if (_size == 0) {
        _readIdx = 0;
        _writeIdx = 0;
    }

}
template<typename T>
void DynamicQueue<T>::free(){
    delete []_data;
    _data = nullptr;
    _size = 0;
    _readIdx = 0;
    _writeIdx = 0;
    _maxSize = 0;
}
template<typename T>
void DynamicQueue<T>::resize(){
    _maxSize *= 2;
    T* tempArr = new T[_maxSize];

    for(size_t i = _readIdx; i < _writeIdx; ++i){
        tempArr[i - _readIdx] = _data[i];
    }

    delete[] _data;
    _data = tempArr;
    _writeIdx -= _readIdx;
    _readIdx = 0;
}

template<typename T>
void DynamicQueue<T>::copyFrom(const DynamicQueue& other){
    _maxSize = other._maxSize;
    _data = new T[_maxSize];

    for (size_t i = other._readIdx; i < other._writeIdx; ++i) {
        _data[i - other._readIdx] = other._data[i];
    }

    _size = other._size;
    _readIdx = 0;
    _writeIdx = other._writeIdx - other._readIdx;
}
