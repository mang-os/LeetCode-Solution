class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums
        vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }
        
        // Base case: taking all stones leaves only the prefix sum at n-1
        int ans = pref[n - 1];
        
        // Transition backwards from n - 2 down to index 1 (since x > 1)
        for (int i = n - 2; i >= 1; --i) {
            ans = max(ans, pref[i] - ans);
        }
        
        return ans;
    }
};