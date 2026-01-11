#pragma once

#include <stdexcept>
#include <cstddef>
#include <cassert>

template<typename T>
class BinarySearchTree{
private:
    struct Node{
        T data;
        Node* left = nullptr;
        Node* right = nullptr;

        Node() = default;
        Node(const T& newData): data(newData), left(nullptr), right(nullptr){}
        Node(const T& newData, Node* newLeft, Node* newRight): data(newData), left(newLeft), right(newRight){}
    };  
public:
    BinarySearchTree();
    ~BinarySearchTree();

    size_t size()const;
    bool isEmpty()const;

    void insert(const T& newElem);
    bool isInside(const T& newElem)const;
    void remove(const T& elemToRemove);

private:
    Node* _root = nullptr;
    size_t _size = 0;

    void insert_rec(Node* const curr_root , const T& newElem);
    bool isInside_rec(const Node* const curr_node , const T& newElem)const;
    Node* findMinSubTree(Node* const curr_root)const;
    Node* remove_rec(Node* curr_root, const T& elemToBeRemoved);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
    _root = nullptr;
    _size = 0;
}

template<typename T>
size_t BinarySearchTree<T>::size()const{
    return _size;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty()const{
    return _root == nullptr;
}
template<typename T>
void BinarySearchTree<T>::insert(const T& newElem){
    if(isEmpty()){
        _root = new Node(newElem);
    }else{
        insert_rec(_root , newElem);
    }
    _size++;
}

template<typename T>
bool BinarySearchTree<T>::isInside(const T& newElem)const{
    return isInside_rec(_root , newElem);
}
template<typename T>
void BinarySearchTree<T>::remove(const T& elemToRemove){
    if(isEmpty())
        return;

    
}

template<typename T>
void BinarySearchTree<T>::insert_rec(Node* const curr_root , const T& newElem){
    assert(curr_root != nullptr);

    if( newElem < curr_root->data ){
        if(curr_root->left == nullptr){
            curr_root->left = new Node(newElem);
        }else{
            insert_rec(curr_root->left , newElem);
        }
    }else{
        if(curr_root->right == nullptr){
            curr_root->right = new Node(newElem);
        }else{
            insert_rec(curr_root->right , newElem);
        }
    }
}

template<typename T>
bool BinarySearchTree<T>::isInside_rec(const Node* const curr_root, const T& newElem)const{
    if(curr_root == nullptr){
        return false;
    }else if(curr_root->data == newElem){
        return true;
    }else if(newElem < curr_root->data ){
        return isInside_rec(curr_root->left, newElem);
    }else{
        return isInside_rec(curr_root->right, newElem);
    }
}
template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMinSubTree(Node* const curr_root)const{
    assert(curr_root != nullptr);

    if (curr_root->left == nullptr) {
        return curr_root;
    } else {
        return findMinSubTree(curr_root->left);
    }
}
template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove_rec(Node* curr_root, const T& elemToRemove) {
    if (!curr_root)
        return nullptr;

    if (elemToRemove < curr_root->data) {
        curr_root->left = remove_rec(curr_root->left, elemToRemove);
    } else if (elemToRemove > curr_root->data) {
        curr_root->right = remove_rec(curr_root->right, elemToRemove);
    } else {
        if (!curr_root->left) {
            Node* temp = curr_root->right;
            delete curr_root;
            _size--;
            return temp;
        } else if (!curr_root->right) {
            Node* temp = curr_root->left;
            delete curr_root;
            _size--;
            return temp;
        } else {
            Node* minNode = findMinSubTree(curr_root->right);
            std::swap(curr_root->data, minNode->data);
            curr_root->right = remove_rec(curr_root->right, elemToRemove);
        }
    }

    return curr_root;
}
