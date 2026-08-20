class Solution {
    private:
        int findingCount(vector<int>& nums,int k){
            int n=nums.size();
            int left=0,right=0,count=0;
            unordered_map<int,int>hashmap;
            while(right<n){
                hashmap[nums[right]]++;
                while(hashmap.size()>k){
                    hashmap[nums[left]]--;
                    if(hashmap[nums[left]]==0){
                        hashmap.erase(nums[left]);   
                    }
                    left++;
                }
                count+=(right-left+1);
                right++;
            }
            return count;
        }
    public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findingCount(nums,k)-findingCount(nums,k-1);
    }
};