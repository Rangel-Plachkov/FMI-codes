#include<iostream>
using namespace std;
bool vutreLiE(int N, int K){
    N=N/10;
    int saveN = N, saveK =K ;
    while(N>0){
        while(K>0){
            if(K%10 == N%10){
                K=K/10;
                N=N/10;
            }else{
                break;
            }
        }
        if(K == 0){
            if(saveN/saveK == 1){
                return false;
            }
            return true;
        }
        K=saveK;
        saveN=saveN/10;
        N=saveN;
    }
    return false;
}
int main(){
    int N,K;
    cin>>N>>K;
    if(vutreLiE(N , K)){
        cout<<"True";
    }else{
        cout<<"False";
    }
}
