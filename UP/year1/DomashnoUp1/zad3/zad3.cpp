#include<iostream>
using namespace std;
bool proverkaInteresno (int vhod){
    int lastNumber = vhod%2;
    vhod=vhod/10;
    while(vhod>0){
       if(vhod%2 == lastNumber){
            return false;
       }else{
            lastNumber = vhod%2;
            vhod=vhod/10;
       }
    }
    return true;

}
int main(){
    int a , b;
    int suma = 0;
    cin>>a>>b;
    for(int i=a; i<=b; i++){
        if(proverkaInteresno(i) == true){
            suma = suma + i;
        }
    }
    cout<<suma;
}
