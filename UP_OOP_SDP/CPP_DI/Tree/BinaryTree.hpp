#pragma once

#include <stdexcept>
#include <cstddef>
#include <cassert>
#include <string>

template<typename T>
class BinaryTree{
private:
    struct Node{
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    
        Node() = default;
        Node(const T& newData): data(newData) {}
        Node(const T& newData, Node* newLeft, Node* newRight): data(newData), left(newLeft), right(newRight) {}
    };
public:
    bool isEmpty()const;
    size_t size()const;

    
private:
    size_t _size = 0;
    Node* _root = nullptr;

    void defaultValues();
};

template<typename T>
bool BinaryTree<T>::isEmpty()const{
    return _root == nullptr;
}
template<typename T>
size_t BinaryTree<T>::size()const{
    return _size;
}

template<typename T>
void BinaryTree<T>::defaultValues(){
    _size = 0;
    _root = nullptr;
}