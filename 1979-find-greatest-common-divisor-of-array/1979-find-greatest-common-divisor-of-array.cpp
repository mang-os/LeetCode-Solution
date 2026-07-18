class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val=*min_element(nums.begin(),nums.end());
        int max_val=*max_element(nums.begin(),nums.end());

        return gcd(min_val,max_val);
    }
};