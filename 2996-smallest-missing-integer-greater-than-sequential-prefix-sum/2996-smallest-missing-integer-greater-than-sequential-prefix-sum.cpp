class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // Step 1: Find the sum of the longest sequential prefix starting at index 0
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Sequential chain breaks here
            }
        }
        
        // Step 2: Store elements in an unordered_set for O(1) membership lookup
        unordered_set<int> present(nums.begin(), nums.end());
        
        // Step 3: Increment sum until we find an integer NOT present in nums
        while (present.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};