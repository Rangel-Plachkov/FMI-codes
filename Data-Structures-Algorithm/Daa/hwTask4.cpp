#include<iostream>
#include<vector>

class Row{
public:
    void input(){
        std::cin >> N;
        row.resize(N);
        for(size_t i = 0; i < N; ++i){
            std::cin >> row[i];
        }
    }
    long long maxSum(){
        std::vector<std::vector<int>> dp;
        dp.resize(N);
        for(size_t i = 0; i < N; ++i){
            dp[i].resize(2);
        }
        dp[0][0] = row[0]*2;
        dp[0][1] = row[0]*3;
        for(size_t i = 1; i < N; ++i){
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]) + row[i]*2;
            dp[i][1] = row[i]*3 + dp[i-1][0];
        }
        return std::max(dp[N-1][0], dp[N-1][1]);
    }

private:
    size_t N;
    std::vector<int> row;
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Row row;
    row.input();
    std::cout<< row.maxSum() << std::endl;

    return 0;
}