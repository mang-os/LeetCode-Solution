class Solution {
public:
    int memo[205][205][205];
    int MOD = 1e9 + 7;
    int n;
    vector<int> arr;

    int solve(int i, int g1, int g2) {
        if (i == n) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }

        if (memo[i][g1][g2] != -1) {
            return memo[i][g1][g2];
        }

        long long ways = solve(i + 1, g1, g2);

        ways = (ways + solve(i + 1, std::gcd(g1, arr[i]), g2)) % MOD;

        ways = (ways + solve(i + 1, g1, std::gcd(g2, arr[i]))) % MOD;

        return memo[i][g1][g2] = (int)ways;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        
        memset(memo, -1, sizeof(memo));
        
        return solve(0, 0, 0);
    }
};