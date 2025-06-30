#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class LinkedQueue{
private:
    struct Node {
        Node* next;
        T data;
        Node(): next(nullptr), data() {}
        Node(const T& newData): data(newData), next(nullptr) {}
        Node(const T& newData, Node* newPtr): data(newData), next(newPtr) {}
    };
public:
    LinkedQueue() = default;
    LinkedQueue(const LinkedQueue& other);
    ~LinkedQueue();

    LinkedQueue<T>& operator=(const LinkedQueue& other);

    bool isEmpty()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const;
    void pop();

private:
    size_t _size = 0;
    Node* _readPtr = nullptr;
    Node* _writePtr = nullptr;

    void free();
    void copyFrom(const LinkedQueue& other);
};

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& other){
    copyFrom(other);
}
template<typename T>
LinkedQueue<T>::~LinkedQueue(){
    free();
}
template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
template<typename T>
bool LinkedQueue<T>::isEmpty()const{
    return _size == 0;
}
template<typename T>
size_t LinkedQueue<T>::size()const{
    return _size;
}
template<typename T>
void LinkedQueue<T>::push(const T& newElem){
    Node* newNode = new Node(newElem, nullptr);
    if (isEmpty()) {
        _readPtr = newNode;
        _writePtr = newNode;
    } else {
        _writePtr->next = newNode;
        _writePtr = newNode;
    }
    _size++;
}

template<typename T>
const T& LinkedQueue<T>::peek()const{
    if(isEmpty()){
        throw std::logic_error("Empty queue");
    }
    return _readPtr -> data;
}
template<typename T>
void LinkedQueue<T>::pop(){
    if (isEmpty()) {
        throw std::logic_error("Empty queue");
    }

    Node* temp = _readPtr->next;
    delete _readPtr;
    _readPtr = temp;
    _size--;

    if (_size == 0) {
        _writePtr = nullptr;
    }
}


template<typename T>
void LinkedQueue<T>::free(){
    while (_size){
        pop();
    }
}
template<typename T>
void LinkedQueue<T>::copyFrom(const LinkedQueue& other) {
    _size = 0;
    _readPtr = nullptr;
    _writePtr = nullptr;

    Node* otherIter = other._readPtr;
    while (otherIter != nullptr) {
        push(otherIter->data);
        otherIter = otherIter->next;
    }
}
