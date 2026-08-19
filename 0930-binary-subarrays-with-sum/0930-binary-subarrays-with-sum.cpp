class Solution {
private:
    int numSubarraysWithAtMostSum(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int left=0,right=0,sum=0,count=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum=sum-nums[left];
                left++;   
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithAtMostSum(nums,goal)-numSubarraysWithAtMostSum(nums,goal-1);
    }
   
};