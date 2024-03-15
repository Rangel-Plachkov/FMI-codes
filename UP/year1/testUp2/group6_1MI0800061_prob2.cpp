#include<iostream>
#include<cstring>
using namespace std;
int matrix [31][31];
int n;
void printMatrix(){
    for(int x=0; x<n;x++){
        for(int y=0; y<n; y++){
            cout<<matrix[x][y]<<" ";
        }
        cout<<endl;
    }
}
void inputMatrix(){
    for(int i=n-1; i>=0;i--){
        for(int j=0;j+i<n;j++){
            //cout<<i+j<<" "<<j;
            cin>>matrix[i+j][j];
            //cout<<endl;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0; j+i<n; j++){
            //cout<<i+j<<" "<<j;
            cin>>matrix[j][i+j];
            //cout<<endl;
        }
    }
}
bool checkSameDigits(int number){
    bool findDigits[10];
    for(int i=0; i<10;i++){
        findDigits[i] = 0;
    }
    while(number>0){
        if( findDigits[number%10] == 0){
            findDigits[number%10] =1;
        }else{
            return true;
        }
        number = number/10;
    }
    return false;
}

int* collect(int n, int matrix[31][31]){
    int i=0;
    //int* output[n*n];
    //int *output[10]; //= new int(matrix[x][y]);
    int *output = new int[n*n];
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if ( checkSameDigits(matrix[x][y]) ){
                //cout<<matrix[x][y]<<endl;
                //*output[i] = new int(matrix[x][y]);
                *output = matrix[x][y];
                output++;
            }
        }
    }
    return output;
}
int main(){
    cin>>n;
    int *arr[10];
    //cout<<checkSameDigits(n);
    inputMatrix();
    *arr = collect(n , matrix);
    for(int i=0 ; i<n*n ; i++){
        cout<<*arr[i];
        delete arr[i];
    }
    //printMatrix();
}
