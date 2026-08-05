class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixCount;
        int currentSum=0;
        int count=0;

        prefixCount[0]=1;

        for(int num:nums){
            currentSum+=num;

            if(prefixCount.find(currentSum-goal)!=prefixCount.end()){
                count+=prefixCount[currentSum-goal];
            }
            prefixCount[currentSum]++;
        }
        return count;
    }
};