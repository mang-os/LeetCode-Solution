class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        
        for (int num : nums1) {
            if (num % 2 == 0) {
                min_even = min(min_even, num);
            } else {
                min_odd = min(min_odd, num);
            }
        }
        
        if (min_odd == INT_MAX || min_even == INT_MAX) {
            return true;
        }
        
        return min_even > min_odd;
    }
};