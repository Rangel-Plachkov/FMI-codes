#include<iostream>
#include<cstring>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_SIZE = 10;
const int MIN_SIZE = 3;

const char MINE_SYM = '*';
const char HIDDEN_TILE_SYM = '.';
const char FLAG_SYM = 'X';
const char BORDER_SYM = '#';

const size_t MAX_INPUT_SIZE = 64;


size_t getInutSize(){
    int result;
    std::cout<<"Size of matrix: ";
    std::cin>>result;
    while ( result > MAX_SIZE || result < MIN_SIZE ){
        std::cout<<"Invalide size, try again: : ";
        std::cin>>result;
    }
    return result;
}
size_t getBombCount(const int N){
    int result;
    std::cout<<"Bomb count: ";
    std::cin>>result;
    while ( result > 3*N || result < 0 ){
        std::cout<<"Invalide bomb count, try again: : ";
        std::cin>>result;
    }
    return result;
}
void drawMatrix(const char matrix[MAX_SIZE][MAX_SIZE] ,const size_t size){
    std::cout<<std::endl;
    for(size_t i=0; i<size+2; i++){
        std::cout<<BORDER_SYM;
    }
    std::cout<<std::endl;
    std::cout<<'#';
    for(size_t x = 0; x<size; x++){
        for(size_t y=0; y<size; y++){
            if(matrix[x][y] == '0'){
                std::cout<<' ';
            }else{
                std::cout<<matrix[x][y];
            }
        }
        std::cout<<BORDER_SYM;
        std::cout<<std::endl;
        std::cout<<BORDER_SYM;
    }
    for(size_t i=0; i<size+1; i++){
        std::cout<<BORDER_SYM;
    }
}
void resetMatrix(char matrix[MAX_SIZE][MAX_SIZE],const size_t size,const char defaultSym){
    for(size_t x =0; x<size; x++){
        for(size_t y = 0; y <size; y++){
            matrix[x][y] = defaultSym;
        }
    }
}
void addMines(bool matrix[MAX_SIZE][MAX_SIZE],const size_t size,const size_t minesCount){
    for(size_t x=0; x<size; x++){
        for(size_t y=0; y<size; y++){
            matrix[x][y]=false;
        }
    }
    srand (time(NULL));
    for(size_t i=0; i<minesCount; i++){
        int x = rand() % size;
        int y = rand() % size;
        if(matrix[x][y]){
            i--;
        }else{
            matrix[x][y] = true;
        }
    }

}
char revealPosition(const bool minesMatrix[MAX_SIZE][MAX_SIZE],const size_t size, const size_t posX, const size_t posY ){
    if( minesMatrix[posX][posY] ){
        return MINE_SYM;
    }
    size_t count = 0;
    if(posX == 0){
        if(posY == 0){
            count = ( minesMatrix[posX+1][posY] + minesMatrix[posX][posY+1] + minesMatrix[posX+1][posY+1]  );
        }else if(posY == size-1){
            count = ( minesMatrix[posX+1][posY] + minesMatrix[posX][posY-1] + minesMatrix[posX+1][posY-1]  );
        }else{
            count = (   minesMatrix[posX][posY-1] + minesMatrix[posX][posY+1] + 
                        minesMatrix[posX+1][posY-1] + minesMatrix[posX+1][posY] + minesMatrix[posX+1][posY+1] );
        }
    }else if(posX == size-1){
        if(posY == 0){
            count = ( minesMatrix[posX-1][posY] + minesMatrix[posX][posY+1] + minesMatrix[posX-1][posY+1]  );
        }else if(posY == size-1){
            count = ( minesMatrix[posX-1][posY] + minesMatrix[posX][posY-1] + minesMatrix[posX-1][posY-1]  );
        }else{
            count = ( minesMatrix[posX][posY-1] + minesMatrix[posX][posY+1] + 
            minesMatrix[posX-1][posY-1] + minesMatrix[posX-1][posY] + minesMatrix[posX-1][posY+1] );
        }
    }else{
        if(posY == 0){
            count = ( minesMatrix[posX-1][posY] + minesMatrix[posX+1][posY] +
            minesMatrix[posX-1][posY+1] + minesMatrix[posX][posY+1] + minesMatrix[posX+1][posY+1] );
        }else if(posY == size-1){
            count = ( minesMatrix[posX-1][posY] + minesMatrix[posX+1][posY] +
            minesMatrix[posX-1][posY-1] + minesMatrix[posX][posY-1] + minesMatrix[posX+1][posY-1] );
        }else{
            count = ( minesMatrix[posX-1][posY-1] + minesMatrix[posX-1][posY]+ minesMatrix[posX-1][posY+1] +
                    minesMatrix[posX][posY-1] + minesMatrix[posX][posY+1] +
                    minesMatrix[posX+1][posY-1] + minesMatrix[posX+1][posY] + minesMatrix[posX+1][posY+1]);
        }
    }
    return count + '0';
}
void revealRecusion(char visMatrix[MAX_SIZE][MAX_SIZE],const bool minesMatrix[MAX_SIZE][MAX_SIZE],const size_t size, const size_t posX, const size_t posY){
    if(visMatrix[posX][posY] != HIDDEN_TILE_SYM && visMatrix[posX][posY] != FLAG_SYM){
        return;
    }
    visMatrix[posX][posY] = revealPosition(minesMatrix,size,posX,posY);
    if( visMatrix[posX][posY] != '0'){
        return;
    }
    if(posX == 0){
        if(posY == 0){
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY+1);
        }else if(posY == size-1){
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY-1);
        }else{
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY-1);
        }
    }else if(posX == size-1){
        if(posY == 0){
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY+1);
        }else if(posY == size-1){
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY-1);
        }else{
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY-1);
        }
    }else{
        if(posY == 0){
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY+1);
        }else if(posY == size-1){
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY-1);
        }else{
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX-1,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX,posY+1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY-1);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY);
            revealRecusion(visMatrix,minesMatrix,size,posX+1,posY+1);
        }
    }
}
void flag(char visMatrix[MAX_SIZE][MAX_SIZE],const size_t posX, const size_t posY){
    if(visMatrix[posX][posY] == HIDDEN_TILE_SYM){
        visMatrix[posX][posY] = FLAG_SYM;
    }
}
void unmark(char visMatrix[MAX_SIZE][MAX_SIZE],const size_t posX, const size_t posY){
    if(visMatrix[posX][posY] == FLAG_SYM){
        visMatrix[posX][posY] = HIDDEN_TILE_SYM;
    }else{
        std::cout<<"Already unmarked tile"<<std::endl;
    }
}
bool open(char visMatrix[MAX_SIZE][MAX_SIZE],const bool minesMatrix[MAX_SIZE][MAX_SIZE],const size_t size,const size_t posX, const size_t posY){
    if(minesMatrix[posX][posY]){
        return false;
    }
    revealRecusion(visMatrix,minesMatrix,size,posX,posY);
    return true;
}
void getCord(int& cord,const int size){
    std::cin>>cord;
    if(cord >= size || cord<0){
        cord = -1;
    }
}
bool winCond(char visMatrix[MAX_SIZE][MAX_SIZE],const size_t size,const size_t bombCount){
    size_t count = 0;
    for(size_t x=0; x<size;x++){
        for(size_t y=0; y<size;y++){
            if(visMatrix[x][y] == HIDDEN_TILE_SYM){
                count++;
            }
        }
    }
    return count==bombCount;
}
bool getCommand(char visMatrix[MAX_SIZE][MAX_SIZE],const bool minesMatrix[MAX_SIZE][MAX_SIZE] ,const size_t size){
    char command[MAX_INPUT_SIZE];
    int posX,posY;
    std::cin.getline(command,MAX_INPUT_SIZE,' ');
    //std::cout<<command;
    if(strstr(command, "open") == command){
        getCord(posX,size);
        getCord(posY,size);
        std::cin.ignore();
        return open(visMatrix,minesMatrix,size,posX,posY);

    }else if(strcmp(command, "mark") == 0){
        getCord(posX,size);
        getCord(posY,size);
        std::cin.ignore();
        flag(visMatrix,posX,posY);
        return true;

    }else if (strcmp(command,"unmark") == 0){
        getCord(posX,size);
        getCord(posY,size);
        std::cin.ignore();
        unmark(visMatrix,posX,posY);
        return true;
    }else{
        std::cin.ignore();
        return true;
    }
    
    
}
void revealBombs(char visMatrix[MAX_SIZE][MAX_SIZE], bool minesMatrix[MAX_SIZE][MAX_SIZE]){
    for(size_t x=0; x<MAX_SIZE;x++){
        for(size_t y=0 ;y<MAX_SIZE;y++){
            if(minesMatrix[x][y] == 1){
                visMatrix[x][y] = MINE_SYM;
            }
        }
    }
}
void play(){
    const size_t N = getInutSize();
    const size_t bombCount = getBombCount(N);
    //size_t N = 10,bombCount = 10;
    bool minesMatrix[MAX_SIZE][MAX_SIZE];
    char visibleMatrix[MAX_SIZE][MAX_SIZE];
    addMines(minesMatrix,N,bombCount);
    resetMatrix(visibleMatrix,N,HIDDEN_TILE_SYM);
    
    std::cin.ignore();
    while(true){
        drawMatrix(visibleMatrix,N);
        std::cout<<std::endl;
        
        if( getCommand(visibleMatrix,minesMatrix,N) == false){
            revealBombs(visibleMatrix,minesMatrix);
            drawMatrix(visibleMatrix,N);

            std::cout<<std::endl<<"YOU LOST"<<std::endl;
            break;
        }else if(winCond(visibleMatrix,N,bombCount)){
            revealBombs(visibleMatrix,minesMatrix);
            drawMatrix(visibleMatrix,N);
            std::cout<<std::endl<<"YOU WIN"<<std::endl;
            break;
        }
    }
    
}

int main(){
    play();
}