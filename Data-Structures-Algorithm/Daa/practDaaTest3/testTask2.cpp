#include <iostream>
#include<cstring>
using namespace std;

long long dp[300005][2];
char str[300005];
const long long MOD = 1000000007;

void fillDp(){
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for(int i = 2; i <= 300000; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0])%MOD;
    }
}
long long getForN(int N){
    return (dp[N][0] + dp[N][1])%MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fillDp();
    cin>>str;
    for(int pos = 0; str[pos]; pos++){
        if(str[pos] == 'm' || str[pos] == 'w'){
            cout<<0<<endl;
            return 0;
        }
    }
    long long res = 1;
    for(int pos = 0; str[pos]; pos++){
        if(str[pos] == 'u'){
            int curr = 0;
            while(str[pos] == 'u'){
                pos++;
                curr++;
            }
            pos--;
            res = (res*getForN(curr))%MOD;
        }else if(str[pos] == 'n'){
            int curr = 0;
            while(str[pos] == 'n'){
                pos++;
                curr++;
            }
            pos--;
            res = (res*getForN(curr))%MOD;
        }
    }
    cout<<res<<endl;
    return 0;
}