class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // dp[i][m] stores the maximum stones a player can get starting from index i with M = m
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        // Suffix sum array to quickly calculate the sum of remaining piles
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Fill the DP table starting from the end
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                // If we can take all remaining stones, just take them
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } else {
                    // Otherwise, try all possible moves x from 1 to 2M
                    // Score = Total remaining stones - Opponent's max score
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }

        // The answer for Alice starting at index 0 with M = 1
        return dp[0][1];
    }
};