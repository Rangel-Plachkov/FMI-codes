#include <iostream>
#include <vector>
#include <numeric>

int minLeftover(std::vector<int>& nums) {
    int n = nums.size();
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    int minLeftover = totalSum;

    for (int i = 0; i < (1 << n); ++i) {
        int sumA = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sumA += nums[j];
            }
        }

        for (int j = 0; j < (1 << n); ++j) {
            if (i != j) {
                int sumB = 0;
                for (int k = 0; k < n; ++k) {
                    if (j & (1 << k)) {
                        sumB += nums[k];
                    }
                }

                if (sumA == sumB) {
                    int leftover = totalSum - 2 * sumA;
                    minLeftover = std::min(minLeftover, leftover);
                }
            }
        }
    }

    return minLeftover;
}

int main() {
    std::vector<int> nums = {8, 1, 3, 5, 2};
    std::cout << "Minimum leftover is: " << minLeftover(nums) << std::endl;
    return 0;
}
