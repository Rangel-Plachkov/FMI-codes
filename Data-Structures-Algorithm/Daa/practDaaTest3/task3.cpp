#include<iostream>
using namespace std;

int N, M;
int matrix[1005][1005];
long long dp[1005][1005];



int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<N; i++){
        dp[i][0] = matrix[i][0];
    }
    for(int x = 1; x<M; x++){
        for(int y =0; y<N; y++){
            if(y == 0){
                dp[y][x] = matrix[y][x] + min(dp[y][x-1], dp[y+1][x-1]);
            }else if(y == N-1){
                dp[y][x] = matrix[y][x] + min(dp[y][x-1], dp[y-1][x-1]);
            }else{
                dp[y][x] = matrix[y][x] + min(dp[y][x-1], min(dp[y-1][x-1], dp[y+1][x-1]));
            }
        }
    }
    /*
    cout<<endl;
    cout<<endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int min;
    for(int i = 0; i < N; i++){
        if(i == 0){
            min = dp[i][M-1];
        }else{
            if(dp[i][M-1] < min){
                min = dp[i][M-1];
            }
        }
    }
    cout<<min<<endl;
    return 0;
}