class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;

            // Shrink window if the current element exceeds frequency k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            // Update maximum valid window size
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};