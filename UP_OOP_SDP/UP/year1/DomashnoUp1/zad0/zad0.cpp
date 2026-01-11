#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x,y;
    bool inCircle;
    int kvadrant=0;
    cin>>x>>y;
    if(sqrt(pow(x,2)+pow(y,2)) < 4){
        inCircle = true;

    }else{
        inCircle = false;
    }
    if(x>0 && y>0){
        kvadrant = 1;
    }
    if(x<0 && y>0){
        kvadrant = 2;
    }
    if(x<0 && y<0){
        kvadrant = 3;
    }
    if(x>0 && y<0){
        kvadrant = 4;
    }
    ///Green
    if(kvadrant == 1 && inCircle && x < y && x != y){
        cout<<"Green";
        return 0;
    }
    ///Red
    if(kvadrant == 2 && inCircle && x*(-1) < y){
        cout<<"Red";
        return 0;
    }
    ///Sin
    if(kvadrant == 3 && inCircle && x > y){
        cout<<"Blue";
        return 0;
    }
    ///Rozovo
    if(kvadrant == 3 && inCircle && x > sqrt(8)*(-1) && x*(-1) > y ){
        cout<<"Pink";
        return 0;
    }
    if(kvadrant == 4 && inCircle && x > sqrt(8)*(-1) && x < y ){
        cout<<"Pink";
        return 0;
    }
    ///Jult
    if(kvadrant == 4 && inCircle && x<=y*(-1) ){
        cout<<"Yellow";
        return 0;
    }
    if(kvadrant == 4 && inCircle && x>y*(-1) &&x<sqrt(8) ){
        cout<<"Yellow";
        return 0;
    }
    if(kvadrant == 1 && inCircle && x>y &&x<sqrt(8) ){
        cout<<"Yellow";
        return 0;
    }
    ///Lilav
    if(inCircle &&x>sqrt(8) ){
        cout<<"Purple";
        return 0;
    }
    ///Siv
    if(x>-2 && x<2 && y>-7 && y<-6){
        cout<<"Grey";
        return 0;
    }
    cout<<"Nowhere";
}
