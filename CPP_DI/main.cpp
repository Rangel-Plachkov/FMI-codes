#include <iostream>
using namespace std;

template <typename Type>
struct node
{
    const Type data;
    node<Type>* next;
};

template <typename Type>
node<Type>* filter(node<Type>* first) {
    if (first == nullptr) {
        return nullptr;
    }
    Type firstValue = first->data;
    node<Type>* current = first -> next;
    node<Type>* previous = first;

    while (current != nullptr) {
        if (current -> data == firstValue) {
            node<Type>* nextNode = current -> next;
            delete current;
            previous -> next = nextNode;
            current = nextNode;
        }else {
            previous = current;
            current = current -> next;
        }
    }

    return first;
}

int main() {
    node<int>* n4 = new node<int>{3, nullptr};
    node<int>* n3 = new node<int>{1, n4};
    node<int>* n2 = new node<int>{2, n3};
    node<int>* n1 = new node<int>{1, n2};  // head

    node<int>* filtered = filter(n1);

    // Print result
    node<int>* curr = filtered;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "null\n";

    // Free memory
    curr = filtered;
    while (curr) {
        node<int>* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}