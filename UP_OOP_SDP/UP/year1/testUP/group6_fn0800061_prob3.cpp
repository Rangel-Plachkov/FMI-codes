#include<iostream>
using namespace std;

int size1 , size2;
char firstArr[1024];
char secondArr[1024];

bool proverka(){
    for(int i=0;i<size1;i++){
        if( secondArr[0] == firstArr[i] ){
            if(size2 == 1){
                return true;
            }
            int u=1;
            for(int j=i+1; j !=i; j++){
                if(secondArr[u] == firstArr[j]){
                    u=u+1;
                    if(u==size2){
                        return true;
                    }
                }
                if(j>=size1){
                    j=-1;
                }
            }
        }
    }
    return false;
}
void pechat(){
    cout<<"Rotation found after NOT deleting charcters: ";
    for(int i=0;i<size1;i++){
        if( secondArr[0] == firstArr[i] ){
            if(size2 == 1){
                return;
            }
            int u=1;
            for(int j=i+1; j !=i; j++){
                if(secondArr[u] == firstArr[j]){
                    cout<<j;
                    cout<<" , ";
                    u=u+1;
                    if(u==size2){
                        return;
                    }
                }
                if(j>=size1){
                    j=-1;
                }
            }
        }
    }
    return;


}
int main(){
    //cin>>size1;
    cin>>size1>>size2;
    //INPUT
    for(int i=0;i<size1;i++){
        cin>>firstArr[i];
    }

    for(int i=0;i<size2;i++){
        cin>>secondArr[i];
    }
    if(proverka() == true){
        cout<<"Rotation found after deleting ";
        cout<<size1-size2;
        cout<<" \n characters and NOT deleting (keeping) charcters in position: ";
    for(int i=0;i<size1;i++){
        if( secondArr[0] == firstArr[i] ){
            cout<<i+1;
            cout<<" , ";
            if(size2 == 1){
                return 0;
            }
            int u=1;
            for(int j=i+1; j !=i; j++){
                if(secondArr[u] == firstArr[j]){
                    cout<<j+1;
                    cout<<" , ";
                    u=u+1;
                    if(u==size2){
                        return 0;
                    }
                }
                if(j>=size1){
                    j=-1;
                }
            }
        }
    }
    return 0;

    }else{
        cout<<"No rotation found!";
    }
    ////
    //cin>>size2;
    /*
    for(int i=0; i<100; i++){

        cin>>size2;
        for(int j=0;j<size2;j++){
            cin>>secondArr[j];
        }
        cout<<proverka()<<endl;
    }
    */


}
