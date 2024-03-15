///ZAD0
//##############################################################
/*
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
///ZAD1
//##########################################################
/*
#include <iostream>
using namespace std;
int main(){
    const int functionN = 36;
    int result[functionN];
    cin >> result[0];
    for (int f = 1; f < functionN; f++)
    {
        if (result[f - 1] % 2 == 0)
        {
            result[f] = result[f - 1] / 2;
        }
        else
        {
            result[f] = (result[f - 1] * 3) + 1;
        }
    }
    cout << "f35 = "<< result[functionN - 1] << endl;
}
*/
///ZAD2
//############################################################
/*
#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int borovinki = 0, praskovi = 0, shipka = 0;
    int kodVid = 0;
    for(int i=0; i<N; i++){
        int vhod;
        cin>>vhod;
        switch(i%8){
            case 3:
                kodVid = kodVid + (vhod*1000);
                break;
            case 4:

                kodVid = kodVid + (vhod*100);
                break;
            case 5:

                kodVid = kodVid + (vhod*10);
                break;
            case 6:

                kodVid = kodVid + (vhod*1);
                break;
            case 7:
                if (kodVid % 7 == 0){
                    borovinki++;
                }else{
                    if (kodVid % 13 == 0){
                        praskovi++;
                    }else{
                        if (kodVid % 17 == 0){
                            shipka++;
                        }
                    }
                }
                kodVid = 0;
                break;
            default:
                break;
        }
    }

    cout<<"Marmalad ot borovinki: "<<borovinki<<endl;
    cout<<"Marmalad ot praskovi: " <<praskovi<<endl;
    cout<<"Shipkov marmalad: : "<<shipka<<endl;
}
*/
///ZAD3
//################################################################
/*
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
*/
///ZAD4
//####################################################################
/*
#include<iostream>
#include<cmath>
using namespace std;
const int lengt = 4;
int getBullsnCows(int number, int secretNumber){
    int cows = 0;
    int bulls = 0;
    for(int i=0; i<lengt; i++){
        for(int j=0; j<lengt; j++){
            int delimo = pow(10 ,j);
            if(number%10 == (secretNumber/delimo)%10){
                if(j == i){
                    bulls++;
                }else{
                    cows++;
                }
            }
        }
        number = number / 10;
    }
    //Формулата ще ми позволи да изпращам с числото с една функция
    //На първа позиция ще стоят кравите
    //На втора позиция ще стоят биковете
    int formula = bulls + cows*10;
    return formula;
}
int printAnswer (int formula){
    cout<<"bulls: ";
    cout<<formula%10<<endl;
    cout<<"cows: ";
    cout<<(formula/10)%10<<endl;
}

int main(){
    const int N = 10;
    int SecretNumber = 1234;
    int guessNumber;
    bool PlayerWin = false;
    for(int i=0; i<N; i++){
        cin>>guessNumber;
        int formula = getBullsnCows(guessNumber ,SecretNumber);
        if(formula % 10 == lengt){
            PlayerWin = true;
            cout<<"\nPlayer win in "<<i+1<<" move(s)"<<endl;
            break;
        }
        printAnswer(formula);
    }

    if (PlayerWin == false){
        cout<<"\nComputer win"<<endl;
        cout<<"The secret number is: "<<SecretNumber<<endl;
    }
}
*/
