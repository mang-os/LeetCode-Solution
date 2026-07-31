class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int posCount=0;
        int negCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                negCount++;
            }
            else if(nums[i]>0){
                posCount++;
            }
        }
        return max(posCount,negCount);
    }
};