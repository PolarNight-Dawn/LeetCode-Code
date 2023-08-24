#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-24.
//

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        if (n == 0) return 0;
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

int main() {
    int n = 3;

    Solution sol;
    std::cout << sol.numTrees(n);

    return 0;
}