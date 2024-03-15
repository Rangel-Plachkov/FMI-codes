#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int stringlenght;
unsigned longestSequence (char* s){
    int longest=INT_MIN;
    int current = 1;
    char currentSymbol=s[0];
    for(int i=1;i<=stringlenght;i++){
        if(currentSymbol == s[i]){
            current = current + 1;
        }else{
            if(current>longest){
                longest = current;
            }
            current = 1;
            currentSymbol = s[i];
        }
    }
    return longest;
}

int main(){
char *sequence = new char[100];
cin.ignore();
cin.getline(sequence ,INT_MAX);
stringlenght = strlen(sequence);
cout<<longestSequence(sequence);
delete [] sequence;
}
//char **matrix; //GLOBAL
/*
matrix = new char*[N];
    for(int x=0; x<N; x++){
        matrix[x] = new char[M];
        for(int y=0; y<M; y++){
            cin>>matrix[x][y];
        }
    }
*/
/*for( int x = 0; x<N; x++){
        delete [] matrix[x];
    }
delete [] matrix;*/
