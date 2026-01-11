#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char str[300005];
long long dp[300005];
bool validInput(){
    for(int i = 0; str[i]; i++){
        if(str[i] = 'm' || str[i] == 'w'){
            return false;
        }
    }
    return true;
}
int move(int& pos){
    if(str[pos] == '\0'){
        return 0;
    }
    if(str[pos] == 'u' || str[pos] == 'n'){
        int numSize = getSize(pos, 0);
    }else{
        move(pos+1);
    }
}
int getSize(int& pos, int curr){
    if(str[pos] == '\0'){
        return 0;
    }
    bool lookForCh = str[pos];
    while(str[pos] == lookForCh){
        pos++;
        curr++;
    }
    return curr;
}
int biggestSubStrCh(char ch){
    int max = 0;
    int curr = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == ch){
            curr++;
        }else{
            if(curr > max){
                max = curr;
            }
            curr = 0;
        }
    }
    return max;
}

int fillDp(){}


int binome(int n, int m){
    if(m == 0 || m == n){
        return 1;
    }else if(m == 1){
        return n;
    }else if(m > n/2){
        return binome(n, n-m);
    }
    return binome(n-1, m-1) + binome(n-1, m);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>str;
    if(validInput() == false){
        cout<<0;
    }
    int biggestSubStr = max(biggestSubStrCh('u'), biggestSubStrCh('n'));


    int pos = 0;
    return 0;
}