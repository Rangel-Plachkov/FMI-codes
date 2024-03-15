#include<iostream>
#include<cstring>
const unsigned int ROW_SIZE =1024;

int rowRec(char (&row)[ROW_SIZE], unsigned int curr, int moves){
    if( curr >= ROW_SIZE || row[curr] == '\0'){
        return moves-1;
    }else if(row[curr] == 'g'){
        return rowRec(row, curr+1 , moves+1);

    }else if(row[curr] == 'y'){
        while(curr < ROW_SIZE){
            if(row[curr] == 'g'){
                break;
            }
            curr++;
        }
        return rowRec(row, curr , moves+1);
    }else if(row[curr] == 'r'){
        return moves;
    }
    return -1;
}
bool getInput(char (&row)[ROW_SIZE] ){
    std::cin.getline(row,ROW_SIZE);
    for(int i=0; i<ROW_SIZE;i++){
        if(row[i] == '\0'){
            break;
        }else if(!(row[i] == 'r' || row[i] == 'y' || row[i] == 'g')){
            return false;
        }
    }
    return true;
}
int findMax(char (&row)[ROW_SIZE]){
    unsigned int rowLen = strlen(row);
    int max = 0;
    for(int i=0; i<rowLen ; i++){
        int curr = rowRec(row,i,0);
        if(curr > max){
            max = curr;
        }
    }
    return max;
}
int main(){
    char row[ROW_SIZE];
    if( !getInput(row) ){
        std::cout<<"Invalid input!";
        return 0;
    }
    //ggrrgyrgyr
    //rgyrggrygr
    std::cout<<findMax(row);
}