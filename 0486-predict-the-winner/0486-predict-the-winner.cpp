class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == j) return nums[i];

        if (dp[i][j] != -1) return dp[i][j];

        int takeLeft = nums[i] - solve(i + 1, j, nums, dp);
        int takeRight = nums[j] - solve(i, j - 1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, nums, dp) >= 0;
    }
};