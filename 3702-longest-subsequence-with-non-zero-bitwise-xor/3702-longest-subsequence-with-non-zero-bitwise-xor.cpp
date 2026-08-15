class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total_xor = 0;
        bool all_zero = true;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                all_zero = false;
            }
        }
        
        if (all_zero) {
            return 0; // It's impossible to get a non-zero XOR if everything is 0
        }
        
        if (total_xor != 0) {
            return n; // The entire array already gives a non-zero XOR
        }
        
        // If the total XOR is 0 but there are non-zero elements, 
        // removing exactly one non-zero element will make the XOR non-zero.
        return n - 1;
    }
};