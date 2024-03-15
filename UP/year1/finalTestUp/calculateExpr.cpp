#include<iostream>
#include<cstring>
//char *row = new char;
int length;
///zero     4
///one      3
///two      3
///three    5
///four     4
///five     4
///six      3
///seven    5
///eight    5
///nine     4
///plus     4
///minus    5
using namespace std;

int pow(int a,int b){
    for(int i=0;i<b;i++){
        a=a*10;
    }
    return a;
}
int main(){
    char *row = new char[100];
    char *converted = new char[100];
    cin.getline(row , 100);
    int length = strlen(row);
    int convertedlenght=0;
    for(int i=0; i<length;i=i+0){
        if(row[i]=='z'){
            converted[convertedlenght]='0';
            convertedlenght++;
            i=i+4;
        }
        if(row[i]=='o'){
            converted[convertedlenght]='1';
            convertedlenght++;
            i=i+3;

        }
        if(row[i]=='t'){
            if(row[i+1]=='w'){
                converted[convertedlenght]='2';
                convertedlenght++;
                i=i+3;
            }else{
                converted[convertedlenght]='3';
                convertedlenght++;
                i=i+5;
            }
        }
        if(row[i]=='f'){
            if(row[i+1]=='o'){
                converted[convertedlenght]='4';
                convertedlenght++;
                i=i+4;
            }else{
                converted[convertedlenght]='5';
                convertedlenght++;
                i=i+4;
            }
        }
        if(row[i]=='s'){
            if(row[i+1]=='i'){
                converted[convertedlenght]='6';
                convertedlenght++;
                i=i+3;
            }else{
                converted[convertedlenght]='7';
                convertedlenght++;
                i=i+5;
            }
        }
        if(row[i]=='e'){
            converted[convertedlenght]='8';
            convertedlenght++;
            i=i+5;
        }
        if(row[i]=='n'){
            converted[convertedlenght]='9';
            convertedlenght++;
            i=i+4;
        }
        if(row[i]=='p'){
            converted[convertedlenght]='+';
            convertedlenght++;
            i=i+4;
        }
        if(row[i]=='m'){
            converted[convertedlenght]='-';
            convertedlenght++;
            i=i+5;
        }
    }
    if(converted[0] == '+' || converted[0] =='-'){
        cout<<"Incorect string";
        return 0;
    }
    if(converted[convertedlenght-1] == '+' || converted[convertedlenght-1] =='-'){
        cout<<"Incorect string";
        return 0;
    }
    for(int i=0;i<convertedlenght;i++){
        if(converted[i] == '+' || converted[i]=='-'){
            if(converted[i+1] == '+' || converted[i+1] == '-'){
                cout<<"Incorect string";
                return 0;
            }
        }
    }
    int numberA=0;
    int numberB=0;
    int p=1;
    bool operationPlus;
    for(int i=convertedlenght-1;i>=0;i--){
        if(converted[i]=='0'){
            numberA=numberA+pow(0,p);
            p++;
        }
        if(converted[i]=='1'){
            numberA=numberA+pow(1,p);
            p++;
        }
        if(converted[i]=='2'){
            numberA=numberA+pow(2,p);
            p++;
        }
        if(converted[i]=='3'){
            numberA=numberA+pow(3,p);
            p++;
        }
        if(converted[i]=='4'){
            numberA=numberA+pow(4,p);
            p++;
        }
        if(converted[i]=='5'){
            numberA=numberA+pow(5,p);
            p++;
        }
        if(converted[i]=='6'){
            numberA=numberA+pow(6,p);
            p++;
        }
        if(converted[i]=='7'){
            numberA=numberA+pow(7,p);
            p++;
        }
        if(converted[i]=='8'){
            numberA=numberA+pow(8,p);
            p++;
        }
        if(converted[i]=='9'){
            numberA=numberA+pow(9,p);
            p++;
        }
        if(converted[i]=='-'){
            if(operationPlus==1){
                numberB=numberB+numberA;
            }else{
                numberB=numberB-numberA;
            }

            p=1;
            numberA=0;
            operationPlus=0;
        }
        if(converted[i]=='+'){
            if(operationPlus==1){
                numberB=numberB+numberA;
            }else{
                numberB=numberB-numberA;
            }
            p=1;
            numberA=0;
            operationPlus=1;
        }

    }
    if(operationPlus==1){
                numberB=numberB+numberA;
    }else{
                numberB=numberB-numberA;
    }
    cout<<converted<<endl;
    cout<<numberB/10;
    delete [] row;
    delete [] converted;

}
