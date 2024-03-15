#include<iostream>
#include<cstring>
using namespace std;
char row[1025];
int lenght;
int current=0;
void inputCheck();
void input(){
    //cin.ignore();
    cin.getline(row , 1025);
    lenght=strlen(row);
    inputCheck();
}
void output(){
    cout<<row;
    /*
    for(int i=0; i<lenght; i++){
        cout<<row;
    }
    */
}
void inputCheck(){
    for(int i=0; i<lenght; i++){
        if(row[i] == 'g' || row[i] == 'y'|| row[i] == 'r'){

        }else{
            cout<<"Invalid input! \n";
            input();
        }
    }
}

void cellCheck(int n){
    if(row[n] == 'g'){
        current++;
        cellCheck(n+1);
        //cout<<step;
    }
    if(row[n] == 'y'){
        for(int i=0; i+n<=lenght;i++){
            if(i+n == lenght){
                return;
            }else{
                if(row[n+i] == 'g'){
                    current++;
                    cellCheck(n+i);
                    return;
                }
            }
        }
    }
    if(row[n] == 'r'){
        return;
    }
    if(row[n] >= lenght){
        return;
    }

}
int main(){
    input();
    //output();
    //cellCheck(3);
    int longest = 0;//,current;
    int longestCell;
    for(int i=0;i<lenght;i++){
        current = 0;
        cellCheck(i);
        //cout<<current;
        if(current>longest){
            longestCell = i;
            longest = current;
        }
    }
    cout<<longest;

}
