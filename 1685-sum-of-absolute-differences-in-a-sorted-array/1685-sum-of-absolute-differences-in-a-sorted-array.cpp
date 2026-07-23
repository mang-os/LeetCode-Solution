class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);

        int totalSum=accumulate(nums.begin(),nums.end(),0);

        int leftSum=0;
        for(int i=0;i<n;i++){
            int rightSum=totalSum-leftSum-nums[i];

            int leftDiff=nums[i]*i-(leftSum);
            int rightDiff=rightSum-(nums[i]*(n-i-1));

            result[i]=leftDiff+rightDiff;
            leftSum+=nums[i];
        }
        return result;
    }
};