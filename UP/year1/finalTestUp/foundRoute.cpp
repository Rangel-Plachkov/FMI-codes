#include<iostream>
using namespace std;
int maxVolume = 10;
int homeRow = 1,homeColumn = 1;
int grannyRow = 4,grannyColumn = 3;
int matrixSize;
bool **matrixPassed;
int **matrix; //не използвам име "map" защото ми го дава като запазена дума
void output(){
    for(int x=0;x<matrixSize;x++){
        for(int y=0;y<matrixSize;y++){
            cout<<matrix[x][y]<<"  ";
        }
        cout<<endl;
    }
}
void input(){
    cout<<"map size: ";
    cin>>matrixSize;
    matrix = new int *[matrixSize];
    for(int x = 0; x<matrixSize; x++){
        matrix[x] = new int [matrixSize];
        for(int y =0; y<matrixSize; y++){
            cin>>matrix[x][y];
        }
    }
    matrixPassed = new bool *[matrixSize];
    for(int x=0;x<matrixSize;x++){
        matrixPassed[x] = new bool [matrixSize];
        for(int y=0;y<matrixSize;y++){
            matrixPassed[x][y]=0;
        }
    }
    cout<<"home position (row , column): ";
    cin>>homeRow>>homeColumn;
    if(homeRow >= matrixSize || homeColumn >= matrixSize){
        cout<<"invalidInput"<<endl;
        input();
    }
    cout<<"granny position (row , column): ";
    cin>>grannyRow>>grannyColumn;
    if(homeRow >= matrixSize || homeColumn >= matrixSize){
        cout<<"invalidInput"<<endl;
        input();
    }
    cout<<"max volume:";
    cin>>maxVolume;
}
bool finishedMatrixCheck(){
    for(int x=0;x<matrixSize;x++){
        for(int y=0; y<matrixSize;y++){
            if(matrix[x][y] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int cellCheck(int x,int y, int volume){
    if(matrixPassed[x][y]== 1){
        return 0;
    }else{
        matrixPassed[x][y] = 1;
    }
    volume = volume + matrix[x][y];
    matrix[x][y] = 0;
    if(x == grannyRow && y == grannyColumn){
        if(finishedMatrixCheck()){
            cout<<"true";
            return 1;
        }else{
            return 0;
        }

    }
    if(volume > maxVolume || volume < 0){
        return 0;
    }else{
        if(x>0){
            if(matrix[x-1][y] != 0){
                cellCheck(x-1,y,volume);
            }
        }
        if(x<matrixSize-1){
            if(matrix[x+1][y] != 0){
                cellCheck(x+1,y,volume);
            }
        }
        if(y>0){
            if(matrix[x][y-1] != 0){
                cellCheck(x,y-1,volume);
            }
        }
        if(y<matrixSize-1){
            if(matrix[x][y+1] != 0){
                cellCheck(x,y+1,volume);
            }
        }
    }
}

int main(){
    input();
    cellCheck(homeRow,homeColumn,0);
    //output();
    for(int x=0; x<matrixSize;x++){
        delete [] matrix[x];
        delete [] matrixPassed[x];
    }
    delete [] matrix;
    delete [] matrixPassed;
}
