class Solution {
private:
    int atmostK(vector<int>& nums,int k){
         int n = nums.size();
         int left=0;
         int count=0;
        unordered_map<int,int>hash;
        for(int right=0;right<n;right++){
            hash[nums[right]]++;
            while(hash.size()>k){
                hash[nums[left]]--;
                if(hash[nums[left]]==0){
                    hash.erase(nums[left]);
                }
                left++;
            }
            count+=(right-left+1);
        } 
        return count;
}

public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int k=set.size();

        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};