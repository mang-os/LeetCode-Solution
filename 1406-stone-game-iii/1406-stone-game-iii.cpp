class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] represents the max score difference the current player 
        // can achieve from index i to the end.
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int takeSum = 0;
            dp[i] = INT_MIN;
            
            // A player can take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                takeSum += stoneValue[i + k - 1];
                dp[i] = max(dp[i], takeSum - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};