class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> subarray_counts;
        int n = nums.size();
        
        // Iterate through all possible starting indices of a subarray of size k
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_subarray;
            
            // Collect unique elements in the current subarray
            for (int j = i; j < i + k; ++j) {
                unique_in_subarray.insert(nums[j]);
            }
            
            // Increment the count for each unique element found
            for (int num : unique_in_subarray) {
                subarray_counts[num]++;
            }
        }
        
        int ans = -1;
        // Find the largest integer that appears in exactly one subarray
        for (const auto& [num, count] : subarray_counts) {
            if (count == 1) {
                ans = max(ans, num);
            }
        }
        
        return ans;
    }
};