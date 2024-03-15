#include<iostream>
#include<exception>
const size_t MAX_MATRIX_SIZE = 32;

void putWordIn(char word[100], char* adr){
    if(adr == nullptr){
        //throw std::exception("Invalide addres");
        return;
    }
    for(size_t i=0; i<MAX_MATRIX_SIZE;i++){
        adr[i] = word[i];
    }
}

void inputIn(char mat[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],const size_t x, const size_t y){
    if(x>MAX_MATRIX_SIZE || y> MAX_MATRIX_SIZE){
        throw std::exception("Invalid cordinates");
        return;
    }
    char word[MAX_MATRIX_SIZE];
    std::cin.getline(word,MAX_MATRIX_SIZE,'\n');

    putWordIn(word,mat[x][y]);
}
void resetMatrix(char mat[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE][MAX_MATRIX_SIZE]){
    for(size_t x=0; x<MAX_MATRIX_SIZE;x++){
        for(size_t y=0; y<MAX_MATRIX_SIZE;y++){
            mat[x][y][0] = '/0';
        }
    }
}
/*
void printMat(char mat[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE][MAX_MATRIX_SIZE]){

    for(size_t x=MAX_MATRIX_SIZE-1, x>0; x--){
        for(size_t y=0; y<MAX_MATRIX_SIZE,y++){
            //if()
        }

    }
}
*/

int main(){
    char matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    
    putWordIn("banan",matrix[0][0]);
    putWordIn("zele",matrix[0][1]);
    putWordIn("portokal",matrix[0][2]);
    putWordIn("qgoha",matrix[1][0]);
    putWordIn("madrarina",matrix[1][2]);

    
}