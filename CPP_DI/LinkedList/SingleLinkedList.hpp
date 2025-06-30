#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class SingleLinkedList{
private:
    struct Node{
        T data;
        Node* next = nullptr;
        Node(const T& newElem): data(newElem), next(nullptr){}
        Node(const T& newElem, Node* nextPtr): data(newElem), next(nextPtr){}
    };
public:
    SingleLinkedList();
    SingleLinkedList(const SingleLinkedList& other);
    ~SingleLinkedList();

    T& operator[](size_t index);
    const T& operator[](size_t index)const;
    SingleLinkedList<T>& operator=(const SingleLinkedList& other);

    size_t size()const;
    bool isEmpty()const;
    void pushBack(const T& newElem);
    void pushFront(const T& newElem);
    const T& peekBack()const;
    const T& peekFront()const;
    void popBack(); // O(n)
    void popFront();


private:
    Node* _startPtr = nullptr;
    Node* _endPtr = nullptr;
    size_t _size = 0;

    void free();
    void copyFrom(const SingleLinkedList& other);
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(){
    _startPtr = nullptr;
    _endPtr = nullptr;
    _size = 0;
}
template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList& other ){
    copyFrom(other);
}
template<typename T>
SingleLinkedList<T>::~SingleLinkedList(){
    free();
}
template<typename T>
T& SingleLinkedList<T>::operator[](size_t index){
    if(index >= _size){
        throw std::logic_error("Out of bounds");
    }
    Node* current = _startPtr;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
const T& SingleLinkedList<T>::operator[](size_t index) const {
    if(index >= _size){
        throw std::logic_error("Out of bounds");
    }
    const Node* current = _startPtr;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}
template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
template<typename T>
size_t SingleLinkedList<T>::size()const{
    return _size;
}
template<typename T>
bool SingleLinkedList<T>::isEmpty()const{
    return _size == 0; 
}
template<typename T>
void SingleLinkedList<T>::pushBack(const T& newElem){
    Node* newNodePtr = new Node(newElem, nullptr);
    if(isEmpty()){
        _startPtr = newNodePtr;
        _endPtr = newNodePtr;
    }else{
        _endPtr -> next = newNodePtr;
        _endPtr = newNodePtr;
    }
    _size++;
}
template<typename T>
void SingleLinkedList<T>::pushFront(const T& newElem){
    Node* newNodePtr = new Node(newElem, _startPtr);
    _startPtr = newNodePtr;
    if (_size == 0) {
        _endPtr = newNodePtr;
    }
    _size++;

}
template<typename T>
const T& SingleLinkedList<T>::peekBack()const{
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }
    return _endPtr -> data;
}
template<typename T>
const T& SingleLinkedList<T>::peekFront()const{
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }
    return _startPtr -> data;
}
template<typename T>
void SingleLinkedList<T>::popBack(){
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }else if(_size == 1){
        delete _startPtr;
        _startPtr = nullptr;
        _endPtr = nullptr; 
    }else{
        Node* tempPtr = _startPtr;
        while(tempPtr -> next != _endPtr){
            tempPtr = tempPtr -> next;
        }
        delete _endPtr;
        _endPtr = tempPtr;
        tempPtr -> next = nullptr;
    }
    _size--;
} 
template<typename T>
void SingleLinkedList<T>::popFront(){
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }else if(_size == 1){
        delete _startPtr;
        _startPtr = nullptr;
        _endPtr = nullptr;
    }else{
        Node* tempPtr = _startPtr -> next;
        delete _startPtr;
        _startPtr = tempPtr;
    }
    _size--;
} 
template<typename T>
void SingleLinkedList<T>::free(){
    while(!isEmpty()){
        popFront();
    }
} 
template<typename T>
void SingleLinkedList<T>::copyFrom(const SingleLinkedList& other) {
    Node* current = other._startPtr;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}