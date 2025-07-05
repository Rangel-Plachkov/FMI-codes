#pragma once

#include<stdexcept>
#include<cstddef>

template<typename T>
class DoubleLinkedList{
private:
    struct Node{
        Node* left = nullptr , right = nullptr;
        T data;
        Node() = default;
        Node(const T& newData): data(newData){}
        Node(const T& newData, Node* newLeft, Node* newRight): data(newData), left(newLeft), right(newRight){}
    };
public:
    DoubleLinkedList() = default;
    DoubleLinkedList(const DoubleLinkedList& other);
    ~DoubleLinkedList();

    DoubleLinkedList<T>& operator=(const DoubleLinkedList& other);

    bool isEmpty()const;
    size_t size()const;
    void pushFront(const T& newElem);
    void pushBack(const T& newElem);
    const T& peekFront()const;
    const T& peekBack()const;
    void popFront();
    void popBack();

private:
    Node* _begin = nullptr , _end = nullptr;
    size_t _size = 0;

    void setDefaultValues();
    void free();
    void copyFrom(const DoubleLinkedList& other);
};
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& other){
    copyFrom(other);
}
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    free();
}
template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
template<typename T>
bool DoubleLinkedList<T>::isEmpty()const{
    return _size == 0;
}
template<typename T>
size_t DoubleLinkedList<T>::size()const{
    return _size;
}
template<typename T>
void DoubleLinkedList<T>::pushFront(const T& newElem){
    if(isEmpty()){
        _begin = new Node(newElem);
        _end = _begin;
        _size++;
        return;    
    }
    _begin -> left = new Node(newElem , nullptr , _begin); 
    _begin = _begin -> left;
    _size++;
}
template<typename T>
void DoubleLinkedList<T>::pushBack(const T& newElem){
    if(isEmpty()){
        _end = new Node(newElem);
        _begin = _end;
        _size++;
        return;    
    }
    _end -> right = new Node(newElem , _end , nullptr); 
    _end = _end -> right;
    _size++;
}
template<typename T>
const T& DoubleLinkedList<T>::peekFront()const{
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }
    return _begin -> data;
}
template<typename T>
const T& DoubleLinkedList<T>::peekBack()const{
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }
    return _end -> data;
}
template<typename T>
void DoubleLinkedList<T>::popFront(){
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }else if(_size == 1){
        delete _begin;
        setDefaultValues();
    }else{
        _begin = _begin -> right;
        delete _begin -> left;
        _begin -> left = nullptr;
        _size--;
    }
}
template<typename T>
void DoubleLinkedList<T>::popBack(){
    if(isEmpty()){
        throw std::logic_error("Empty list");
    }else if(_size == 1){
        delete _end;
        setDefaultValues();
    }else{
        _end = _end -> left;
        delete _end -> right;
        _end -> right = nullptr;
        _size--;
    }
}

template<typename T>
void DoubleLinkedList<T>::setDefaultValues(){
    _begin = nullptr;
    _end = nullptr;
    _size = 0;
}
template<typename T>
void DoubleLinkedList<T>::free(){
    while (!isEmpty()){
        popBack();
    }  
}
template<typename T>
void DoubleLinkedList<T>::copyFrom(const DoubleLinkedList& other){
    setDefaultValues();
    Node* iter = other._begin;
    while(iter){
        pushBack(iter->data);
        iter = iter->right;
    }
}

