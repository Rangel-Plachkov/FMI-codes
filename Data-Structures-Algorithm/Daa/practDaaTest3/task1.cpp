#include <iostream>
#include <vector>
using namespace std;

vector<int>dp;
vector<int> row;

int getMax(){
    int max = 0;
    for(int i = 0; i < dp.size(); i++){
        if(dp[i] > max){
            max = dp[i];
        }
    }
    return max;
}

int main() {
    int N;
    cin>>N;
    row.resize(N);
    dp.resize(20005);
    for(int i = 0; i < N; i++){
        cin>>row[i];
    }
    for(int i=0; i<N; i++){
        dp[row[i]] = dp[row[i]-1] + 1;
    }
    cout<<getMax()<<endl;
    return 0;
}