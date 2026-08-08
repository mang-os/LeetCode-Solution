class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;

        for(int i=0;i<nums.size();i++){
            int num=nums[i];

            if(num<=first){
                first=num;
            }
            else if(num<=second){
                second=num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};