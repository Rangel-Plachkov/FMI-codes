#include<iostream>
#include<vector>

#include<numeric>

class Ministries{
public:
    void input(){
        std::cin >> N;
        _ministries.resize(N);
        for(size_t i = 0; i < N; ++i){
            std::cin >> _ministries[i];
        }
    }
    long long minDifference(){
        long long sum = std::accumulate(_ministries.begin(), _ministries.end(), 0);
        std::vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(size_t i = 0; i < N; ++i){
            for(int j = sum; j >= _ministries[i]; --j){
                dp[j] = dp[j] || dp[j - _ministries[i]];
            }
        }
        long long half_sum = sum / 2;
        while(half_sum > 0 && !dp[half_sum]){
            --half_sum;
        }
        return sum - 2 * half_sum;
    }
    

private:
    size_t N;
    std::vector<size_t> _ministries;
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Ministries ministries;
    ministries.input();
    std::cout << ministries.minDifference() << std::endl;
    
    return 0;
}