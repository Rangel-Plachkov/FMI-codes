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
