class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int currentSum=0;
        for(int i=0;i<k;i++){
             currentSum+=nums[i];
        }
        int maxSum=currentSum;
        for(int i=k;i<n;i++){
            currentSum-=nums[i-k];
            currentSum+=nums[i];

            maxSum=max(currentSum,maxSum);
        }
        return (double)maxSum/k;
    }
};