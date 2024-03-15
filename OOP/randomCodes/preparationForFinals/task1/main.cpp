#include<iostream>
//#include"Dossier/Dossier.h"
#include"Dossier/Dossier.cpp"


int main(){
    Encoder A('a' , 1);
    Encoder B('b' , 31);
    Encoder C('c' , 2);
    Dossier Dos;
    
    Dos.addRow(A);

    Dos.addRow(B);
    Dos.addRow(C);
    
    Dos.setText("ababcabA");
    Dos.printText();

}