#include<iostream>
#include<cstring>
const int MAX_STR_SIZE = 512;

int numLen(int number){
    int res=1;
    while(number>9){
        res++;
        number /= 10;
    }
    return res;
}
unsigned int getCount(char (&str)[MAX_STR_SIZE] , char sym){
    unsigned int count = 0;
    for(int i=0; i<MAX_STR_SIZE; i++){
        if(str[i] == sym){
            count++;
        }
    }
    return count;
}
void replaceCount(char (&str)[MAX_STR_SIZE] , char sym){
    unsigned int symCount = getCount(str,sym);
    int moveForw = numLen(symCount) -1;
    int currSize = strlen(str);
    for(int i=0; i<currSize; i++){
        if(str[i] == sym){
            if(moveForw == 0){
                str[i] = symCount + '0';
            }else{
                currSize += moveForw;
                for(int j = currSize; j>i; j--){
                    str[j] = str[j-moveForw];
                }

                if(moveForw == 1){
                    str[i+1] = symCount%10 +'0';
                    str[i] = (symCount/10)%10 +'0';
                }else{
                    str[i+2] = symCount%10 +'0';
                    str[i+1] = (symCount/10) %10 +'0';
                    str[i] = (symCount/100)%10 +'0';
                }
            }
            
            i += moveForw;
        }
    }
}


bool willItFit(char (&str)[MAX_STR_SIZE]){
    int size = strlen(str);
    int newSize = size;
    for(char sym = 'A' ; sym <= 'Z'; sym++){
        int count = 0;
        for(int i=0; i<size; i++){
            if(str[i] == sym){
                count++;
            }
        }
        if(count > 9){
            newSize++;
        }
        if(count > 100){
            newSize++;
        }
    }
    return newSize < MAX_STR_SIZE;
}
bool isValid(char (&str)[MAX_STR_SIZE]){
    int size = strlen(str);
    for(int i=0 ;i<size; i++){
        if( !(str[i] >= 'A' && str[i] <='Z') ){
            return false;
        }
    }
    return true;
}

bool convertToStrNumber(char (&str)[MAX_STR_SIZE]){
    if( !isValid(str) ){
        std::cout<<"Invalid string"<<std::endl;
        return false;
    }else if( !willItFit(str) ){
        return false;
    }

    for(char sym = 'A'; sym <= 'Z'; sym++){
        //std::cout<<sym<<std::endl;
        replaceCount(str,sym);
    }
    return true;
}

int main(){
    char str[MAX_STR_SIZE];
    strcpy(str, "AAABCAADCSMAABBBBSAAACC");
    //strcpy(str, "AAAAAAAAAAB");
    convertToStrNumber(str);
    std::cout<<str;
}