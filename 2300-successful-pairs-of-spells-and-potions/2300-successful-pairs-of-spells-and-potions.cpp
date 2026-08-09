class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            int firstValid=m;
            while(low<=high){
                int mid=low+(high-low)/2;
                long long power=1LL*spells[i]*potions[mid];
                if(power>=success){
                    firstValid=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            ans.push_back(m-firstValid);
        }
        return ans;
    }
};