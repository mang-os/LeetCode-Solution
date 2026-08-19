class Solution {
private:
    int SubarrayWithSumAtMostK(vector<int>& nums, int k){
        if(k<0)return 0;
        int left=0,right=0,sum=0,count=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right]%2;
            while(sum>k){
                sum-=nums[left]%2;
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return SubarrayWithSumAtMostK(nums,k)-SubarrayWithSumAtMostK(nums,k-1);
    }
};