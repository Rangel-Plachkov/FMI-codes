#include <iostream>
#include <string>

struct Node {
    std::string text;
    Node* next = nullptr;

    Node() = default;
    Node(std::string newText) : text(std::move(newText)) {}
    Node(std::string newText, Node* newPtr) : text(std::move(newText)), next(newPtr) {}

    void concatNext() {
        if (next == nullptr || next == this)
            return;

        text += '-';
        text += next->text;
        Node* temp = next->next;
        delete next;
        next = temp;
    }

    char getFisrtSym() const { return text[0]; }
    char getLastSym() const { return text[text.size() - 1]; }
};

size_t cylceLinkedListLen(const Node* start_ptr) {
    if (start_ptr == nullptr)
        return 0;

    const Node* iter = start_ptr;
    size_t size = 1;
    while (iter->next != start_ptr) {
        iter = iter->next;
        size++;
    }
    return size;
}

void unite(Node* list_ptr) {
    if (list_ptr == nullptr)
        return;

    size_t listSize = cylceLinkedListLen(list_ptr);

    Node* currPtr = list_ptr;
    size_t i = 0;

    while (i < listSize) {
        Node* nextPtr = currPtr->next;
        if (currPtr != nextPtr && currPtr->getLastSym() == nextPtr->getFisrtSym()) {
            currPtr->concatNext();
            listSize--; // One node removed
            // Do NOT move currPtr — check new currPtr->next again
        } else {
            currPtr = currPtr->next;
            i++; // advance only if no merge
        }
    }
}


void printCylceList(const Node* listPtr){
    if(listPtr == nullptr)
        return;

    const Node* iter = listPtr;
    do{
        std::cout<<iter->text<<'\n';
        iter = iter->next;
    }while(iter != listPtr);
}

int main() {
    // Create nodes dynamically
    Node* a = new Node("street");
    Node* b = new Node("taxi");
    Node* c = new Node("ink");
    Node* d = new Node("dog");
    Node* e = new Node("smile");
    Node* f = new Node("eat");
    Node* g = new Node("tall");
    Node* h = new Node("pass");

    // Link nodes into a cyclic list
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = a;

    // Perform the unite operation
    //printCylceList(a);
    //a->concatNext();
    //h->concatNext();
    unite(a);
    printCylceList(h);

    return 0;
}
