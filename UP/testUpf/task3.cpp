#include<iostream>

const unsigned int MAX_N = 102;

int getRing(const int (&matr)[MAX_N][MAX_N], unsigned size, unsigned start){
    unsigned toFinnish = size - start;
    int sum = 0;
    for(unsigned i=start; i<toFinnish; i++){
        sum += matr[start][i];
        sum += matr[size-start-1][i];
        sum += matr[i][start];
        sum += matr[i][size - start -1];
    }
    sum -= matr[start][start];
    sum -= matr[start][toFinnish-1];
    sum -= matr[toFinnish-1][start];
    sum -= matr[toFinnish-1][toFinnish-1];
    return sum;
}
void inputMatr(int (&matr)[MAX_N][MAX_N], unsigned& size){
    std::cin>>size;
    for(unsigned x=0; x<size; x++){
        for(unsigned y=0; y<size; y++){
            std::cin>>matr[x][y];
        }
    }
}

void hardcodeInput(int (&matr)[MAX_N][MAX_N], unsigned& size){
    /*
    size = 6;
    matr[0][0] = -1;
    matr[0][1] = -1;
    matr[0][2] = -1;
    matr[0][3] = -1;
    matr[0][4] = -1;
    matr[0][5] = -1;

    matr[1][0] = -1;
    matr[1][1] = 0;
    matr[1][2] = 0;
    matr[1][3] = 0;
    matr[1][4] = 0;
    matr[1][5] = -1;

    matr[2][0] = -1;
    matr[2][1] = 0;
    matr[2][2] = 1;
    matr[2][3] = 1;
    matr[2][4] = 0;
    matr[2][5] = -1;
    
    matr[3][0] = -1;
    matr[3][1] = 0;
    matr[3][2] = 1;
    matr[3][3] = 1;
    matr[3][4] = 0;
    matr[3][5] = -1;

    matr[4][0] = -1;
    matr[4][1] = 0;
    matr[4][2] = 0;
    matr[4][3] = 0;
    matr[4][4] = 0;
    matr[4][5] = -1;

    matr[5][0] = -1;
    matr[5][1] = -1;
    matr[5][2] = -1;
    matr[5][3] = -1;
    matr[5][4] = -1;
    matr[5][5] = -1;
    */
   
    size = 6;
    matr[0][0] = 1;
    matr[0][1] = 0;
    matr[0][2] = 2;
    matr[0][3] = -3;
    matr[0][4] = 5;
    matr[0][5] = -2;

    matr[1][0] = -5;
    matr[1][1] = 8;
    matr[1][2] = 2;
    matr[1][3] = 5;
    matr[1][4] = -2;
    matr[1][5] = 1;

    matr[2][0] = 1;
    matr[2][1] = 10;
    matr[2][2] = 5;
    matr[2][3] = 8;
    matr[2][4] = 0;
    matr[2][5] = 0;
    
    matr[3][0] = 0;
    matr[3][1] = 3;
    matr[3][2] = 2;
    matr[3][3] = 5;
    matr[3][4] = 4;
    matr[3][5] = -3;

    matr[4][0] = 2;
    matr[4][1] =0;
    //matr[4][1] = -14;
    matr[4][2] = -7;
    matr[4][3] = 5;
    matr[4][4] = 6;
    matr[4][5] = 3;

    matr[5][0] = 10;
    matr[5][1] = 2;
    matr[5][2] = 0;
    matr[5][3] = 2;
    matr[5][4] = 3;
    matr[5][5] = 1;
    

}

int task3(const int (&matr)[MAX_N][MAX_N], unsigned size){
    unsigned ringCount = size/2;
    int centerSum = getRing(matr, size, ringCount-1);

    for(unsigned i=0; i<ringCount;i++){
        int tempSum = getRing(matr, size,i);
        if(tempSum != centerSum){
            std::cout<<"( "<< size- i -1 << " , " <<size - i -1 <<" )"<<std::endl;
            return 0;
        }
    }
    return -1;
}

int main(){
    int matr[MAX_N][MAX_N];
    unsigned int size;
    inputMatr(matr,size);
    //hardcodeInput(matr,size);
    std::cout<<task3(matr,size);
}