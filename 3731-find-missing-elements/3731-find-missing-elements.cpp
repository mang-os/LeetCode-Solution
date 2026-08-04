class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_val=*min_element(nums.begin(),nums.end());
        int max_val=*max_element(nums.begin(),nums.end());

        unordered_set<int>present_nums(nums.begin(),nums.end());
        vector<int> missing;

        for(int i=min_val;i<=max_val;i++){
            if(present_nums.find(i)==present_nums.end()){
                missing.push_back(i);
            }
        }
        return missing;
    }
};