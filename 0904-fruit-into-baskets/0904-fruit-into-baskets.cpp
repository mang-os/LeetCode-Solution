class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int n=fruits.size();
        int left=0,right=0,maxLen=0;
        unordered_map<int,int>mpp;
        while(right<n){
            mpp[fruits[right]]++;
            if(mpp.size()>k){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]);   
                }
                left++;
            }
            if(mpp.size()<=k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};