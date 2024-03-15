#include<iostream>
using namespace std;
struct complexNumber{
    double realPart;
    double imagineryPart;

};
void printComplex(const complexNumber& number){
    cout<<number.realPart<<" +i"<<number.imagineryPart<<endl;
}
complexNumber sum(const complexNumber& a ,const complexNumber& b){
    complexNumber result;
    result.realPart = a.realPart + b.realPart;
    result.imagineryPart = a.imagineryPart + b.imagineryPart;
    return result;

}
int main(){
    complexNumber a;
    complexNumber b;
    cout<<"complex Number A:";
    cin>>a.realPart>>a.imagineryPart;

    cout<<"complex Number B:";
    cin>>b.realPart>>b.imagineryPart;
    cout<<endl;

    printComplex(a);
    printComplex(b);

    complexNumber c = sum(a,b);
    printComplex(c);
}
