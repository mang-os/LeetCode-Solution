class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last=nums[n-1]-1;
        int secondLast=nums[n-2]-1;
        return last*secondLast;
    }
};