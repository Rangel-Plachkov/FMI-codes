#include<iostream>
#include<cassert>

const unsigned MAX_SIZE = 50;

void inputMatr(int& size, char (&matr)[MAX_SIZE][MAX_SIZE]){
    std::cin>>size;
    for(int x=0; x<size; x++){
        for(y=0; y<size; y++){
            std::cin>>matr[x][y];
        }
    }
}
bool findWord(const char (&matr)[MAX_SIZE][MAX_SIZE],char* word, int matrSize, int startX, int startY){
    if(startX <0 || startX >= MAX_SIZE || startY < 0 || startY >= MAX_SIZE){
        return false;
    }
    if(word[0] == matr[startX][startY]){
        return findWord(matr, word[1], matrSize, startX-1, startY-1) ||
                findWord(matr, word[1], matrSize, startX-1, startY+1) ||
                findWord(matr, word[1], matrSize, startX+1, startY-1) ||
                findWord(matr, word[1], matrSize, startX+1, startY+1);
    }else{
        return false;
    }
}


int main(){
    char matr[MAX_SIZE][MAX_SIZE];
}