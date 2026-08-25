class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // Step 1: Insert all array elements into a hash set for O(1) lookups
        unordered_set<int> seen(nums.begin(), nums.end());
        
        int ans = k;
        while (seen.count(ans)) {
            ans += k;
        }
        
        return ans;
    }
};