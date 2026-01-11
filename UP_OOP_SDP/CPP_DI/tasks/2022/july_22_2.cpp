#include<iostream>


class A {
public:
    A() { std::cout << "A()\n"; }
    A(A&) { std::cout << "A(A&)\n"; }
    virtual ~A() { std::cout << "~A()\n"; }
    A& operator=(A&) {
        std::cout << "op=(A&)\n";
        return *this;
    }
};
class B : public A {
public:
    B() { std::cout << "B()\n"; }
    B(B&) { std::cout << "B(B&)\n"; }
    virtual ~B() { std::cout << "~B()\n"; }
    B& operator=(B&) {
        std::cout << "op=(B&)\n";
        return *this;
    }
};
void f(A b) { std::cout << "f(A)\n"; }

int main(){
    B d;
    std::cout<<"##########\n";
    B copy = d;
    std::cout<<"############\n";
    A b = d;
    std::cout<<"############\n";
    A& ref = d;
    std::cout<<"############\n";
    B arr[2];
    std::cout<<"############\n";
    f(d);
    std::cout<<"############\n";
    A* p = new B(d);
    std::cout<<"############\n";
    delete p;
    std::cout<<"############\n";
    d = d;
    std::cout<<"############\n";
    ref = d;
    std::cout<<"############\n";
}