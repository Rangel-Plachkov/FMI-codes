///zad0
/*
#include<iostream>
#include<cstring>
using namespace std;
char inputText[1024][1024];
int textLenght;
int numberOfWords = 0;
void input(){
    cin>>textLenght;
    char *sentence = new char[textLenght];
    cin.getline(sentence, textLenght ,'\n');

    //int n=0;

    while(n<=textLenght){
        cin.getline(inputText[numberOfWords] ,textLenght);
        n=n+strlen(inputText[numberOfWords]);
        numberOfWords++;
    }


    for(int n=0; n<textLenght; n++){
        //cin.ingone
        cin>>inputText[n];
    }


}
void outputText(){
    //cout<<*sentence;
    //cout<<"\n"<<numberOfWords<<"\n";
    //for(int i=0; )

    for(int i=0;i<numberOfWords;i++){
        cout<<inputText[i];
    }

}
int main(){
    //input();
    //outputText();
    cin>>textLenght;
    char *sentence = new char[textLenght];
    char redacted[2048] = {""};
    cin.ignore();
    cin.getline(sentence, textLenght ,'\n');
    for(int i=0; i<textLenght;i++){
        cout<<*(sentence+i);
    }


}

*/
///###################################################
///zad1
/*
#include<iostream>
using namespace std;

int main(){
    int N1,N2,M1,M2;
    int oldN1, oldM1;
    cin>>N1>>M1>>N2>>M2;
    oldN1 = N1;
    oldM1 = M1;

    if(N1 <= 0 || N2 <= 0 || M1 <= 0 || M2 <= 0){
        cout<<"invalid numbers";
        return 0;
    }

    int **matrix1 = new int*[N1];
    for(int x=0; x<N1; x++){
        matrix1[x] = new int[M1];
        for(int y=0; y<M1; y++){
            cin>>matrix1[x][y];
        }
    }
    int **matrix2 = new int*[N2];
    for(int x=0; x<N2; x++){
        matrix2[x] = new int[M2];
        for(int y=0; y<M2; y++){
            cin>>matrix2[x][y];
        }
    }

    if(N2 < N1){
        //for(int x=N2; x<N1 ; x++){
            //delete [] matrix1[x];
        //}
        N1 = N2;
    }
    if(M2 < M1){
        //for(int x=M2; x<M1 ; x++){
            //for(int y=0; y<N1; y++){
                // [x] matrix1[x][y];
            //}
        //}
        M1 = M2;
    }

    for(int x=0; x<N1; x++){
        for(int y = 0; y<M1; y++){
            if(matrix1[x][y] == matrix2[x][y]){

            }
            if(matrix1[x][y] < matrix2[x][y]){
                matrix1[x][y] = matrix2[x][y];

            }
            if(matrix1[x][y] > matrix2[x][y]){
                matrix1[x][y] = matrix1[x][y]*(-1);

            }
        }
    }

    cout<<endl<<endl;
    for(int x=0; x<N1; x++){
        for(int y=0; y<M1; y++){
            cout<<matrix1[x][y]<<" ";
        }
        cout<<endl;
    }

    for( int x = 0; x<oldN1; x++){
        delete [] matrix1[x];
    }
    delete [] matrix1;

    for( int x = 0; x<N2; x++){
        delete [] matrix2[x];
    }
    delete [] matrix2;
}
*/
///################################################
///Zad2 - robot
/*
#include<iostream>
using namespace std;
char **matrix;
int N,M;
int counter;


bool isItPassed(int X, int Y){
    if(matrix[X][Y] > 95){
        return 1;
    }else{
        return 0;
    }
}

bool isItOut(int X, int Y){
    if(X<0 || X>=N || Y<0 || Y>=M){
        return 1;
    }else{
        return 0;
    }
}

void step(int X ,int Y){

    //cout<<matrix[2][2];
    switch(matrix[X][Y]){
        case 'U':
            matrix[X][Y]='u';
            if(isItOut(X-1,Y) == false){
                if(isItPassed(X-1, Y) == false ){
                    counter++;
                    step(X-1, Y);
                }else{
                    return;
                }
            }else{
                return;
            }
            break;


        case 'D':
            matrix[X][Y]='d';
            if(isItOut(X+1,Y) == false){
                if(isItPassed(X+1, Y) == false ){
                    counter++;
                    step(X+1, Y);
                }else{
                    return;
                }
            }else{
                return;
            }
            break;


        case 'L':
            matrix[X][Y]='l';
            if(isItOut(X,Y-1) == false){
                if(isItPassed(X, Y-1) == false ){
                    counter++;
                    step(X, Y-1);
                }else{
                    return;
                }
            }else{
                return;
            }



            break;
        case 'R':
            matrix[X][Y]='r';
            if(isItOut(X,Y+1) == false){
                if(isItPassed(X, Y+1) == false ){
                    counter++;
                    step(X, Y+1);
                }else{
                    return;
                }
            }else{
                return;
            }

            break;
        //default:
            //break;
    }
}
void resetMatrix(){
    //cout<<endl;
    //for(int x=0; x<N ;x++){
        //for(int y=0; y<M; y++){
            //cout<<matrix[x][y];
        //}
        //cout<<endl;
    //}
    //cout<<counter<<endl;


    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            switch(matrix[x][y]){
            case 'u':
                matrix[x][y] = 'U';
                break;
            case 'd':
                matrix[x][y] = 'D';
                break;
            case 'l':
                matrix[x][y] = 'L';
                break;
            case 'r':
                matrix[x][y] = 'R';
                break;
            }
        }
    }

}

int main(){
    cin>>N>>M;
    if(N <= 0 || M <= 0){
        cout<<"invalid numbers";
        return 0;
    }
    matrix = new char*[N];
    for(int x=0; x<N; x++){
        matrix[x] = new char[M];
        for(int y=0; y<M; y++){
            cin>>matrix[x][y];
        }
    }
    int longest= -1;
    int longX;
    int longY;

    for(int x = 0; x<N;x++){
        for(int y = 0; y<M; y++){
            counter = 0;
            step(x,y);
            if(longest < counter){
                longest = counter;
                longX = x;
                longY = y;
            }
            resetMatrix();
            //cout<<counter;
        }
    }
    cout<<longX<<" "<<longY;
    //for(int x=0; x<N ;x++){
        //for(int y=0; y<M; y++){
            //cout<<matrix[x][y];
        //}
        //cout<<endl;
    //}
    for( int x = 0; x<N; x++){
        delete [] matrix[x];
    }
    delete [] matrix;
}
*/

