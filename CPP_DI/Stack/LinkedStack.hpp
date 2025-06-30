#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class LinkedStack{
private:
    struct Node{
        Node* next = nullptr;
        T data;
        Node(const T& newElem) : data(newElem) {}
    };
public:
    LinkedStack();
    LinkedStack(const LinkedStack& other);
    ~LinkedStack();

    LinkedStack<T>& operator=(const LinkedStack& other);
    bool isEmpty()const;
    size_t size()const;
    void push(const T& newElem);
    const T& peek()const;
    void pop();
    

private:
    Node* _currNode = nullptr;
    size_t _size = 0;

    void free();
    void copyFrom(const LinkedStack& other);
};

template<typename T>
LinkedStack<T>::LinkedStack(){
    _currNode = nullptr;
    _size = 0;
}
template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack& other){
    copyFrom(other);
}

template<typename T>
LinkedStack<T>::~LinkedStack(){
    free();
}
template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other){
    if( this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
bool LinkedStack<T>::isEmpty()const{
    return !_currNode;
}
template<typename T>
size_t LinkedStack<T>::size()const{
    return _size;
}

template<typename T>
void LinkedStack<T>::push(const T& newElem){
    Node* newNode = new Node(newElem);
    newNode -> next = _currNode;
    _currNode = newNode;
    _size++;
}
template<typename T>
const T& LinkedStack<T>::peek()const{
    if (isEmpty()) {
        throw std::logic_error("Empty stack");
    }
    return _currNode->data;
}
template<typename T>
void LinkedStack<T>::pop(){
    if(isEmpty()){
        throw std::logic_error("Empty stack");
    }
    Node* temp = _currNode;
    _currNode = _currNode ->next;
    delete temp;
    _size--;
}
template<typename T>
void LinkedStack<T>::free(){
    while (_currNode){
        Node* temp = _currNode;
        _currNode = _currNode ->next;
        delete temp;
        _size--;
    }
}
template<typename T>
void LinkedStack<T>::copyFrom(const LinkedStack& other) {
    if (!other._currNode) {
        _currNode = nullptr;
        _size = 0;
        return;
    }

    _currNode = new Node(other._currNode->data);
    Node* tail = _currNode;
    Node* otherCurr = other._currNode->next;

    while (otherCurr) {
        tail->next = new Node(otherCurr->data);
        tail = tail->next;
        otherCurr = otherCurr->next;
    }

    _size = other._size;
}
