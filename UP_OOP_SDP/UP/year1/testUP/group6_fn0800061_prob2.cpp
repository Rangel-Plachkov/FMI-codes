#include<iostream>
using namespace std;
bool susedstcoCheck(int vhod){
    while(vhod>0){
        if(vhod%10 == (vhod/10)%10){
            return false;
        }
        vhod=vhod/10;
    }
    return  true;

}
int main(){
    int a,b;
    int susedsvoA = 11 ,susedstvoB = 11 ;
    cin>>a>>b;
    for(int i=a; i<=b; i++){
        if(susedstcoCheck(i) == true){
            susedsvoA=i;
            break;
        }
    }
    for(int i=b; i>=a; i--){
        if(susedstcoCheck(i) == true){
            susedstvoB=i;
            break;
        }
    }
    if(susedsvoA == 11 || susedstvoB == 11){
        cout<<"No adjacent numbers!";
    }else{
        cout<<susedstvoB-susedsvoA;
    }
}
