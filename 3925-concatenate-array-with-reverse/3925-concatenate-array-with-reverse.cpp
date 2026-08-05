class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(2*n);
        for(int i=0;i<n;i++){
            result[i]=nums[i];

            result[i+n]=nums[n-i-1];
        }
        return result;
    }
};